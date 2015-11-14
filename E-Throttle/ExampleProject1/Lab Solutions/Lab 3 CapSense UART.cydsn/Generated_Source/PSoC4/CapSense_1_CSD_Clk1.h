/*******************************************************************************
* File Name: CapSense_1_CSD_Clk1.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CapSense_1_CSD_Clk1_H)
#define CY_CLOCK_CapSense_1_CSD_Clk1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void CapSense_1_CSD_Clk1_Start(void);
void CapSense_1_CSD_Clk1_Stop(void);

void CapSense_1_CSD_Clk1_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CapSense_1_CSD_Clk1_GetDividerRegister(void);
uint8  CapSense_1_CSD_Clk1_GetFractionalDividerRegister(void);

#define CapSense_1_CSD_Clk1_Enable()                         CapSense_1_CSD_Clk1_Start()
#define CapSense_1_CSD_Clk1_Disable()                        CapSense_1_CSD_Clk1_Stop()
#define CapSense_1_CSD_Clk1_SetDividerRegister(clkDivider, reset)  \
                        CapSense_1_CSD_Clk1_SetFractionalDividerRegister((clkDivider), 0)
#define CapSense_1_CSD_Clk1_SetDivider(clkDivider)           CapSense_1_CSD_Clk1_SetDividerRegister((clkDivider), 1)
#define CapSense_1_CSD_Clk1_SetDividerValue(clkDivider)      CapSense_1_CSD_Clk1_SetDividerRegister((clkDivider) - 1, 1)


/***************************************
*             Registers
***************************************/

#define CapSense_1_CSD_Clk1_DIV_REG    (*(reg32 *)CapSense_1_CSD_Clk1__REGISTER)
#define CapSense_1_CSD_Clk1_ENABLE_REG CapSense_1_CSD_Clk1_DIV_REG

#endif /* !defined(CY_CLOCK_CapSense_1_CSD_Clk1_H) */

/* [] END OF FILE */
