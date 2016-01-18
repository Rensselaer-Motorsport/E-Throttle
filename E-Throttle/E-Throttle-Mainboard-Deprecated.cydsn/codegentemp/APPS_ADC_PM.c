/*******************************************************************************
* File Name: APPS_ADC_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "APPS_ADC.h"
#include "APPS_ADC_SAR.h"
#if(APPS_ADC_CLOCK_SOURCE == APPS_ADC_CLOCK_INTERNAL)
    #include "APPS_ADC_IntClock.h"
#endif   /* APPS_ADC_CLOCK_SOURCE == APPS_ADC_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: APPS_ADC_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void APPS_ADC_Sleep(void)
{
    APPS_ADC_SAR_Stop();
    APPS_ADC_SAR_Sleep();
    APPS_ADC_Disable();

    #if(APPS_ADC_CLOCK_SOURCE == APPS_ADC_CLOCK_INTERNAL)
        APPS_ADC_IntClock_Stop();
    #endif   /* APPS_ADC_CLOCK_SOURCE == APPS_ADC_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: APPS_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void APPS_ADC_Wakeup(void)
{
    APPS_ADC_SAR_Wakeup();
    APPS_ADC_SAR_Enable();

    #if(APPS_ADC_CLOCK_SOURCE == APPS_ADC_CLOCK_INTERNAL)
        APPS_ADC_IntClock_Start();
    #endif   /* APPS_ADC_CLOCK_SOURCE == APPS_ADC_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    APPS_ADC_Enable();

    #if(APPS_ADC_SAMPLE_MODE == APPS_ADC_SAMPLE_MODE_FREE_RUNNING)
        APPS_ADC_SAR_StartConvert();
    #endif /* (APPS_ADC_SAMPLE_MODE == APPS_ADC_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(APPS_ADC_STATUS_PTR);
}


/*******************************************************************************
* Function Name: APPS_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void APPS_ADC_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: APPS_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void APPS_ADC_RestoreConfig(void)
{

}


/* [] END OF FILE */
