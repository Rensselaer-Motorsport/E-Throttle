/*******************************************************************************
* File Name: I2CM_PM.c
* Version 1.0
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CM.h"

#if(I2CM_SCB_MODE_I2C_INC)
    #include "I2CM_I2C_PVT.h"
#endif /* (I2CM_SCB_MODE_I2C_INC) */

#if(I2CM_SCB_MODE_SPI_INC || I2CM_SCB_MODE_UART_INC)
    #include "I2CM_SPI_UART_PVT.h"
#endif /* (I2CM_SCB_MODE_SPI_INC || I2CM_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

I2CM_BACKUP_STRUCT I2CM_backup =
{
    0u, /* enableState */
};


/*******************************************************************************
* Function Name: I2CM_Sleep
********************************************************************************
*
* Summary:
*  Calls SaveConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2CM_Sleep(void)
{
    I2CM_backup.enableState = (uint8) I2CM_GET_CTRL_ENABLED;

    #if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)

        if(I2CM_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2CM_I2CSaveConfig();
        }
        else if(I2CM_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2CM_SpiSaveConfig();
        }
        else if(I2CM_SCB_MODE_UART_RUNTM_CFG)
        {
            I2CM_UartSaveConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }

    #elif(I2CM_SCB_MODE_I2C_CONST_CFG)
        I2CM_I2CSaveConfig();

    #elif(I2CM_SCB_MODE_SPI_CONST_CFG)
        I2CM_SpiSaveConfig();

    #elif(I2CM_SCB_MODE_UART_CONST_CFG)
        I2CM_UartSaveConfig();

    #else
        /* Do nothing */

    #endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */

    if(0u != I2CM_backup.enableState)
    {
        I2CM_Stop();
    }
}


/*******************************************************************************
* Function Name: I2CM_Wakeup
********************************************************************************
*
* Summary:
*  Calls RestoreConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2CM_Wakeup(void)
{
    #if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)

        if(I2CM_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2CM_I2CRestoreConfig();
        }
        else if(I2CM_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2CM_SpiRestoreConfig();
        }
        else if(I2CM_SCB_MODE_UART_RUNTM_CFG)
        {
            I2CM_UartRestoreConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }

    #elif(I2CM_SCB_MODE_I2C_CONST_CFG)
        I2CM_I2CRestoreConfig();

    #elif(I2CM_SCB_MODE_SPI_CONST_CFG)
        I2CM_SpiRestoreConfig();

    #elif(I2CM_SCB_MODE_UART_CONST_CFG)
        I2CM_UartRestoreConfig();

    #else
        /* Do nothing */

    #endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */

    if(0u != I2CM_backup.enableState)
    {
        I2CM_Enable();
    }
}


/* [] END OF FILE */
