/*******************************************************************************
* File Name: TILT_O.h  
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

#if !defined(CY_PINS_TILT_O_H) /* Pins TILT_O_H */
#define CY_PINS_TILT_O_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TILT_O_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TILT_O_Write(uint8 value) ;
void    TILT_O_SetDriveMode(uint8 mode) ;
uint8   TILT_O_ReadDataReg(void) ;
uint8   TILT_O_Read(void) ;
uint8   TILT_O_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TILT_O_DRIVE_MODE_BITS        (3)
#define TILT_O_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TILT_O_DRIVE_MODE_BITS))
#define TILT_O_DRIVE_MODE_SHIFT       (0x00u)
#define TILT_O_DRIVE_MODE_MASK        (0x07u << TILT_O_DRIVE_MODE_SHIFT)

#define TILT_O_DM_ALG_HIZ         (0x00u << TILT_O_DRIVE_MODE_SHIFT)
#define TILT_O_DM_DIG_HIZ         (0x01u << TILT_O_DRIVE_MODE_SHIFT)
#define TILT_O_DM_RES_UP          (0x02u << TILT_O_DRIVE_MODE_SHIFT)
#define TILT_O_DM_RES_DWN         (0x03u << TILT_O_DRIVE_MODE_SHIFT)
#define TILT_O_DM_OD_LO           (0x04u << TILT_O_DRIVE_MODE_SHIFT)
#define TILT_O_DM_OD_HI           (0x05u << TILT_O_DRIVE_MODE_SHIFT)
#define TILT_O_DM_STRONG          (0x06u << TILT_O_DRIVE_MODE_SHIFT)
#define TILT_O_DM_RES_UPDWN       (0x07u << TILT_O_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define TILT_O_MASK               TILT_O__MASK
#define TILT_O_SHIFT              TILT_O__SHIFT
#define TILT_O_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TILT_O_PS                     (* (reg32 *) TILT_O__PS)
/* Port Configuration */
#define TILT_O_PC                     (* (reg32 *) TILT_O__PC)
/* Data Register */
#define TILT_O_DR                     (* (reg32 *) TILT_O__DR)
/* Input Buffer Disable Override */
#define TILT_O_INP_DIS                (* (reg32 *) TILT_O__PC2)


#if defined(TILT_O__INTSTAT)  /* Interrupt Registers */

    #define TILT_O_INTSTAT                (* (reg32 *) TILT_O__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins TILT_O_H */


/* [] END OF FILE */
