/*******************************************************************************
* File Name: PAN_O.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PAN_O.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PAN_O_PC =   (PAN_O_PC & \
                                (uint32)(~(uint32)(PAN_O_DRIVE_MODE_IND_MASK << (PAN_O_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PAN_O_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PAN_O_Write
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
void PAN_O_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PAN_O_DR & (uint8)(~PAN_O_MASK));
    drVal = (drVal | ((uint8)(value << PAN_O_SHIFT) & PAN_O_MASK));
    PAN_O_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PAN_O_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void PAN_O_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PAN_O__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PAN_O_Read
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
*  Macro PAN_O_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PAN_O_Read(void) 
{
    return (uint8)((PAN_O_PS & PAN_O_MASK) >> PAN_O_SHIFT);
}


/*******************************************************************************
* Function Name: PAN_O_ReadDataReg
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
uint8 PAN_O_ReadDataReg(void) 
{
    return (uint8)((PAN_O_DR & PAN_O_MASK) >> PAN_O_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PAN_O_INTSTAT) 

    /*******************************************************************************
    * Function Name: PAN_O_ClearInterrupt
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
    uint8 PAN_O_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PAN_O_INTSTAT & PAN_O_MASK);
		PAN_O_INTSTAT = maskedStatus;
        return maskedStatus >> PAN_O_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
