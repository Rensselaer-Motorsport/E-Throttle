/*******************************************************************************
* File Name: APPS_ADC_INT.c
* Version 2.0
*
*  Description:
*    This file contains the code that operates during the interrupt
*    service routine.
*
*   Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "APPS_ADC.h"


/******************************************************************************
* Custom Declarations and Variables
* - add user inlcude files, prototypes and variables between the following
*   #START and #END tags
******************************************************************************/
/* `#START SEQ_ADC_SYS_VAR`  */

/* `#END`  */


#if(APPS_ADC_IRQ_REMOVE == 0u)


    /******************************************************************************
    * Function Name: APPS_ADC_ISR
    *******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  No.
    *
    ******************************************************************************/
    CY_ISR( APPS_ADC_ISR )
    {
        /************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        *************************************************************************/
          /* `#START MAIN_SEQ_ADC_ISR`  */

          /* `#END`  */

    }

#endif   /* End APPS_ADC_IRQ_REMOVE */

/* [] END OF FILE */
