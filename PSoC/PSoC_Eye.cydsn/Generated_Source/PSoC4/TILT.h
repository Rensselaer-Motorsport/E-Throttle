/*******************************************************************************
* File Name: TILT.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the TILT
*  component.
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

#if !defined(CY_TCPWM_TILT_H)
#define CY_TCPWM_TILT_H

#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} TILT_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  TILT_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* TCPWM Configuration */
#define TILT_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define TILT_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define TILT_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define TILT_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define TILT_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define TILT_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define TILT_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define TILT_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define TILT_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define TILT_TC_RUN_MODE                    (0lu)
#define TILT_TC_COUNTER_MODE                (0lu)
#define TILT_TC_COMP_CAP_MODE               (2lu)
#define TILT_TC_PRESCALER                   (0lu)

/* Signal modes */
#define TILT_TC_RELOAD_SIGNAL_MODE          (0lu)
#define TILT_TC_COUNT_SIGNAL_MODE           (3lu)
#define TILT_TC_START_SIGNAL_MODE           (0lu)
#define TILT_TC_STOP_SIGNAL_MODE            (0lu)
#define TILT_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define TILT_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define TILT_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define TILT_TC_START_SIGNAL_PRESENT        (0lu)
#define TILT_TC_STOP_SIGNAL_PRESENT         (0lu)
#define TILT_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TILT_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define TILT_PWM_KILL_EVENT                 (0lu)
#define TILT_PWM_STOP_EVENT                 (0lu)
#define TILT_PWM_MODE                       (4lu)
#define TILT_PWM_OUT_N_INVERT               (0lu)
#define TILT_PWM_OUT_INVERT                 (0lu)
#define TILT_PWM_ALIGN                      (0lu)
#define TILT_PWM_RUN_MODE                   (0lu)
#define TILT_PWM_DEAD_TIME_CYCLE            (0lu)
#define TILT_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define TILT_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define TILT_PWM_COUNT_SIGNAL_MODE          (3lu)
#define TILT_PWM_START_SIGNAL_MODE          (0lu)
#define TILT_PWM_STOP_SIGNAL_MODE           (0lu)
#define TILT_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define TILT_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define TILT_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define TILT_PWM_START_SIGNAL_PRESENT       (0lu)
#define TILT_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define TILT_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TILT_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define TILT_TC_PERIOD_VALUE                (65535lu)
#define TILT_TC_COMPARE_VALUE               (65535lu)
#define TILT_TC_COMPARE_BUF_VALUE           (65535lu)
#define TILT_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define TILT_PWM_PERIOD_VALUE               (600lu)
#define TILT_PWM_PERIOD_BUF_VALUE           (65535lu)
#define TILT_PWM_PERIOD_SWAP                (0lu)
#define TILT_PWM_COMPARE_VALUE              (0lu)
#define TILT_PWM_COMPARE_BUF_VALUE          (65535lu)
#define TILT_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define TILT__LEFT 0
#define TILT__RIGHT 1
#define TILT__CENTER 2
#define TILT__ASYMMETRIC 3

#define TILT__X1 0
#define TILT__X2 1
#define TILT__X4 2

#define TILT__PWM 4
#define TILT__PWM_DT 5
#define TILT__PWM_PR 6

#define TILT__INVERSE 1
#define TILT__DIRECT 0

#define TILT__CAPTURE 2
#define TILT__COMPARE 0

#define TILT__TRIG_LEVEL 3
#define TILT__TRIG_RISING 0
#define TILT__TRIG_FALLING 1
#define TILT__TRIG_BOTH 2

#define TILT__INTR_MASK_TC 1
#define TILT__INTR_MASK_CC_MATCH 2
#define TILT__INTR_MASK_NONE 0
#define TILT__INTR_MASK_TC_CC 3

#define TILT__UNCONFIG 8
#define TILT__TIMER 1
#define TILT__QUAD 3
#define TILT__PWM_SEL 7

#define TILT__COUNT_UP 0
#define TILT__COUNT_DOWN 1
#define TILT__COUNT_UPDOWN0 2
#define TILT__COUNT_UPDOWN1 3


/* Prescaler */
#define TILT_PRESCALE_DIVBY1                ((uint32)(0u << TILT_PRESCALER_SHIFT))
#define TILT_PRESCALE_DIVBY2                ((uint32)(1u << TILT_PRESCALER_SHIFT))
#define TILT_PRESCALE_DIVBY4                ((uint32)(2u << TILT_PRESCALER_SHIFT))
#define TILT_PRESCALE_DIVBY8                ((uint32)(3u << TILT_PRESCALER_SHIFT))
#define TILT_PRESCALE_DIVBY16               ((uint32)(4u << TILT_PRESCALER_SHIFT))
#define TILT_PRESCALE_DIVBY32               ((uint32)(5u << TILT_PRESCALER_SHIFT))
#define TILT_PRESCALE_DIVBY64               ((uint32)(6u << TILT_PRESCALER_SHIFT))
#define TILT_PRESCALE_DIVBY128              ((uint32)(7u << TILT_PRESCALER_SHIFT))

/* TCPWM set modes */
#define TILT_MODE_TIMER_COMPARE             ((uint32)(TILT__COMPARE         <<  \
                                                                  TILT_MODE_SHIFT))
#define TILT_MODE_TIMER_CAPTURE             ((uint32)(TILT__CAPTURE         <<  \
                                                                  TILT_MODE_SHIFT))
#define TILT_MODE_QUAD                      ((uint32)(TILT__QUAD            <<  \
                                                                  TILT_MODE_SHIFT))
#define TILT_MODE_PWM                       ((uint32)(TILT__PWM             <<  \
                                                                  TILT_MODE_SHIFT))
#define TILT_MODE_PWM_DT                    ((uint32)(TILT__PWM_DT          <<  \
                                                                  TILT_MODE_SHIFT))
#define TILT_MODE_PWM_PR                    ((uint32)(TILT__PWM_PR          <<  \
                                                                  TILT_MODE_SHIFT))

/* Quad Modes */
#define TILT_MODE_X1                        ((uint32)(TILT__X1              <<  \
                                                                  TILT_QUAD_MODE_SHIFT))
#define TILT_MODE_X2                        ((uint32)(TILT__X2              <<  \
                                                                  TILT_QUAD_MODE_SHIFT))
#define TILT_MODE_X4                        ((uint32)(TILT__X4              <<  \
                                                                  TILT_QUAD_MODE_SHIFT))

/* Counter modes */
#define TILT_COUNT_UP                       ((uint32)(TILT__COUNT_UP        <<  \
                                                                  TILT_UPDOWN_SHIFT))
#define TILT_COUNT_DOWN                     ((uint32)(TILT__COUNT_DOWN      <<  \
                                                                  TILT_UPDOWN_SHIFT))
#define TILT_COUNT_UPDOWN0                  ((uint32)(TILT__COUNT_UPDOWN0   <<  \
                                                                  TILT_UPDOWN_SHIFT))
#define TILT_COUNT_UPDOWN1                  ((uint32)(TILT__COUNT_UPDOWN1   <<  \
                                                                  TILT_UPDOWN_SHIFT))

/* PWM output invert */
#define TILT_INVERT_LINE                    ((uint32)(TILT__INVERSE         <<  \
                                                                  TILT_INV_OUT_SHIFT))
#define TILT_INVERT_LINE_N                  ((uint32)(TILT__INVERSE         <<  \
                                                                  TILT_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define TILT_TRIG_RISING                    (TILT__TRIG_RISING)
#define TILT_TRIG_FALLING                   (TILT__TRIG_FALLING)
#define TILT_TRIG_BOTH                      (TILT__TRIG_BOTH)
#define TILT_TRIG_LEVEL                     (TILT__TRIG_LEVEL)

/* Interrupt mask */
#define TILT_INTR_MASK_TC                   (TILT__INTR_MASK_TC)
#define TILT_INTR_MASK_CC_MATCH             (TILT__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define TILT_CC_MATCH_SET                   (0x00u)
#define TILT_CC_MATCH_CLEAR                 (0x01u)
#define TILT_CC_MATCH_INVERT                (0x02u)
#define TILT_CC_MATCH_NO_CHANGE             (0x03u)
#define TILT_OVERLOW_SET                    (0x00u)
#define TILT_OVERLOW_CLEAR                  (0x04u)
#define TILT_OVERLOW_INVERT                 (0x08u)
#define TILT_OVERLOW_NO_CHANGE              (0x0Cu)
#define TILT_UNDERFLOW_SET                  (0x00u)
#define TILT_UNDERFLOW_CLEAR                (0x10u)
#define TILT_UNDERFLOW_INVERT               (0x20u)
#define TILT_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define TILT_PWM_MODE_LEFT                  (TILT_CC_MATCH_CLEAR        |   \
                                                         TILT_OVERLOW_SET           |   \
                                                         TILT_UNDERFLOW_NO_CHANGE)
#define TILT_PWM_MODE_RIGHT                 (TILT_CC_MATCH_SET          |   \
                                                         TILT_OVERLOW_NO_CHANGE     |   \
                                                         TILT_UNDERFLOW_CLEAR)
#define TILT_PWM_MODE_CENTER                (TILT_CC_MATCH_INVERT       |   \
                                                         TILT_OVERLOW_NO_CHANGE     |   \
                                                         TILT_UNDERFLOW_CLEAR)
#define TILT_PWM_MODE_ASYM                  (TILT_CC_MATCH_NO_CHANGE    |   \
                                                         TILT_OVERLOW_SET           |   \
                                                         TILT_UNDERFLOW_CLEAR )

/* Command operations without condition */
#define TILT_CMD_CAPTURE                    (0u)
#define TILT_CMD_RELOAD                     (8u)
#define TILT_CMD_STOP                       (16u)
#define TILT_CMD_START                      (24u)

/* Status */
#define TILT_STATUS_DOWN                    (1u)
#define TILT_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   TILT_Init(void);
void   TILT_Enable(void);
void   TILT_Start(void);
void   TILT_Stop(void);

void   TILT_SetMode(uint32 mode);
void   TILT_SetCounterMode(uint32 counterMode);
void   TILT_SetPWMMode(uint32 modeMask);
void   TILT_SetQDMode(uint32 qdMode);

void   TILT_SetPrescaler(uint32 prescaler);
void   TILT_TriggerCommand(uint32 mask, uint32 command);
void   TILT_SetOneShot(uint32 oneShotEnable);
uint32 TILT_ReadStatus(void);

void   TILT_SetPWMSyncKill(uint32 syncKillEnable);
void   TILT_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   TILT_SetPWMDeadTime(uint32 deadTime);
void   TILT_SetPWMInvert(uint32 mask);

void   TILT_SetInterruptMode(uint32 interruptMask);
uint32 TILT_GetInterruptSourceMasked(void);
uint32 TILT_GetInterruptSource(void);
void   TILT_ClearInterrupt(uint32 interruptMask);
void   TILT_SetInterrupt(uint32 interruptMask);

void   TILT_WriteCounter(uint32 count);
uint32 TILT_ReadCounter(void);

uint32 TILT_ReadCapture(void);
uint32 TILT_ReadCaptureBuf(void);

void   TILT_WritePeriod(uint32 period);
uint32 TILT_ReadPeriod(void);
void   TILT_WritePeriodBuf(uint32 periodBuf);
uint32 TILT_ReadPeriodBuf(void);

void   TILT_WriteCompare(uint32 compare);
uint32 TILT_ReadCompare(void);
void   TILT_WriteCompareBuf(uint32 compareBuf);
uint32 TILT_ReadCompareBuf(void);

void   TILT_SetPeriodSwap(uint32 swapEnable);
void   TILT_SetCompareSwap(uint32 swapEnable);

void   TILT_SetCaptureMode(uint32 triggerMode);
void   TILT_SetReloadMode(uint32 triggerMode);
void   TILT_SetStartMode(uint32 triggerMode);
void   TILT_SetStopMode(uint32 triggerMode);
void   TILT_SetCountMode(uint32 triggerMode);

void   TILT_SaveConfig(void);
void   TILT_RestoreConfig(void);
void   TILT_Sleep(void);
void   TILT_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define TILT_BLOCK_CONTROL_REG              (*(reg32 *) TILT_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TILT_BLOCK_CONTROL_PTR              ( (reg32 *) TILT_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TILT_COMMAND_REG                    (*(reg32 *) TILT_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TILT_COMMAND_PTR                    ( (reg32 *) TILT_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TILT_INTRRUPT_CAUSE_REG             (*(reg32 *) TILT_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TILT_INTRRUPT_CAUSE_PTR             ( (reg32 *) TILT_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TILT_CONTROL_REG                    (*(reg32 *) TILT_cy_m0s8_tcpwm_1__CTRL )
#define TILT_CONTROL_PTR                    ( (reg32 *) TILT_cy_m0s8_tcpwm_1__CTRL )
#define TILT_STATUS_REG                     (*(reg32 *) TILT_cy_m0s8_tcpwm_1__STATUS )
#define TILT_STATUS_PTR                     ( (reg32 *) TILT_cy_m0s8_tcpwm_1__STATUS )
#define TILT_COUNTER_REG                    (*(reg32 *) TILT_cy_m0s8_tcpwm_1__COUNTER )
#define TILT_COUNTER_PTR                    ( (reg32 *) TILT_cy_m0s8_tcpwm_1__COUNTER )
#define TILT_COMP_CAP_REG                   (*(reg32 *) TILT_cy_m0s8_tcpwm_1__CC )
#define TILT_COMP_CAP_PTR                   ( (reg32 *) TILT_cy_m0s8_tcpwm_1__CC )
#define TILT_COMP_CAP_BUF_REG               (*(reg32 *) TILT_cy_m0s8_tcpwm_1__CC_BUFF )
#define TILT_COMP_CAP_BUF_PTR               ( (reg32 *) TILT_cy_m0s8_tcpwm_1__CC_BUFF )
#define TILT_PERIOD_REG                     (*(reg32 *) TILT_cy_m0s8_tcpwm_1__PERIOD )
#define TILT_PERIOD_PTR                     ( (reg32 *) TILT_cy_m0s8_tcpwm_1__PERIOD )
#define TILT_PERIOD_BUF_REG                 (*(reg32 *) TILT_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TILT_PERIOD_BUF_PTR                 ( (reg32 *) TILT_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TILT_TRIG_CONTROL0_REG              (*(reg32 *) TILT_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TILT_TRIG_CONTROL0_PTR              ( (reg32 *) TILT_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TILT_TRIG_CONTROL1_REG              (*(reg32 *) TILT_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TILT_TRIG_CONTROL1_PTR              ( (reg32 *) TILT_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TILT_TRIG_CONTROL2_REG              (*(reg32 *) TILT_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TILT_TRIG_CONTROL2_PTR              ( (reg32 *) TILT_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TILT_INTERRUPT_REQ_REG              (*(reg32 *) TILT_cy_m0s8_tcpwm_1__INTR )
#define TILT_INTERRUPT_REQ_PTR              ( (reg32 *) TILT_cy_m0s8_tcpwm_1__INTR )
#define TILT_INTERRUPT_SET_REG              (*(reg32 *) TILT_cy_m0s8_tcpwm_1__INTR_SET )
#define TILT_INTERRUPT_SET_PTR              ( (reg32 *) TILT_cy_m0s8_tcpwm_1__INTR_SET )
#define TILT_INTERRUPT_MASK_REG             (*(reg32 *) TILT_cy_m0s8_tcpwm_1__INTR_MASK )
#define TILT_INTERRUPT_MASK_PTR             ( (reg32 *) TILT_cy_m0s8_tcpwm_1__INTR_MASK )
#define TILT_INTERRUPT_MASKED_REG           (*(reg32 *) TILT_cy_m0s8_tcpwm_1__INTR_MASKED )
#define TILT_INTERRUPT_MASKED_PTR           ( (reg32 *) TILT_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define TILT_MASK                           ((uint32)TILT_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define TILT_RELOAD_CC_SHIFT                (0u)
#define TILT_RELOAD_PERIOD_SHIFT            (1u)
#define TILT_PWM_SYNC_KILL_SHIFT            (2u)
#define TILT_PWM_STOP_KILL_SHIFT            (3u)
#define TILT_PRESCALER_SHIFT                (8u)
#define TILT_UPDOWN_SHIFT                   (16u)
#define TILT_ONESHOT_SHIFT                  (18u)
#define TILT_QUAD_MODE_SHIFT                (20u)
#define TILT_INV_OUT_SHIFT                  (20u)
#define TILT_INV_COMPL_OUT_SHIFT            (21u)
#define TILT_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define TILT_RELOAD_CC_MASK                 ((uint32)(TILT_1BIT_MASK        <<  \
                                                                            TILT_RELOAD_CC_SHIFT))
#define TILT_RELOAD_PERIOD_MASK             ((uint32)(TILT_1BIT_MASK        <<  \
                                                                            TILT_RELOAD_PERIOD_SHIFT))
#define TILT_PWM_SYNC_KILL_MASK             ((uint32)(TILT_1BIT_MASK        <<  \
                                                                            TILT_PWM_SYNC_KILL_SHIFT))
#define TILT_PWM_STOP_KILL_MASK             ((uint32)(TILT_1BIT_MASK        <<  \
                                                                            TILT_PWM_STOP_KILL_SHIFT))
#define TILT_PRESCALER_MASK                 ((uint32)(TILT_8BIT_MASK        <<  \
                                                                            TILT_PRESCALER_SHIFT))
#define TILT_UPDOWN_MASK                    ((uint32)(TILT_2BIT_MASK        <<  \
                                                                            TILT_UPDOWN_SHIFT))
#define TILT_ONESHOT_MASK                   ((uint32)(TILT_1BIT_MASK        <<  \
                                                                            TILT_ONESHOT_SHIFT))
#define TILT_QUAD_MODE_MASK                 ((uint32)(TILT_3BIT_MASK        <<  \
                                                                            TILT_QUAD_MODE_SHIFT))
#define TILT_INV_OUT_MASK                   ((uint32)(TILT_2BIT_MASK        <<  \
                                                                            TILT_INV_OUT_SHIFT))
#define TILT_MODE_MASK                      ((uint32)(TILT_3BIT_MASK        <<  \
                                                                            TILT_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define TILT_CAPTURE_SHIFT                  (0u)
#define TILT_COUNT_SHIFT                    (2u)
#define TILT_RELOAD_SHIFT                   (4u)
#define TILT_STOP_SHIFT                     (6u)
#define TILT_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define TILT_CAPTURE_MASK                   ((uint32)(TILT_2BIT_MASK        <<  \
                                                                  TILT_CAPTURE_SHIFT))
#define TILT_COUNT_MASK                     ((uint32)(TILT_2BIT_MASK        <<  \
                                                                  TILT_COUNT_SHIFT))
#define TILT_RELOAD_MASK                    ((uint32)(TILT_2BIT_MASK        <<  \
                                                                  TILT_RELOAD_SHIFT))
#define TILT_STOP_MASK                      ((uint32)(TILT_2BIT_MASK        <<  \
                                                                  TILT_STOP_SHIFT))
#define TILT_START_MASK                     ((uint32)(TILT_2BIT_MASK        <<  \
                                                                  TILT_START_SHIFT))

/* MASK */
#define TILT_1BIT_MASK                      ((uint32)0x01u)
#define TILT_2BIT_MASK                      ((uint32)0x03u)
#define TILT_3BIT_MASK                      ((uint32)0x07u)
#define TILT_6BIT_MASK                      ((uint32)0x3Fu)
#define TILT_8BIT_MASK                      ((uint32)0xFFu)
#define TILT_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define TILT_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define TILT_PWM_PR_INIT_VALUE              (1u)

#endif /* End CY_TCPWM_TILT_H */

/* [] END OF FILE */
