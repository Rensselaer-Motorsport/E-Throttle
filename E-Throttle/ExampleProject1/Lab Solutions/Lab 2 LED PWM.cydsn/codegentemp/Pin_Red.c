/*******************************************************************************
* File Name: Pin_Red.c  
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
#include "Pin_Red.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Pin_Red_PC =   (Pin_Red_PC & \
                                (uint32)(~(uint32)(Pin_Red_DRIVE_MODE_IND_MASK << (Pin_Red_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Pin_Red_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Pin_Red_Write
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
void Pin_Red_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Pin_Red_DR & (uint8)(~Pin_Red_MASK));
    drVal = (drVal | ((uint8)(value << Pin_Red_SHIFT) & Pin_Red_MASK));
    Pin_Red_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Pin_Red_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Pin_Red_DM_STRONG     Strong Drive 
*  Pin_Red_DM_OD_HI      Open Drain, Drives High 
*  Pin_Red_DM_OD_LO      Open Drain, Drives Low 
*  Pin_Red_DM_RES_UP     Resistive Pull Up 
*  Pin_Red_DM_RES_DWN    Resistive Pull Down 
*  Pin_Red_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Pin_Red_DM_DIG_HIZ    High Impedance Digital 
*  Pin_Red_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Pin_Red_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Pin_Red__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Pin_Red_Read
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
*  Macro Pin_Red_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pin_Red_Read(void) 
{
    return (uint8)((Pin_Red_PS & Pin_Red_MASK) >> Pin_Red_SHIFT);
}


/*******************************************************************************
* Function Name: Pin_Red_ReadDataReg
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
uint8 Pin_Red_ReadDataReg(void) 
{
    return (uint8)((Pin_Red_DR & Pin_Red_MASK) >> Pin_Red_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pin_Red_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pin_Red_ClearInterrupt
    ********************************************************************************
    *
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
    uint8 Pin_Red_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Pin_Red_INTSTAT & Pin_Red_MASK);
		Pin_Red_INTSTAT = maskedStatus;
        return maskedStatus >> Pin_Red_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
