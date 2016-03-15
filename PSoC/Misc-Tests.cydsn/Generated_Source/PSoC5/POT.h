/*******************************************************************************
* File Name: POT.h  
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

#if !defined(CY_PINS_POT_H) /* Pins POT_H */
#define CY_PINS_POT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "POT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 POT__PORT == 15 && ((POT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    POT_Write(uint8 value) ;
void    POT_SetDriveMode(uint8 mode) ;
uint8   POT_ReadDataReg(void) ;
uint8   POT_Read(void) ;
uint8   POT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define POT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define POT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define POT_DM_RES_UP          PIN_DM_RES_UP
#define POT_DM_RES_DWN         PIN_DM_RES_DWN
#define POT_DM_OD_LO           PIN_DM_OD_LO
#define POT_DM_OD_HI           PIN_DM_OD_HI
#define POT_DM_STRONG          PIN_DM_STRONG
#define POT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define POT_MASK               POT__MASK
#define POT_SHIFT              POT__SHIFT
#define POT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT_PS                     (* (reg8 *) POT__PS)
/* Data Register */
#define POT_DR                     (* (reg8 *) POT__DR)
/* Port Number */
#define POT_PRT_NUM                (* (reg8 *) POT__PRT) 
/* Connect to Analog Globals */                                                  
#define POT_AG                     (* (reg8 *) POT__AG)                       
/* Analog MUX bux enable */
#define POT_AMUX                   (* (reg8 *) POT__AMUX) 
/* Bidirectional Enable */                                                        
#define POT_BIE                    (* (reg8 *) POT__BIE)
/* Bit-mask for Aliased Register Access */
#define POT_BIT_MASK               (* (reg8 *) POT__BIT_MASK)
/* Bypass Enable */
#define POT_BYP                    (* (reg8 *) POT__BYP)
/* Port wide control signals */                                                   
#define POT_CTL                    (* (reg8 *) POT__CTL)
/* Drive Modes */
#define POT_DM0                    (* (reg8 *) POT__DM0) 
#define POT_DM1                    (* (reg8 *) POT__DM1)
#define POT_DM2                    (* (reg8 *) POT__DM2) 
/* Input Buffer Disable Override */
#define POT_INP_DIS                (* (reg8 *) POT__INP_DIS)
/* LCD Common or Segment Drive */
#define POT_LCD_COM_SEG            (* (reg8 *) POT__LCD_COM_SEG)
/* Enable Segment LCD */
#define POT_LCD_EN                 (* (reg8 *) POT__LCD_EN)
/* Slew Rate Control */
#define POT_SLW                    (* (reg8 *) POT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define POT_PRTDSI__CAPS_SEL       (* (reg8 *) POT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define POT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) POT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define POT_PRTDSI__OE_SEL0        (* (reg8 *) POT__PRTDSI__OE_SEL0) 
#define POT_PRTDSI__OE_SEL1        (* (reg8 *) POT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define POT_PRTDSI__OUT_SEL0       (* (reg8 *) POT__PRTDSI__OUT_SEL0) 
#define POT_PRTDSI__OUT_SEL1       (* (reg8 *) POT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define POT_PRTDSI__SYNC_OUT       (* (reg8 *) POT__PRTDSI__SYNC_OUT) 


#if defined(POT__INTSTAT)  /* Interrupt Registers */

    #define POT_INTSTAT                (* (reg8 *) POT__INTSTAT)
    #define POT_SNAP                   (* (reg8 *) POT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_POT_H */


/* [] END OF FILE */
