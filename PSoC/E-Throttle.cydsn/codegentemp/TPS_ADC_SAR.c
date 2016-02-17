/*******************************************************************************
* File Name: TPS_ADC_SAR.c
* Version 3.0
*
* Description:
*  This file provides the source code to the API for the Successive
*  approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "TPS_ADC_SAR.h"

#if(TPS_ADC_SAR_DEFAULT_INTERNAL_CLK)
    #include "TPS_ADC_SAR_theACLK.h"
#endif /* End TPS_ADC_SAR_DEFAULT_INTERNAL_CLK */


/***************************************
* Forward function references
***************************************/
static void TPS_ADC_SAR_CalcGain(uint8 resolution);


/***************************************
* Global data allocation
***************************************/
uint8 TPS_ADC_SAR_initVar = 0u;
volatile int16 TPS_ADC_SAR_offset;
volatile int16 TPS_ADC_SAR_countsPerVolt;     /* Obsolete Gain compensation */
volatile int32 TPS_ADC_SAR_countsPer10Volt;   /* Gain compensation */
volatile int16 TPS_ADC_SAR_shift;


/*******************************************************************************
* Function Name: TPS_ADC_SAR_Start
********************************************************************************
*
* Summary:
*  This is the preferred method to begin component operation.
*  TPS_ADC_SAR_Start() sets the initVar variable, calls the
*  TPS_ADC_SAR_Init() function, and then calls the
*  TPS_ADC_SAR_Enable() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  The TPS_ADC_SAR_initVar variable is used to indicate when/if initial
*  configuration of this component has happened. The variable is initialized to
*  zero and set to 1 the first time ADC_Start() is called. This allows for
*  component Re-Start without re-initialization in all subsequent calls to the
*  TPS_ADC_SAR_Start() routine.
*  If re-initialization of the component is required the variable should be set
*  to zero before call of TPS_ADC_SAR_Start() routine, or the user may call
*  TPS_ADC_SAR_Init() and TPS_ADC_SAR_Enable() as done in the
*  TPS_ADC_SAR_Start() routine.
*
* Side Effect:
*  If the initVar variable is already set, this function only calls the
*  TPS_ADC_SAR_Enable() function.
*
*******************************************************************************/
void TPS_ADC_SAR_Start(void)
{

    /* If not Initialized then initialize all required hardware and software */
    if(TPS_ADC_SAR_initVar == 0u)
    {
        TPS_ADC_SAR_Init();
        TPS_ADC_SAR_initVar = 1u;
    }
    TPS_ADC_SAR_Enable();
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  TPS_ADC_SAR_Start().
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  The TPS_ADC_SAR_offset variable is initialized to 0.
*
*******************************************************************************/
void TPS_ADC_SAR_Init(void)
{

    /* This is only valid if there is an internal clock */
    #if(TPS_ADC_SAR_DEFAULT_INTERNAL_CLK)
        TPS_ADC_SAR_theACLK_SetMode(CYCLK_DUTY);
    #endif /* End TPS_ADC_SAR_DEFAULT_INTERNAL_CLK */

    #if(TPS_ADC_SAR_IRQ_REMOVE == 0u)
        /* Start and set interrupt vector */
        CyIntSetPriority(TPS_ADC_SAR_INTC_NUMBER, TPS_ADC_SAR_INTC_PRIOR_NUMBER);
        (void)CyIntSetVector(TPS_ADC_SAR_INTC_NUMBER, &TPS_ADC_SAR_ISR);
    #endif   /* End TPS_ADC_SAR_IRQ_REMOVE */

    /* Enable IRQ mode*/
    TPS_ADC_SAR_SAR_CSR1_REG |= TPS_ADC_SAR_SAR_IRQ_MASK_EN | TPS_ADC_SAR_SAR_IRQ_MODE_EDGE;

    /*Set SAR ADC resolution ADC */
    TPS_ADC_SAR_SetResolution(TPS_ADC_SAR_DEFAULT_RESOLUTION);
    TPS_ADC_SAR_offset = 0;
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_Enable
********************************************************************************
*
* Summary:
*  Enables the reference, clock and power for SAR ADC.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void TPS_ADC_SAR_Enable(void)
{
    uint8 tmpReg;
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Enable the SAR ADC block in Active Power Mode */
    TPS_ADC_SAR_PWRMGR_SAR_REG |= TPS_ADC_SAR_ACT_PWR_SAR_EN;

     /* Enable the SAR ADC in Standby Power Mode*/
    TPS_ADC_SAR_STBY_PWRMGR_SAR_REG |= TPS_ADC_SAR_STBY_PWR_SAR_EN;

    /* This is only valid if there is an internal clock */
    #if(TPS_ADC_SAR_DEFAULT_INTERNAL_CLK)
        TPS_ADC_SAR_PWRMGR_CLK_REG |= TPS_ADC_SAR_ACT_PWR_CLK_EN;
        TPS_ADC_SAR_STBY_PWRMGR_CLK_REG |= TPS_ADC_SAR_STBY_PWR_CLK_EN;
    #endif /* End TPS_ADC_SAR_DEFAULT_INTERNAL_CLK */

    /* Enable VCM buffer and Enable Int Ref Amp */
    tmpReg = TPS_ADC_SAR_SAR_CSR3_REG;
    tmpReg |= TPS_ADC_SAR_SAR_EN_BUF_VCM_EN;
    /* PD_BUF_VREF is OFF in External reference or Vdda reference mode */
    #if((TPS_ADC_SAR_DEFAULT_REFERENCE == TPS_ADC_SAR__EXT_REF) || \
        (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VNEG_VDDA_DIFF))
        tmpReg &= (uint8)~TPS_ADC_SAR_SAR_EN_BUF_VREF_EN;
    #else /* In INTREF or INTREF Bypassed this buffer is ON */
        tmpReg |= TPS_ADC_SAR_SAR_EN_BUF_VREF_EN;
    #endif /* TPS_ADC_SAR_DEFAULT_REFERENCE == TPS_ADC_SAR__EXT_REF */
    TPS_ADC_SAR_SAR_CSR3_REG = tmpReg;

    /* Set reference for ADC */
    #if(TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VNEG_VDDA_DIFF)
        #if(TPS_ADC_SAR_DEFAULT_REFERENCE == TPS_ADC_SAR__EXT_REF)
            TPS_ADC_SAR_SAR_CSR6_REG = TPS_ADC_SAR_INT_BYPASS_EXT_VREF; /* S2 */
        #else /* Internal Vdda reference or obsolete bypass mode */
            TPS_ADC_SAR_SAR_CSR6_REG = TPS_ADC_SAR_VDDA_VREF;           /* S7 */
        #endif /* TPS_ADC_SAR_DEFAULT_REFERENCE == TPS_ADC_SAR__EXT_REF */
    #else  /* Reference goes through internal buffer */
        #if(TPS_ADC_SAR_DEFAULT_REFERENCE == TPS_ADC_SAR__INT_REF_NOT_BYPASSED)
            TPS_ADC_SAR_SAR_CSR6_REG = TPS_ADC_SAR_INT_VREF;            /* S3 + S4 */
        #else /* INTREF Bypassed of External */
            TPS_ADC_SAR_SAR_CSR6_REG = TPS_ADC_SAR_INT_BYPASS_EXT_VREF; /* S2 */
        #endif /* TPS_ADC_SAR_DEFAULT_REFERENCE == TPS_ADC_SAR__INT_REF_NOT_BYPASSED */
    #endif /* VNEG_VDDA_DIFF */

    /* Low non-overlap delay for sampling clock signals (for 1MSPS) */
    #if(TPS_ADC_SAR_HIGH_POWER_PULSE == 0u) /* MinPulseWidth <= 50 ns */
        TPS_ADC_SAR_SAR_CSR5_REG &= (uint8)~TPS_ADC_SAR_SAR_DLY_INC;
    #else /* Set High non-overlap delay for sampling clock signals (for <500KSPS)*/
        TPS_ADC_SAR_SAR_CSR5_REG |= TPS_ADC_SAR_SAR_DLY_INC;
    #endif /* TPS_ADC_SAR_HIGH_POWER_PULSE == 0u */

    /* Increase comparator latch enable delay by 20%, 
    *  Increase comparator bias current by 30% without impacting delaysDelay 
    *  Default for 1MSPS) 
    */
    #if(TPS_ADC_SAR_HIGH_POWER_PULSE == 0u)    /* MinPulseWidth <= 50 ns */
        TPS_ADC_SAR_SAR_CSR5_REG |= TPS_ADC_SAR_SAR_SEL_CSEL_DFT_CHAR;
    #else /* for <500ksps */
        TPS_ADC_SAR_SAR_CSR5_REG &= (uint8)~TPS_ADC_SAR_SAR_SEL_CSEL_DFT_CHAR;
    #endif /* TPS_ADC_SAR_HIGH_POWER_PULSE == 0u */

    /* Set default power and other configurations for control register 0 in multiple lines */
    TPS_ADC_SAR_SAR_CSR0_REG = (uint8)((uint8)TPS_ADC_SAR_DEFAULT_POWER << TPS_ADC_SAR_SAR_POWER_SHIFT)
    /* SAR_HIZ_CLEAR:   Should not be used for LP */
    #if ((CY_PSOC5LP) || (TPS_ADC_SAR_DEFAULT_REFERENCE != TPS_ADC_SAR__EXT_REF))
        | TPS_ADC_SAR_SAR_HIZ_CLEAR
    #endif /* SAR_HIZ_CLEAR */
    /*Set Convertion mode */
    #if(TPS_ADC_SAR_DEFAULT_CONV_MODE != TPS_ADC_SAR__FREE_RUNNING)      /* If triggered mode */
        | TPS_ADC_SAR_SAR_MX_SOF_UDB           /* source: UDB */
        | TPS_ADC_SAR_SAR_SOF_MODE_EDGE        /* Set edge-sensitive sof source */
    #endif /* TPS_ADC_SAR_DEFAULT_CONV_MODE */
    ; /* end of multiple line initialization */

    TPS_ADC_SAR_SAR_TR0_REG = TPS_ADC_SAR_SAR_CAP_TRIM_2;

    /* Enable clock for SAR ADC*/
    TPS_ADC_SAR_SAR_CLK_REG |= TPS_ADC_SAR_SAR_MX_CLK_EN;

    CyDelayUs(10u); /* The block is ready to use 10 us after the enable signal is set high. */

    #if(TPS_ADC_SAR_IRQ_REMOVE == 0u)
        /* Clear a pending interrupt */
        CyIntClearPending(TPS_ADC_SAR_INTC_NUMBER);
    #endif   /* End TPS_ADC_SAR_IRQ_REMOVE */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_Stop
********************************************************************************
*
* Summary:
*  Stops ADC conversions and puts the ADC into its lowest power mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void TPS_ADC_SAR_Stop(void)
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Stop all conversions */
    TPS_ADC_SAR_SAR_CSR0_REG &= (uint8)~TPS_ADC_SAR_SAR_SOF_START_CONV;
    /* Disable the SAR ADC block in Active Power Mode */
    TPS_ADC_SAR_PWRMGR_SAR_REG &= (uint8)~TPS_ADC_SAR_ACT_PWR_SAR_EN;
    /* Disable the SAR ADC in Standby Power Mode */
    TPS_ADC_SAR_STBY_PWRMGR_SAR_REG &= (uint8)~TPS_ADC_SAR_STBY_PWR_SAR_EN;

    /* This is only valid if there is an internal clock */
    #if(TPS_ADC_SAR_DEFAULT_INTERNAL_CLK)
        TPS_ADC_SAR_PWRMGR_CLK_REG &= (uint8)~TPS_ADC_SAR_ACT_PWR_CLK_EN;
        TPS_ADC_SAR_STBY_PWRMGR_CLK_REG &= (uint8)~TPS_ADC_SAR_STBY_PWR_CLK_EN;
    #endif /* End TPS_ADC_SAR_DEFAULT_INTERNAL_CLK */

    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_SetPower
********************************************************************************
*
* Summary:
*  Sets the operational power of the ADC. You should use the higher power
*  settings with faster clock speeds.
*
* Parameters:
*  power:  Power setting for ADC
*  0 ->    Normal
*  1 ->    Medium power
*  2 ->    1.25 power
*  3 ->    Minimum power.
*
* Return:
*  None.
*
*******************************************************************************/
void TPS_ADC_SAR_SetPower(uint8 power)
{
    uint8 tmpReg;

    /* mask off invalid power settings */
    power &= TPS_ADC_SAR_SAR_API_POWER_MASK;

    /* Set Power parameter  */
    tmpReg = TPS_ADC_SAR_SAR_CSR0_REG & (uint8)~TPS_ADC_SAR_SAR_POWER_MASK;
    tmpReg |= (uint8)(power << TPS_ADC_SAR_SAR_POWER_SHIFT);
    TPS_ADC_SAR_SAR_CSR0_REG = tmpReg;
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_SetResolution
********************************************************************************
*
* Summary:
*  Sets the Relution of the SAR.
*
* Parameters:
*  resolution:
*  12 ->    RES12
*  10 ->    RES10
*  8  ->    RES8
*
* Return:
*  None.
*
* Side Effects:
*  The ADC resolution cannot be changed during a conversion cycle. The
*  recommended best practice is to stop conversions with
*  ADC_StopConvert(), change the resolution, then restart the
*  conversions with ADC_StartConvert().
*  If you decide not to stop conversions before calling this API, you
*  should use ADC_IsEndConversion() to wait until conversion is complete
*  before changing the resolution.
*  If you call ADC_SetResolution() during a conversion, the resolution will
*  not be changed until the current conversion is complete. Data will not be
*  available in the new resolution for another 6 + "New Resolution(in bits)"
*  clock cycles.
*  You may need add a delay of this number of clock cycles after
*  ADC_SetResolution() is called before data is valid again.
*  Affects ADC_CountsTo_Volts(), ADC_CountsTo_mVolts(), and
*  ADC_CountsTo_uVolts() by calculating the correct conversion between ADC
*  counts and the applied input voltage. Calculation depends on resolution,
*  input range, and voltage reference.
*
*******************************************************************************/
void TPS_ADC_SAR_SetResolution(uint8 resolution)
{
    uint8 tmpReg;

    /* Set SAR ADC resolution and sample width: 18 conversion cycles at 12bits + 1 gap */
    switch (resolution)
    {
        case (uint8)TPS_ADC_SAR__BITS_12:
            tmpReg = TPS_ADC_SAR_SAR_RESOLUTION_12BIT | TPS_ADC_SAR_SAR_SAMPLE_WIDTH;
            break;
        case (uint8)TPS_ADC_SAR__BITS_10:
            tmpReg = TPS_ADC_SAR_SAR_RESOLUTION_10BIT | TPS_ADC_SAR_SAR_SAMPLE_WIDTH;
            break;
        case (uint8)TPS_ADC_SAR__BITS_8:
            tmpReg = TPS_ADC_SAR_SAR_RESOLUTION_8BIT | TPS_ADC_SAR_SAR_SAMPLE_WIDTH;
            break;
        default:
            tmpReg = TPS_ADC_SAR_SAR_RESOLUTION_12BIT | TPS_ADC_SAR_SAR_SAMPLE_WIDTH;
            /* Halt CPU in debug mode if resolution is out of valid range */
            CYASSERT(0u != 0u);
            break;
    }
    TPS_ADC_SAR_SAR_CSR2_REG = tmpReg;

     /* Calculate gain for convert counts to volts */
    TPS_ADC_SAR_CalcGain(resolution);
}


#if(TPS_ADC_SAR_DEFAULT_CONV_MODE != TPS_ADC_SAR__HARDWARE_TRIGGER)


    /*******************************************************************************
    * Function Name: TPS_ADC_SAR_StartConvert
    ********************************************************************************
    *
    * Summary:
    *  Forces the ADC to initiate a conversion. In free-running mode, the ADC runs
    *  continuously. In software trigger mode, the function also acts as a software
    *  version of the SOC and every conversion must be triggered by
    *  TPS_ADC_SAR_StartConvert(). This function is not available when the
    *  Hardware Trigger sample mode is selected.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Forces the ADC to initiate a conversion. In Free Running mode, the ADC will
    *  run continuously. In a software trigger mode the function also acts as a
    *  software version of the SOC. Here every conversion has to be triggered by
    *  the routine. This writes into the SOC bit in SAR_CTRL reg.
    *
    * Side Effects:
    *  In a software trigger mode the function switches source for SOF from the
    *  external pin to the internal SOF generation. Application should not call
    *  StartConvert if external source used for SOF.
    *
    *******************************************************************************/
    void TPS_ADC_SAR_StartConvert(void)
    {
        #if(TPS_ADC_SAR_DEFAULT_CONV_MODE != TPS_ADC_SAR__FREE_RUNNING)  /* If software triggered mode */
            TPS_ADC_SAR_SAR_CSR0_REG &= (uint8)~TPS_ADC_SAR_SAR_MX_SOF_UDB;   /* source: SOF bit */
        #endif /* End TPS_ADC_SAR_DEFAULT_CONV_MODE */

        /* Start the conversion */
        TPS_ADC_SAR_SAR_CSR0_REG |= TPS_ADC_SAR_SAR_SOF_START_CONV;
    }


    /*******************************************************************************
    * Function Name: TPS_ADC_SAR_StopConvert
    ********************************************************************************
    *
    * Summary:
    *  Forces the ADC to stop conversions. If a conversion is currently executing,
    *  that conversion will complete, but no further conversions will occur. This
    *  function is not available when the Hardware Trigger sample mode is selected.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Stops ADC conversion in Free Running mode.
    *
    * Side Effects:
    *  In Software Trigger sample mode, this function sets a software version of the
    *  SOC to low level and switches the SOC source to hardware SOC input.
    *
    *******************************************************************************/
    void TPS_ADC_SAR_StopConvert(void)
    {
        /* Stop all conversions */
        TPS_ADC_SAR_SAR_CSR0_REG &= (uint8)~TPS_ADC_SAR_SAR_SOF_START_CONV;

        #if(TPS_ADC_SAR_DEFAULT_CONV_MODE != TPS_ADC_SAR__FREE_RUNNING)  /* If software triggered mode */
            /* Return source to UDB for hardware SOF signal */
            TPS_ADC_SAR_SAR_CSR0_REG |= TPS_ADC_SAR_SAR_MX_SOF_UDB;    /* source: UDB */
        #endif /* End TPS_ADC_SAR_DEFAULT_CONV_MODE */

    }

#endif /* End TPS_ADC_SAR_DEFAULT_CONV_MODE != TPS_ADC_SAR__HARDWARE_TRIGGER */


/*******************************************************************************
* Function Name: TPS_ADC_SAR_IsEndConversion
********************************************************************************
*
* Summary:
*  Immediately returns the status of the conversion or does not return
*  (blocking) until the conversion completes, depending on the retMode
*  parameter.
*
* Parameters:
*  retMode:  Check conversion return mode.
*   TPS_ADC_SAR_RETURN_STATUS: Immediately returns the status. If the
*     value returned is zero, the conversion is not complete, and this function
*     should be retried until a nonzero result is returned.
*   TPS_ADC_SAR_WAIT_FOR_RESULT: Does not return a result until the ADC
*     conversion is complete.
*
* Return:
*  (uint8)  0 =>  The ADC is still calculating the last result.
*           1 =>  The last conversion is complete.
*
* Side Effects:
*  This function reads the end of conversion status, which is cleared on read.
*
*******************************************************************************/
uint8 TPS_ADC_SAR_IsEndConversion(uint8 retMode)
{
    uint8 status;

    do
    {
        status = TPS_ADC_SAR_SAR_CSR1_REG & TPS_ADC_SAR_SAR_EOF_1;
    } while ((status != TPS_ADC_SAR_SAR_EOF_1) && (retMode == TPS_ADC_SAR_WAIT_FOR_RESULT));
    /* If convertion complete, wait until EOF bit released */
    if(status == TPS_ADC_SAR_SAR_EOF_1)
    {
        /* wait one ADC clock to let the EOC status bit release */
        CyDelayUs(1u);
        /* Do the unconditional read operation of the CSR1 register to make sure the EOC bit has been cleared */
        CY_GET_REG8(TPS_ADC_SAR_SAR_CSR1_PTR);
    }

    return(status);
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_GetResult8
********************************************************************************
*
* Summary:
*  Returns the result of an 8-bit conversion. If the resolution is set greater
*  than 8 bits, the function returns the LSB of the result.
*  TPS_ADC_SAR_IsEndConversion() should be called to verify that the data
*   sample is ready.
*
* Parameters:
*  None.
*
* Return:
*  The LSB of the last ADC conversion.
*
* Global Variables:
*  TPS_ADC_SAR_shift - used to convert the ADC counts to the 2s
*  compliment form.
*
* Side Effects:
*  Converts the ADC counts to the 2s complement form.
*
*******************************************************************************/
int8 TPS_ADC_SAR_GetResult8( void )
{
    return( (int8)TPS_ADC_SAR_SAR_WRK0_REG - (int8)TPS_ADC_SAR_shift);
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_GetResult16
********************************************************************************
*
* Summary:
*  Returns a 16-bit result for a conversion with a result that has a resolution
*  of 8 to 12 bits.
*  TPS_ADC_SAR_IsEndConversion() should be called to verify that the data
*   sample is ready
*
* Parameters:
*  None.
*
* Return:
*  The 16-bit result of the last ADC conversion
*
* Global Variables:
*  TPS_ADC_SAR_shift - used to convert the ADC counts to the 2s
*  compliment form.
*
* Side Effects:
*  Converts the ADC counts to the 2s complement form.
*
*******************************************************************************/
int16 TPS_ADC_SAR_GetResult16( void )
{
    uint16 res;

    res = CY_GET_REG16(TPS_ADC_SAR_SAR_WRK_PTR);

    return( (int16)res - TPS_ADC_SAR_shift );
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_SetOffset
********************************************************************************
*
* Summary:
*  Sets the ADC offset, which is used by TPS_ADC_SAR_CountsTo_Volts(),
*  TPS_ADC_SAR_CountsTo_mVolts(), and TPS_ADC_SAR_CountsTo_uVolts()
*  to subtract the offset from the given reading before calculating the voltage
*  conversion.
*
* Parameters:
*  int16: This value is measured when the inputs are shorted or connected to
   the same input voltage.
*
* Return:
*  None.
*
* Global Variables:
*  The TPS_ADC_SAR_offset variable modified. This variable is used for
*  offset calibration purpose.
*  Affects the TPS_ADC_SAR_CountsTo_Volts,
*  TPS_ADC_SAR_CountsTo_mVolts, TPS_ADC_SAR_CountsTo_uVolts functions
*  by subtracting the given offset.
*
*******************************************************************************/
void TPS_ADC_SAR_SetOffset(int16 offset)
{
    TPS_ADC_SAR_offset = offset;
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_CalcGain
********************************************************************************
*
* Summary:
*  This function calculates the ADC gain in counts per 10 volt.
*
* Parameters:
*  uint8: resolution
*
* Return:
*  None.
*
* Global Variables:
*  TPS_ADC_SAR_shift variable initialized. This variable is used to
*  convert the ADC counts to the 2s compliment form.
*  TPS_ADC_SAR_countsPer10Volt variable initialized. This variable is used
*  for gain calibration purpose.
*
*******************************************************************************/
static void TPS_ADC_SAR_CalcGain( uint8 resolution )
{
    int32 counts;
    #if(!((TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSS_TO_VREF) || \
         (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDDA) || \
         (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDAC)) )
        uint16 diff_zero;
    #endif /* End TPS_ADC_SAR_DEFAULT_RANGE */

    switch (resolution)
    {
        case (uint8)TPS_ADC_SAR__BITS_12:
            counts = (int32)TPS_ADC_SAR_SAR_WRK_MAX_12BIT;
            #if(!((TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSS_TO_VREF) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDDA) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDAC)) )
                diff_zero = TPS_ADC_SAR_SAR_DIFF_SHIFT;
            #endif /* End TPS_ADC_SAR_DEFAULT_RANGE */
            break;
        case (uint8)TPS_ADC_SAR__BITS_10:
            counts = (int32)TPS_ADC_SAR_SAR_WRK_MAX_10BIT;
            #if(!((TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSS_TO_VREF) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDDA) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDAC)) )
                diff_zero = TPS_ADC_SAR_SAR_DIFF_SHIFT >> 2u;
            #endif /* End TPS_ADC_SAR_DEFAULT_RANGE */
            break;
        case (uint8)TPS_ADC_SAR__BITS_8:
            counts = (int32)TPS_ADC_SAR_SAR_WRK_MAX_8BIT;
            #if(!((TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSS_TO_VREF) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDDA) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDAC)) )
                diff_zero = TPS_ADC_SAR_SAR_DIFF_SHIFT >> 4u;
            #endif /* End TPS_ADC_SAR_DEFAULT_RANGE */
            break;
        default: /* Halt CPU in debug mode if resolution is out of valid range */
            counts = 0;
            #if(!((TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSS_TO_VREF) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDDA) || \
                 (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDAC)) )
                diff_zero = 0u;
            #endif /* End TPS_ADC_SAR_DEFAULT_RANGE */
            CYASSERT(0u != 0u);
            break;
    }
    TPS_ADC_SAR_countsPerVolt = 0; /* Clear obsolete variable */
    /* Calculate gain in counts per 10 volts with rounding */
    TPS_ADC_SAR_countsPer10Volt = (((counts * TPS_ADC_SAR_10MV_COUNTS) +
                        TPS_ADC_SAR_DEFAULT_REF_VOLTAGE_MV) / (TPS_ADC_SAR_DEFAULT_REF_VOLTAGE_MV * 2));

    #if( (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSS_TO_VREF) || \
         (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDDA) || \
         (TPS_ADC_SAR_DEFAULT_RANGE == TPS_ADC_SAR__VSSA_TO_VDAC) )
        TPS_ADC_SAR_shift = 0;
    #else
        TPS_ADC_SAR_shift = diff_zero;
    #endif /* End TPS_ADC_SAR_DEFAULT_RANGE */
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_SetGain
********************************************************************************
*
* Summary:
*  Sets the ADC gain in counts per volt for the voltage conversion functions
*  that follow. This value is set by default by the reference and input range
*  settings. It should only be used to further calibrate the ADC with a known
*  input or if the ADC is using an external reference.
*
* Parameters:
*  int16 adcGain counts per volt
*
* Return:
*  None.
*
* Global Variables:
*  TPS_ADC_SAR_countsPer10Volt variable modified. This variable is used
*  for gain calibration purpose.
*
*******************************************************************************/
void TPS_ADC_SAR_SetGain(int16 adcGain)
{
    TPS_ADC_SAR_countsPer10Volt = (int32)adcGain * 10;
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_SetScaledGain
********************************************************************************
*
* Summary:
*  Sets the ADC gain in counts per 10 volt for the voltage conversion functions
*  that follow. This value is set by default by the reference and input range
*  settings. It should only be used to further calibrate the ADC with a known
*  input or if the ADC is using an external reference.
*
* Parameters:
*  int32 adcGain  counts per 10 volt
*
* Return:
*  None.
*
* Global Variables:
*  TPS_ADC_SAR_countsPer10Volt variable modified. This variable is used
*  for gain calibration purpose.
*
*******************************************************************************/
void TPS_ADC_SAR_SetScaledGain(int32 adcGain)
{
    TPS_ADC_SAR_countsPer10Volt = adcGain;
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_CountsTo_mVolts
********************************************************************************
*
* Summary:
*  Converts the ADC output to millivolts as a 16-bit integer.
*
* Parameters:
*  int16 adcCounts:  Result from the ADC conversion
*
* Return:
*  int16 Result in mVolts
*
* Global Variables:
*  TPS_ADC_SAR_offset variable used.
*  TPS_ADC_SAR_countsPer10Volt variable used.
*
*******************************************************************************/
int16 TPS_ADC_SAR_CountsTo_mVolts(int16 adcCounts)
{
    int16 mVolts;
    int32 countsPer10Volt;

    if(TPS_ADC_SAR_countsPerVolt != 0)
    {   /* Support obsolete method */
        countsPer10Volt = (int32)TPS_ADC_SAR_countsPerVolt * 10;
    }
    else
    {
        countsPer10Volt = TPS_ADC_SAR_countsPer10Volt;
    }

    /* Subtract ADC offset */
    adcCounts -= TPS_ADC_SAR_offset;
    /* Convert to millivolts with rounding */
    mVolts = (int16)( (( (int32)adcCounts * TPS_ADC_SAR_10MV_COUNTS ) + ( (adcCounts > 0) ?
                       (countsPer10Volt / 2) : (-(countsPer10Volt / 2)) )) / countsPer10Volt);

    return( mVolts );
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_CountsTo_uVolts
********************************************************************************
*
* Summary:
*  Converts the ADC output to microvolts as a 32-bit integer.
*
* Parameters:
*  int16 adcCounts: Result from the ADC conversion
*
* Return:
*  int32 Result in micro Volts
*
* Global Variables:
*  TPS_ADC_SAR_offset variable used.
*  TPS_ADC_SAR_countsPer10Volt used to convert ADC counts to uVolts.
*
*******************************************************************************/
int32 TPS_ADC_SAR_CountsTo_uVolts(int16 adcCounts)
{

    int64 uVolts;
    int32 countsPer10Volt;

    if(TPS_ADC_SAR_countsPerVolt != 0)
    {   /* Support obsolete method */
        countsPer10Volt = (int32)TPS_ADC_SAR_countsPerVolt * 10;
    }
    else
    {
        countsPer10Volt = TPS_ADC_SAR_countsPer10Volt;
    }

    /* Subtract ADC offset */
    adcCounts -= TPS_ADC_SAR_offset;
    /* To convert adcCounts to microVolts it is required to be multiplied
    *  on 10 million and later divide on gain in counts per 10V.
    */
    uVolts = (( (int64)adcCounts * TPS_ADC_SAR_10UV_COUNTS ) / countsPer10Volt);

    return( uVolts );
}


/*******************************************************************************
* Function Name: TPS_ADC_SAR_CountsTo_Volts
********************************************************************************
*
* Summary:
*  Converts the ADC output to volts as a floating-point number.
*
* Parameters:
*  int16 adcCounts: Result from the ADC conversion
*
* Return:
*  float Result in Volts
*
* Global Variables:
*  TPS_ADC_SAR_offset variable used.
*  TPS_ADC_SAR_countsPer10Volt used to convert ADC counts to Volts.
*
*******************************************************************************/
float32 TPS_ADC_SAR_CountsTo_Volts(int16 adcCounts)
{
    float32 volts;
    int32 countsPer10Volt;

    if(TPS_ADC_SAR_countsPerVolt != 0)
    {   /* Support obsolete method */
        countsPer10Volt = (int32)TPS_ADC_SAR_countsPerVolt * 10;
    }
    else
    {
        countsPer10Volt = TPS_ADC_SAR_countsPer10Volt;
    }

    /* Subtract ADC offset */
    adcCounts -= TPS_ADC_SAR_offset;

    volts = ((float32)adcCounts * TPS_ADC_SAR_10V_COUNTS) / (float32)countsPer10Volt;

    return( volts );
}


/* [] END OF FILE */
