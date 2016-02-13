/*******************************************************************************
* File Name: BRAKE_ADC_Ext_CP_Clk.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_BRAKE_ADC_Ext_CP_Clk_H)
#define CY_CLOCK_BRAKE_ADC_Ext_CP_Clk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void BRAKE_ADC_Ext_CP_Clk_Start(void) ;
void BRAKE_ADC_Ext_CP_Clk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void BRAKE_ADC_Ext_CP_Clk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void BRAKE_ADC_Ext_CP_Clk_StandbyPower(uint8 state) ;
void BRAKE_ADC_Ext_CP_Clk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 BRAKE_ADC_Ext_CP_Clk_GetDividerRegister(void) ;
void BRAKE_ADC_Ext_CP_Clk_SetModeRegister(uint8 modeBitMask) ;
void BRAKE_ADC_Ext_CP_Clk_ClearModeRegister(uint8 modeBitMask) ;
uint8 BRAKE_ADC_Ext_CP_Clk_GetModeRegister(void) ;
void BRAKE_ADC_Ext_CP_Clk_SetSourceRegister(uint8 clkSource) ;
uint8 BRAKE_ADC_Ext_CP_Clk_GetSourceRegister(void) ;
#if defined(BRAKE_ADC_Ext_CP_Clk__CFG3)
void BRAKE_ADC_Ext_CP_Clk_SetPhaseRegister(uint8 clkPhase) ;
uint8 BRAKE_ADC_Ext_CP_Clk_GetPhaseRegister(void) ;
#endif /* defined(BRAKE_ADC_Ext_CP_Clk__CFG3) */

#define BRAKE_ADC_Ext_CP_Clk_Enable()                       BRAKE_ADC_Ext_CP_Clk_Start()
#define BRAKE_ADC_Ext_CP_Clk_Disable()                      BRAKE_ADC_Ext_CP_Clk_Stop()
#define BRAKE_ADC_Ext_CP_Clk_SetDivider(clkDivider)         BRAKE_ADC_Ext_CP_Clk_SetDividerRegister(clkDivider, 1u)
#define BRAKE_ADC_Ext_CP_Clk_SetDividerValue(clkDivider)    BRAKE_ADC_Ext_CP_Clk_SetDividerRegister((clkDivider) - 1u, 1u)
#define BRAKE_ADC_Ext_CP_Clk_SetMode(clkMode)               BRAKE_ADC_Ext_CP_Clk_SetModeRegister(clkMode)
#define BRAKE_ADC_Ext_CP_Clk_SetSource(clkSource)           BRAKE_ADC_Ext_CP_Clk_SetSourceRegister(clkSource)
#if defined(BRAKE_ADC_Ext_CP_Clk__CFG3)
#define BRAKE_ADC_Ext_CP_Clk_SetPhase(clkPhase)             BRAKE_ADC_Ext_CP_Clk_SetPhaseRegister(clkPhase)
#define BRAKE_ADC_Ext_CP_Clk_SetPhaseValue(clkPhase)        BRAKE_ADC_Ext_CP_Clk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(BRAKE_ADC_Ext_CP_Clk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define BRAKE_ADC_Ext_CP_Clk_CLKEN              (* (reg8 *) BRAKE_ADC_Ext_CP_Clk__PM_ACT_CFG)
#define BRAKE_ADC_Ext_CP_Clk_CLKEN_PTR          ((reg8 *) BRAKE_ADC_Ext_CP_Clk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define BRAKE_ADC_Ext_CP_Clk_CLKSTBY            (* (reg8 *) BRAKE_ADC_Ext_CP_Clk__PM_STBY_CFG)
#define BRAKE_ADC_Ext_CP_Clk_CLKSTBY_PTR        ((reg8 *) BRAKE_ADC_Ext_CP_Clk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define BRAKE_ADC_Ext_CP_Clk_DIV_LSB            (* (reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG0)
#define BRAKE_ADC_Ext_CP_Clk_DIV_LSB_PTR        ((reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG0)
#define BRAKE_ADC_Ext_CP_Clk_DIV_PTR            ((reg16 *) BRAKE_ADC_Ext_CP_Clk__CFG0)

/* Clock MSB divider configuration register. */
#define BRAKE_ADC_Ext_CP_Clk_DIV_MSB            (* (reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG1)
#define BRAKE_ADC_Ext_CP_Clk_DIV_MSB_PTR        ((reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG1)

/* Mode and source configuration register */
#define BRAKE_ADC_Ext_CP_Clk_MOD_SRC            (* (reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG2)
#define BRAKE_ADC_Ext_CP_Clk_MOD_SRC_PTR        ((reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG2)

#if defined(BRAKE_ADC_Ext_CP_Clk__CFG3)
/* Analog clock phase configuration register */
#define BRAKE_ADC_Ext_CP_Clk_PHASE              (* (reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG3)
#define BRAKE_ADC_Ext_CP_Clk_PHASE_PTR          ((reg8 *) BRAKE_ADC_Ext_CP_Clk__CFG3)
#endif /* defined(BRAKE_ADC_Ext_CP_Clk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define BRAKE_ADC_Ext_CP_Clk_CLKEN_MASK         BRAKE_ADC_Ext_CP_Clk__PM_ACT_MSK
#define BRAKE_ADC_Ext_CP_Clk_CLKSTBY_MASK       BRAKE_ADC_Ext_CP_Clk__PM_STBY_MSK

/* CFG2 field masks */
#define BRAKE_ADC_Ext_CP_Clk_SRC_SEL_MSK        BRAKE_ADC_Ext_CP_Clk__CFG2_SRC_SEL_MASK
#define BRAKE_ADC_Ext_CP_Clk_MODE_MASK          (~(BRAKE_ADC_Ext_CP_Clk_SRC_SEL_MSK))

#if defined(BRAKE_ADC_Ext_CP_Clk__CFG3)
/* CFG3 phase mask */
#define BRAKE_ADC_Ext_CP_Clk_PHASE_MASK         BRAKE_ADC_Ext_CP_Clk__CFG3_PHASE_DLY_MASK
#endif /* defined(BRAKE_ADC_Ext_CP_Clk__CFG3) */

#endif /* CY_CLOCK_BRAKE_ADC_Ext_CP_Clk_H */


/* [] END OF FILE */
