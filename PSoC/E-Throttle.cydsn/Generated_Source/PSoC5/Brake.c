/*******************************************************************************
* File Name: BRAKE.c  
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
#include "BRAKE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 BRAKE__PORT == 15 && ((BRAKE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: BRAKE_Write
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
void BRAKE_Write(uint8 value) 
{
    uint8 staticBits = (BRAKE_DR & (uint8)(~BRAKE_MASK));
    BRAKE_DR = staticBits | ((uint8)(value << BRAKE_SHIFT) & BRAKE_MASK);
}


/*******************************************************************************
* Function Name: BRAKE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BRAKE_DM_STRONG     Strong Drive 
*  BRAKE_DM_OD_HI      Open Drain, Drives High 
*  BRAKE_DM_OD_LO      Open Drain, Drives Low 
*  BRAKE_DM_RES_UP     Resistive Pull Up 
*  BRAKE_DM_RES_DWN    Resistive Pull Down 
*  BRAKE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BRAKE_DM_DIG_HIZ    High Impedance Digital 
*  BRAKE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BRAKE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BRAKE_0, mode);
}


/*******************************************************************************
* Function Name: BRAKE_Read
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
*  Macro BRAKE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BRAKE_Read(void) 
{
    return (BRAKE_PS & BRAKE_MASK) >> BRAKE_SHIFT;
}


/*******************************************************************************
* Function Name: BRAKE_ReadDataReg
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
uint8 BRAKE_ReadDataReg(void) 
{
    return (BRAKE_DR & BRAKE_MASK) >> BRAKE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BRAKE_INTSTAT) 

    /*******************************************************************************
    * Function Name: BRAKE_ClearInterrupt
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
    uint8 BRAKE_ClearInterrupt(void) 
    {
        return (BRAKE_INTSTAT & BRAKE_MASK) >> BRAKE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
