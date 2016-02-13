/*******************************************************************************
* File Name: Brake.c  
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
#include "Brake.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Brake__PORT == 15 && ((Brake__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Brake_Write
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
void Brake_Write(uint8 value) 
{
    uint8 staticBits = (Brake_DR & (uint8)(~Brake_MASK));
    Brake_DR = staticBits | ((uint8)(value << Brake_SHIFT) & Brake_MASK);
}


/*******************************************************************************
* Function Name: Brake_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Brake_DM_STRONG     Strong Drive 
*  Brake_DM_OD_HI      Open Drain, Drives High 
*  Brake_DM_OD_LO      Open Drain, Drives Low 
*  Brake_DM_RES_UP     Resistive Pull Up 
*  Brake_DM_RES_DWN    Resistive Pull Down 
*  Brake_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Brake_DM_DIG_HIZ    High Impedance Digital 
*  Brake_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Brake_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Brake_0, mode);
}


/*******************************************************************************
* Function Name: Brake_Read
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
*  Macro Brake_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Brake_Read(void) 
{
    return (Brake_PS & Brake_MASK) >> Brake_SHIFT;
}


/*******************************************************************************
* Function Name: Brake_ReadDataReg
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
uint8 Brake_ReadDataReg(void) 
{
    return (Brake_DR & Brake_MASK) >> Brake_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Brake_INTSTAT) 

    /*******************************************************************************
    * Function Name: Brake_ClearInterrupt
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
    uint8 Brake_ClearInterrupt(void) 
    {
        return (Brake_INTSTAT & Brake_MASK) >> Brake_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
