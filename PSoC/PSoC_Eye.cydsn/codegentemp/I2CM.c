/*******************************************************************************
* File Name: I2CM.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CM_PVT.h"

#if(I2CM_SCB_MODE_I2C_INC)
    #include "I2CM_I2C_PVT.h"
#endif /* (I2CM_SCB_MODE_I2C_INC) */

#if(I2CM_SCB_MODE_SPI_INC || I2CM_SCB_MODE_UART_INC)
    #include "I2CM_SPI_UART_PVT.h"
#endif /* (I2CM_SCB_MODE_SPI_INC || I2CM_SCB_MODE_UART_INC) */


/**********************************
*    Run Time Configuration Vars
**********************************/

/* Stores internal component configuration for unconfigured mode */
#if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    volatile uint8 I2CM_scbMode = I2CM_SCB_MODE_UNCONFIG;
    volatile uint8 I2CM_scbEnableWake;

    /* I2C config vars */
    volatile uint8 I2CM_mode;
    volatile uint8 I2CM_acceptAddr;

    /* SPI/UART config vars */
    volatile uint8 * I2CM_rxBuffer;
    volatile uint8   I2CM_rxDataBits;
    volatile uint32  I2CM_rxBufferSize;

    volatile uint8 * I2CM_txBuffer;
    volatile uint8   I2CM_txDataBits;
    volatile uint32  I2CM_txBufferSize;

#endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */


/**********************************
*     Common SCB Vars
**********************************/

uint8 I2CM_initVar = 0u;
cyisraddress I2CM_customIntrHandler = NULL;


/***************************************
*    Private Function Prototypes
***************************************/

static void I2CM_ScbModeStop(void);


/*******************************************************************************
* Function Name: I2CM_Init
********************************************************************************
*
* Summary:
*  Initializes SCB component to operate in one of selected configurations:
*  I2C, SPI, UART, EZI2C or EZSPI.
*  This function does not do any initialization when configuration is set to
*  Unconfigured SCB.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2CM_Init(void)
{
    #if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2CM_SCB_MODE_UNCONFIG_RUNTM_CFG)
        {
            I2CM_initVar = 0u; /* Clear init var */
        }
        else
        {
            /* Initialization was done before call */
        }

    #elif(I2CM_SCB_MODE_I2C_CONST_CFG)
        I2CM_I2CInit();

    #elif(I2CM_SCB_MODE_SPI_CONST_CFG)
        I2CM_SpiInit();

    #elif(I2CM_SCB_MODE_UART_CONST_CFG)
        I2CM_UartInit();

    #else

    #endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2CM_Enable
********************************************************************************
*
* Summary:
*  Enables SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2CM_Enable(void)
{
    #if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)
        if(!I2CM_SCB_MODE_UNCONFIG_RUNTM_CFG)
        {
            /* Enable SCB block, only if already configured */
            I2CM_CTRL_REG |= I2CM_CTRL_ENABLED;
        }
    #else
        I2CM_CTRL_REG |= I2CM_CTRL_ENABLED; /* Enable SCB block */
    #endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2CM_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call the component is enabled and ready for operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  I2CM_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void I2CM_Start(void)
{
    if(0u == I2CM_initVar)
    {
        I2CM_initVar = 1u; /* Component was initialized */
        I2CM_Init();       /* Initialize component      */
    }

    I2CM_Enable();
}


/*******************************************************************************
* Function Name: I2CM_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2CM_Stop(void)
{
    I2CM_CTRL_REG &= (uint32) ~I2CM_CTRL_ENABLED;  /* Disable SCB block */

    #if(I2CM_SCB_IRQ_INTERNAL)
        I2CM_SCB_IRQ_ClearPending(); /* Clear pending interrupt */
    #endif /* (I2CM_SCB_IRQ_INTERNAL) */

    I2CM_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: I2CM_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operations such as software buffer management functions
*  before the interrupt returns.  It is user's responsibility to not break the
*  software buffer operations. Only one custom handler is supported, which is
*  the function provided by the most recent call.
*  At initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void I2CM_SetCustomInterruptHandler(cyisraddress func)
{
    I2CM_customIntrHandler = func; /* Register interrupt handler */
}


/*******************************************************************************
* Function Name: I2CM_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls Stop function for specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void I2CM_ScbModeStop(void)
{
    #if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2CM_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2CM_I2CStop();
        }
    #elif(I2CM_SCB_MODE_I2C_CONST_CFG)
        I2CM_I2CStop();
    #else

    #endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */
}



#if(I2CM_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: I2CM_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets pins settings accordingly to selected operation mode.
    *  Only available in Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when specific mode of operation
    *  selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Submode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartTxRx:  Direction for UART.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void I2CM_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx)
    {
        uint32 hsiomSel[I2CM_SCB_PINS_NUMBER];
        uint32 pinsDm  [I2CM_SCB_PINS_NUMBER];
        uint32 i;

        /* Make all unused */
        for(i = 0u; i < I2CM_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i] = I2CM_HSIOM_DEF_SEL;
            pinsDm[i]   = I2CM_PIN_DM_ALG_HIZ;
        }

        /* Choice the Dm and HSIOM */
        if(I2CM_SCB_MODE_I2C == mode)
        {
            hsiomSel[I2CM_MOSI_SCL_RX_PIN_INDEX] = I2CM_HSIOM_I2C_SEL;
            hsiomSel[I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_HSIOM_I2C_SEL;

            pinsDm[I2CM_MOSI_SCL_RX_PIN_INDEX] = I2CM_PIN_DM_OD_LO;
            pinsDm[I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_PIN_DM_OD_LO;
        }
        else if(I2CM_SCB_MODE_SPI == mode)
        {
            hsiomSel[I2CM_MOSI_SCL_RX_PIN_INDEX] = I2CM_HSIOM_SPI_SEL;
            hsiomSel[I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_HSIOM_SPI_SEL;
            hsiomSel[I2CM_SCLK_PIN_INDEX]        = I2CM_HSIOM_SPI_SEL;

            if(I2CM_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[I2CM_MOSI_SCL_RX_PIN_INDEX] = I2CM_PIN_DM_DIG_HIZ;
                pinsDm[I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_PIN_DM_STRONG;
                pinsDm[I2CM_SCLK_PIN_INDEX]        = I2CM_PIN_DM_DIG_HIZ;

                #if(I2CM_SS0_PIN)
                    /* Only SS0 is valid choice for Slave */
                    hsiomSel[I2CM_SS0_PIN_INDEX] = I2CM_HSIOM_SPI_SEL;
                    pinsDm  [I2CM_SS0_PIN_INDEX] = I2CM_PIN_DM_DIG_HIZ;
                #endif /* (I2CM_SS1_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[I2CM_MOSI_SCL_RX_PIN_INDEX] = I2CM_PIN_DM_STRONG;
                pinsDm[I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_PIN_DM_DIG_HIZ;
                pinsDm[I2CM_SCLK_PIN_INDEX]        = I2CM_PIN_DM_STRONG;

                #if(I2CM_SS0_PIN)
                    hsiomSel[I2CM_SS0_PIN_INDEX] = I2CM_HSIOM_SPI_SEL;
                    pinsDm  [I2CM_SS0_PIN_INDEX] = I2CM_PIN_DM_STRONG;
                #endif /* (I2CM_SS0_PIN) */

                #if(I2CM_SS1_PIN)
                    hsiomSel[I2CM_SS1_PIN_INDEX] = I2CM_HSIOM_SPI_SEL;
                    pinsDm  [I2CM_SS1_PIN_INDEX] = I2CM_PIN_DM_STRONG;
                #endif /* (I2CM_SS1_PIN) */

                #if(I2CM_SS2_PIN)
                    hsiomSel[I2CM_SS2_PIN_INDEX] = I2CM_HSIOM_SPI_SEL;
                    pinsDm  [I2CM_SS2_PIN_INDEX] = I2CM_PIN_DM_STRONG;
                #endif /* (I2CM_SS2_PIN) */

                #if(I2CM_SS3_PIN)
                    hsiomSel[I2CM_SS3_PIN_INDEX] = I2CM_HSIOM_SPI_SEL;
                    pinsDm  [I2CM_SS3_PIN_INDEX] = I2CM_PIN_DM_STRONG;
                #endif /* (I2CM_SS2_PIN) */
            }
        }
        else /* UART */
        {
            if(I2CM_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_HSIOM_UART_SEL;
                pinsDm  [I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (I2CM_UART_RX & uartTxRx))
                {
                    hsiomSel[I2CM_MOSI_SCL_RX_PIN_INDEX] = I2CM_HSIOM_UART_SEL;
                    pinsDm  [I2CM_MOSI_SCL_RX_PIN_INDEX] = I2CM_PIN_DM_DIG_HIZ;
                }

                if(0u != (I2CM_UART_TX & uartTxRx))
                {
                    hsiomSel[I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_HSIOM_UART_SEL;
                    pinsDm  [I2CM_MISO_SDA_TX_PIN_INDEX] = I2CM_PIN_DM_STRONG;
                }
            }
        }

        /* Condfigure pins: set HSIOM and DM */
        /* Condfigure pins: DR registers configuration remains unchanged for cyfitter_cfg() */

        #if(I2CM_MOSI_SCL_RX_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_MOSI_SCL_RX_HSIOM_REG,
                                           I2CM_MOSI_SCL_RX_HSIOM_MASK,
                                           I2CM_MOSI_SCL_RX_HSIOM_POS,
                                           hsiomSel[I2CM_MOSI_SCL_RX_PIN_INDEX]);
        #endif /* (I2CM_MOSI_SCL_RX_PIN) */

        #if(I2CM_MOSI_SCL_RX_WAKE_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                           I2CM_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                           I2CM_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                           hsiomSel[I2CM_MOSI_SCL_RX_WAKE_PIN_INDEX]);
        #endif /* (I2CM_MOSI_SCL_RX_WAKE_PIN) */

        #if(I2CM_MISO_SDA_TX_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_MISO_SDA_TX_HSIOM_REG,
                                           I2CM_MISO_SDA_TX_HSIOM_MASK,
                                           I2CM_MISO_SDA_TX_HSIOM_POS,
                                           hsiomSel[I2CM_MISO_SDA_TX_PIN_INDEX]);
        #endif /* (I2CM_MOSI_SCL_RX_PIN) */

        #if(I2CM_SCLK_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_SCLK_HSIOM_REG, I2CM_SCLK_HSIOM_MASK,
                                           I2CM_SCLK_HSIOM_POS, hsiomSel[I2CM_SCLK_PIN_INDEX]);
        #endif /* (I2CM_SCLK_PIN) */

        #if(I2CM_SS0_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_SS0_HSIOM_REG, I2CM_SS0_HSIOM_MASK,
                                           I2CM_SS0_HSIOM_POS, hsiomSel[I2CM_SS0_PIN_INDEX]);
        #endif /* (I2CM_SS1_PIN) */

        #if(I2CM_SS1_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_SS1_HSIOM_REG, I2CM_SS1_HSIOM_MASK,
                                           I2CM_SS1_HSIOM_POS, hsiomSel[I2CM_SS1_PIN_INDEX]);
        #endif /* (I2CM_SS1_PIN) */

        #if(I2CM_SS2_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_SS2_HSIOM_REG, I2CM_SS2_HSIOM_MASK,
                                           I2CM_SS2_HSIOM_POS, hsiomSel[I2CM_SS2_PIN_INDEX]);
        #endif /* (I2CM_SS2_PIN) */

        #if(I2CM_SS3_PIN)
            I2CM_SET_HSIOM_SEL(I2CM_SS3_HSIOM_REG,  I2CM_SS3_HSIOM_MASK,
                                           I2CM_SS3_HSIOM_POS, hsiomSel[I2CM_SS3_PIN_INDEX]);
        #endif /* (I2CM_SS3_PIN) */



        #if(I2CM_MOSI_SCL_RX_PIN)
            I2CM_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8)
                                                                   pinsDm[I2CM_MOSI_SCL_RX_PIN_INDEX]);
        #endif /* (I2CM_MOSI_SCL_RX_PIN) */

        #if(I2CM_MOSI_SCL_RX_WAKE_PIN)
        I2CM_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                                   pinsDm[I2CM_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        /* Set interrupt on rising edge */
        I2CM_SET_INCFG_TYPE(I2CM_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                        I2CM_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                        I2CM_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                        I2CM_INTCFG_TYPE_FALLING_EDGE);

        #endif /* (I2CM_MOSI_SCL_RX_WAKE_PIN) */

        #if(I2CM_MISO_SDA_TX_PIN)
            I2CM_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8)
                                                                        pinsDm[I2CM_MISO_SDA_TX_PIN_INDEX]);
        #endif /* (I2CM_MOSI_SCL_RX_PIN) */

        #if(I2CM_SCLK_PIN)
            I2CM_spi_sclk_SetDriveMode((uint8) pinsDm[I2CM_SCLK_PIN_INDEX]);
        #endif /* (I2CM_SCLK_PIN) */

        #if(I2CM_SS0_PIN)
            I2CM_spi_ss0_SetDriveMode((uint8) pinsDm[I2CM_SS0_PIN_INDEX]);
        #endif /* (I2CM_SS0_PIN) */

        #if(I2CM_SS1_PIN)
            I2CM_spi_ss1_SetDriveMode((uint8) pinsDm[I2CM_SS1_PIN_INDEX]);
        #endif /* (I2CM_SS1_PIN) */

        #if(I2CM_SS2_PIN)
            I2CM_spi_ss2_SetDriveMode((uint8) pinsDm[I2CM_SS2_PIN_INDEX]);
        #endif /* (I2CM_SS2_PIN) */

        #if(I2CM_SS3_PIN)
            I2CM_spi_ss3_SetDriveMode((uint8) pinsDm[I2CM_SS3_PIN_INDEX]);
        #endif /* (I2CM_SS3_PIN) */
    }

#endif /* (I2CM_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
