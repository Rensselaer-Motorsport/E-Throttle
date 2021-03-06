.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* TILT_cy_m0s8_tcpwm_1 */
.set TILT_cy_m0s8_tcpwm_1__CC, CYREG_TCPWM_CNT1_CC
.set TILT_cy_m0s8_tcpwm_1__CC_BUFF, CYREG_TCPWM_CNT1_CC_BUFF
.set TILT_cy_m0s8_tcpwm_1__COUNTER, CYREG_TCPWM_CNT1_COUNTER
.set TILT_cy_m0s8_tcpwm_1__CTRL, CYREG_TCPWM_CNT1_CTRL
.set TILT_cy_m0s8_tcpwm_1__INTR, CYREG_TCPWM_CNT1_INTR
.set TILT_cy_m0s8_tcpwm_1__INTR_MASK, CYREG_TCPWM_CNT1_INTR_MASK
.set TILT_cy_m0s8_tcpwm_1__INTR_MASKED, CYREG_TCPWM_CNT1_INTR_MASKED
.set TILT_cy_m0s8_tcpwm_1__INTR_SET, CYREG_TCPWM_CNT1_INTR_SET
.set TILT_cy_m0s8_tcpwm_1__PERIOD, CYREG_TCPWM_CNT1_PERIOD
.set TILT_cy_m0s8_tcpwm_1__PERIOD_BUFF, CYREG_TCPWM_CNT1_PERIOD_BUFF
.set TILT_cy_m0s8_tcpwm_1__STATUS, CYREG_TCPWM_CNT1_STATUS
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMD, CYREG_TCPWM_CMD
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK, 0x02
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT, 1
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK, 0x200
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT, 9
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK, 0x2000000
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT, 25
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK, 0x20000
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT, 17
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CTRL, CYREG_TCPWM_CTRL
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK, 0x02
.set TILT_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT, 1
.set TILT_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE, CYREG_TCPWM_INTR_CAUSE
.set TILT_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK, 0x02
.set TILT_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT, 1
.set TILT_cy_m0s8_tcpwm_1__TCPWM_NUMBER, 1
.set TILT_cy_m0s8_tcpwm_1__TR_CTRL0, CYREG_TCPWM_CNT1_TR_CTRL0
.set TILT_cy_m0s8_tcpwm_1__TR_CTRL1, CYREG_TCPWM_CNT1_TR_CTRL1
.set TILT_cy_m0s8_tcpwm_1__TR_CTRL2, CYREG_TCPWM_CNT1_TR_CTRL2

/* PAN_cy_m0s8_tcpwm_1 */
.set PAN_cy_m0s8_tcpwm_1__CC, CYREG_TCPWM_CNT0_CC
.set PAN_cy_m0s8_tcpwm_1__CC_BUFF, CYREG_TCPWM_CNT0_CC_BUFF
.set PAN_cy_m0s8_tcpwm_1__COUNTER, CYREG_TCPWM_CNT0_COUNTER
.set PAN_cy_m0s8_tcpwm_1__CTRL, CYREG_TCPWM_CNT0_CTRL
.set PAN_cy_m0s8_tcpwm_1__INTR, CYREG_TCPWM_CNT0_INTR
.set PAN_cy_m0s8_tcpwm_1__INTR_MASK, CYREG_TCPWM_CNT0_INTR_MASK
.set PAN_cy_m0s8_tcpwm_1__INTR_MASKED, CYREG_TCPWM_CNT0_INTR_MASKED
.set PAN_cy_m0s8_tcpwm_1__INTR_SET, CYREG_TCPWM_CNT0_INTR_SET
.set PAN_cy_m0s8_tcpwm_1__PERIOD, CYREG_TCPWM_CNT0_PERIOD
.set PAN_cy_m0s8_tcpwm_1__PERIOD_BUFF, CYREG_TCPWM_CNT0_PERIOD_BUFF
.set PAN_cy_m0s8_tcpwm_1__STATUS, CYREG_TCPWM_CNT0_STATUS
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMD, CYREG_TCPWM_CMD
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK, 0x01
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT, 0
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK, 0x100
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT, 8
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK, 0x1000000
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT, 24
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK, 0x10000
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT, 16
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CTRL, CYREG_TCPWM_CTRL
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK, 0x01
.set PAN_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT, 0
.set PAN_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE, CYREG_TCPWM_INTR_CAUSE
.set PAN_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK, 0x01
.set PAN_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT, 0
.set PAN_cy_m0s8_tcpwm_1__TCPWM_NUMBER, 0
.set PAN_cy_m0s8_tcpwm_1__TR_CTRL0, CYREG_TCPWM_CNT0_TR_CTRL0
.set PAN_cy_m0s8_tcpwm_1__TR_CTRL1, CYREG_TCPWM_CNT0_TR_CTRL1
.set PAN_cy_m0s8_tcpwm_1__TR_CTRL2, CYREG_TCPWM_CNT0_TR_CTRL2

/* I2CM_SCB_IRQ */
.set I2CM_SCB_IRQ__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set I2CM_SCB_IRQ__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set I2CM_SCB_IRQ__INTC_MASK, 0x800
.set I2CM_SCB_IRQ__INTC_NUMBER, 11
.set I2CM_SCB_IRQ__INTC_PRIOR_MASK, 0xC0000000
.set I2CM_SCB_IRQ__INTC_PRIOR_NUM, 3
.set I2CM_SCB_IRQ__INTC_PRIOR_REG, CYREG_CM0_IPR2
.set I2CM_SCB_IRQ__INTC_SET_EN_REG, CYREG_CM0_ISER
.set I2CM_SCB_IRQ__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* I2CM_SCBCLK */
.set I2CM_SCBCLK__DIVIDER_MASK, 0x0000FFFF
.set I2CM_SCBCLK__ENABLE, CYREG_CLK_DIVIDER_A00
.set I2CM_SCBCLK__ENABLE_MASK, 0x80000000
.set I2CM_SCBCLK__MASK, 0x80000000
.set I2CM_SCBCLK__REGISTER, CYREG_CLK_DIVIDER_A00

/* I2CM_SCB */
.set I2CM_SCB__BIST_CONTROL, CYREG_SCB1_BIST_CONTROL
.set I2CM_SCB__BIST_DATA, CYREG_SCB1_BIST_DATA
.set I2CM_SCB__CTRL, CYREG_SCB1_CTRL
.set I2CM_SCB__EZ_DATA00, CYREG_SCB1_EZ_DATA00
.set I2CM_SCB__EZ_DATA01, CYREG_SCB1_EZ_DATA01
.set I2CM_SCB__EZ_DATA02, CYREG_SCB1_EZ_DATA02
.set I2CM_SCB__EZ_DATA03, CYREG_SCB1_EZ_DATA03
.set I2CM_SCB__EZ_DATA04, CYREG_SCB1_EZ_DATA04
.set I2CM_SCB__EZ_DATA05, CYREG_SCB1_EZ_DATA05
.set I2CM_SCB__EZ_DATA06, CYREG_SCB1_EZ_DATA06
.set I2CM_SCB__EZ_DATA07, CYREG_SCB1_EZ_DATA07
.set I2CM_SCB__EZ_DATA08, CYREG_SCB1_EZ_DATA08
.set I2CM_SCB__EZ_DATA09, CYREG_SCB1_EZ_DATA09
.set I2CM_SCB__EZ_DATA10, CYREG_SCB1_EZ_DATA10
.set I2CM_SCB__EZ_DATA11, CYREG_SCB1_EZ_DATA11
.set I2CM_SCB__EZ_DATA12, CYREG_SCB1_EZ_DATA12
.set I2CM_SCB__EZ_DATA13, CYREG_SCB1_EZ_DATA13
.set I2CM_SCB__EZ_DATA14, CYREG_SCB1_EZ_DATA14
.set I2CM_SCB__EZ_DATA15, CYREG_SCB1_EZ_DATA15
.set I2CM_SCB__EZ_DATA16, CYREG_SCB1_EZ_DATA16
.set I2CM_SCB__EZ_DATA17, CYREG_SCB1_EZ_DATA17
.set I2CM_SCB__EZ_DATA18, CYREG_SCB1_EZ_DATA18
.set I2CM_SCB__EZ_DATA19, CYREG_SCB1_EZ_DATA19
.set I2CM_SCB__EZ_DATA20, CYREG_SCB1_EZ_DATA20
.set I2CM_SCB__EZ_DATA21, CYREG_SCB1_EZ_DATA21
.set I2CM_SCB__EZ_DATA22, CYREG_SCB1_EZ_DATA22
.set I2CM_SCB__EZ_DATA23, CYREG_SCB1_EZ_DATA23
.set I2CM_SCB__EZ_DATA24, CYREG_SCB1_EZ_DATA24
.set I2CM_SCB__EZ_DATA25, CYREG_SCB1_EZ_DATA25
.set I2CM_SCB__EZ_DATA26, CYREG_SCB1_EZ_DATA26
.set I2CM_SCB__EZ_DATA27, CYREG_SCB1_EZ_DATA27
.set I2CM_SCB__EZ_DATA28, CYREG_SCB1_EZ_DATA28
.set I2CM_SCB__EZ_DATA29, CYREG_SCB1_EZ_DATA29
.set I2CM_SCB__EZ_DATA30, CYREG_SCB1_EZ_DATA30
.set I2CM_SCB__EZ_DATA31, CYREG_SCB1_EZ_DATA31
.set I2CM_SCB__I2C_CFG, CYREG_SCB1_I2C_CFG
.set I2CM_SCB__I2C_CTRL, CYREG_SCB1_I2C_CTRL
.set I2CM_SCB__I2C_M_CMD, CYREG_SCB1_I2C_M_CMD
.set I2CM_SCB__I2C_STATUS, CYREG_SCB1_I2C_STATUS
.set I2CM_SCB__I2C_S_CMD, CYREG_SCB1_I2C_S_CMD
.set I2CM_SCB__INTR_CAUSE, CYREG_SCB1_INTR_CAUSE
.set I2CM_SCB__INTR_I2C_EC, CYREG_SCB1_INTR_I2C_EC
.set I2CM_SCB__INTR_I2C_EC_MASK, CYREG_SCB1_INTR_I2C_EC_MASK
.set I2CM_SCB__INTR_I2C_EC_MASKED, CYREG_SCB1_INTR_I2C_EC_MASKED
.set I2CM_SCB__INTR_M, CYREG_SCB1_INTR_M
.set I2CM_SCB__INTR_M_MASK, CYREG_SCB1_INTR_M_MASK
.set I2CM_SCB__INTR_M_MASKED, CYREG_SCB1_INTR_M_MASKED
.set I2CM_SCB__INTR_M_SET, CYREG_SCB1_INTR_M_SET
.set I2CM_SCB__INTR_RX, CYREG_SCB1_INTR_RX
.set I2CM_SCB__INTR_RX_MASK, CYREG_SCB1_INTR_RX_MASK
.set I2CM_SCB__INTR_RX_MASKED, CYREG_SCB1_INTR_RX_MASKED
.set I2CM_SCB__INTR_RX_SET, CYREG_SCB1_INTR_RX_SET
.set I2CM_SCB__INTR_S, CYREG_SCB1_INTR_S
.set I2CM_SCB__INTR_SPI_EC, CYREG_SCB1_INTR_SPI_EC
.set I2CM_SCB__INTR_SPI_EC_MASK, CYREG_SCB1_INTR_SPI_EC_MASK
.set I2CM_SCB__INTR_SPI_EC_MASKED, CYREG_SCB1_INTR_SPI_EC_MASKED
.set I2CM_SCB__INTR_S_MASK, CYREG_SCB1_INTR_S_MASK
.set I2CM_SCB__INTR_S_MASKED, CYREG_SCB1_INTR_S_MASKED
.set I2CM_SCB__INTR_S_SET, CYREG_SCB1_INTR_S_SET
.set I2CM_SCB__INTR_TX, CYREG_SCB1_INTR_TX
.set I2CM_SCB__INTR_TX_MASK, CYREG_SCB1_INTR_TX_MASK
.set I2CM_SCB__INTR_TX_MASKED, CYREG_SCB1_INTR_TX_MASKED
.set I2CM_SCB__INTR_TX_SET, CYREG_SCB1_INTR_TX_SET
.set I2CM_SCB__RX_CTRL, CYREG_SCB1_RX_CTRL
.set I2CM_SCB__RX_FIFO_CTRL, CYREG_SCB1_RX_FIFO_CTRL
.set I2CM_SCB__RX_FIFO_RD, CYREG_SCB1_RX_FIFO_RD
.set I2CM_SCB__RX_FIFO_RD_SILENT, CYREG_SCB1_RX_FIFO_RD_SILENT
.set I2CM_SCB__RX_FIFO_STATUS, CYREG_SCB1_RX_FIFO_STATUS
.set I2CM_SCB__RX_MATCH, CYREG_SCB1_RX_MATCH
.set I2CM_SCB__SPI_CTRL, CYREG_SCB1_SPI_CTRL
.set I2CM_SCB__SPI_STATUS, CYREG_SCB1_SPI_STATUS
.set I2CM_SCB__STATUS, CYREG_SCB1_STATUS
.set I2CM_SCB__TX_CTRL, CYREG_SCB1_TX_CTRL
.set I2CM_SCB__TX_FIFO_CTRL, CYREG_SCB1_TX_FIFO_CTRL
.set I2CM_SCB__TX_FIFO_STATUS, CYREG_SCB1_TX_FIFO_STATUS
.set I2CM_SCB__TX_FIFO_WR, CYREG_SCB1_TX_FIFO_WR
.set I2CM_SCB__UART_CTRL, CYREG_SCB1_UART_CTRL
.set I2CM_SCB__UART_RX_CTRL, CYREG_SCB1_UART_RX_CTRL
.set I2CM_SCB__UART_RX_STATUS, CYREG_SCB1_UART_RX_STATUS
.set I2CM_SCB__UART_TX_CTRL, CYREG_SCB1_UART_TX_CTRL

/* I2CM_scl */
.set I2CM_scl__0__DM__MASK, 0x07
.set I2CM_scl__0__DM__SHIFT, 0
.set I2CM_scl__0__DR, CYREG_PRT3_DR
.set I2CM_scl__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set I2CM_scl__0__HSIOM_MASK, 0x0000000F
.set I2CM_scl__0__HSIOM_SHIFT, 0
.set I2CM_scl__0__INTCFG, CYREG_PRT3_INTCFG
.set I2CM_scl__0__INTSTAT, CYREG_PRT3_INTSTAT
.set I2CM_scl__0__MASK, 0x01
.set I2CM_scl__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set I2CM_scl__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set I2CM_scl__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set I2CM_scl__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set I2CM_scl__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set I2CM_scl__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set I2CM_scl__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set I2CM_scl__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set I2CM_scl__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set I2CM_scl__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set I2CM_scl__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set I2CM_scl__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set I2CM_scl__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set I2CM_scl__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set I2CM_scl__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set I2CM_scl__0__PC, CYREG_PRT3_PC
.set I2CM_scl__0__PC2, CYREG_PRT3_PC2
.set I2CM_scl__0__PORT, 3
.set I2CM_scl__0__PS, CYREG_PRT3_PS
.set I2CM_scl__0__SHIFT, 0
.set I2CM_scl__DR, CYREG_PRT3_DR
.set I2CM_scl__INTCFG, CYREG_PRT3_INTCFG
.set I2CM_scl__INTSTAT, CYREG_PRT3_INTSTAT
.set I2CM_scl__MASK, 0x01
.set I2CM_scl__PA__CFG0, CYREG_UDB_PA3_CFG0
.set I2CM_scl__PA__CFG1, CYREG_UDB_PA3_CFG1
.set I2CM_scl__PA__CFG10, CYREG_UDB_PA3_CFG10
.set I2CM_scl__PA__CFG11, CYREG_UDB_PA3_CFG11
.set I2CM_scl__PA__CFG12, CYREG_UDB_PA3_CFG12
.set I2CM_scl__PA__CFG13, CYREG_UDB_PA3_CFG13
.set I2CM_scl__PA__CFG14, CYREG_UDB_PA3_CFG14
.set I2CM_scl__PA__CFG2, CYREG_UDB_PA3_CFG2
.set I2CM_scl__PA__CFG3, CYREG_UDB_PA3_CFG3
.set I2CM_scl__PA__CFG4, CYREG_UDB_PA3_CFG4
.set I2CM_scl__PA__CFG5, CYREG_UDB_PA3_CFG5
.set I2CM_scl__PA__CFG6, CYREG_UDB_PA3_CFG6
.set I2CM_scl__PA__CFG7, CYREG_UDB_PA3_CFG7
.set I2CM_scl__PA__CFG8, CYREG_UDB_PA3_CFG8
.set I2CM_scl__PA__CFG9, CYREG_UDB_PA3_CFG9
.set I2CM_scl__PC, CYREG_PRT3_PC
.set I2CM_scl__PC2, CYREG_PRT3_PC2
.set I2CM_scl__PORT, 3
.set I2CM_scl__PS, CYREG_PRT3_PS
.set I2CM_scl__SHIFT, 0

/* I2CM_sda */
.set I2CM_sda__0__DM__MASK, 0x38
.set I2CM_sda__0__DM__SHIFT, 3
.set I2CM_sda__0__DR, CYREG_PRT3_DR
.set I2CM_sda__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set I2CM_sda__0__HSIOM_MASK, 0x000000F0
.set I2CM_sda__0__HSIOM_SHIFT, 4
.set I2CM_sda__0__INTCFG, CYREG_PRT3_INTCFG
.set I2CM_sda__0__INTSTAT, CYREG_PRT3_INTSTAT
.set I2CM_sda__0__MASK, 0x02
.set I2CM_sda__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set I2CM_sda__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set I2CM_sda__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set I2CM_sda__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set I2CM_sda__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set I2CM_sda__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set I2CM_sda__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set I2CM_sda__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set I2CM_sda__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set I2CM_sda__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set I2CM_sda__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set I2CM_sda__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set I2CM_sda__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set I2CM_sda__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set I2CM_sda__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set I2CM_sda__0__PC, CYREG_PRT3_PC
.set I2CM_sda__0__PC2, CYREG_PRT3_PC2
.set I2CM_sda__0__PORT, 3
.set I2CM_sda__0__PS, CYREG_PRT3_PS
.set I2CM_sda__0__SHIFT, 1
.set I2CM_sda__DR, CYREG_PRT3_DR
.set I2CM_sda__INTCFG, CYREG_PRT3_INTCFG
.set I2CM_sda__INTSTAT, CYREG_PRT3_INTSTAT
.set I2CM_sda__MASK, 0x02
.set I2CM_sda__PA__CFG0, CYREG_UDB_PA3_CFG0
.set I2CM_sda__PA__CFG1, CYREG_UDB_PA3_CFG1
.set I2CM_sda__PA__CFG10, CYREG_UDB_PA3_CFG10
.set I2CM_sda__PA__CFG11, CYREG_UDB_PA3_CFG11
.set I2CM_sda__PA__CFG12, CYREG_UDB_PA3_CFG12
.set I2CM_sda__PA__CFG13, CYREG_UDB_PA3_CFG13
.set I2CM_sda__PA__CFG14, CYREG_UDB_PA3_CFG14
.set I2CM_sda__PA__CFG2, CYREG_UDB_PA3_CFG2
.set I2CM_sda__PA__CFG3, CYREG_UDB_PA3_CFG3
.set I2CM_sda__PA__CFG4, CYREG_UDB_PA3_CFG4
.set I2CM_sda__PA__CFG5, CYREG_UDB_PA3_CFG5
.set I2CM_sda__PA__CFG6, CYREG_UDB_PA3_CFG6
.set I2CM_sda__PA__CFG7, CYREG_UDB_PA3_CFG7
.set I2CM_sda__PA__CFG8, CYREG_UDB_PA3_CFG8
.set I2CM_sda__PA__CFG9, CYREG_UDB_PA3_CFG9
.set I2CM_sda__PC, CYREG_PRT3_PC
.set I2CM_sda__PC2, CYREG_PRT3_PC2
.set I2CM_sda__PORT, 3
.set I2CM_sda__PS, CYREG_PRT3_PS
.set I2CM_sda__SHIFT, 1

/* TILT_O */
.set TILT_O__0__DM__MASK, 0x07
.set TILT_O__0__DM__SHIFT, 0
.set TILT_O__0__DR, CYREG_PRT1_DR
.set TILT_O__0__HSIOM, CYREG_HSIOM_PORT_SEL1
.set TILT_O__0__HSIOM_MASK, 0x0000000F
.set TILT_O__0__HSIOM_SHIFT, 0
.set TILT_O__0__INTCFG, CYREG_PRT1_INTCFG
.set TILT_O__0__INTSTAT, CYREG_PRT1_INTSTAT
.set TILT_O__0__MASK, 0x01
.set TILT_O__0__OUT_SEL, CYREG_UDB_PA1_CFG10
.set TILT_O__0__OUT_SEL_SHIFT, 0
.set TILT_O__0__OUT_SEL_VAL, 3
.set TILT_O__0__PA__CFG0, CYREG_UDB_PA1_CFG0
.set TILT_O__0__PA__CFG1, CYREG_UDB_PA1_CFG1
.set TILT_O__0__PA__CFG10, CYREG_UDB_PA1_CFG10
.set TILT_O__0__PA__CFG11, CYREG_UDB_PA1_CFG11
.set TILT_O__0__PA__CFG12, CYREG_UDB_PA1_CFG12
.set TILT_O__0__PA__CFG13, CYREG_UDB_PA1_CFG13
.set TILT_O__0__PA__CFG14, CYREG_UDB_PA1_CFG14
.set TILT_O__0__PA__CFG2, CYREG_UDB_PA1_CFG2
.set TILT_O__0__PA__CFG3, CYREG_UDB_PA1_CFG3
.set TILT_O__0__PA__CFG4, CYREG_UDB_PA1_CFG4
.set TILT_O__0__PA__CFG5, CYREG_UDB_PA1_CFG5
.set TILT_O__0__PA__CFG6, CYREG_UDB_PA1_CFG6
.set TILT_O__0__PA__CFG7, CYREG_UDB_PA1_CFG7
.set TILT_O__0__PA__CFG8, CYREG_UDB_PA1_CFG8
.set TILT_O__0__PA__CFG9, CYREG_UDB_PA1_CFG9
.set TILT_O__0__PC, CYREG_PRT1_PC
.set TILT_O__0__PC2, CYREG_PRT1_PC2
.set TILT_O__0__PORT, 1
.set TILT_O__0__PS, CYREG_PRT1_PS
.set TILT_O__0__SHIFT, 0
.set TILT_O__DR, CYREG_PRT1_DR
.set TILT_O__INTCFG, CYREG_PRT1_INTCFG
.set TILT_O__INTSTAT, CYREG_PRT1_INTSTAT
.set TILT_O__MASK, 0x01
.set TILT_O__PA__CFG0, CYREG_UDB_PA1_CFG0
.set TILT_O__PA__CFG1, CYREG_UDB_PA1_CFG1
.set TILT_O__PA__CFG10, CYREG_UDB_PA1_CFG10
.set TILT_O__PA__CFG11, CYREG_UDB_PA1_CFG11
.set TILT_O__PA__CFG12, CYREG_UDB_PA1_CFG12
.set TILT_O__PA__CFG13, CYREG_UDB_PA1_CFG13
.set TILT_O__PA__CFG14, CYREG_UDB_PA1_CFG14
.set TILT_O__PA__CFG2, CYREG_UDB_PA1_CFG2
.set TILT_O__PA__CFG3, CYREG_UDB_PA1_CFG3
.set TILT_O__PA__CFG4, CYREG_UDB_PA1_CFG4
.set TILT_O__PA__CFG5, CYREG_UDB_PA1_CFG5
.set TILT_O__PA__CFG6, CYREG_UDB_PA1_CFG6
.set TILT_O__PA__CFG7, CYREG_UDB_PA1_CFG7
.set TILT_O__PA__CFG8, CYREG_UDB_PA1_CFG8
.set TILT_O__PA__CFG9, CYREG_UDB_PA1_CFG9
.set TILT_O__PC, CYREG_PRT1_PC
.set TILT_O__PC2, CYREG_PRT1_PC2
.set TILT_O__PORT, 1
.set TILT_O__PS, CYREG_PRT1_PS
.set TILT_O__SHIFT, 0

/* CLOCK */
.set CLOCK__0__DM__MASK, 0xE00000
.set CLOCK__0__DM__SHIFT, 21
.set CLOCK__0__DR, CYREG_PRT2_DR
.set CLOCK__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set CLOCK__0__HSIOM_MASK, 0xF0000000
.set CLOCK__0__HSIOM_SHIFT, 28
.set CLOCK__0__INTCFG, CYREG_PRT2_INTCFG
.set CLOCK__0__INTSTAT, CYREG_PRT2_INTSTAT
.set CLOCK__0__MASK, 0x80
.set CLOCK__0__OUT_SEL, CYREG_UDB_PA2_CFG10
.set CLOCK__0__OUT_SEL_SHIFT, 14
.set CLOCK__0__OUT_SEL_VAL, 2
.set CLOCK__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set CLOCK__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set CLOCK__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set CLOCK__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set CLOCK__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set CLOCK__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set CLOCK__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set CLOCK__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set CLOCK__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set CLOCK__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set CLOCK__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set CLOCK__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set CLOCK__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set CLOCK__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set CLOCK__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set CLOCK__0__PC, CYREG_PRT2_PC
.set CLOCK__0__PC2, CYREG_PRT2_PC2
.set CLOCK__0__PORT, 2
.set CLOCK__0__PS, CYREG_PRT2_PS
.set CLOCK__0__SHIFT, 7
.set CLOCK__DR, CYREG_PRT2_DR
.set CLOCK__INTCFG, CYREG_PRT2_INTCFG
.set CLOCK__INTSTAT, CYREG_PRT2_INTSTAT
.set CLOCK__MASK, 0x80
.set CLOCK__PA__CFG0, CYREG_UDB_PA2_CFG0
.set CLOCK__PA__CFG1, CYREG_UDB_PA2_CFG1
.set CLOCK__PA__CFG10, CYREG_UDB_PA2_CFG10
.set CLOCK__PA__CFG11, CYREG_UDB_PA2_CFG11
.set CLOCK__PA__CFG12, CYREG_UDB_PA2_CFG12
.set CLOCK__PA__CFG13, CYREG_UDB_PA2_CFG13
.set CLOCK__PA__CFG14, CYREG_UDB_PA2_CFG14
.set CLOCK__PA__CFG2, CYREG_UDB_PA2_CFG2
.set CLOCK__PA__CFG3, CYREG_UDB_PA2_CFG3
.set CLOCK__PA__CFG4, CYREG_UDB_PA2_CFG4
.set CLOCK__PA__CFG5, CYREG_UDB_PA2_CFG5
.set CLOCK__PA__CFG6, CYREG_UDB_PA2_CFG6
.set CLOCK__PA__CFG7, CYREG_UDB_PA2_CFG7
.set CLOCK__PA__CFG8, CYREG_UDB_PA2_CFG8
.set CLOCK__PA__CFG9, CYREG_UDB_PA2_CFG9
.set CLOCK__PC, CYREG_PRT2_PC
.set CLOCK__PC2, CYREG_PRT2_PC2
.set CLOCK__PORT, 2
.set CLOCK__PS, CYREG_PRT2_PS
.set CLOCK__SHIFT, 7

/* PAN_O */
.set PAN_O__0__DM__MASK, 0x7000
.set PAN_O__0__DM__SHIFT, 12
.set PAN_O__0__DR, CYREG_PRT2_DR
.set PAN_O__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set PAN_O__0__HSIOM_MASK, 0x000F0000
.set PAN_O__0__HSIOM_SHIFT, 16
.set PAN_O__0__INTCFG, CYREG_PRT2_INTCFG
.set PAN_O__0__INTSTAT, CYREG_PRT2_INTSTAT
.set PAN_O__0__MASK, 0x10
.set PAN_O__0__OUT_SEL, CYREG_UDB_PA2_CFG10
.set PAN_O__0__OUT_SEL_SHIFT, 8
.set PAN_O__0__OUT_SEL_VAL, -1
.set PAN_O__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set PAN_O__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set PAN_O__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set PAN_O__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set PAN_O__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set PAN_O__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set PAN_O__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set PAN_O__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set PAN_O__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set PAN_O__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set PAN_O__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set PAN_O__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set PAN_O__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set PAN_O__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set PAN_O__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set PAN_O__0__PC, CYREG_PRT2_PC
.set PAN_O__0__PC2, CYREG_PRT2_PC2
.set PAN_O__0__PORT, 2
.set PAN_O__0__PS, CYREG_PRT2_PS
.set PAN_O__0__SHIFT, 4
.set PAN_O__DR, CYREG_PRT2_DR
.set PAN_O__INTCFG, CYREG_PRT2_INTCFG
.set PAN_O__INTSTAT, CYREG_PRT2_INTSTAT
.set PAN_O__MASK, 0x10
.set PAN_O__PA__CFG0, CYREG_UDB_PA2_CFG0
.set PAN_O__PA__CFG1, CYREG_UDB_PA2_CFG1
.set PAN_O__PA__CFG10, CYREG_UDB_PA2_CFG10
.set PAN_O__PA__CFG11, CYREG_UDB_PA2_CFG11
.set PAN_O__PA__CFG12, CYREG_UDB_PA2_CFG12
.set PAN_O__PA__CFG13, CYREG_UDB_PA2_CFG13
.set PAN_O__PA__CFG14, CYREG_UDB_PA2_CFG14
.set PAN_O__PA__CFG2, CYREG_UDB_PA2_CFG2
.set PAN_O__PA__CFG3, CYREG_UDB_PA2_CFG3
.set PAN_O__PA__CFG4, CYREG_UDB_PA2_CFG4
.set PAN_O__PA__CFG5, CYREG_UDB_PA2_CFG5
.set PAN_O__PA__CFG6, CYREG_UDB_PA2_CFG6
.set PAN_O__PA__CFG7, CYREG_UDB_PA2_CFG7
.set PAN_O__PA__CFG8, CYREG_UDB_PA2_CFG8
.set PAN_O__PA__CFG9, CYREG_UDB_PA2_CFG9
.set PAN_O__PC, CYREG_PRT2_PC
.set PAN_O__PC2, CYREG_PRT2_PC2
.set PAN_O__PORT, 2
.set PAN_O__PS, CYREG_PRT2_PS
.set PAN_O__SHIFT, 4

/* RESET */
.set RESET__0__DM__MASK, 0xE00
.set RESET__0__DM__SHIFT, 9
.set RESET__0__DR, CYREG_PRT1_DR
.set RESET__0__HSIOM, CYREG_HSIOM_PORT_SEL1
.set RESET__0__HSIOM_MASK, 0x0000F000
.set RESET__0__HSIOM_SHIFT, 12
.set RESET__0__INTCFG, CYREG_PRT1_INTCFG
.set RESET__0__INTSTAT, CYREG_PRT1_INTSTAT
.set RESET__0__MASK, 0x08
.set RESET__0__PA__CFG0, CYREG_UDB_PA1_CFG0
.set RESET__0__PA__CFG1, CYREG_UDB_PA1_CFG1
.set RESET__0__PA__CFG10, CYREG_UDB_PA1_CFG10
.set RESET__0__PA__CFG11, CYREG_UDB_PA1_CFG11
.set RESET__0__PA__CFG12, CYREG_UDB_PA1_CFG12
.set RESET__0__PA__CFG13, CYREG_UDB_PA1_CFG13
.set RESET__0__PA__CFG14, CYREG_UDB_PA1_CFG14
.set RESET__0__PA__CFG2, CYREG_UDB_PA1_CFG2
.set RESET__0__PA__CFG3, CYREG_UDB_PA1_CFG3
.set RESET__0__PA__CFG4, CYREG_UDB_PA1_CFG4
.set RESET__0__PA__CFG5, CYREG_UDB_PA1_CFG5
.set RESET__0__PA__CFG6, CYREG_UDB_PA1_CFG6
.set RESET__0__PA__CFG7, CYREG_UDB_PA1_CFG7
.set RESET__0__PA__CFG8, CYREG_UDB_PA1_CFG8
.set RESET__0__PA__CFG9, CYREG_UDB_PA1_CFG9
.set RESET__0__PC, CYREG_PRT1_PC
.set RESET__0__PC2, CYREG_PRT1_PC2
.set RESET__0__PORT, 1
.set RESET__0__PS, CYREG_PRT1_PS
.set RESET__0__SHIFT, 3
.set RESET__DR, CYREG_PRT1_DR
.set RESET__INTCFG, CYREG_PRT1_INTCFG
.set RESET__INTSTAT, CYREG_PRT1_INTSTAT
.set RESET__MASK, 0x08
.set RESET__PA__CFG0, CYREG_UDB_PA1_CFG0
.set RESET__PA__CFG1, CYREG_UDB_PA1_CFG1
.set RESET__PA__CFG10, CYREG_UDB_PA1_CFG10
.set RESET__PA__CFG11, CYREG_UDB_PA1_CFG11
.set RESET__PA__CFG12, CYREG_UDB_PA1_CFG12
.set RESET__PA__CFG13, CYREG_UDB_PA1_CFG13
.set RESET__PA__CFG14, CYREG_UDB_PA1_CFG14
.set RESET__PA__CFG2, CYREG_UDB_PA1_CFG2
.set RESET__PA__CFG3, CYREG_UDB_PA1_CFG3
.set RESET__PA__CFG4, CYREG_UDB_PA1_CFG4
.set RESET__PA__CFG5, CYREG_UDB_PA1_CFG5
.set RESET__PA__CFG6, CYREG_UDB_PA1_CFG6
.set RESET__PA__CFG7, CYREG_UDB_PA1_CFG7
.set RESET__PA__CFG8, CYREG_UDB_PA1_CFG8
.set RESET__PA__CFG9, CYREG_UDB_PA1_CFG9
.set RESET__PC, CYREG_PRT1_PC
.set RESET__PC2, CYREG_PRT1_PC2
.set RESET__PORT, 1
.set RESET__PS, CYREG_PRT1_PS
.set RESET__SHIFT, 3

/* H100 */
.set H100__DIVIDER_MASK, 0x0000FFFF
.set H100__ENABLE, CYREG_CLK_DIVIDER_B00
.set H100__ENABLE_MASK, 0x80000000
.set H100__MASK, 0x80000000
.set H100__REGISTER, CYREG_CLK_DIVIDER_B00

/* Miscellaneous */
/* -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release */
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_MEMBER_4A, 2
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_DIE_PSOC4A, 2
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_DIE_PSOC4A
.set CYDEV_BCLK__HFCLK__HZ, 48000000
.set CYDEV_BCLK__HFCLK__KHZ, 48000
.set CYDEV_BCLK__HFCLK__MHZ, 48
.set CYDEV_BCLK__SYSCLK__HZ, 48000000
.set CYDEV_BCLK__SYSCLK__KHZ, 48000
.set CYDEV_BCLK__SYSCLK__MHZ, 48
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 3
.set CYDEV_CHIP_DIE_PSOC5LP, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 4
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REV_PSOC4A_PRODUCTION
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_HEAP_SIZE, 0x0100
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0400
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
