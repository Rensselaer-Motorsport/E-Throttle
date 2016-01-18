/*******************************************************************************
* File Name: APPS_0.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "APPS_0.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 APPS_0__PORT == 15 && ((APPS_0__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: APPS_0_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void APPS_0_Write(uint8 value) 
{
    uint8 staticBits = (APPS_0_DR & (uint8)(~APPS_0_MASK));
    APPS_0_DR = staticBits | ((uint8)(value << APPS_0_SHIFT) & APPS_0_MASK);
}


/*******************************************************************************
* Function Name: APPS_0_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  APPS_0_DM_STRONG     Strong Drive 
*  APPS_0_DM_OD_HI      Open Drain, Drives High 
*  APPS_0_DM_OD_LO      Open Drain, Drives Low 
*  APPS_0_DM_RES_UP     Resistive Pull Up 
*  APPS_0_DM_RES_DWN    Resistive Pull Down 
*  APPS_0_DM_RES_UPDWN  Resistive Pull Up/Down 
*  APPS_0_DM_DIG_HIZ    High Impedance Digital 
*  APPS_0_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void APPS_0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(APPS_0_0, mode);
}


/*******************************************************************************
* Function Name: APPS_0_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro APPS_0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 APPS_0_Read(void) 
{
    return (APPS_0_PS & APPS_0_MASK) >> APPS_0_SHIFT;
}


/*******************************************************************************
* Function Name: APPS_0_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 APPS_0_ReadDataReg(void) 
{
    return (APPS_0_DR & APPS_0_MASK) >> APPS_0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(APPS_0_INTSTAT) 

    /*******************************************************************************
    * Function Name: APPS_0_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 APPS_0_ClearInterrupt(void) 
    {
        return (APPS_0_INTSTAT & APPS_0_MASK) >> APPS_0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
