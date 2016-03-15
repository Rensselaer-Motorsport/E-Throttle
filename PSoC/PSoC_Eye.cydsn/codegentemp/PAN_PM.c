/*******************************************************************************
* File Name: PAN_PM.c
* Version 1.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PAN.h"

static PAN_BACKUP_STRUCT PAN_backup;


/*******************************************************************************
* Function Name: PAN_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PAN_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PAN_Sleep(void)
{
    if(0u != (PAN_BLOCK_CONTROL_REG & PAN_MASK))
    {
        PAN_backup.enableState = 1u;
    }
    else
    {
        PAN_backup.enableState = 0u;
    }

    PAN_Stop();
    PAN_SaveConfig();
}


/*******************************************************************************
* Function Name: PAN_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PAN_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PAN_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PAN_Wakeup(void)
{
    PAN_RestoreConfig();

    if(0u != PAN_backup.enableState)
    {
        PAN_Enable();
    }
}


/* [] END OF FILE */
