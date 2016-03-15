/*******************************************************************************
* File Name: I2CM_PINS.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_I2CM_H)
#define CY_SCB_PINS_I2CM_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define I2CM_REMOVE_UART_RX_WAKE_PIN        (1u)
#define I2CM_REMOVE_MOSI_SCL_RX_WAKE_PIN    (1u)
#define I2CM_REMOVE_MOSI_SCL_RX_PIN         (1u)
#define I2CM_REMOVE_MISO_SDA_TX_PIN         (1u)
#define I2CM_REMOVE_SCLK_PIN                (1u)
#define I2CM_REMOVE_SS0_PIN                 (1u)
#define I2CM_REMOVE_SS1_PIN                 (1u)
#define I2CM_REMOVE_SS2_PIN                 (1u)
#define I2CM_REMOVE_SS3_PIN                 (1u)
#define I2CM_REMOVE_I2C_PINS                (0u)
#define I2CM_REMOVE_SPI_SLAVE_PINS          (1u)

#define I2CM_UART_RX_WAKE_PIN       (0u == I2CM_REMOVE_UART_RX_WAKE_PIN)
#define I2CM_MOSI_SCL_RX_WAKE_PIN   (0u == I2CM_REMOVE_MOSI_SCL_RX_WAKE_PIN)
#define I2CM_MOSI_SCL_RX_PIN        (0u == I2CM_REMOVE_MOSI_SCL_RX_PIN)
#define I2CM_MISO_SDA_TX_PIN        (0u == I2CM_REMOVE_MISO_SDA_TX_PIN)
#define I2CM_SCLK_PIN               (0u == I2CM_REMOVE_SCLK_PIN)
#define I2CM_SS0_PIN                (0u == I2CM_REMOVE_SS0_PIN)
#define I2CM_SS1_PIN                (0u == I2CM_REMOVE_SS1_PIN)
#define I2CM_SS2_PIN                (0u == I2CM_REMOVE_SS2_PIN)
#define I2CM_SS3_PIN                (0u == I2CM_REMOVE_SS3_PIN)
#define I2CM_I2C_PINS               (0u == I2CM_REMOVE_I2C_PINS)
#define I2CM_SPI_SLAVE_PINS         (0u == I2CM_REMOVE_SPI_SLAVE_PINS)


/***************************************
*             Includes
****************************************/

#if(I2CM_UART_RX_WAKE_PIN)
    #include "I2CM_rx_wake.h"
#endif /* (I2CM_UART_RX_WAKE_PIN) */

#if(I2CM_MOSI_SCL_RX_WAKE_PIN)
    #include "I2CM_spi_mosi_i2c_scl_uart_rx_wake.h"
#endif /* (I2CM_MOSI_SCL_RX_WAKE_PIN) */

#if(I2CM_MOSI_SCL_RX_PIN)
    #include "I2CM_spi_mosi_i2c_scl_uart_rx.h"
#endif /* (I2CM_MOSI_SCL_RX_PIN) */

#if(I2CM_MISO_SDA_TX_PIN)
    #include "I2CM_spi_miso_i2c_sda_uart_tx.h"
#endif /* (I2CM_MISO_SDA_TX_PIN_PIN) */

#if(I2CM_SCLK_PIN)
    #include "I2CM_spi_sclk.h"
#endif /* (I2CM_SCLK_PIN) */

#if(I2CM_SS0_PIN)
    #include "I2CM_spi_ss0.h"
#endif /* (I2CM_SS1_PIN) */

#if(I2CM_SS1_PIN)
    #include "I2CM_spi_ss1.h"
#endif /* (I2CM_SS1_PIN) */

#if(I2CM_SS2_PIN)
    #include "I2CM_spi_ss2.h"
#endif /* (I2CM_SS2_PIN) */

#if(I2CM_SS3_PIN)
    #include "I2CM_spi_ss3.h"
#endif /* (I2CM_SS3_PIN) */

#if(I2CM_I2C_PINS)
    #include "I2CM_scl.h"
    #include "I2CM_sda.h"
#endif /* (I2CM_I2C_PINS) */


/***************************************
*              Registers
***************************************/

#if(I2CM_MOSI_SCL_RX_WAKE_PIN)
    #define I2CM_MOSI_SCL_RX_WAKE_HSIOM_REG  \
                                                (*(reg32 *) I2CM_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define I2CM_MOSI_SCL_RX_WAKE_HSIOM_PTR  \
                                                ( (reg32 *) I2CM_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define I2CM_MOSI_SCL_RX_WAKE_HSIOM_MASK \
                                                (I2CM_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_MASK)
    #define I2CM_MOSI_SCL_RX_WAKE_HSIOM_POS  \
                                                (I2CM_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_SHIFT)

    #define I2CM_MOSI_SCL_RX_WAKE_INTCFG_REG    (*(reg32 *) \
                                                              I2CM_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)
    #define I2CM_MOSI_SCL_RX_WAKE_INTCFG_PTR    ( (reg32 *) \
                                                              I2CM_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)

    #define I2CM_INTCFG_TYPE_MASK                  (0x03u)
    #define I2CM_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS  (I2CM_spi_mosi_i2c_scl_uart_rx_wake__SHIFT)
    #define I2CM_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK ((uint32)                                           \
                                                                    ((uint32) I2CM_INTCFG_TYPE_MASK << \
                                                                    I2CM_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS))
#endif /* (I2CM_MOSI_SCL_RX_WAKE_PIN) */

#if(I2CM_MOSI_SCL_RX_PIN)
    #define I2CM_MOSI_SCL_RX_HSIOM_REG      (*(reg32 *) I2CM_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define I2CM_MOSI_SCL_RX_HSIOM_PTR      ( (reg32 *) I2CM_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define I2CM_MOSI_SCL_RX_HSIOM_MASK     (I2CM_spi_mosi_i2c_scl_uart_rx__0__HSIOM_MASK)
    #define I2CM_MOSI_SCL_RX_HSIOM_POS      (I2CM_spi_mosi_i2c_scl_uart_rx__0__HSIOM_SHIFT)
#endif /* (I2CM_MOSI_SCL_RX_PIN) */

#if(I2CM_MISO_SDA_TX_PIN)
    #define I2CM_MISO_SDA_TX_HSIOM_REG      (*(reg32 *) I2CM_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define I2CM_MISO_SDA_TX_HSIOM_PTR      ( (reg32 *) I2CM_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define I2CM_MISO_SDA_TX_HSIOM_MASK     (I2CM_spi_miso_i2c_sda_uart_tx__0__HSIOM_MASK)
    #define I2CM_MISO_SDA_TX_HSIOM_POS      (I2CM_spi_miso_i2c_sda_uart_tx__0__HSIOM_SHIFT)
#endif /* (I2CM_MISO_SDA_TX_PIN_PIN) */

#if(I2CM_SCLK_PIN)
    #define I2CM_SCLK_HSIOM_REG     (*(reg32 *) I2CM_spi_sclk__0__HSIOM)
    #define I2CM_SCLK_HSIOM_PTR     ( (reg32 *) I2CM_spi_sclk__0__HSIOM)
    #define I2CM_SCLK_HSIOM_MASK    (I2CM_spi_sclk__0__HSIOM_MASK)
    #define I2CM_SCLK_HSIOM_POS     (I2CM_spi_sclk__0__HSIOM_SHIFT)
#endif /* (I2CM_SCLK_PIN) */

#if(I2CM_SS0_PIN)
    #define I2CM_SS0_HSIOM_REG      (*(reg32 *) I2CM_spi_ss0__0__HSIOM)
    #define I2CM_SS0_HSIOM_PTR      ( (reg32 *) I2CM_spi_ss0__0__HSIOM)
    #define I2CM_SS0_HSIOM_MASK     (I2CM_spi_ss0__0__HSIOM_MASK)
    #define I2CM_SS0_HSIOM_POS      (I2CM_spi_ss0__0__HSIOM_SHIFT)
#endif /* (I2CM_SS1_PIN) */

#if(I2CM_SS1_PIN)
    #define I2CM_SS1_HSIOM_REG      (*(reg32 *) I2CM_spi_ss1__0__HSIOM)
    #define I2CM_SS1_HSIOM_PTR      ( (reg32 *) I2CM_spi_ss1__0__HSIOM)
    #define I2CM_SS1_HSIOM_MASK     (I2CM_spi_ss1__0__HSIOM_MASK)
    #define I2CM_SS1_HSIOM_POS      (I2CM_spi_ss1__0__HSIOM_SHIFT)
#endif /* (I2CM_SS1_PIN) */

#if(I2CM_SS2_PIN)
    #define I2CM_SS2_HSIOM_REG     (*(reg32 *) I2CM_spi_ss2__0__HSIOM)
    #define I2CM_SS2_HSIOM_PTR     ( (reg32 *) I2CM_spi_ss2__0__HSIOM)
    #define I2CM_SS2_HSIOM_MASK    (I2CM_spi_ss2__0__HSIOM_MASK)
    #define I2CM_SS2_HSIOM_POS     (I2CM_spi_ss2__0__HSIOM_SHIFT)
#endif /* (I2CM_SS2_PIN) */

#if(I2CM_SS3_PIN)
    #define I2CM_SS3_HSIOM_REG     (*(reg32 *) I2CM_spi_ss3__0__HSIOM)
    #define I2CM_SS3_HSIOM_PTR     ( (reg32 *) I2CM_spi_ss3__0__HSIOM)
    #define I2CM_SS3_HSIOM_MASK    (I2CM_spi_ss3__0__HSIOM_MASK)
    #define I2CM_SS3_HSIOM_POS     (I2CM_spi_ss3__0__HSIOM_SHIFT)
#endif /* (I2CM_SS3_PIN) */

#if(I2CM_I2C_PINS)
    #define I2CM_SCL_HSIOM_REG     (*(reg32 *) I2CM_scl__0__HSIOM)
    #define I2CM_SCL_HSIOM_PTR     ( (reg32 *) I2CM_scl__0__HSIOM)
    #define I2CM_SCL_HSIOM_MASK    (I2CM_scl__0__HSIOM_MASK)
    #define I2CM_SCL_HSIOM_POS     (I2CM_scl__0__HSIOM_SHIFT)
    
    #define I2CM_SDA_HSIOM_REG     (*(reg32 *) I2CM_sda__0__HSIOM)
    #define I2CM_SDA_HSIOM_PTR     ( (reg32 *) I2CM_sda__0__HSIOM)
    #define I2CM_SDA_HSIOM_MASK    (I2CM_sda__0__HSIOM_MASK)
    #define I2CM_SDA_HSIOM_POS     (I2CM_sda__0__HSIOM_SHIFT)
#endif /* (I2CM_I2C_PINS) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constanst */
#define I2CM_HSIOM_DEF_SEL      (0x00u)
#define I2CM_HSIOM_GPIO_SEL     (0x00u)
#define I2CM_HSIOM_UART_SEL     (0x09u)
#define I2CM_HSIOM_I2C_SEL      (0x0Eu)
#define I2CM_HSIOM_SPI_SEL      (0x0Fu)

#define I2CM_SCB_PINS_NUMBER            (7u)
#define I2CM_MOSI_SCL_RX_PIN_INDEX      (0u) /* RX pins without interrupt */
#define I2CM_MOSI_SCL_RX_WAKE_PIN_INDEX (0u) /* RX pin with interrupt     */
#define I2CM_MISO_SDA_TX_PIN_INDEX      (1u)
#define I2CM_SCLK_PIN_INDEX             (2u)
#define I2CM_SS0_PIN_INDEX              (3u)
#define I2CM_SS1_PIN_INDEX              (4u)
#define I2CM_SS2_PIN_INDEX              (5u)
#define I2CM_SS3_PIN_INDEX              (6u)

#define I2CM_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin DM defines */
#define I2CM_PIN_DM_ALG_HIZ  (0u)
#define I2CM_PIN_DM_DIG_HIZ  (1u)
#define I2CM_PIN_DM_OD_LO    (4u)
#define I2CM_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

#define I2CM_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        /* Sets new bits-mask */                 \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

#define I2CM_SET_HSIOM_SEL(reg, mask, pos, sel) I2CM_SET_REGISTER_BITS(reg, mask, pos, sel)
#define I2CM_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        I2CM_SET_REGISTER_BITS(reg, mask, pos, intType)


/* I2CM_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  I2CM_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* Unconfigured SCB: scl singnal */
#if(I2CM_MOSI_SCL_RX_WAKE_PIN)
    #define I2CM_SET_I2C_SCL_DR(val) \
                            I2CM_spi_mosi_i2c_scl_uart_rx_wake_Write(val)

    #define I2CM_SET_I2C_SCL_HSIOM_SEL(sel) \
                    I2CM_SET_HSIOM_SEL(I2CM_MOSI_SCL_RX_WAKE_HSIOM_REG,  \
                                                   I2CM_MOSI_SCL_RX_WAKE_HSIOM_MASK, \
                                                   I2CM_MOSI_SCL_RX_WAKE_HSIOM_POS,  \
                                                   (sel))

#elif(I2CM_MOSI_SCL_RX_PIN)
    #define I2CM_SET_I2C_SCL_DR(val) \
                            I2CM_spi_mosi_i2c_scl_uart_rx_Write(val)
                            

    #define I2CM_SET_I2C_SCL_HSIOM_SEL(sel) \
                            I2CM_SET_HSIOM_SEL(I2CM_MOSI_SCL_RX_HSIOM_REG,  \
                                                           I2CM_MOSI_SCL_RX_HSIOM_MASK, \
                                                           I2CM_MOSI_SCL_RX_HSIOM_POS,  \
                                                           (sel))
#else
    #if(!I2CM_I2C_PINS)
        #define I2CM_SET_I2C_SCL_DR(val) \
                                                 do{ ; }while(0)
        #define I2CM_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                        do{ ; }while(0)
        
    #endif /* (!I2CM_I2C_PINS) */
#endif /* (I2CM_MOSI_SCL_RX_PIN) */

/* SCB I2C: scl singal */
#if(I2CM_I2C_PINS)
    #define I2CM_SET_I2C_SCL_DR(val) I2CM_scl_Write(val)
    
    #define I2CM_SET_I2C_SCL_HSIOM_SEL(sel) \
                          I2CM_SET_HSIOM_SEL(I2CM_SCL_HSIOM_REG,  \
                                                         I2CM_SCL_HSIOM_MASK, \
                                                         I2CM_SCL_HSIOM_POS,  \
                                                         (sel))
    
#endif /* (I2CM_I2C_PINS) */


#endif /* (CY_SCB_PINS_I2CM_H) */


/* [] END OF FILE */
