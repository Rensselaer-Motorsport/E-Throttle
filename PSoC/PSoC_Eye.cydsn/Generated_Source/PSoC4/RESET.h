/*******************************************************************************
* File Name: RESET.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RESET_H) /* Pins RESET_H */
#define CY_PINS_RESET_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RESET_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RESET_Write(uint8 value) ;
void    RESET_SetDriveMode(uint8 mode) ;
uint8   RESET_ReadDataReg(void) ;
uint8   RESET_Read(void) ;
uint8   RESET_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RESET_DRIVE_MODE_BITS        (3)
#define RESET_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RESET_DRIVE_MODE_BITS))
#define RESET_DRIVE_MODE_SHIFT       (0x00u)
#define RESET_DRIVE_MODE_MASK        (0x07u << RESET_DRIVE_MODE_SHIFT)

#define RESET_DM_ALG_HIZ         (0x00u << RESET_DRIVE_MODE_SHIFT)
#define RESET_DM_DIG_HIZ         (0x01u << RESET_DRIVE_MODE_SHIFT)
#define RESET_DM_RES_UP          (0x02u << RESET_DRIVE_MODE_SHIFT)
#define RESET_DM_RES_DWN         (0x03u << RESET_DRIVE_MODE_SHIFT)
#define RESET_DM_OD_LO           (0x04u << RESET_DRIVE_MODE_SHIFT)
#define RESET_DM_OD_HI           (0x05u << RESET_DRIVE_MODE_SHIFT)
#define RESET_DM_STRONG          (0x06u << RESET_DRIVE_MODE_SHIFT)
#define RESET_DM_RES_UPDWN       (0x07u << RESET_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define RESET_MASK               RESET__MASK
#define RESET_SHIFT              RESET__SHIFT
#define RESET_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RESET_PS                     (* (reg32 *) RESET__PS)
/* Port Configuration */
#define RESET_PC                     (* (reg32 *) RESET__PC)
/* Data Register */
#define RESET_DR                     (* (reg32 *) RESET__DR)
/* Input Buffer Disable Override */
#define RESET_INP_DIS                (* (reg32 *) RESET__PC2)


#if defined(RESET__INTSTAT)  /* Interrupt Registers */

    #define RESET_INTSTAT                (* (reg32 *) RESET__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins RESET_H */


/* [] END OF FILE */
