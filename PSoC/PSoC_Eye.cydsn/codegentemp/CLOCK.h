/*******************************************************************************
* File Name: CLOCK.h  
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

#if !defined(CY_PINS_CLOCK_H) /* Pins CLOCK_H */
#define CY_PINS_CLOCK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CLOCK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CLOCK_Write(uint8 value) ;
void    CLOCK_SetDriveMode(uint8 mode) ;
uint8   CLOCK_ReadDataReg(void) ;
uint8   CLOCK_Read(void) ;
uint8   CLOCK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CLOCK_DRIVE_MODE_BITS        (3)
#define CLOCK_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CLOCK_DRIVE_MODE_BITS))
#define CLOCK_DRIVE_MODE_SHIFT       (0x00u)
#define CLOCK_DRIVE_MODE_MASK        (0x07u << CLOCK_DRIVE_MODE_SHIFT)

#define CLOCK_DM_ALG_HIZ         (0x00u << CLOCK_DRIVE_MODE_SHIFT)
#define CLOCK_DM_DIG_HIZ         (0x01u << CLOCK_DRIVE_MODE_SHIFT)
#define CLOCK_DM_RES_UP          (0x02u << CLOCK_DRIVE_MODE_SHIFT)
#define CLOCK_DM_RES_DWN         (0x03u << CLOCK_DRIVE_MODE_SHIFT)
#define CLOCK_DM_OD_LO           (0x04u << CLOCK_DRIVE_MODE_SHIFT)
#define CLOCK_DM_OD_HI           (0x05u << CLOCK_DRIVE_MODE_SHIFT)
#define CLOCK_DM_STRONG          (0x06u << CLOCK_DRIVE_MODE_SHIFT)
#define CLOCK_DM_RES_UPDWN       (0x07u << CLOCK_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define CLOCK_MASK               CLOCK__MASK
#define CLOCK_SHIFT              CLOCK__SHIFT
#define CLOCK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CLOCK_PS                     (* (reg32 *) CLOCK__PS)
/* Port Configuration */
#define CLOCK_PC                     (* (reg32 *) CLOCK__PC)
/* Data Register */
#define CLOCK_DR                     (* (reg32 *) CLOCK__DR)
/* Input Buffer Disable Override */
#define CLOCK_INP_DIS                (* (reg32 *) CLOCK__PC2)


#if defined(CLOCK__INTSTAT)  /* Interrupt Registers */

    #define CLOCK_INTSTAT                (* (reg32 *) CLOCK__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins CLOCK_H */


/* [] END OF FILE */
