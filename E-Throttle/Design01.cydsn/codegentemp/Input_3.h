/*******************************************************************************
* File Name: Input_3.h  
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

#if !defined(CY_PINS_Input_3_H) /* Pins Input_3_H */
#define CY_PINS_Input_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Input_3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Input_3_Write(uint8 value) ;
void    Input_3_SetDriveMode(uint8 mode) ;
uint8   Input_3_ReadDataReg(void) ;
uint8   Input_3_Read(void) ;
uint8   Input_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Input_3_DRIVE_MODE_BITS        (3)
#define Input_3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Input_3_DRIVE_MODE_BITS))

#define Input_3_DM_ALG_HIZ         (0x00u)
#define Input_3_DM_DIG_HIZ         (0x01u)
#define Input_3_DM_RES_UP          (0x02u)
#define Input_3_DM_RES_DWN         (0x03u)
#define Input_3_DM_OD_LO           (0x04u)
#define Input_3_DM_OD_HI           (0x05u)
#define Input_3_DM_STRONG          (0x06u)
#define Input_3_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Input_3_MASK               Input_3__MASK
#define Input_3_SHIFT              Input_3__SHIFT
#define Input_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Input_3_PS                     (* (reg32 *) Input_3__PS)
/* Port Configuration */
#define Input_3_PC                     (* (reg32 *) Input_3__PC)
/* Data Register */
#define Input_3_DR                     (* (reg32 *) Input_3__DR)
/* Input Buffer Disable Override */
#define Input_3_INP_DIS                (* (reg32 *) Input_3__PC2)


#if defined(Input_3__INTSTAT)  /* Interrupt Registers */

    #define Input_3_INTSTAT                (* (reg32 *) Input_3__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Input_3_DRIVE_MODE_SHIFT       (0x00u)
#define Input_3_DRIVE_MODE_MASK        (0x07u << Input_3_DRIVE_MODE_SHIFT)


#endif /* End Pins Input_3_H */


/* [] END OF FILE */
