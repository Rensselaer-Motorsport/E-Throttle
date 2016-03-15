/*******************************************************************************
* File Name: pwm_clock.h
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

#if !defined(CY_CLOCK_pwm_clock_H)
#define CY_CLOCK_pwm_clock_H

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

void pwm_clock_Start(void) ;
void pwm_clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void pwm_clock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void pwm_clock_StandbyPower(uint8 state) ;
void pwm_clock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 pwm_clock_GetDividerRegister(void) ;
void pwm_clock_SetModeRegister(uint8 modeBitMask) ;
void pwm_clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 pwm_clock_GetModeRegister(void) ;
void pwm_clock_SetSourceRegister(uint8 clkSource) ;
uint8 pwm_clock_GetSourceRegister(void) ;
#if defined(pwm_clock__CFG3)
void pwm_clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 pwm_clock_GetPhaseRegister(void) ;
#endif /* defined(pwm_clock__CFG3) */

#define pwm_clock_Enable()                       pwm_clock_Start()
#define pwm_clock_Disable()                      pwm_clock_Stop()
#define pwm_clock_SetDivider(clkDivider)         pwm_clock_SetDividerRegister(clkDivider, 1u)
#define pwm_clock_SetDividerValue(clkDivider)    pwm_clock_SetDividerRegister((clkDivider) - 1u, 1u)
#define pwm_clock_SetMode(clkMode)               pwm_clock_SetModeRegister(clkMode)
#define pwm_clock_SetSource(clkSource)           pwm_clock_SetSourceRegister(clkSource)
#if defined(pwm_clock__CFG3)
#define pwm_clock_SetPhase(clkPhase)             pwm_clock_SetPhaseRegister(clkPhase)
#define pwm_clock_SetPhaseValue(clkPhase)        pwm_clock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(pwm_clock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define pwm_clock_CLKEN              (* (reg8 *) pwm_clock__PM_ACT_CFG)
#define pwm_clock_CLKEN_PTR          ((reg8 *) pwm_clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define pwm_clock_CLKSTBY            (* (reg8 *) pwm_clock__PM_STBY_CFG)
#define pwm_clock_CLKSTBY_PTR        ((reg8 *) pwm_clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define pwm_clock_DIV_LSB            (* (reg8 *) pwm_clock__CFG0)
#define pwm_clock_DIV_LSB_PTR        ((reg8 *) pwm_clock__CFG0)
#define pwm_clock_DIV_PTR            ((reg16 *) pwm_clock__CFG0)

/* Clock MSB divider configuration register. */
#define pwm_clock_DIV_MSB            (* (reg8 *) pwm_clock__CFG1)
#define pwm_clock_DIV_MSB_PTR        ((reg8 *) pwm_clock__CFG1)

/* Mode and source configuration register */
#define pwm_clock_MOD_SRC            (* (reg8 *) pwm_clock__CFG2)
#define pwm_clock_MOD_SRC_PTR        ((reg8 *) pwm_clock__CFG2)

#if defined(pwm_clock__CFG3)
/* Analog clock phase configuration register */
#define pwm_clock_PHASE              (* (reg8 *) pwm_clock__CFG3)
#define pwm_clock_PHASE_PTR          ((reg8 *) pwm_clock__CFG3)
#endif /* defined(pwm_clock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define pwm_clock_CLKEN_MASK         pwm_clock__PM_ACT_MSK
#define pwm_clock_CLKSTBY_MASK       pwm_clock__PM_STBY_MSK

/* CFG2 field masks */
#define pwm_clock_SRC_SEL_MSK        pwm_clock__CFG2_SRC_SEL_MASK
#define pwm_clock_MODE_MASK          (~(pwm_clock_SRC_SEL_MSK))

#if defined(pwm_clock__CFG3)
/* CFG3 phase mask */
#define pwm_clock_PHASE_MASK         pwm_clock__CFG3_PHASE_DLY_MASK
#endif /* defined(pwm_clock__CFG3) */

#endif /* CY_CLOCK_pwm_clock_H */


/* [] END OF FILE */
