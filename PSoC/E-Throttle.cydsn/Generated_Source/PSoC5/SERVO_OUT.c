/*******************************************************************************
* File Name: SERVO_OUT.c  
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
#include "SERVO_OUT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SERVO_OUT__PORT == 15 && ((SERVO_OUT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SERVO_OUT_Write
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
void SERVO_OUT_Write(uint8 value) 
{
    uint8 staticBits = (SERVO_OUT_DR & (uint8)(~SERVO_OUT_MASK));
    SERVO_OUT_DR = staticBits | ((uint8)(value << SERVO_OUT_SHIFT) & SERVO_OUT_MASK);
}


/*******************************************************************************
* Function Name: SERVO_OUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SERVO_OUT_DM_STRONG     Strong Drive 
*  SERVO_OUT_DM_OD_HI      Open Drain, Drives High 
*  SERVO_OUT_DM_OD_LO      Open Drain, Drives Low 
*  SERVO_OUT_DM_RES_UP     Resistive Pull Up 
*  SERVO_OUT_DM_RES_DWN    Resistive Pull Down 
*  SERVO_OUT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SERVO_OUT_DM_DIG_HIZ    High Impedance Digital 
*  SERVO_OUT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SERVO_OUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SERVO_OUT_0, mode);
}


/*******************************************************************************
* Function Name: SERVO_OUT_Read
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
*  Macro SERVO_OUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SERVO_OUT_Read(void) 
{
    return (SERVO_OUT_PS & SERVO_OUT_MASK) >> SERVO_OUT_SHIFT;
}


/*******************************************************************************
* Function Name: SERVO_OUT_ReadDataReg
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
uint8 SERVO_OUT_ReadDataReg(void) 
{
    return (SERVO_OUT_DR & SERVO_OUT_MASK) >> SERVO_OUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SERVO_OUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: SERVO_OUT_ClearInterrupt
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
    uint8 SERVO_OUT_ClearInterrupt(void) 
    {
        return (SERVO_OUT_INTSTAT & SERVO_OUT_MASK) >> SERVO_OUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
