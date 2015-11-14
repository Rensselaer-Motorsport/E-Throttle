/*******************************************************************************
* File Name: CapSense_1_TunerHelper.h
* Version 2.20
*
* Description:
*  This file provides constants and structure declarations for the tuner helper
*  APIs for the CapSense CSD component.
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_TUNERHELPER_CapSense_1_H)
#define CY_CAPSENSE_CSD_TUNERHELPER_CapSense_1_H

#include "CapSense_1.h"

#if(0u != CapSense_1_CSHL_API_GENERATE)
	#include "CapSense_1_CSHL.h"
#endif /* (0u != CapSense_1_CSHL_API_GENERATE) */

#if (CapSense_1_TUNER_API_GENERATE)
    #include "CapSense_1_MBX.h"
#endif /* (CapSense_1_TUNER_API_GENERATE) */


/***************************************
*     Constants for mailboxes
***************************************/

#define CapSense_1_DEFAULT_MAILBOXES_NUMBER   	(1u)

#define CapSense_1_CENTROID_POSITION_BUFFER_SIZE	(2u)
#define CapSense_1_MB_POSITION_BUFFER_SIZE		(2u)

#define CapSense_1_DEFAULT_TRACKPAD_INDEX			(0u) 

#define CapSense_1_FIRST_FINGER_INDEX   			(0u)
#define CapSense_1_SECOND_FINGER_INDEX   			(1u)

#define CapSense_1_FIRST_FINGER_X_INDEX			(0u)
#define CapSense_1_FIRST_FINGER_Y_INDEX			(1u)

#define CapSense_1_SECOND_FINGER_X_INDEX			(2u)
#define CapSense_1_SECOND_FINGER_Y_INDEX			(3u)


/***************************************
*        Function Prototypes
***************************************/

void CapSense_1_TunerStart(void);
void CapSense_1_TunerComm(void);

#if (CapSense_1_TUNER_API_GENERATE)
   CapSense_1_NO_STRICT_VOLATILE void CapSense_1_ProcessAllWidgets(volatile CapSense_1_OUTBOX *outbox);
#endif /* (CapSense_1_TUNER_API_GENERATE) */


/***************************************
*     Vars with External Linkage
***************************************/
#if (CapSense_1_TUNER_API_GENERATE)
	extern volatile CapSense_1_MAILBOXES CapSense_1_mailboxesComm;
#endif /* (CapSense_1_TUNER_API_GENERATE) */

#endif  /* (CY_CAPSENSE_CSD_TUNERHELPER_CapSense_1_H)*/


/* [] END OF FILE */
