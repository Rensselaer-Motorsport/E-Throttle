/*******************************************************************************
* File Name: PAN.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the PAN
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

#include "PAN.h"
#include "cyLib.h"

uint8 PAN_initVar = 0u;


/*******************************************************************************
* Function Name: PAN_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default PAN configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PAN_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (PAN__QUAD == PAN_CONFIG)
        PAN_CONTROL_REG =
        (((uint32)(PAN_QUAD_ENCODING_MODES     << PAN_QUAD_MODE_SHIFT))       |
         ((uint32)(PAN_CONFIG                  << PAN_MODE_SHIFT)));
    #endif  /* (PAN__QUAD == PAN_CONFIG) */

    #if (PAN__PWM_SEL == PAN_CONFIG)
        PAN_CONTROL_REG =
        (((uint32)(PAN_PWM_STOP_EVENT          << PAN_PWM_STOP_KILL_SHIFT))    |
         ((uint32)(PAN_PWM_OUT_INVERT          << PAN_INV_OUT_SHIFT))         |
         ((uint32)(PAN_PWM_OUT_N_INVERT        << PAN_INV_COMPL_OUT_SHIFT))     |
         ((uint32)(PAN_PWM_MODE                << PAN_MODE_SHIFT)));

        #if (PAN__PWM_PR == PAN_PWM_MODE)
            PAN_CONTROL_REG |=
            ((uint32)(PAN_PWM_RUN_MODE         << PAN_ONESHOT_SHIFT));

            PAN_WriteCounter(PAN_PWM_PR_INIT_VALUE);
        #else
            PAN_CONTROL_REG |=
            (((uint32)(PAN_PWM_ALIGN           << PAN_UPDOWN_SHIFT))          |
             ((uint32)(PAN_PWM_KILL_EVENT      << PAN_PWM_SYNC_KILL_SHIFT)));
        #endif  /* (PAN__PWM_PR == PAN_PWM_MODE) */

        #if (PAN__PWM_DT == PAN_PWM_MODE)
            PAN_CONTROL_REG |=
            ((uint32)(PAN_PWM_DEAD_TIME_CYCLE  << PAN_PRESCALER_SHIFT));
        #endif  /* (PAN__PWM_DT == PAN_PWM_MODE) */

        #if (PAN__PWM == PAN_PWM_MODE)
            PAN_CONTROL_REG |=
            ((uint32)PAN_PWM_PRESCALER         << PAN_PRESCALER_SHIFT);
        #endif  /* (PAN__PWM == PAN_PWM_MODE) */
    #endif  /* (PAN__PWM_SEL == PAN_CONFIG) */

    #if (PAN__TIMER == PAN_CONFIG)
        PAN_CONTROL_REG =
        (((uint32)(PAN_TC_PRESCALER            << PAN_PRESCALER_SHIFT))   |
         ((uint32)(PAN_TC_COUNTER_MODE         << PAN_UPDOWN_SHIFT))      |
         ((uint32)(PAN_TC_RUN_MODE             << PAN_ONESHOT_SHIFT))     |
         ((uint32)(PAN_TC_COMP_CAP_MODE        << PAN_MODE_SHIFT)));
    #endif  /* (PAN__TIMER == PAN_CONFIG) */

    /* Set values from customizer to CTRL1 */
    #if (PAN__QUAD == PAN_CONFIG)
        PAN_TRIG_CONTROL1_REG  =
        (((uint32)(PAN_QUAD_PHIA_SIGNAL_MODE   << PAN_COUNT_SHIFT))       |
         ((uint32)(PAN_QUAD_INDEX_SIGNAL_MODE  << PAN_RELOAD_SHIFT))      |
         ((uint32)(PAN_QUAD_STOP_SIGNAL_MODE   << PAN_STOP_SHIFT))        |
         ((uint32)(PAN_QUAD_PHIB_SIGNAL_MODE   << PAN_START_SHIFT)));
    #endif  /* (PAN__QUAD == PAN_CONFIG) */

    #if (PAN__PWM_SEL == PAN_CONFIG)
        PAN_TRIG_CONTROL1_REG  =
        (((uint32)(PAN_PWM_SWITCH_SIGNAL_MODE  << PAN_CAPTURE_SHIFT))     |
         ((uint32)(PAN_PWM_COUNT_SIGNAL_MODE   << PAN_COUNT_SHIFT))       |
         ((uint32)(PAN_PWM_RELOAD_SIGNAL_MODE  << PAN_RELOAD_SHIFT))      |
         ((uint32)(PAN_PWM_STOP_SIGNAL_MODE    << PAN_STOP_SHIFT))        |
         ((uint32)(PAN_PWM_START_SIGNAL_MODE   << PAN_START_SHIFT)));
    #endif  /* (PAN__PWM_SEL == PAN_CONFIG) */

    #if (PAN__TIMER == PAN_CONFIG)
        PAN_TRIG_CONTROL1_REG  =
        (((uint32)(PAN_TC_CAPTURE_SIGNAL_MODE  << PAN_CAPTURE_SHIFT))     |
         ((uint32)(PAN_TC_COUNT_SIGNAL_MODE    << PAN_COUNT_SHIFT))       |
         ((uint32)(PAN_TC_RELOAD_SIGNAL_MODE   << PAN_RELOAD_SHIFT))      |
         ((uint32)(PAN_TC_STOP_SIGNAL_MODE     << PAN_STOP_SHIFT))        |
         ((uint32)(PAN_TC_START_SIGNAL_MODE    << PAN_START_SHIFT)));
    #endif  /* (PAN__TIMER == PAN_CONFIG) */

    /* Set values from customizer to INTR */
    #if (PAN__QUAD == PAN_CONFIG)
        PAN_SetInterruptMode(PAN_QUAD_INTERRUPT_MASK);
    #endif  /* (PAN__QUAD == PAN_CONFIG) */

    #if (PAN__PWM_SEL == PAN_CONFIG)
        PAN_SetInterruptMode(PAN_PWM_INTERRUPT_MASK);
    #endif  /* (PAN__PWM_SEL == PAN_CONFIG) */

    #if (PAN__TIMER == PAN_CONFIG)
        PAN_SetInterruptMode(PAN_TC_INTERRUPT_MASK);
    #endif  /* (PAN__TIMER == PAN_CONFIG) */

    /* Set other values from customizer */
    #if (PAN__TIMER == PAN_CONFIG)
        PAN_WritePeriod(PAN_TC_PERIOD_VALUE );
        #if (PAN__COMPARE == PAN_TC_COMP_CAP_MODE)
            PAN_WriteCompare(PAN_TC_COMPARE_VALUE);

            #if (1u == PAN_TC_COMPARE_SWAP)
                PAN_SetCompareSwap(1u);
                PAN_WriteCompareBuf(PAN_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == PAN_TC_COMPARE_SWAP) */
        #endif  /* (PAN__COMPARE == PAN_TC_COMP_CAP_MODE) */
    #endif  /* (PAN__TIMER == PAN_CONFIG) */

    #if (PAN__PWM_SEL == PAN_CONFIG)
        PAN_WritePeriod(PAN_PWM_PERIOD_VALUE );
        PAN_WriteCompare(PAN_PWM_COMPARE_VALUE);

        #if (1u == PAN_PWM_COMPARE_SWAP)
            PAN_SetCompareSwap(1u);
            PAN_WriteCompareBuf(PAN_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == PAN_PWM_COMPARE_SWAP) */

        #if (1u == PAN_PWM_PERIOD_SWAP)
            PAN_SetPeriodSwap(1u);
            PAN_WritePeriodBuf(PAN_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == PAN_PWM_PERIOD_SWAP) */

        /* Set values from customizer to CTRL2 */
        #if (PAN__PWM_PR == PAN_PWM_MODE)
            PAN_TRIG_CONTROL2_REG =
                    (PAN_CC_MATCH_NO_CHANGE    |
                    PAN_OVERLOW_NO_CHANGE      |
                    PAN_UNDERFLOW_NO_CHANGE);
        #else
            #if (PAN__LEFT == PAN_PWM_ALIGN)
                PAN_TRIG_CONTROL2_REG = PAN_PWM_MODE_LEFT;
            #endif  /* ( PAN_PWM_LEFT == PAN_PWM_ALIGN) */

            #if (PAN__RIGHT == PAN_PWM_ALIGN)
                PAN_TRIG_CONTROL2_REG = PAN_PWM_MODE_RIGHT;
            #endif  /* ( PAN_PWM_RIGHT == PAN_PWM_ALIGN) */

            #if (PAN__CENTER == PAN_PWM_ALIGN)
                PAN_TRIG_CONTROL2_REG = PAN_PWM_MODE_CENTER;
            #endif  /* ( PAN_PWM_CENTER == PAN_PWM_ALIGN) */

            #if (PAN__ASYMMETRIC == PAN_PWM_ALIGN)
                PAN_TRIG_CONTROL2_REG = PAN_PWM_MODE_ASYM;
            #endif  /* (PAN__ASYMMETRIC == PAN_PWM_ALIGN) */
        #endif  /* (PAN__PWM_PR == PAN_PWM_MODE) */
    #endif  /* (PAN__PWM_SEL == PAN_CONFIG) */
}


/*******************************************************************************
* Function Name: PAN_Enable
********************************************************************************
*
* Summary:
*  Enables the PAN.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PAN_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    PAN_BLOCK_CONTROL_REG |= PAN_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Statr Timer or PWM if start input is absent */
    #if (PAN__PWM_SEL == PAN_CONFIG)
        #if (0u == PAN_PWM_START_SIGNAL_PRESENT)
            PAN_TriggerCommand(PAN_MASK, PAN_CMD_START);
        #endif /* (0u == PAN_PWM_START_SIGNAL_PRESENT) */
    #endif /* (PAN__PWM_SEL == PAN_CONFIG) */

    #if (PAN__TIMER == PAN_CONFIG)
        #if (0u == PAN_TC_START_SIGNAL_PRESENT)
            PAN_TriggerCommand(PAN_MASK, PAN_CMD_START);
        #endif /* (0u == PAN_TC_START_SIGNAL_PRESENT) */
    #endif /* (PAN__TIMER == PAN_CONFIG) */
}


/*******************************************************************************
* Function Name: PAN_Start
********************************************************************************
*
* Summary:
*  Initialize the PAN with default customizer
*  values when called the first time and enables the PAN.
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
*  PAN_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time PAN_Start() is called. This allows
*  enable/disable component without re-initialization in all subsequent calls
*  to the PAN_Start() routine.
*
*******************************************************************************/
void PAN_Start(void)
{
    if (0u == PAN_initVar)
    {
        PAN_Init();
        PAN_initVar = 1u;
    }

    PAN_Enable();
}


/*******************************************************************************
* Function Name: PAN_Stop
********************************************************************************
*
* Summary:
*  Disables the PAN.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PAN_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_BLOCK_CONTROL_REG &= (uint32)~PAN_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the PAN. This function is used when
*  configured as a generic PAN and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the PAN to operate in
*   Values:
*   - PAN_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - PAN_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - PAN_MODE_QUAD - Quadrature decoder
*         - PAN_MODE_PWM - PWM
*         - PAN_MODE_PWM_DT - PWM with dead time
*         - PAN_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_MODE_MASK;
    PAN_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of 3 supported modes.
*  Is functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - PAN_MODE_X1 - Counts on phi 1 rising
*         - PAN_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - PAN_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_QUAD_MODE_MASK;
    PAN_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to PWM with dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - PAN_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - PAN_PRESCALE_DIVBY2    - Divide by 2
*         - PAN_PRESCALE_DIVBY4    - Divide by 4
*         - PAN_PRESCALE_DIVBY8    - Divide by 8
*         - PAN_PRESCALE_DIVBY16   - Divide by 16
*         - PAN_PRESCALE_DIVBY32   - Divide by 32
*         - PAN_PRESCALE_DIVBY64   - Divide by 64
*         - PAN_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_PRESCALER_MASK;
    PAN_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PAN runs
*  continuously or stops when terminal count is reached.  By default the
*  PAN operates in continuous mode.
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
void PAN_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_ONESHOT_MASK;
    PAN_CONTROL_REG |= ((uint32)((oneShotEnable & PAN_1BIT_MASK) <<
                                                               PAN_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetPWMMode
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
void PAN_SetPWMMode(uint32 modeMask)
{
    PAN_TRIG_CONTROL2_REG = (modeMask & PAN_6BIT_MASK);
}



/*******************************************************************************
* Function Name: PAN_SetPWMSyncKill
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
void PAN_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_PWM_SYNC_KILL_MASK;
    PAN_CONTROL_REG |= ((uint32)((syncKillEnable & PAN_1BIT_MASK)  <<
                                               PAN_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetPWMStopOnKill
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
void PAN_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_PWM_STOP_KILL_MASK;
    PAN_CONTROL_REG |= ((uint32)((stopOnKillEnable & PAN_1BIT_MASK)  <<
                                                         PAN_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetPWMDeadTime
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
void PAN_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_PRESCALER_MASK;
    PAN_CONTROL_REG |= ((uint32)((deadTime & PAN_8BIT_MASK) <<
                                                          PAN_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetPWMInvert
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
*         - PAN_INVERT_LINE   - Inverts the line output
*         - PAN_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_INV_OUT_MASK;
    PAN_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PAN_WriteCounter
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
void PAN_WriteCounter(uint32 count)
{
    PAN_COUNTER_REG = (count & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_ReadCounter
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
uint32 PAN_ReadCounter(void)
{
    return (PAN_COUNTER_REG & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and PWM with pseudo random output.
*
* Parameters:
*  counterMode: Enumerated couner type values
*   Values:
*     - PAN_COUNT_UP       - Counts up
*     - PAN_COUNT_DOWN     - Counts down
*     - PAN_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - PAN_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_UPDOWN_MASK;
    PAN_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_WritePeriod
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
void PAN_WritePeriod(uint32 period)
{
    PAN_PERIOD_REG = (period & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_ReadPeriod
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
uint32 PAN_ReadPeriod(void)
{
    return (PAN_PERIOD_REG & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_SetCompareSwap
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
void PAN_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_RELOAD_CC_MASK;
    PAN_CONTROL_REG |= (swapEnable & PAN_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_WritePeriodBuf
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
void PAN_WritePeriodBuf(uint32 periodBuf)
{
    PAN_PERIOD_BUF_REG = (periodBuf & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_ReadPeriodBuf
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
uint32 PAN_ReadPeriodBuf(void)
{
    return (PAN_PERIOD_BUF_REG & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_SetPeriodSwap
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
void PAN_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_CONTROL_REG &= (uint32)~PAN_RELOAD_PERIOD_MASK;
    PAN_CONTROL_REG |= ((uint32)((swapEnable & PAN_1BIT_MASK) <<
                                                            PAN_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_WriteCompare
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
void PAN_WriteCompare(uint32 compare)
{
    PAN_COMP_CAP_REG = (compare & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_ReadCompare
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
uint32 PAN_ReadCompare(void)
{
    return (PAN_COMP_CAP_REG & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_WriteCompareBuf
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
void PAN_WriteCompareBuf(uint32 compareBuf)
{
   PAN_COMP_CAP_BUF_REG = (compareBuf & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_ReadCompareBuf
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
uint32 PAN_ReadCompareBuf(void)
{
    return (PAN_COMP_CAP_BUF_REG & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_ReadCapture
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
uint32 PAN_ReadCapture(void)
{
    return (PAN_COMP_CAP_REG & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_ReadCaptureBuf
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
uint32 PAN_ReadCaptureBuf(void)
{
    return (PAN_COMP_CAP_BUF_REG & PAN_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PAN_SetCaptureMode
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
*     - PAN_TRIG_LEVEL     - Level
*     - PAN_TRIG_RISING    - Rising edge
*     - PAN_TRIG_FALLING   - Falling edge
*     - PAN_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_TRIG_CONTROL1_REG &= (uint32)~PAN_CAPTURE_MASK;
    PAN_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PAN_TRIG_LEVEL     - Level
*     - PAN_TRIG_RISING    - Rising edge
*     - PAN_TRIG_FALLING   - Falling edge
*     - PAN_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_TRIG_CONTROL1_REG &= (uint32)~PAN_RELOAD_MASK;
    PAN_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PAN_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PAN_TRIG_LEVEL     - Level
*     - PAN_TRIG_RISING    - Rising edge
*     - PAN_TRIG_FALLING   - Falling edge
*     - PAN_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_TRIG_CONTROL1_REG &= (uint32)~PAN_START_MASK;
    PAN_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PAN_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PAN_TRIG_LEVEL     - Level
*     - PAN_TRIG_RISING    - Rising edge
*     - PAN_TRIG_FALLING   - Falling edge
*     - PAN_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_TRIG_CONTROL1_REG &= (uint32)~PAN_STOP_MASK;
    PAN_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PAN_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PAN_TRIG_LEVEL     - Level
*     - PAN_TRIG_RISING    - Rising edge
*     - PAN_TRIG_FALLING   - Falling edge
*     - PAN_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_TRIG_CONTROL1_REG &= (uint32)~PAN_COUNT_MASK;
    PAN_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PAN_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_TriggerCommand
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
*     - PAN_CMD_CAPTURE    - Trigger Capture command
*     - PAN_CMD_RELOAD     - Trigger Reload command
*     - PAN_CMD_STOP       - Trigger Stop command
*     - PAN_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void PAN_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PAN_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PAN_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the PAN.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - PAN_STATUS_DOWN    - Set if counting down
*     - PAN_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 PAN_ReadStatus(void)
{
    return ((PAN_STATUS_REG >> PAN_RUNNING_STATUS_SHIFT) |
            (PAN_STATUS_REG & PAN_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: PAN_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - PAN_INTR_MASK_TC       - Terminal count mask
*     - PAN_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetInterruptMode(uint32 interruptMask)
{
    PAN_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: PAN_GetInterruptSourceMasked
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
*     - PAN_INTR_MASK_TC       - Terminal count mask
*     - PAN_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PAN_GetInterruptSourceMasked(void)
{
    return (PAN_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: PAN_GetInterruptSource
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
*     - PAN_INTR_MASK_TC       - Terminal count mask
*     - PAN_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PAN_GetInterruptSource(void)
{
    return (PAN_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: PAN_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - PAN_INTR_MASK_TC       - Terminal count mask
*     - PAN_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PAN_ClearInterrupt(uint32 interruptMask)
{
    PAN_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: PAN_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - PAN_INTR_MASK_TC       - Terminal count mask
*     - PAN_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PAN_SetInterrupt(uint32 interruptMask)
{
    PAN_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
