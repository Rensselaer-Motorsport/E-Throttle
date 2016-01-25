/*******************************************************************************
* File Name: APPS_ADC.h
* Version 2.0
*
* Description:
*  Contains the function prototypes, constants and register definition of the
*  ADC SAR Sequencer Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_APPS_ADC_H)
    #define CY_APPS_ADC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "APPS_ADC_TempBuf_dma.h"
#include "APPS_ADC_FinalBuf_dma.h"
#include "APPS_ADC_SAR.h"

#define APPS_ADC_NUMBER_OF_CHANNELS    (2u)
#define APPS_ADC_SAMPLE_MODE           (1u)
#define APPS_ADC_CLOCK_SOURCE          (0u)

extern int16  APPS_ADC_finalArray[APPS_ADC_NUMBER_OF_CHANNELS];
extern uint32 APPS_ADC_initVar;

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ADC_SAR_SEQ_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*        Function Prototypes
***************************************/
void APPS_ADC_Init(void);
void APPS_ADC_Enable(void);
void APPS_ADC_Disable(void);
void APPS_ADC_Start(void);
void APPS_ADC_Stop(void);

uint32 APPS_ADC_IsEndConversion(uint8 retMode);
int16 APPS_ADC_GetResult16(uint16 chan);
int16 APPS_ADC_GetAdcResult(void);
void APPS_ADC_SetOffset(int32 offset);
void APPS_ADC_SetResolution(uint8 resolution);
void APPS_ADC_SetScaledGain(int32 adcGain);
int32 APPS_ADC_CountsTo_mVolts(int16 adcCounts);
int32 APPS_ADC_CountsTo_uVolts(int16 adcCounts);
float32 APPS_ADC_CountsTo_Volts(int16 adcCounts);
void APPS_ADC_Sleep(void);
void APPS_ADC_Wakeup(void);
void APPS_ADC_SaveConfig(void);
void APPS_ADC_RestoreConfig(void);

CY_ISR_PROTO( APPS_ADC_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void APPS_ADC_SetGain(int32 adcGain);


/**************************************
*    Initial Parameter Constants
**************************************/
#define APPS_ADC_IRQ_REMOVE             (0u)                /* Removes internal interrupt */


/***************************************
*             Registers
***************************************/
#define APPS_ADC_CYCLE_COUNTER_AUX_CONTROL_REG \
                                               (*(reg8 *) APPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define APPS_ADC_CYCLE_COUNTER_AUX_CONTROL_PTR \
                                               ( (reg8 *) APPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define APPS_ADC_CONTROL_REG    (*(reg8 *) \
                                             APPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define APPS_ADC_CONTROL_PTR    ( (reg8 *) \
                                             APPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define APPS_ADC_COUNT_REG      (*(reg8 *) \
                                             APPS_ADC_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define APPS_ADC_COUNT_PTR      ( (reg8 *) \
                                             APPS_ADC_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define APPS_ADC_STATUS_REG     (*(reg8 *) APPS_ADC_bSAR_SEQ_EOCSts__STATUS_REG)
#define APPS_ADC_STATUS_PTR     ( (reg8 *) APPS_ADC_bSAR_SEQ_EOCSts__STATUS_REG)

#define APPS_ADC_SAR_DATA_ADDR_0 (APPS_ADC_SAR_ADC_SAR__WRK0)
#define APPS_ADC_SAR_DATA_ADDR_1 (APPS_ADC_SAR_ADC_SAR__WRK1)
#define APPS_ADC_SAR_DATA_ADDR_0_REG (*(reg8 *) \
                                              APPS_ADC_SAR_ADC_SAR__WRK0)
#define APPS_ADC_SAR_DATA_ADDR_1_REG (*(reg8 *) \
                                              APPS_ADC_SAR_ADC_SAR__WRK1)


/**************************************
*       Register Constants
**************************************/

#if(APPS_ADC_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define APPS_ADC_INTC_PRIOR_NUMBER          (uint8)(APPS_ADC_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define APPS_ADC_INTC_NUMBER                (uint8)(APPS_ADC_IRQ__INTC_NUMBER)

#endif   /* End APPS_ADC_IRQ_REMOVE */


/***************************************
*       API Constants
***************************************/

/* Constants for IsEndConversion() "retMode" parameter */
#define APPS_ADC_RETURN_STATUS              (0x01u)
#define APPS_ADC_WAIT_FOR_RESULT            (0x00u)

/* Defines for the Resolution parameter */
#define APPS_ADC_BITS_12    APPS_ADC_SAR__BITS_12
#define APPS_ADC_BITS_10    APPS_ADC_SAR__BITS_10
#define APPS_ADC_BITS_8     APPS_ADC_SAR__BITS_8

#define APPS_ADC_CYCLE_COUNTER_ENABLE    (0x20u)
#define APPS_ADC_BASE_COMPONENT_ENABLE   (0x01u)
#define APPS_ADC_LOAD_COUNTER_PERIOD     (0x02u)
#define APPS_ADC_SOFTWARE_SOC_PULSE      (0x04u)

/* Generic DMA Configuration parameters */
#define APPS_ADC_TEMP_BYTES_PER_BURST     (uint8)(2u)
#define APPS_ADC_TEMP_TRANSFER_COUNT      ((uint16)APPS_ADC_NUMBER_OF_CHANNELS << 1u)
#define APPS_ADC_FINAL_BYTES_PER_BURST    ((uint16)APPS_ADC_NUMBER_OF_CHANNELS << 1u)
#define APPS_ADC_REQUEST_PER_BURST        (uint8)(1u)

#define APPS_ADC_GET_RESULT_INDEX_OFFSET    ((uint8)APPS_ADC_NUMBER_OF_CHANNELS - 1u)

/* Define for Sample Mode  */
#define APPS_ADC_SAMPLE_MODE_FREE_RUNNING    (0x00u)
#define APPS_ADC_SAMPLE_MODE_SW_TRIGGERED    (0x01u)
#define APPS_ADC_SAMPLE_MODE_HW_TRIGGERED    (0x02u)

/* Define for Clock Source  */
#define APPS_ADC_CLOCK_INTERNAL              (0x00u)
#define APPS_ADC_CLOCK_EXTERNAL              (0x01u)


/***************************************
*        Optional Function Prototypes
***************************************/
#if(APPS_ADC_SAMPLE_MODE != APPS_ADC_SAMPLE_MODE_HW_TRIGGERED)
    void APPS_ADC_StartConvert(void);
    void APPS_ADC_StopConvert(void);
#endif /* APPS_ADC_SAMPLE_MODE != APPS_ADC_SAMPLE_MODE_HW_TRIGGERED */

#endif  /* !defined(CY_APPS_ADC_H) */

/* [] END OF FILE */
