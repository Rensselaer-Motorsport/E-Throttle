/*******************************************************************************
* File Name: Brake.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Brake_H) /* Pins Brake_H */
#define CY_PINS_Brake_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Brake_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Brake__PORT == 15 && ((Brake__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Brake_Write(uint8 value) ;
void    Brake_SetDriveMode(uint8 mode) ;
uint8   Brake_ReadDataReg(void) ;
uint8   Brake_Read(void) ;
uint8   Brake_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Brake_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Brake_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Brake_DM_RES_UP          PIN_DM_RES_UP
#define Brake_DM_RES_DWN         PIN_DM_RES_DWN
#define Brake_DM_OD_LO           PIN_DM_OD_LO
#define Brake_DM_OD_HI           PIN_DM_OD_HI
#define Brake_DM_STRONG          PIN_DM_STRONG
#define Brake_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Brake_MASK               Brake__MASK
#define Brake_SHIFT              Brake__SHIFT
#define Brake_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Brake_PS                     (* (reg8 *) Brake__PS)
/* Data Register */
#define Brake_DR                     (* (reg8 *) Brake__DR)
/* Port Number */
#define Brake_PRT_NUM                (* (reg8 *) Brake__PRT) 
/* Connect to Analog Globals */                                                  
#define Brake_AG                     (* (reg8 *) Brake__AG)                       
/* Analog MUX bux enable */
#define Brake_AMUX                   (* (reg8 *) Brake__AMUX) 
/* Bidirectional Enable */                                                        
#define Brake_BIE                    (* (reg8 *) Brake__BIE)
/* Bit-mask for Aliased Register Access */
#define Brake_BIT_MASK               (* (reg8 *) Brake__BIT_MASK)
/* Bypass Enable */
#define Brake_BYP                    (* (reg8 *) Brake__BYP)
/* Port wide control signals */                                                   
#define Brake_CTL                    (* (reg8 *) Brake__CTL)
/* Drive Modes */
#define Brake_DM0                    (* (reg8 *) Brake__DM0) 
#define Brake_DM1                    (* (reg8 *) Brake__DM1)
#define Brake_DM2                    (* (reg8 *) Brake__DM2) 
/* Input Buffer Disable Override */
#define Brake_INP_DIS                (* (reg8 *) Brake__INP_DIS)
/* LCD Common or Segment Drive */
#define Brake_LCD_COM_SEG            (* (reg8 *) Brake__LCD_COM_SEG)
/* Enable Segment LCD */
#define Brake_LCD_EN                 (* (reg8 *) Brake__LCD_EN)
/* Slew Rate Control */
#define Brake_SLW                    (* (reg8 *) Brake__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Brake_PRTDSI__CAPS_SEL       (* (reg8 *) Brake__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Brake_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Brake__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Brake_PRTDSI__OE_SEL0        (* (reg8 *) Brake__PRTDSI__OE_SEL0) 
#define Brake_PRTDSI__OE_SEL1        (* (reg8 *) Brake__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Brake_PRTDSI__OUT_SEL0       (* (reg8 *) Brake__PRTDSI__OUT_SEL0) 
#define Brake_PRTDSI__OUT_SEL1       (* (reg8 *) Brake__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Brake_PRTDSI__SYNC_OUT       (* (reg8 *) Brake__PRTDSI__SYNC_OUT) 


#if defined(Brake__INTSTAT)  /* Interrupt Registers */

    #define Brake_INTSTAT                (* (reg8 *) Brake__INTSTAT)
    #define Brake_SNAP                   (* (reg8 *) Brake__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Brake_H */


/* [] END OF FILE */
