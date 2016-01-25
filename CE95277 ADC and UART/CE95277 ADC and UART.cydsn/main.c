/******************************************************************************
* Project Name		: CE95277 ADC and UART
* File Name			: main.c
* Version 			: **
* Device Used		: CY8C5888LTI-LP097
* Software Used		: PSoC Creator 3.1 SP2
* Compiler    		: ARM GCC 4.8.4, ARM RVDS Generic, ARM MDK Generic
* Related Hardware	: CY8CKIT059 PSoC 5 LP Prototyping Kit 
* Owner				: KLMZ
*
********************************************************************************
* Copyright (2015), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/

#include <device.h>
#include "stdio.h"

/* Project Defines */
#define FALSE  0
#define TRUE   1
#define TRANSMIT_BUFFER_SIZE  16


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main() performs following functions:
*  1: Starts the ADC and UART components.
*  2: Checks for ADC end of conversion.  Stores latest result in output
*     if conversion complete.
*  3: Checks for UART input.
*     On 'C' or 'c' received: transmits the last sample via the UART.
*     On 'S' or 's' received: continuously transmits samples as they are completed.
*     On 'X' or 'x' received: stops continuously transmitting samples.
*     On 'E' or 'e' received: transmits a dummy byte of data.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void main()
{
    /* Variable to store ADC result */
    uint32 Output;
    /* Variable to store UART received character */
    uint8 Ch;
    /* Variable used to send emulated data */
    uint8 EmulatedData;
    /* Flags used to store transmit data commands */
    uint8 ContinuouslySendData;
    uint8 SendSingleByte;
    uint8 SendEmulatedData;
    /* Transmit Buffer */
    char TransmitBuffer[TRANSMIT_BUFFER_SIZE];
    
    /* Start the components */
    ADC_DelSig_1_Start();
    UART_1_Start();
    
    /* Initialize Variables */
    ContinuouslySendData = FALSE;
    SendSingleByte = FALSE;
    SendEmulatedData = FALSE;
    EmulatedData = 0;
    
    /* Start the ADC conversion */
    ADC_DelSig_1_StartConvert();
    
    /* Send message to verify COM port is connected properly */
    UART_1_PutString("COM Port Open");
    
    for(;;)
    {        
        /* Non-blocking call to get the latest data recieved  */
        Ch = UART_1_GetChar();
        
        /* Set flags based on UART command */
        switch(Ch)
        {
            case 0:
                /* No new data was recieved */
                break;
            case 'C':
            case 'c':
                SendSingleByte = TRUE;
                break;
            case 'S':
            case 's':
                ContinuouslySendData = TRUE;
                break;
            case 'X':
            case 'x':
                ContinuouslySendData = FALSE;
                break;
            case 'E':
            case 'e':
                SendEmulatedData = TRUE;
                break;
            default:
                /* Place error handling code here */
                break;    
        }
        
        /* Check to see if an ADC conversion has completed */
        if(ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_RETURN_STATUS))
        {
            /* Use the GetResult16 API to get an 8 bit unsigned result in
             * single ended mode.  The API CountsTo_mVolts is then used
             * to convert the ADC counts into mV before transmitting via
             * the UART.  See the datasheet API description for more
             * details */
            Output = ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_GetResult16());
            
            /* Send data based on last UART command */
            if(SendSingleByte || ContinuouslySendData)
            {
                /* Format ADC result for transmition */
                sprintf(TransmitBuffer, "Sample: %d mV\r\n", Output);
                /* Send out the data */
                UART_1_PutString(TransmitBuffer);
                /* Reset the send once flag */
                SendSingleByte = FALSE;
            }
            else if(SendEmulatedData)
            {
                /* Format ADC result for transmition */
                sprintf(TransmitBuffer, "Emulated Data: %x \r\n", EmulatedData);
                /* Send out the data */
                UART_1_PutString(TransmitBuffer);
                EmulatedData++;
                /* Reset the send once flag */
                SendEmulatedData = FALSE;   
            }
        }
    }
}


/* [] END OF FILE */
