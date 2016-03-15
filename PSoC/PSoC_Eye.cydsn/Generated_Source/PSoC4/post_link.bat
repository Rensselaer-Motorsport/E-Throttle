@REM This script allows a 3rd party IDE to use CyHexTool to perform
@REM any post processing that is necessary to convert the raw flash
@REM image into a complete hex file to use in programming the PSoC.
@REM USAGE: post_link.bat
@REM    arg1: Persistant path back to the directory containing the app project.
@REM    arg2: Path (relative to arg1) of the directory where the hex files go.
@REM    arg3: Name of the project.
@REM NOTE: This script is auto generated. Do not modify.

"C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyvalidateide.exe" -dev CY8C4245AXI-483 -ide "%~1\%~3" -flsAddr 0x0 -flsSize 0x8000 -sramAddr 0x20000000 -sramSize 0x1000
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
move "%~1\%~2\%~n3.hex" "%~1\%~2\%~n3.ihx"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
"C:\Program Files (x86)\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyhextool" -o "%~1\%~2\%~n3.hex" -f "%~1\%~2\%~n3.ihx" -prot "%~dp0protect.hex" -id 4C81193 -a EEPROM=90200000:0,PROGRAM=00000000:8000,CONFIG=80000000:1000,PROTECT=90400000:40 -meta 1101 -chipProt 01 
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
CD /D "C:\Keil\UV4"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
IF NOT EXIST "C:\myProjects\Hobby\100_day_100_projects\Mine\PSoC_Eye\PSoC_Eye.cydsn\PSoC_Eye.svd" rem "C:\myProjects\Hobby\100_day_100_projects\Mine\PSoC_Eye\PSoC_Eye.cydsn\PSoC_Eye.sfr"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
