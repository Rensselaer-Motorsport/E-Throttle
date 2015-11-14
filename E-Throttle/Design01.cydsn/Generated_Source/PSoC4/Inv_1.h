/*******************************************************************************
* File Name: Inv_1.h  
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

#if !defined(CY_PINS_Inv_1_H) /* Pins Inv_1_H */
#define CY_PINS_Inv_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Inv_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Inv_1_Write(uint8 value) ;
void    Inv_1_SetDriveMode(uint8 mode) ;
uint8   Inv_1_ReadDataReg(void) ;
uint8   Inv_1_Read(void) ;
uint8   Inv_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Inv_1_DRIVE_MODE_BITS        (3)
#define Inv_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Inv_1_DRIVE_MODE_BITS))

#define Inv_1_DM_ALG_HIZ         (0x00u)
#define Inv_1_DM_DIG_HIZ         (0x01u)
#define Inv_1_DM_RES_UP          (0x02u)
#define Inv_1_DM_RES_DWN         (0x03u)
#define Inv_1_DM_OD_LO           (0x04u)
#define Inv_1_DM_OD_HI           (0x05u)
#define Inv_1_DM_STRONG          (0x06u)
#define Inv_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Inv_1_MASK               Inv_1__MASK
#define Inv_1_SHIFT              Inv_1__SHIFT
#define Inv_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Inv_1_PS                     (* (reg32 *) Inv_1__PS)
/* Port Configuration */
#define Inv_1_PC                     (* (reg32 *) Inv_1__PC)
/* Data Register */
#define Inv_1_DR                     (* (reg32 *) Inv_1__DR)
/* Input Buffer Disable Override */
#define Inv_1_INP_DIS                (* (reg32 *) Inv_1__PC2)


#if defined(Inv_1__INTSTAT)  /* Interrupt Registers */

    #define Inv_1_INTSTAT                (* (reg32 *) Inv_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Inv_1_DRIVE_MODE_SHIFT       (0x00u)
#define Inv_1_DRIVE_MODE_MASK        (0x07u << Inv_1_DRIVE_MODE_SHIFT)


#endif /* End Pins Inv_1_H */


/* [] END OF FILE */
