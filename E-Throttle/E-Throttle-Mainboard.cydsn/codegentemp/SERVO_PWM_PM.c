/*******************************************************************************
* File Name: SERVO_PWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SERVO_PWM.h"

static SERVO_PWM_backupStruct SERVO_PWM_backup;


/*******************************************************************************
* Function Name: SERVO_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVO_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SERVO_PWM_SaveConfig(void) 
{

    #if(!SERVO_PWM_UsingFixedFunction)
        #if(!SERVO_PWM_PWMModeIsCenterAligned)
            SERVO_PWM_backup.PWMPeriod = SERVO_PWM_ReadPeriod();
        #endif /* (!SERVO_PWM_PWMModeIsCenterAligned) */
        SERVO_PWM_backup.PWMUdb = SERVO_PWM_ReadCounter();
        #if (SERVO_PWM_UseStatus)
            SERVO_PWM_backup.InterruptMaskValue = SERVO_PWM_STATUS_MASK;
        #endif /* (SERVO_PWM_UseStatus) */

        #if(SERVO_PWM_DeadBandMode == SERVO_PWM__B_PWM__DBM_256_CLOCKS || \
            SERVO_PWM_DeadBandMode == SERVO_PWM__B_PWM__DBM_2_4_CLOCKS)
            SERVO_PWM_backup.PWMdeadBandValue = SERVO_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(SERVO_PWM_KillModeMinTime)
             SERVO_PWM_backup.PWMKillCounterPeriod = SERVO_PWM_ReadKillTime();
        #endif /* (SERVO_PWM_KillModeMinTime) */

        #if(SERVO_PWM_UseControl)
            SERVO_PWM_backup.PWMControlRegister = SERVO_PWM_ReadControlRegister();
        #endif /* (SERVO_PWM_UseControl) */
    #endif  /* (!SERVO_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SERVO_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVO_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SERVO_PWM_RestoreConfig(void) 
{
        #if(!SERVO_PWM_UsingFixedFunction)
            #if(!SERVO_PWM_PWMModeIsCenterAligned)
                SERVO_PWM_WritePeriod(SERVO_PWM_backup.PWMPeriod);
            #endif /* (!SERVO_PWM_PWMModeIsCenterAligned) */

            SERVO_PWM_WriteCounter(SERVO_PWM_backup.PWMUdb);

            #if (SERVO_PWM_UseStatus)
                SERVO_PWM_STATUS_MASK = SERVO_PWM_backup.InterruptMaskValue;
            #endif /* (SERVO_PWM_UseStatus) */

            #if(SERVO_PWM_DeadBandMode == SERVO_PWM__B_PWM__DBM_256_CLOCKS || \
                SERVO_PWM_DeadBandMode == SERVO_PWM__B_PWM__DBM_2_4_CLOCKS)
                SERVO_PWM_WriteDeadTime(SERVO_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(SERVO_PWM_KillModeMinTime)
                SERVO_PWM_WriteKillTime(SERVO_PWM_backup.PWMKillCounterPeriod);
            #endif /* (SERVO_PWM_KillModeMinTime) */

            #if(SERVO_PWM_UseControl)
                SERVO_PWM_WriteControlRegister(SERVO_PWM_backup.PWMControlRegister);
            #endif /* (SERVO_PWM_UseControl) */
        #endif  /* (!SERVO_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: SERVO_PWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVO_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void SERVO_PWM_Sleep(void) 
{
    #if(SERVO_PWM_UseControl)
        if(SERVO_PWM_CTRL_ENABLE == (SERVO_PWM_CONTROL & SERVO_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            SERVO_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            SERVO_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (SERVO_PWM_UseControl) */

    /* Stop component */
    SERVO_PWM_Stop();

    /* Save registers configuration */
    SERVO_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: SERVO_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVO_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SERVO_PWM_Wakeup(void) 
{
     /* Restore registers values */
    SERVO_PWM_RestoreConfig();

    if(SERVO_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        SERVO_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
