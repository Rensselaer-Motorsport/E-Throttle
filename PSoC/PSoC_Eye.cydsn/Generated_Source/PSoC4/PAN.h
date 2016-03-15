/*******************************************************************************
* File Name: PAN.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the PAN
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

#if !defined(CY_TCPWM_PAN_H)
#define CY_TCPWM_PAN_H

#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} PAN_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  PAN_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* TCPWM Configuration */
#define PAN_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define PAN_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define PAN_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define PAN_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define PAN_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define PAN_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define PAN_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define PAN_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define PAN_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define PAN_TC_RUN_MODE                    (0lu)
#define PAN_TC_COUNTER_MODE                (0lu)
#define PAN_TC_COMP_CAP_MODE               (2lu)
#define PAN_TC_PRESCALER                   (0lu)

/* Signal modes */
#define PAN_TC_RELOAD_SIGNAL_MODE          (0lu)
#define PAN_TC_COUNT_SIGNAL_MODE           (3lu)
#define PAN_TC_START_SIGNAL_MODE           (0lu)
#define PAN_TC_STOP_SIGNAL_MODE            (0lu)
#define PAN_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define PAN_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define PAN_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define PAN_TC_START_SIGNAL_PRESENT        (0lu)
#define PAN_TC_STOP_SIGNAL_PRESENT         (0lu)
#define PAN_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PAN_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define PAN_PWM_KILL_EVENT                 (0lu)
#define PAN_PWM_STOP_EVENT                 (0lu)
#define PAN_PWM_MODE                       (4lu)
#define PAN_PWM_OUT_N_INVERT               (0lu)
#define PAN_PWM_OUT_INVERT                 (0lu)
#define PAN_PWM_ALIGN                      (0lu)
#define PAN_PWM_RUN_MODE                   (0lu)
#define PAN_PWM_DEAD_TIME_CYCLE            (0lu)
#define PAN_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define PAN_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define PAN_PWM_COUNT_SIGNAL_MODE          (3lu)
#define PAN_PWM_START_SIGNAL_MODE          (0lu)
#define PAN_PWM_STOP_SIGNAL_MODE           (0lu)
#define PAN_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define PAN_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define PAN_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define PAN_PWM_START_SIGNAL_PRESENT       (0lu)
#define PAN_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define PAN_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PAN_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define PAN_TC_PERIOD_VALUE                (65535lu)
#define PAN_TC_COMPARE_VALUE               (65535lu)
#define PAN_TC_COMPARE_BUF_VALUE           (65535lu)
#define PAN_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define PAN_PWM_PERIOD_VALUE               (600lu)
#define PAN_PWM_PERIOD_BUF_VALUE           (65535lu)
#define PAN_PWM_PERIOD_SWAP                (0lu)
#define PAN_PWM_COMPARE_VALUE              (0lu)
#define PAN_PWM_COMPARE_BUF_VALUE          (65535lu)
#define PAN_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define PAN__LEFT 0
#define PAN__RIGHT 1
#define PAN__CENTER 2
#define PAN__ASYMMETRIC 3

#define PAN__X1 0
#define PAN__X2 1
#define PAN__X4 2

#define PAN__PWM 4
#define PAN__PWM_DT 5
#define PAN__PWM_PR 6

#define PAN__INVERSE 1
#define PAN__DIRECT 0

#define PAN__CAPTURE 2
#define PAN__COMPARE 0

#define PAN__TRIG_LEVEL 3
#define PAN__TRIG_RISING 0
#define PAN__TRIG_FALLING 1
#define PAN__TRIG_BOTH 2

#define PAN__INTR_MASK_TC 1
#define PAN__INTR_MASK_CC_MATCH 2
#define PAN__INTR_MASK_NONE 0
#define PAN__INTR_MASK_TC_CC 3

#define PAN__UNCONFIG 8
#define PAN__TIMER 1
#define PAN__QUAD 3
#define PAN__PWM_SEL 7

#define PAN__COUNT_UP 0
#define PAN__COUNT_DOWN 1
#define PAN__COUNT_UPDOWN0 2
#define PAN__COUNT_UPDOWN1 3


/* Prescaler */
#define PAN_PRESCALE_DIVBY1                ((uint32)(0u << PAN_PRESCALER_SHIFT))
#define PAN_PRESCALE_DIVBY2                ((uint32)(1u << PAN_PRESCALER_SHIFT))
#define PAN_PRESCALE_DIVBY4                ((uint32)(2u << PAN_PRESCALER_SHIFT))
#define PAN_PRESCALE_DIVBY8                ((uint32)(3u << PAN_PRESCALER_SHIFT))
#define PAN_PRESCALE_DIVBY16               ((uint32)(4u << PAN_PRESCALER_SHIFT))
#define PAN_PRESCALE_DIVBY32               ((uint32)(5u << PAN_PRESCALER_SHIFT))
#define PAN_PRESCALE_DIVBY64               ((uint32)(6u << PAN_PRESCALER_SHIFT))
#define PAN_PRESCALE_DIVBY128              ((uint32)(7u << PAN_PRESCALER_SHIFT))

/* TCPWM set modes */
#define PAN_MODE_TIMER_COMPARE             ((uint32)(PAN__COMPARE         <<  \
                                                                  PAN_MODE_SHIFT))
#define PAN_MODE_TIMER_CAPTURE             ((uint32)(PAN__CAPTURE         <<  \
                                                                  PAN_MODE_SHIFT))
#define PAN_MODE_QUAD                      ((uint32)(PAN__QUAD            <<  \
                                                                  PAN_MODE_SHIFT))
#define PAN_MODE_PWM                       ((uint32)(PAN__PWM             <<  \
                                                                  PAN_MODE_SHIFT))
#define PAN_MODE_PWM_DT                    ((uint32)(PAN__PWM_DT          <<  \
                                                                  PAN_MODE_SHIFT))
#define PAN_MODE_PWM_PR                    ((uint32)(PAN__PWM_PR          <<  \
                                                                  PAN_MODE_SHIFT))

/* Quad Modes */
#define PAN_MODE_X1                        ((uint32)(PAN__X1              <<  \
                                                                  PAN_QUAD_MODE_SHIFT))
#define PAN_MODE_X2                        ((uint32)(PAN__X2              <<  \
                                                                  PAN_QUAD_MODE_SHIFT))
#define PAN_MODE_X4                        ((uint32)(PAN__X4              <<  \
                                                                  PAN_QUAD_MODE_SHIFT))

/* Counter modes */
#define PAN_COUNT_UP                       ((uint32)(PAN__COUNT_UP        <<  \
                                                                  PAN_UPDOWN_SHIFT))
#define PAN_COUNT_DOWN                     ((uint32)(PAN__COUNT_DOWN      <<  \
                                                                  PAN_UPDOWN_SHIFT))
#define PAN_COUNT_UPDOWN0                  ((uint32)(PAN__COUNT_UPDOWN0   <<  \
                                                                  PAN_UPDOWN_SHIFT))
#define PAN_COUNT_UPDOWN1                  ((uint32)(PAN__COUNT_UPDOWN1   <<  \
                                                                  PAN_UPDOWN_SHIFT))

/* PWM output invert */
#define PAN_INVERT_LINE                    ((uint32)(PAN__INVERSE         <<  \
                                                                  PAN_INV_OUT_SHIFT))
#define PAN_INVERT_LINE_N                  ((uint32)(PAN__INVERSE         <<  \
                                                                  PAN_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define PAN_TRIG_RISING                    (PAN__TRIG_RISING)
#define PAN_TRIG_FALLING                   (PAN__TRIG_FALLING)
#define PAN_TRIG_BOTH                      (PAN__TRIG_BOTH)
#define PAN_TRIG_LEVEL                     (PAN__TRIG_LEVEL)

/* Interrupt mask */
#define PAN_INTR_MASK_TC                   (PAN__INTR_MASK_TC)
#define PAN_INTR_MASK_CC_MATCH             (PAN__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define PAN_CC_MATCH_SET                   (0x00u)
#define PAN_CC_MATCH_CLEAR                 (0x01u)
#define PAN_CC_MATCH_INVERT                (0x02u)
#define PAN_CC_MATCH_NO_CHANGE             (0x03u)
#define PAN_OVERLOW_SET                    (0x00u)
#define PAN_OVERLOW_CLEAR                  (0x04u)
#define PAN_OVERLOW_INVERT                 (0x08u)
#define PAN_OVERLOW_NO_CHANGE              (0x0Cu)
#define PAN_UNDERFLOW_SET                  (0x00u)
#define PAN_UNDERFLOW_CLEAR                (0x10u)
#define PAN_UNDERFLOW_INVERT               (0x20u)
#define PAN_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define PAN_PWM_MODE_LEFT                  (PAN_CC_MATCH_CLEAR        |   \
                                                         PAN_OVERLOW_SET           |   \
                                                         PAN_UNDERFLOW_NO_CHANGE)
#define PAN_PWM_MODE_RIGHT                 (PAN_CC_MATCH_SET          |   \
                                                         PAN_OVERLOW_NO_CHANGE     |   \
                                                         PAN_UNDERFLOW_CLEAR)
#define PAN_PWM_MODE_CENTER                (PAN_CC_MATCH_INVERT       |   \
                                                         PAN_OVERLOW_NO_CHANGE     |   \
                                                         PAN_UNDERFLOW_CLEAR)
#define PAN_PWM_MODE_ASYM                  (PAN_CC_MATCH_NO_CHANGE    |   \
                                                         PAN_OVERLOW_SET           |   \
                                                         PAN_UNDERFLOW_CLEAR )

/* Command operations without condition */
#define PAN_CMD_CAPTURE                    (0u)
#define PAN_CMD_RELOAD                     (8u)
#define PAN_CMD_STOP                       (16u)
#define PAN_CMD_START                      (24u)

/* Status */
#define PAN_STATUS_DOWN                    (1u)
#define PAN_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   PAN_Init(void);
void   PAN_Enable(void);
void   PAN_Start(void);
void   PAN_Stop(void);

void   PAN_SetMode(uint32 mode);
void   PAN_SetCounterMode(uint32 counterMode);
void   PAN_SetPWMMode(uint32 modeMask);
void   PAN_SetQDMode(uint32 qdMode);

void   PAN_SetPrescaler(uint32 prescaler);
void   PAN_TriggerCommand(uint32 mask, uint32 command);
void   PAN_SetOneShot(uint32 oneShotEnable);
uint32 PAN_ReadStatus(void);

void   PAN_SetPWMSyncKill(uint32 syncKillEnable);
void   PAN_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   PAN_SetPWMDeadTime(uint32 deadTime);
void   PAN_SetPWMInvert(uint32 mask);

void   PAN_SetInterruptMode(uint32 interruptMask);
uint32 PAN_GetInterruptSourceMasked(void);
uint32 PAN_GetInterruptSource(void);
void   PAN_ClearInterrupt(uint32 interruptMask);
void   PAN_SetInterrupt(uint32 interruptMask);

void   PAN_WriteCounter(uint32 count);
uint32 PAN_ReadCounter(void);

uint32 PAN_ReadCapture(void);
uint32 PAN_ReadCaptureBuf(void);

void   PAN_WritePeriod(uint32 period);
uint32 PAN_ReadPeriod(void);
void   PAN_WritePeriodBuf(uint32 periodBuf);
uint32 PAN_ReadPeriodBuf(void);

void   PAN_WriteCompare(uint32 compare);
uint32 PAN_ReadCompare(void);
void   PAN_WriteCompareBuf(uint32 compareBuf);
uint32 PAN_ReadCompareBuf(void);

void   PAN_SetPeriodSwap(uint32 swapEnable);
void   PAN_SetCompareSwap(uint32 swapEnable);

void   PAN_SetCaptureMode(uint32 triggerMode);
void   PAN_SetReloadMode(uint32 triggerMode);
void   PAN_SetStartMode(uint32 triggerMode);
void   PAN_SetStopMode(uint32 triggerMode);
void   PAN_SetCountMode(uint32 triggerMode);

void   PAN_SaveConfig(void);
void   PAN_RestoreConfig(void);
void   PAN_Sleep(void);
void   PAN_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define PAN_BLOCK_CONTROL_REG              (*(reg32 *) PAN_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PAN_BLOCK_CONTROL_PTR              ( (reg32 *) PAN_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PAN_COMMAND_REG                    (*(reg32 *) PAN_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PAN_COMMAND_PTR                    ( (reg32 *) PAN_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PAN_INTRRUPT_CAUSE_REG             (*(reg32 *) PAN_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PAN_INTRRUPT_CAUSE_PTR             ( (reg32 *) PAN_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PAN_CONTROL_REG                    (*(reg32 *) PAN_cy_m0s8_tcpwm_1__CTRL )
#define PAN_CONTROL_PTR                    ( (reg32 *) PAN_cy_m0s8_tcpwm_1__CTRL )
#define PAN_STATUS_REG                     (*(reg32 *) PAN_cy_m0s8_tcpwm_1__STATUS )
#define PAN_STATUS_PTR                     ( (reg32 *) PAN_cy_m0s8_tcpwm_1__STATUS )
#define PAN_COUNTER_REG                    (*(reg32 *) PAN_cy_m0s8_tcpwm_1__COUNTER )
#define PAN_COUNTER_PTR                    ( (reg32 *) PAN_cy_m0s8_tcpwm_1__COUNTER )
#define PAN_COMP_CAP_REG                   (*(reg32 *) PAN_cy_m0s8_tcpwm_1__CC )
#define PAN_COMP_CAP_PTR                   ( (reg32 *) PAN_cy_m0s8_tcpwm_1__CC )
#define PAN_COMP_CAP_BUF_REG               (*(reg32 *) PAN_cy_m0s8_tcpwm_1__CC_BUFF )
#define PAN_COMP_CAP_BUF_PTR               ( (reg32 *) PAN_cy_m0s8_tcpwm_1__CC_BUFF )
#define PAN_PERIOD_REG                     (*(reg32 *) PAN_cy_m0s8_tcpwm_1__PERIOD )
#define PAN_PERIOD_PTR                     ( (reg32 *) PAN_cy_m0s8_tcpwm_1__PERIOD )
#define PAN_PERIOD_BUF_REG                 (*(reg32 *) PAN_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PAN_PERIOD_BUF_PTR                 ( (reg32 *) PAN_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PAN_TRIG_CONTROL0_REG              (*(reg32 *) PAN_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PAN_TRIG_CONTROL0_PTR              ( (reg32 *) PAN_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PAN_TRIG_CONTROL1_REG              (*(reg32 *) PAN_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PAN_TRIG_CONTROL1_PTR              ( (reg32 *) PAN_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PAN_TRIG_CONTROL2_REG              (*(reg32 *) PAN_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PAN_TRIG_CONTROL2_PTR              ( (reg32 *) PAN_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PAN_INTERRUPT_REQ_REG              (*(reg32 *) PAN_cy_m0s8_tcpwm_1__INTR )
#define PAN_INTERRUPT_REQ_PTR              ( (reg32 *) PAN_cy_m0s8_tcpwm_1__INTR )
#define PAN_INTERRUPT_SET_REG              (*(reg32 *) PAN_cy_m0s8_tcpwm_1__INTR_SET )
#define PAN_INTERRUPT_SET_PTR              ( (reg32 *) PAN_cy_m0s8_tcpwm_1__INTR_SET )
#define PAN_INTERRUPT_MASK_REG             (*(reg32 *) PAN_cy_m0s8_tcpwm_1__INTR_MASK )
#define PAN_INTERRUPT_MASK_PTR             ( (reg32 *) PAN_cy_m0s8_tcpwm_1__INTR_MASK )
#define PAN_INTERRUPT_MASKED_REG           (*(reg32 *) PAN_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PAN_INTERRUPT_MASKED_PTR           ( (reg32 *) PAN_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define PAN_MASK                           ((uint32)PAN_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define PAN_RELOAD_CC_SHIFT                (0u)
#define PAN_RELOAD_PERIOD_SHIFT            (1u)
#define PAN_PWM_SYNC_KILL_SHIFT            (2u)
#define PAN_PWM_STOP_KILL_SHIFT            (3u)
#define PAN_PRESCALER_SHIFT                (8u)
#define PAN_UPDOWN_SHIFT                   (16u)
#define PAN_ONESHOT_SHIFT                  (18u)
#define PAN_QUAD_MODE_SHIFT                (20u)
#define PAN_INV_OUT_SHIFT                  (20u)
#define PAN_INV_COMPL_OUT_SHIFT            (21u)
#define PAN_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define PAN_RELOAD_CC_MASK                 ((uint32)(PAN_1BIT_MASK        <<  \
                                                                            PAN_RELOAD_CC_SHIFT))
#define PAN_RELOAD_PERIOD_MASK             ((uint32)(PAN_1BIT_MASK        <<  \
                                                                            PAN_RELOAD_PERIOD_SHIFT))
#define PAN_PWM_SYNC_KILL_MASK             ((uint32)(PAN_1BIT_MASK        <<  \
                                                                            PAN_PWM_SYNC_KILL_SHIFT))
#define PAN_PWM_STOP_KILL_MASK             ((uint32)(PAN_1BIT_MASK        <<  \
                                                                            PAN_PWM_STOP_KILL_SHIFT))
#define PAN_PRESCALER_MASK                 ((uint32)(PAN_8BIT_MASK        <<  \
                                                                            PAN_PRESCALER_SHIFT))
#define PAN_UPDOWN_MASK                    ((uint32)(PAN_2BIT_MASK        <<  \
                                                                            PAN_UPDOWN_SHIFT))
#define PAN_ONESHOT_MASK                   ((uint32)(PAN_1BIT_MASK        <<  \
                                                                            PAN_ONESHOT_SHIFT))
#define PAN_QUAD_MODE_MASK                 ((uint32)(PAN_3BIT_MASK        <<  \
                                                                            PAN_QUAD_MODE_SHIFT))
#define PAN_INV_OUT_MASK                   ((uint32)(PAN_2BIT_MASK        <<  \
                                                                            PAN_INV_OUT_SHIFT))
#define PAN_MODE_MASK                      ((uint32)(PAN_3BIT_MASK        <<  \
                                                                            PAN_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define PAN_CAPTURE_SHIFT                  (0u)
#define PAN_COUNT_SHIFT                    (2u)
#define PAN_RELOAD_SHIFT                   (4u)
#define PAN_STOP_SHIFT                     (6u)
#define PAN_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define PAN_CAPTURE_MASK                   ((uint32)(PAN_2BIT_MASK        <<  \
                                                                  PAN_CAPTURE_SHIFT))
#define PAN_COUNT_MASK                     ((uint32)(PAN_2BIT_MASK        <<  \
                                                                  PAN_COUNT_SHIFT))
#define PAN_RELOAD_MASK                    ((uint32)(PAN_2BIT_MASK        <<  \
                                                                  PAN_RELOAD_SHIFT))
#define PAN_STOP_MASK                      ((uint32)(PAN_2BIT_MASK        <<  \
                                                                  PAN_STOP_SHIFT))
#define PAN_START_MASK                     ((uint32)(PAN_2BIT_MASK        <<  \
                                                                  PAN_START_SHIFT))

/* MASK */
#define PAN_1BIT_MASK                      ((uint32)0x01u)
#define PAN_2BIT_MASK                      ((uint32)0x03u)
#define PAN_3BIT_MASK                      ((uint32)0x07u)
#define PAN_6BIT_MASK                      ((uint32)0x3Fu)
#define PAN_8BIT_MASK                      ((uint32)0xFFu)
#define PAN_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define PAN_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define PAN_PWM_PR_INIT_VALUE              (1u)

#endif /* End CY_TCPWM_PAN_H */

/* [] END OF FILE */
