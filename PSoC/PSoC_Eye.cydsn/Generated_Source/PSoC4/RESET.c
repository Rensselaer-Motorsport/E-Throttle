/*******************************************************************************
* File Name: RESET.c  
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
#include "RESET.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        RESET_PC =   (RESET_PC & \
                                (uint32)(~(uint32)(RESET_DRIVE_MODE_IND_MASK << (RESET_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (RESET_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: RESET_Write
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
void RESET_Write(uint8 value) 
{
    uint8 drVal = (uint8)(RESET_DR & (uint8)(~RESET_MASK));
    drVal = (drVal | ((uint8)(value << RESET_SHIFT) & RESET_MASK));
    RESET_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: RESET_SetDriveMode
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
void RESET_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(RESET__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: RESET_Read
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
*  Macro RESET_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RESET_Read(void) 
{
    return (uint8)((RESET_PS & RESET_MASK) >> RESET_SHIFT);
}


/*******************************************************************************
* Function Name: RESET_ReadDataReg
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
uint8 RESET_ReadDataReg(void) 
{
    return (uint8)((RESET_DR & RESET_MASK) >> RESET_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RESET_INTSTAT) 

    /*******************************************************************************
    * Function Name: RESET_ClearInterrupt
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
    uint8 RESET_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(RESET_INTSTAT & RESET_MASK);
		RESET_INTSTAT = maskedStatus;
        return maskedStatus >> RESET_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
