/*******************************************************************************
* File Name: H100.h
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

#if !defined(CY_CLOCK_H100_H)
#define CY_CLOCK_H100_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void H100_Start(void);
void H100_Stop(void);

void H100_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 H100_GetDividerRegister(void);
uint8  H100_GetFractionalDividerRegister(void);

#define H100_Enable()                         H100_Start()
#define H100_Disable()                        H100_Stop()
#define H100_SetDividerRegister(clkDivider, reset)  \
                        H100_SetFractionalDividerRegister((clkDivider), 0)
#define H100_SetDivider(clkDivider)           H100_SetDividerRegister((clkDivider), 1)
#define H100_SetDividerValue(clkDivider)      H100_SetDividerRegister((clkDivider) - 1, 1)


/***************************************
*             Registers
***************************************/

#define H100_DIV_REG    (*(reg32 *)H100__REGISTER)
#define H100_ENABLE_REG H100_DIV_REG

#endif /* !defined(CY_CLOCK_H100_H) */

/* [] END OF FILE */
