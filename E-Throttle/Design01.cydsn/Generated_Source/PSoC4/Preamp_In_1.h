/*******************************************************************************
* File Name: Preamp_In_1.h  
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

#if !defined(CY_PINS_Preamp_In_1_H) /* Pins Preamp_In_1_H */
#define CY_PINS_Preamp_In_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Preamp_In_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Preamp_In_1_Write(uint8 value) ;
void    Preamp_In_1_SetDriveMode(uint8 mode) ;
uint8   Preamp_In_1_ReadDataReg(void) ;
uint8   Preamp_In_1_Read(void) ;
uint8   Preamp_In_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Preamp_In_1_DRIVE_MODE_BITS        (3)
#define Preamp_In_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Preamp_In_1_DRIVE_MODE_BITS))

#define Preamp_In_1_DM_ALG_HIZ         (0x00u)
#define Preamp_In_1_DM_DIG_HIZ         (0x01u)
#define Preamp_In_1_DM_RES_UP          (0x02u)
#define Preamp_In_1_DM_RES_DWN         (0x03u)
#define Preamp_In_1_DM_OD_LO           (0x04u)
#define Preamp_In_1_DM_OD_HI           (0x05u)
#define Preamp_In_1_DM_STRONG          (0x06u)
#define Preamp_In_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Preamp_In_1_MASK               Preamp_In_1__MASK
#define Preamp_In_1_SHIFT              Preamp_In_1__SHIFT
#define Preamp_In_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Preamp_In_1_PS                     (* (reg32 *) Preamp_In_1__PS)
/* Port Configuration */
#define Preamp_In_1_PC                     (* (reg32 *) Preamp_In_1__PC)
/* Data Register */
#define Preamp_In_1_DR                     (* (reg32 *) Preamp_In_1__DR)
/* Input Buffer Disable Override */
#define Preamp_In_1_INP_DIS                (* (reg32 *) Preamp_In_1__PC2)


#if defined(Preamp_In_1__INTSTAT)  /* Interrupt Registers */

    #define Preamp_In_1_INTSTAT                (* (reg32 *) Preamp_In_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Preamp_In_1_DRIVE_MODE_SHIFT       (0x00u)
#define Preamp_In_1_DRIVE_MODE_MASK        (0x07u << Preamp_In_1_DRIVE_MODE_SHIFT)


#endif /* End Pins Preamp_In_1_H */


/* [] END OF FILE */
