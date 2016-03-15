/*******************************************************************************
* File Name: TILT_PM.c
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

#include "TILT.h"

static TILT_BACKUP_STRUCT TILT_backup;


/*******************************************************************************
* Function Name: TILT_SaveConfig
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
void TILT_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: TILT_Sleep
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
void TILT_Sleep(void)
{
    if(0u != (TILT_BLOCK_CONTROL_REG & TILT_MASK))
    {
        TILT_backup.enableState = 1u;
    }
    else
    {
        TILT_backup.enableState = 0u;
    }

    TILT_Stop();
    TILT_SaveConfig();
}


/*******************************************************************************
* Function Name: TILT_RestoreConfig
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
void TILT_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: TILT_Wakeup
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
void TILT_Wakeup(void)
{
    TILT_RestoreConfig();

    if(0u != TILT_backup.enableState)
    {
        TILT_Enable();
    }
}


/* [] END OF FILE */
