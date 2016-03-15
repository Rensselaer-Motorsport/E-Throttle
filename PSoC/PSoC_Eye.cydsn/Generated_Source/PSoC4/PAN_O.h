/*******************************************************************************
* File Name: PAN_O.h  
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

#if !defined(CY_PINS_PAN_O_H) /* Pins PAN_O_H */
#define CY_PINS_PAN_O_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PAN_O_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PAN_O_Write(uint8 value) ;
void    PAN_O_SetDriveMode(uint8 mode) ;
uint8   PAN_O_ReadDataReg(void) ;
uint8   PAN_O_Read(void) ;
uint8   PAN_O_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PAN_O_DRIVE_MODE_BITS        (3)
#define PAN_O_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PAN_O_DRIVE_MODE_BITS))
#define PAN_O_DRIVE_MODE_SHIFT       (0x00u)
#define PAN_O_DRIVE_MODE_MASK        (0x07u << PAN_O_DRIVE_MODE_SHIFT)

#define PAN_O_DM_ALG_HIZ         (0x00u << PAN_O_DRIVE_MODE_SHIFT)
#define PAN_O_DM_DIG_HIZ         (0x01u << PAN_O_DRIVE_MODE_SHIFT)
#define PAN_O_DM_RES_UP          (0x02u << PAN_O_DRIVE_MODE_SHIFT)
#define PAN_O_DM_RES_DWN         (0x03u << PAN_O_DRIVE_MODE_SHIFT)
#define PAN_O_DM_OD_LO           (0x04u << PAN_O_DRIVE_MODE_SHIFT)
#define PAN_O_DM_OD_HI           (0x05u << PAN_O_DRIVE_MODE_SHIFT)
#define PAN_O_DM_STRONG          (0x06u << PAN_O_DRIVE_MODE_SHIFT)
#define PAN_O_DM_RES_UPDWN       (0x07u << PAN_O_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define PAN_O_MASK               PAN_O__MASK
#define PAN_O_SHIFT              PAN_O__SHIFT
#define PAN_O_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PAN_O_PS                     (* (reg32 *) PAN_O__PS)
/* Port Configuration */
#define PAN_O_PC                     (* (reg32 *) PAN_O__PC)
/* Data Register */
#define PAN_O_DR                     (* (reg32 *) PAN_O__DR)
/* Input Buffer Disable Override */
#define PAN_O_INP_DIS                (* (reg32 *) PAN_O__PC2)


#if defined(PAN_O__INTSTAT)  /* Interrupt Registers */

    #define PAN_O_INTSTAT                (* (reg32 *) PAN_O__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins PAN_O_H */


/* [] END OF FILE */
