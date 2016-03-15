/*******************************************************************************
* File Name: .h
* Version 1.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_I2CM_H)
#define CY_SCB_PVT_I2CM_H

#include "I2CM.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define I2CM_SetI2CExtClkInterruptMode(interruptMask) I2CM_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define I2CM_ClearI2CExtClkInterruptSource(interruptMask) I2CM_CLEAR_INTR_I2C_EC(interruptMask)
#define I2CM_GetI2CExtClkInterruptSource()                (I2CM_INTR_I2C_EC_REG)
#define I2CM_GetI2CExtClkInterruptMode()                  (I2CM_INTR_I2C_EC_MASK_REG)
#define I2CM_GetI2CExtClkInterruptSourceMasked()          (I2CM_INTR_I2C_EC_MASKED_REG)

/* APIs to service INTR_SPI_EC register */
#define I2CM_SetSpiExtClkInterruptMode(interruptMask) I2CM_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define I2CM_ClearSpiExtClkInterruptSource(interruptMask) I2CM_CLEAR_INTR_SPI_EC(interruptMask)
#define I2CM_GetExtSpiClkInterruptSource()                 (I2CM_INTR_SPI_EC_REG)
#define I2CM_GetExtSpiClkInterruptMode()                   (I2CM_INTR_SPI_EC_MASK_REG)
#define I2CM_GetExtSpiClkInterruptSourceMasked()           (I2CM_INTR_SPI_EC_MASKED_REG)

#if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void I2CM_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_I2CM_H) */


/* [] END OF FILE */
