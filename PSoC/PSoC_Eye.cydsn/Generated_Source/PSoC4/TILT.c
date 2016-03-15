/*******************************************************************************
* File Name: TILT.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the TILT
*  component
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
#include "cyLib.h"

uint8 TILT_initVar = 0u;


/*******************************************************************************
* Function Name: TILT_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default TILT configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TILT_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (TILT__QUAD == TILT_CONFIG)
        TILT_CONTROL_REG =
        (((uint32)(TILT_QUAD_ENCODING_MODES     << TILT_QUAD_MODE_SHIFT))       |
         ((uint32)(TILT_CONFIG                  << TILT_MODE_SHIFT)));
    #endif  /* (TILT__QUAD == TILT_CONFIG) */

    #if (TILT__PWM_SEL == TILT_CONFIG)
        TILT_CONTROL_REG =
        (((uint32)(TILT_PWM_STOP_EVENT          << TILT_PWM_STOP_KILL_SHIFT))    |
         ((uint32)(TILT_PWM_OUT_INVERT          << TILT_INV_OUT_SHIFT))         |
         ((uint32)(TILT_PWM_OUT_N_INVERT        << TILT_INV_COMPL_OUT_SHIFT))     |
         ((uint32)(TILT_PWM_MODE                << TILT_MODE_SHIFT)));

        #if (TILT__PWM_PR == TILT_PWM_MODE)
            TILT_CONTROL_REG |=
            ((uint32)(TILT_PWM_RUN_MODE         << TILT_ONESHOT_SHIFT));

            TILT_WriteCounter(TILT_PWM_PR_INIT_VALUE);
        #else
            TILT_CONTROL_REG |=
            (((uint32)(TILT_PWM_ALIGN           << TILT_UPDOWN_SHIFT))          |
             ((uint32)(TILT_PWM_KILL_EVENT      << TILT_PWM_SYNC_KILL_SHIFT)));
        #endif  /* (TILT__PWM_PR == TILT_PWM_MODE) */

        #if (TILT__PWM_DT == TILT_PWM_MODE)
            TILT_CONTROL_REG |=
            ((uint32)(TILT_PWM_DEAD_TIME_CYCLE  << TILT_PRESCALER_SHIFT));
        #endif  /* (TILT__PWM_DT == TILT_PWM_MODE) */

        #if (TILT__PWM == TILT_PWM_MODE)
            TILT_CONTROL_REG |=
            ((uint32)TILT_PWM_PRESCALER         << TILT_PRESCALER_SHIFT);
        #endif  /* (TILT__PWM == TILT_PWM_MODE) */
    #endif  /* (TILT__PWM_SEL == TILT_CONFIG) */

    #if (TILT__TIMER == TILT_CONFIG)
        TILT_CONTROL_REG =
        (((uint32)(TILT_TC_PRESCALER            << TILT_PRESCALER_SHIFT))   |
         ((uint32)(TILT_TC_COUNTER_MODE         << TILT_UPDOWN_SHIFT))      |
         ((uint32)(TILT_TC_RUN_MODE             << TILT_ONESHOT_SHIFT))     |
         ((uint32)(TILT_TC_COMP_CAP_MODE        << TILT_MODE_SHIFT)));
    #endif  /* (TILT__TIMER == TILT_CONFIG) */

    /* Set values from customizer to CTRL1 */
    #if (TILT__QUAD == TILT_CONFIG)
        TILT_TRIG_CONTROL1_REG  =
        (((uint32)(TILT_QUAD_PHIA_SIGNAL_MODE   << TILT_COUNT_SHIFT))       |
         ((uint32)(TILT_QUAD_INDEX_SIGNAL_MODE  << TILT_RELOAD_SHIFT))      |
         ((uint32)(TILT_QUAD_STOP_SIGNAL_MODE   << TILT_STOP_SHIFT))        |
         ((uint32)(TILT_QUAD_PHIB_SIGNAL_MODE   << TILT_START_SHIFT)));
    #endif  /* (TILT__QUAD == TILT_CONFIG) */

    #if (TILT__PWM_SEL == TILT_CONFIG)
        TILT_TRIG_CONTROL1_REG  =
        (((uint32)(TILT_PWM_SWITCH_SIGNAL_MODE  << TILT_CAPTURE_SHIFT))     |
         ((uint32)(TILT_PWM_COUNT_SIGNAL_MODE   << TILT_COUNT_SHIFT))       |
         ((uint32)(TILT_PWM_RELOAD_SIGNAL_MODE  << TILT_RELOAD_SHIFT))      |
         ((uint32)(TILT_PWM_STOP_SIGNAL_MODE    << TILT_STOP_SHIFT))        |
         ((uint32)(TILT_PWM_START_SIGNAL_MODE   << TILT_START_SHIFT)));
    #endif  /* (TILT__PWM_SEL == TILT_CONFIG) */

    #if (TILT__TIMER == TILT_CONFIG)
        TILT_TRIG_CONTROL1_REG  =
        (((uint32)(TILT_TC_CAPTURE_SIGNAL_MODE  << TILT_CAPTURE_SHIFT))     |
         ((uint32)(TILT_TC_COUNT_SIGNAL_MODE    << TILT_COUNT_SHIFT))       |
         ((uint32)(TILT_TC_RELOAD_SIGNAL_MODE   << TILT_RELOAD_SHIFT))      |
         ((uint32)(TILT_TC_STOP_SIGNAL_MODE     << TILT_STOP_SHIFT))        |
         ((uint32)(TILT_TC_START_SIGNAL_MODE    << TILT_START_SHIFT)));
    #endif  /* (TILT__TIMER == TILT_CONFIG) */

    /* Set values from customizer to INTR */
    #if (TILT__QUAD == TILT_CONFIG)
        TILT_SetInterruptMode(TILT_QUAD_INTERRUPT_MASK);
    #endif  /* (TILT__QUAD == TILT_CONFIG) */

    #if (TILT__PWM_SEL == TILT_CONFIG)
        TILT_SetInterruptMode(TILT_PWM_INTERRUPT_MASK);
    #endif  /* (TILT__PWM_SEL == TILT_CONFIG) */

    #if (TILT__TIMER == TILT_CONFIG)
        TILT_SetInterruptMode(TILT_TC_INTERRUPT_MASK);
    #endif  /* (TILT__TIMER == TILT_CONFIG) */

    /* Set other values from customizer */
    #if (TILT__TIMER == TILT_CONFIG)
        TILT_WritePeriod(TILT_TC_PERIOD_VALUE );
        #if (TILT__COMPARE == TILT_TC_COMP_CAP_MODE)
            TILT_WriteCompare(TILT_TC_COMPARE_VALUE);

            #if (1u == TILT_TC_COMPARE_SWAP)
                TILT_SetCompareSwap(1u);
                TILT_WriteCompareBuf(TILT_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == TILT_TC_COMPARE_SWAP) */
        #endif  /* (TILT__COMPARE == TILT_TC_COMP_CAP_MODE) */
    #endif  /* (TILT__TIMER == TILT_CONFIG) */

    #if (TILT__PWM_SEL == TILT_CONFIG)
        TILT_WritePeriod(TILT_PWM_PERIOD_VALUE );
        TILT_WriteCompare(TILT_PWM_COMPARE_VALUE);

        #if (1u == TILT_PWM_COMPARE_SWAP)
            TILT_SetCompareSwap(1u);
            TILT_WriteCompareBuf(TILT_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == TILT_PWM_COMPARE_SWAP) */

        #if (1u == TILT_PWM_PERIOD_SWAP)
            TILT_SetPeriodSwap(1u);
            TILT_WritePeriodBuf(TILT_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == TILT_PWM_PERIOD_SWAP) */

        /* Set values from customizer to CTRL2 */
        #if (TILT__PWM_PR == TILT_PWM_MODE)
            TILT_TRIG_CONTROL2_REG =
                    (TILT_CC_MATCH_NO_CHANGE    |
                    TILT_OVERLOW_NO_CHANGE      |
                    TILT_UNDERFLOW_NO_CHANGE);
        #else
            #if (TILT__LEFT == TILT_PWM_ALIGN)
                TILT_TRIG_CONTROL2_REG = TILT_PWM_MODE_LEFT;
            #endif  /* ( TILT_PWM_LEFT == TILT_PWM_ALIGN) */

            #if (TILT__RIGHT == TILT_PWM_ALIGN)
                TILT_TRIG_CONTROL2_REG = TILT_PWM_MODE_RIGHT;
            #endif  /* ( TILT_PWM_RIGHT == TILT_PWM_ALIGN) */

            #if (TILT__CENTER == TILT_PWM_ALIGN)
                TILT_TRIG_CONTROL2_REG = TILT_PWM_MODE_CENTER;
            #endif  /* ( TILT_PWM_CENTER == TILT_PWM_ALIGN) */

            #if (TILT__ASYMMETRIC == TILT_PWM_ALIGN)
                TILT_TRIG_CONTROL2_REG = TILT_PWM_MODE_ASYM;
            #endif  /* (TILT__ASYMMETRIC == TILT_PWM_ALIGN) */
        #endif  /* (TILT__PWM_PR == TILT_PWM_MODE) */
    #endif  /* (TILT__PWM_SEL == TILT_CONFIG) */
}


/*******************************************************************************
* Function Name: TILT_Enable
********************************************************************************
*
* Summary:
*  Enables the TILT.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TILT_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    TILT_BLOCK_CONTROL_REG |= TILT_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Statr Timer or PWM if start input is absent */
    #if (TILT__PWM_SEL == TILT_CONFIG)
        #if (0u == TILT_PWM_START_SIGNAL_PRESENT)
            TILT_TriggerCommand(TILT_MASK, TILT_CMD_START);
        #endif /* (0u == TILT_PWM_START_SIGNAL_PRESENT) */
    #endif /* (TILT__PWM_SEL == TILT_CONFIG) */

    #if (TILT__TIMER == TILT_CONFIG)
        #if (0u == TILT_TC_START_SIGNAL_PRESENT)
            TILT_TriggerCommand(TILT_MASK, TILT_CMD_START);
        #endif /* (0u == TILT_TC_START_SIGNAL_PRESENT) */
    #endif /* (TILT__TIMER == TILT_CONFIG) */
}


/*******************************************************************************
* Function Name: TILT_Start
********************************************************************************
*
* Summary:
*  Initialize the TILT with default customizer
*  values when called the first time and enables the TILT.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TILT_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time TILT_Start() is called. This allows
*  enable/disable component without re-initialization in all subsequent calls
*  to the TILT_Start() routine.
*
*******************************************************************************/
void TILT_Start(void)
{
    if (0u == TILT_initVar)
    {
        TILT_Init();
        TILT_initVar = 1u;
    }

    TILT_Enable();
}


/*******************************************************************************
* Function Name: TILT_Stop
********************************************************************************
*
* Summary:
*  Disables the TILT.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TILT_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_BLOCK_CONTROL_REG &= (uint32)~TILT_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the TILT. This function is used when
*  configured as a generic TILT and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the TILT to operate in
*   Values:
*   - TILT_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - TILT_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - TILT_MODE_QUAD - Quadrature decoder
*         - TILT_MODE_PWM - PWM
*         - TILT_MODE_PWM_DT - PWM with dead time
*         - TILT_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_MODE_MASK;
    TILT_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of 3 supported modes.
*  Is functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - TILT_MODE_X1 - Counts on phi 1 rising
*         - TILT_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - TILT_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_QUAD_MODE_MASK;
    TILT_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to PWM with dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - TILT_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - TILT_PRESCALE_DIVBY2    - Divide by 2
*         - TILT_PRESCALE_DIVBY4    - Divide by 4
*         - TILT_PRESCALE_DIVBY8    - Divide by 8
*         - TILT_PRESCALE_DIVBY16   - Divide by 16
*         - TILT_PRESCALE_DIVBY32   - Divide by 32
*         - TILT_PRESCALE_DIVBY64   - Divide by 64
*         - TILT_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_PRESCALER_MASK;
    TILT_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the TILT runs
*  continuously or stops when terminal count is reached.  By default the
*  TILT operates in continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_ONESHOT_MASK;
    TILT_CONTROL_REG |= ((uint32)((oneShotEnable & TILT_1BIT_MASK) <<
                                                               TILT_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the 3 must be ORed together to form the
*  mode.
*
* Parameters:
*  modeMask: Combination of the 3 mode settings.  Mask must include a value for
*  each of the 3 or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be 
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetPWMMode(uint32 modeMask)
{
    TILT_TRIG_CONTROL2_REG = (modeMask & TILT_6BIT_MASK);
}



/*******************************************************************************
* Function Name: TILT_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes an asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to PWM and
*  PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_PWM_SYNC_KILL_MASK;
    TILT_CONTROL_REG |= ((uint32)((syncKillEnable & TILT_1BIT_MASK)  <<
                                               TILT_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_PWM_STOP_KILL_MASK;
    TILT_CONTROL_REG |= ((uint32)((stopOnKillEnable & TILT_1BIT_MASK)  <<
                                                         TILT_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_PRESCALER_MASK;
    TILT_CONTROL_REG |= ((uint32)((deadTime & TILT_8BIT_MASK) <<
                                                          TILT_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - TILT_INVERT_LINE   - Inverts the line output
*         - TILT_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_INV_OUT_MASK;
    TILT_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: TILT_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void TILT_WriteCounter(uint32 count)
{
    TILT_COUNTER_REG = (count & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 TILT_ReadCounter(void)
{
    return (TILT_COUNTER_REG & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and PWM with pseudo random output.
*
* Parameters:
*  counterMode: Enumerated couner type values
*   Values:
*     - TILT_COUNT_UP       - Counts up
*     - TILT_COUNT_DOWN     - Counts down
*     - TILT_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - TILT_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_UPDOWN_MASK;
    TILT_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void TILT_WritePeriod(uint32 period)
{
    TILT_PERIOD_REG = (period & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 TILT_ReadPeriod(void)
{
    return (TILT_PERIOD_REG & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in Timer/Counter mode(without capture) the swap occurs
*  at a TC event. In PWM mode the swap occurs at the next TC event following
*  a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_RELOAD_CC_MASK;
    TILT_CONTROL_REG |= (swapEnable & TILT_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void TILT_WritePeriodBuf(uint32 periodBuf)
{
    TILT_PERIOD_BUF_REG = (periodBuf & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 TILT_ReadPeriodBuf(void)
{
    return (TILT_PERIOD_BUF_REG & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In PWM mode the swap occurs at the next TC event following a hardware switch
*  event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_CONTROL_REG &= (uint32)~TILT_RELOAD_PERIOD_MASK;
    TILT_CONTROL_REG |= ((uint32)((swapEnable & TILT_1BIT_MASK) <<
                                                            TILT_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void TILT_WriteCompare(uint32 compare)
{
    TILT_COMP_CAP_REG = (compare & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 TILT_ReadCompare(void)
{
    return (TILT_COMP_CAP_REG & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void TILT_WriteCompareBuf(uint32 compareBuf)
{
   TILT_COMP_CAP_BUF_REG = (compareBuf & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 TILT_ReadCompareBuf(void)
{
    return (TILT_COMP_CAP_BUF_REG & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 TILT_ReadCapture(void)
{
    return (TILT_COMP_CAP_REG & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 TILT_ReadCaptureBuf(void)
{
    return (TILT_COMP_CAP_BUF_REG & TILT_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TILT_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TILT_TRIG_LEVEL     - Level
*     - TILT_TRIG_RISING    - Rising edge
*     - TILT_TRIG_FALLING   - Falling edge
*     - TILT_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_TRIG_CONTROL1_REG &= (uint32)~TILT_CAPTURE_MASK;
    TILT_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TILT_TRIG_LEVEL     - Level
*     - TILT_TRIG_RISING    - Rising edge
*     - TILT_TRIG_FALLING   - Falling edge
*     - TILT_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_TRIG_CONTROL1_REG &= (uint32)~TILT_RELOAD_MASK;
    TILT_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TILT_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TILT_TRIG_LEVEL     - Level
*     - TILT_TRIG_RISING    - Rising edge
*     - TILT_TRIG_FALLING   - Falling edge
*     - TILT_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_TRIG_CONTROL1_REG &= (uint32)~TILT_START_MASK;
    TILT_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TILT_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TILT_TRIG_LEVEL     - Level
*     - TILT_TRIG_RISING    - Rising edge
*     - TILT_TRIG_FALLING   - Falling edge
*     - TILT_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_TRIG_CONTROL1_REG &= (uint32)~TILT_STOP_MASK;
    TILT_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TILT_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TILT_TRIG_LEVEL     - Level
*     - TILT_TRIG_RISING    - Rising edge
*     - TILT_TRIG_FALLING   - Falling edge
*     - TILT_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_TRIG_CONTROL1_REG &= (uint32)~TILT_COUNT_MASK;
    TILT_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TILT_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: Combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - TILT_CMD_CAPTURE    - Trigger Capture command
*     - TILT_CMD_RELOAD     - Trigger Reload command
*     - TILT_CMD_STOP       - Trigger Stop command
*     - TILT_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void TILT_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TILT_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TILT_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the TILT.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - TILT_STATUS_DOWN    - Set if counting down
*     - TILT_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 TILT_ReadStatus(void)
{
    return ((TILT_STATUS_REG >> TILT_RUNNING_STATUS_SHIFT) |
            (TILT_STATUS_REG & TILT_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: TILT_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - TILT_INTR_MASK_TC       - Terminal count mask
*     - TILT_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetInterruptMode(uint32 interruptMask)
{
    TILT_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: TILT_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - TILT_INTR_MASK_TC       - Terminal count mask
*     - TILT_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TILT_GetInterruptSourceMasked(void)
{
    return (TILT_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: TILT_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - TILT_INTR_MASK_TC       - Terminal count mask
*     - TILT_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TILT_GetInterruptSource(void)
{
    return (TILT_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: TILT_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - TILT_INTR_MASK_TC       - Terminal count mask
*     - TILT_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TILT_ClearInterrupt(uint32 interruptMask)
{
    TILT_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: TILT_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - TILT_INTR_MASK_TC       - Terminal count mask
*     - TILT_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TILT_SetInterrupt(uint32 interruptMask)
{
    TILT_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
