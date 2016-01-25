/*******************************************************************************
* File Name: Preamp_In_1.c  
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
#include "Preamp_In_1.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Preamp_In_1_PC =   (Preamp_In_1_PC & \
                                (uint32)(~(uint32)(Preamp_In_1_DRIVE_MODE_IND_MASK << (Preamp_In_1_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Preamp_In_1_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Preamp_In_1_Write
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
void Preamp_In_1_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Preamp_In_1_DR & (uint8)(~Preamp_In_1_MASK));
    drVal = (drVal | ((uint8)(value << Preamp_In_1_SHIFT) & Preamp_In_1_MASK));
    Preamp_In_1_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Preamp_In_1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Preamp_In_1_DM_STRONG     Strong Drive 
*  Preamp_In_1_DM_OD_HI      Open Drain, Drives High 
*  Preamp_In_1_DM_OD_LO      Open Drain, Drives Low 
*  Preamp_In_1_DM_RES_UP     Resistive Pull Up 
*  Preamp_In_1_DM_RES_DWN    Resistive Pull Down 
*  Preamp_In_1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Preamp_In_1_DM_DIG_HIZ    High Impedance Digital 
*  Preamp_In_1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Preamp_In_1_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Preamp_In_1__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Preamp_In_1_Read
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
*  Macro Preamp_In_1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Preamp_In_1_Read(void) 
{
    return (uint8)((Preamp_In_1_PS & Preamp_In_1_MASK) >> Preamp_In_1_SHIFT);
}


/*******************************************************************************
* Function Name: Preamp_In_1_ReadDataReg
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
uint8 Preamp_In_1_ReadDataReg(void) 
{
    return (uint8)((Preamp_In_1_DR & Preamp_In_1_MASK) >> Preamp_In_1_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Preamp_In_1_INTSTAT) 

    /*******************************************************************************
    * Function Name: Preamp_In_1_ClearInterrupt
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
    uint8 Preamp_In_1_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Preamp_In_1_INTSTAT & Preamp_In_1_MASK);
		Preamp_In_1_INTSTAT = maskedStatus;
        return maskedStatus >> Preamp_In_1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */