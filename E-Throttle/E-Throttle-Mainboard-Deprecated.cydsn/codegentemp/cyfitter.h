#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* TPS_0 */
#define TPS_0__0__MASK 0x08u
#define TPS_0__0__PC CYREG_PRT3_PC3
#define TPS_0__0__PORT 3u
#define TPS_0__0__SHIFT 3
#define TPS_0__AG CYREG_PRT3_AG
#define TPS_0__AMUX CYREG_PRT3_AMUX
#define TPS_0__BIE CYREG_PRT3_BIE
#define TPS_0__BIT_MASK CYREG_PRT3_BIT_MASK
#define TPS_0__BYP CYREG_PRT3_BYP
#define TPS_0__CTL CYREG_PRT3_CTL
#define TPS_0__DM0 CYREG_PRT3_DM0
#define TPS_0__DM1 CYREG_PRT3_DM1
#define TPS_0__DM2 CYREG_PRT3_DM2
#define TPS_0__DR CYREG_PRT3_DR
#define TPS_0__INP_DIS CYREG_PRT3_INP_DIS
#define TPS_0__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define TPS_0__LCD_EN CYREG_PRT3_LCD_EN
#define TPS_0__MASK 0x08u
#define TPS_0__PORT 3u
#define TPS_0__PRT CYREG_PRT3_PRT
#define TPS_0__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define TPS_0__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define TPS_0__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define TPS_0__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define TPS_0__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define TPS_0__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define TPS_0__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define TPS_0__PS CYREG_PRT3_PS
#define TPS_0__SHIFT 3
#define TPS_0__SLW CYREG_PRT3_SLW

/* TPS_1 */
#define TPS_1__0__MASK 0x08u
#define TPS_1__0__PC CYREG_IO_PC_PRT15_PC3
#define TPS_1__0__PORT 15u
#define TPS_1__0__SHIFT 3
#define TPS_1__AG CYREG_PRT15_AG
#define TPS_1__AMUX CYREG_PRT15_AMUX
#define TPS_1__BIE CYREG_PRT15_BIE
#define TPS_1__BIT_MASK CYREG_PRT15_BIT_MASK
#define TPS_1__BYP CYREG_PRT15_BYP
#define TPS_1__CTL CYREG_PRT15_CTL
#define TPS_1__DM0 CYREG_PRT15_DM0
#define TPS_1__DM1 CYREG_PRT15_DM1
#define TPS_1__DM2 CYREG_PRT15_DM2
#define TPS_1__DR CYREG_PRT15_DR
#define TPS_1__INP_DIS CYREG_PRT15_INP_DIS
#define TPS_1__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define TPS_1__LCD_EN CYREG_PRT15_LCD_EN
#define TPS_1__MASK 0x08u
#define TPS_1__PORT 15u
#define TPS_1__PRT CYREG_PRT15_PRT
#define TPS_1__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define TPS_1__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define TPS_1__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define TPS_1__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define TPS_1__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define TPS_1__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define TPS_1__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define TPS_1__PS CYREG_PRT15_PS
#define TPS_1__SHIFT 3
#define TPS_1__SLW CYREG_PRT15_SLW

/* APPS_0 */
#define APPS_0__0__MASK 0x80u
#define APPS_0__0__PC CYREG_PRT4_PC7
#define APPS_0__0__PORT 4u
#define APPS_0__0__SHIFT 7
#define APPS_0__AG CYREG_PRT4_AG
#define APPS_0__AMUX CYREG_PRT4_AMUX
#define APPS_0__BIE CYREG_PRT4_BIE
#define APPS_0__BIT_MASK CYREG_PRT4_BIT_MASK
#define APPS_0__BYP CYREG_PRT4_BYP
#define APPS_0__CTL CYREG_PRT4_CTL
#define APPS_0__DM0 CYREG_PRT4_DM0
#define APPS_0__DM1 CYREG_PRT4_DM1
#define APPS_0__DM2 CYREG_PRT4_DM2
#define APPS_0__DR CYREG_PRT4_DR
#define APPS_0__INP_DIS CYREG_PRT4_INP_DIS
#define APPS_0__LCD_COM_SEG CYREG_PRT4_LCD_COM_SEG
#define APPS_0__LCD_EN CYREG_PRT4_LCD_EN
#define APPS_0__MASK 0x80u
#define APPS_0__PORT 4u
#define APPS_0__PRT CYREG_PRT4_PRT
#define APPS_0__PRTDSI__CAPS_SEL CYREG_PRT4_CAPS_SEL
#define APPS_0__PRTDSI__DBL_SYNC_IN CYREG_PRT4_DBL_SYNC_IN
#define APPS_0__PRTDSI__OE_SEL0 CYREG_PRT4_OE_SEL0
#define APPS_0__PRTDSI__OE_SEL1 CYREG_PRT4_OE_SEL1
#define APPS_0__PRTDSI__OUT_SEL0 CYREG_PRT4_OUT_SEL0
#define APPS_0__PRTDSI__OUT_SEL1 CYREG_PRT4_OUT_SEL1
#define APPS_0__PRTDSI__SYNC_OUT CYREG_PRT4_SYNC_OUT
#define APPS_0__PS CYREG_PRT4_PS
#define APPS_0__SHIFT 7
#define APPS_0__SLW CYREG_PRT4_SLW

/* APPS_1 */
#define APPS_1__0__MASK 0x08u
#define APPS_1__0__PC CYREG_PRT0_PC3
#define APPS_1__0__PORT 0u
#define APPS_1__0__SHIFT 3
#define APPS_1__AG CYREG_PRT0_AG
#define APPS_1__AMUX CYREG_PRT0_AMUX
#define APPS_1__BIE CYREG_PRT0_BIE
#define APPS_1__BIT_MASK CYREG_PRT0_BIT_MASK
#define APPS_1__BYP CYREG_PRT0_BYP
#define APPS_1__CTL CYREG_PRT0_CTL
#define APPS_1__DM0 CYREG_PRT0_DM0
#define APPS_1__DM1 CYREG_PRT0_DM1
#define APPS_1__DM2 CYREG_PRT0_DM2
#define APPS_1__DR CYREG_PRT0_DR
#define APPS_1__INP_DIS CYREG_PRT0_INP_DIS
#define APPS_1__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define APPS_1__LCD_EN CYREG_PRT0_LCD_EN
#define APPS_1__MASK 0x08u
#define APPS_1__PORT 0u
#define APPS_1__PRT CYREG_PRT0_PRT
#define APPS_1__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define APPS_1__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define APPS_1__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define APPS_1__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define APPS_1__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define APPS_1__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define APPS_1__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define APPS_1__PS CYREG_PRT0_PS
#define APPS_1__SHIFT 3
#define APPS_1__SLW CYREG_PRT0_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* TPS_ADC_bSAR_SEQ */
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB05_06_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB05_06_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB05_06_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB05_06_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB05_06_MSK
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB05_06_MSK
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB05_06_MSK
#define TPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB05_06_MSK
#define TPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_REG CYREG_B0_UDB05_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_ST_REG CYREG_B0_UDB05_ST_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__COUNT_REG CYREG_B0_UDB05_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__COUNT_ST_REG CYREG_B0_UDB05_ST_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB05_MSK_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB05_MSK_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter__PERIOD_REG CYREG_B0_UDB05_MSK
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB05_06_ST
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__MASK_REG CYREG_B0_UDB05_MSK
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB05_MSK_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB05_MSK_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_CNT_REG CYREG_B0_UDB05_ST_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB05_ST_CTL
#define TPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_REG CYREG_B0_UDB05_ST
#define TPS_ADC_bSAR_SEQ_CtrlReg__0__MASK 0x01u
#define TPS_ADC_bSAR_SEQ_CtrlReg__0__POS 0
#define TPS_ADC_bSAR_SEQ_CtrlReg__1__MASK 0x02u
#define TPS_ADC_bSAR_SEQ_CtrlReg__1__POS 1
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB03_04_ACTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB03_04_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB03_04_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB03_04_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB03_04_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_MASK_MASK_REG CYREG_B0_UDB03_04_MSK
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB03_04_MSK
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB03_04_MSK
#define TPS_ADC_bSAR_SEQ_CtrlReg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB03_04_MSK
#define TPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_AUX_CTL_REG CYREG_B0_UDB03_ACTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_REG CYREG_B0_UDB03_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_ST_REG CYREG_B0_UDB03_ST_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__COUNT_REG CYREG_B0_UDB03_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__COUNT_ST_REG CYREG_B0_UDB03_ST_CTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__MASK 0x03u
#define TPS_ADC_bSAR_SEQ_CtrlReg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB03_MSK_ACTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB03_MSK_ACTL
#define TPS_ADC_bSAR_SEQ_CtrlReg__PERIOD_REG CYREG_B0_UDB03_MSK
#define TPS_ADC_bSAR_SEQ_EOCSts__0__MASK 0x01u
#define TPS_ADC_bSAR_SEQ_EOCSts__0__POS 0
#define TPS_ADC_bSAR_SEQ_EOCSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define TPS_ADC_bSAR_SEQ_EOCSts__16BIT_STATUS_REG CYREG_B0_UDB06_07_ST
#define TPS_ADC_bSAR_SEQ_EOCSts__MASK 0x01u
#define TPS_ADC_bSAR_SEQ_EOCSts__MASK_REG CYREG_B0_UDB06_MSK
#define TPS_ADC_bSAR_SEQ_EOCSts__STATUS_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define TPS_ADC_bSAR_SEQ_EOCSts__STATUS_REG CYREG_B0_UDB06_ST

/* TPS_ADC_FinalBuf */
#define TPS_ADC_FinalBuf__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define TPS_ADC_FinalBuf__DRQ_NUMBER 2u
#define TPS_ADC_FinalBuf__NUMBEROF_TDS 0u
#define TPS_ADC_FinalBuf__PRIORITY 2u
#define TPS_ADC_FinalBuf__TERMIN_EN 0u
#define TPS_ADC_FinalBuf__TERMIN_SEL 0u
#define TPS_ADC_FinalBuf__TERMOUT0_EN 1u
#define TPS_ADC_FinalBuf__TERMOUT0_SEL 2u
#define TPS_ADC_FinalBuf__TERMOUT1_EN 0u
#define TPS_ADC_FinalBuf__TERMOUT1_SEL 0u

/* TPS_ADC_IntClock */
#define TPS_ADC_IntClock__CFG0 CYREG_CLKDIST_DCFG2_CFG0
#define TPS_ADC_IntClock__CFG1 CYREG_CLKDIST_DCFG2_CFG1
#define TPS_ADC_IntClock__CFG2 CYREG_CLKDIST_DCFG2_CFG2
#define TPS_ADC_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define TPS_ADC_IntClock__INDEX 0x02u
#define TPS_ADC_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define TPS_ADC_IntClock__PM_ACT_MSK 0x04u
#define TPS_ADC_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define TPS_ADC_IntClock__PM_STBY_MSK 0x04u

/* TPS_ADC_IRQ */
#define TPS_ADC_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define TPS_ADC_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define TPS_ADC_IRQ__INTC_MASK 0x02u
#define TPS_ADC_IRQ__INTC_NUMBER 1u
#define TPS_ADC_IRQ__INTC_PRIOR_NUM 7u
#define TPS_ADC_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define TPS_ADC_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define TPS_ADC_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* TPS_ADC_SAR_ADC_SAR */
#define TPS_ADC_SAR_ADC_SAR__CLK CYREG_SAR1_CLK
#define TPS_ADC_SAR_ADC_SAR__CSR0 CYREG_SAR1_CSR0
#define TPS_ADC_SAR_ADC_SAR__CSR1 CYREG_SAR1_CSR1
#define TPS_ADC_SAR_ADC_SAR__CSR2 CYREG_SAR1_CSR2
#define TPS_ADC_SAR_ADC_SAR__CSR3 CYREG_SAR1_CSR3
#define TPS_ADC_SAR_ADC_SAR__CSR4 CYREG_SAR1_CSR4
#define TPS_ADC_SAR_ADC_SAR__CSR5 CYREG_SAR1_CSR5
#define TPS_ADC_SAR_ADC_SAR__CSR6 CYREG_SAR1_CSR6
#define TPS_ADC_SAR_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define TPS_ADC_SAR_ADC_SAR__PM_ACT_MSK 0x02u
#define TPS_ADC_SAR_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define TPS_ADC_SAR_ADC_SAR__PM_STBY_MSK 0x02u
#define TPS_ADC_SAR_ADC_SAR__SW0 CYREG_SAR1_SW0
#define TPS_ADC_SAR_ADC_SAR__SW2 CYREG_SAR1_SW2
#define TPS_ADC_SAR_ADC_SAR__SW3 CYREG_SAR1_SW3
#define TPS_ADC_SAR_ADC_SAR__SW4 CYREG_SAR1_SW4
#define TPS_ADC_SAR_ADC_SAR__SW6 CYREG_SAR1_SW6
#define TPS_ADC_SAR_ADC_SAR__TR0 CYREG_SAR1_TR0
#define TPS_ADC_SAR_ADC_SAR__WRK0 CYREG_SAR1_WRK0
#define TPS_ADC_SAR_ADC_SAR__WRK1 CYREG_SAR1_WRK1

/* TPS_ADC_TempBuf */
#define TPS_ADC_TempBuf__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define TPS_ADC_TempBuf__DRQ_NUMBER 3u
#define TPS_ADC_TempBuf__NUMBEROF_TDS 0u
#define TPS_ADC_TempBuf__PRIORITY 2u
#define TPS_ADC_TempBuf__TERMIN_EN 0u
#define TPS_ADC_TempBuf__TERMIN_SEL 0u
#define TPS_ADC_TempBuf__TERMOUT0_EN 1u
#define TPS_ADC_TempBuf__TERMOUT0_SEL 3u
#define TPS_ADC_TempBuf__TERMOUT1_EN 0u
#define TPS_ADC_TempBuf__TERMOUT1_SEL 0u

/* APPS_ADC_bSAR_SEQ */
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_COUNT_COUNT_REG CYREG_B1_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_MASK_MASK_REG CYREG_B1_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_MASK_PERIOD_REG CYREG_B1_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_MASK_REG CYREG_B1_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_ChannelCounter__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_REG CYREG_B1_UDB07_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__CONTROL_ST_REG CYREG_B1_UDB07_ST_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__COUNT_REG CYREG_B1_UDB07_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__COUNT_ST_REG CYREG_B1_UDB07_ST_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__PER_CTL_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter__PERIOD_REG CYREG_B1_UDB07_MSK
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__16BIT_STATUS_REG CYREG_B1_UDB07_08_ST
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__MASK_REG CYREG_B1_UDB07_MSK
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__PER_ST_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_CNT_REG CYREG_B1_UDB07_ST_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_CONTROL_REG CYREG_B1_UDB07_ST_CTL
#define APPS_ADC_bSAR_SEQ_ChannelCounter_ST__STATUS_REG CYREG_B1_UDB07_ST
#define APPS_ADC_bSAR_SEQ_CtrlReg__0__MASK 0x01u
#define APPS_ADC_bSAR_SEQ_CtrlReg__0__POS 0
#define APPS_ADC_bSAR_SEQ_CtrlReg__1__MASK 0x02u
#define APPS_ADC_bSAR_SEQ_CtrlReg__1__POS 1
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB07_08_ACTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB07_08_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_MASK_MASK_REG CYREG_B0_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_CtrlReg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB07_08_MSK
#define APPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_AUX_CTL_REG CYREG_B0_UDB07_ACTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_REG CYREG_B0_UDB07_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__CONTROL_ST_REG CYREG_B0_UDB07_ST_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__COUNT_REG CYREG_B0_UDB07_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__COUNT_ST_REG CYREG_B0_UDB07_ST_CTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__MASK 0x03u
#define APPS_ADC_bSAR_SEQ_CtrlReg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB07_MSK_ACTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB07_MSK_ACTL
#define APPS_ADC_bSAR_SEQ_CtrlReg__PERIOD_REG CYREG_B0_UDB07_MSK
#define APPS_ADC_bSAR_SEQ_EOCSts__0__MASK 0x01u
#define APPS_ADC_bSAR_SEQ_EOCSts__0__POS 0
#define APPS_ADC_bSAR_SEQ_EOCSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define APPS_ADC_bSAR_SEQ_EOCSts__16BIT_STATUS_REG CYREG_B0_UDB04_05_ST
#define APPS_ADC_bSAR_SEQ_EOCSts__MASK 0x01u
#define APPS_ADC_bSAR_SEQ_EOCSts__MASK_REG CYREG_B0_UDB04_MSK
#define APPS_ADC_bSAR_SEQ_EOCSts__STATUS_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define APPS_ADC_bSAR_SEQ_EOCSts__STATUS_REG CYREG_B0_UDB04_ST

/* APPS_ADC_FinalBuf */
#define APPS_ADC_FinalBuf__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define APPS_ADC_FinalBuf__DRQ_NUMBER 0u
#define APPS_ADC_FinalBuf__NUMBEROF_TDS 0u
#define APPS_ADC_FinalBuf__PRIORITY 2u
#define APPS_ADC_FinalBuf__TERMIN_EN 0u
#define APPS_ADC_FinalBuf__TERMIN_SEL 0u
#define APPS_ADC_FinalBuf__TERMOUT0_EN 1u
#define APPS_ADC_FinalBuf__TERMOUT0_SEL 0u
#define APPS_ADC_FinalBuf__TERMOUT1_EN 0u
#define APPS_ADC_FinalBuf__TERMOUT1_SEL 0u

/* APPS_ADC_IntClock */
#define APPS_ADC_IntClock__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define APPS_ADC_IntClock__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define APPS_ADC_IntClock__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define APPS_ADC_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define APPS_ADC_IntClock__INDEX 0x01u
#define APPS_ADC_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define APPS_ADC_IntClock__PM_ACT_MSK 0x02u
#define APPS_ADC_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define APPS_ADC_IntClock__PM_STBY_MSK 0x02u

/* APPS_ADC_IRQ */
#define APPS_ADC_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define APPS_ADC_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define APPS_ADC_IRQ__INTC_MASK 0x01u
#define APPS_ADC_IRQ__INTC_NUMBER 0u
#define APPS_ADC_IRQ__INTC_PRIOR_NUM 7u
#define APPS_ADC_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define APPS_ADC_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define APPS_ADC_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* APPS_ADC_SAR_ADC_SAR */
#define APPS_ADC_SAR_ADC_SAR__CLK CYREG_SAR0_CLK
#define APPS_ADC_SAR_ADC_SAR__CSR0 CYREG_SAR0_CSR0
#define APPS_ADC_SAR_ADC_SAR__CSR1 CYREG_SAR0_CSR1
#define APPS_ADC_SAR_ADC_SAR__CSR2 CYREG_SAR0_CSR2
#define APPS_ADC_SAR_ADC_SAR__CSR3 CYREG_SAR0_CSR3
#define APPS_ADC_SAR_ADC_SAR__CSR4 CYREG_SAR0_CSR4
#define APPS_ADC_SAR_ADC_SAR__CSR5 CYREG_SAR0_CSR5
#define APPS_ADC_SAR_ADC_SAR__CSR6 CYREG_SAR0_CSR6
#define APPS_ADC_SAR_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define APPS_ADC_SAR_ADC_SAR__PM_ACT_MSK 0x01u
#define APPS_ADC_SAR_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define APPS_ADC_SAR_ADC_SAR__PM_STBY_MSK 0x01u
#define APPS_ADC_SAR_ADC_SAR__SW0 CYREG_SAR0_SW0
#define APPS_ADC_SAR_ADC_SAR__SW2 CYREG_SAR0_SW2
#define APPS_ADC_SAR_ADC_SAR__SW3 CYREG_SAR0_SW3
#define APPS_ADC_SAR_ADC_SAR__SW4 CYREG_SAR0_SW4
#define APPS_ADC_SAR_ADC_SAR__SW6 CYREG_SAR0_SW6
#define APPS_ADC_SAR_ADC_SAR__TR0 CYREG_SAR0_TR0
#define APPS_ADC_SAR_ADC_SAR__WRK0 CYREG_SAR0_WRK0
#define APPS_ADC_SAR_ADC_SAR__WRK1 CYREG_SAR0_WRK1

/* APPS_ADC_TempBuf */
#define APPS_ADC_TempBuf__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define APPS_ADC_TempBuf__DRQ_NUMBER 1u
#define APPS_ADC_TempBuf__NUMBEROF_TDS 0u
#define APPS_ADC_TempBuf__PRIORITY 2u
#define APPS_ADC_TempBuf__TERMIN_EN 0u
#define APPS_ADC_TempBuf__TERMIN_SEL 0u
#define APPS_ADC_TempBuf__TERMOUT0_EN 1u
#define APPS_ADC_TempBuf__TERMOUT0_SEL 1u
#define APPS_ADC_TempBuf__TERMOUT1_EN 0u
#define APPS_ADC_TempBuf__TERMOUT1_SEL 0u

/* SERVO_OUT */
#define SERVO_OUT__0__MASK 0x01u
#define SERVO_OUT__0__PC CYREG_PRT0_PC0
#define SERVO_OUT__0__PORT 0u
#define SERVO_OUT__0__SHIFT 0
#define SERVO_OUT__AG CYREG_PRT0_AG
#define SERVO_OUT__AMUX CYREG_PRT0_AMUX
#define SERVO_OUT__BIE CYREG_PRT0_BIE
#define SERVO_OUT__BIT_MASK CYREG_PRT0_BIT_MASK
#define SERVO_OUT__BYP CYREG_PRT0_BYP
#define SERVO_OUT__CTL CYREG_PRT0_CTL
#define SERVO_OUT__DM0 CYREG_PRT0_DM0
#define SERVO_OUT__DM1 CYREG_PRT0_DM1
#define SERVO_OUT__DM2 CYREG_PRT0_DM2
#define SERVO_OUT__DR CYREG_PRT0_DR
#define SERVO_OUT__INP_DIS CYREG_PRT0_INP_DIS
#define SERVO_OUT__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define SERVO_OUT__LCD_EN CYREG_PRT0_LCD_EN
#define SERVO_OUT__MASK 0x01u
#define SERVO_OUT__PORT 0u
#define SERVO_OUT__PRT CYREG_PRT0_PRT
#define SERVO_OUT__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define SERVO_OUT__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define SERVO_OUT__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define SERVO_OUT__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define SERVO_OUT__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define SERVO_OUT__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define SERVO_OUT__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define SERVO_OUT__PS CYREG_PRT0_PS
#define SERVO_OUT__SHIFT 0
#define SERVO_OUT__SLW CYREG_PRT0_SLW

/* SERVO_PWM_PWMUDB */
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB01_02_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB01_02_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB01_02_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB01_02_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB01_02_MSK
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB01_02_MSK
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB01_02_MSK
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB01_02_MSK
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__7__POS 7
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B0_UDB01_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB01_ST_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B0_UDB01_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B0_UDB01_ST_CTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define SERVO_PWM_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B0_UDB01_MSK
#define SERVO_PWM_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define SERVO_PWM_PWMUDB_genblk8_stsreg__0__POS 0
#define SERVO_PWM_PWMUDB_genblk8_stsreg__1__MASK 0x02u
#define SERVO_PWM_PWMUDB_genblk8_stsreg__1__POS 1
#define SERVO_PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define SERVO_PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_B0_UDB01_02_ST
#define SERVO_PWM_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define SERVO_PWM_PWMUDB_genblk8_stsreg__2__POS 2
#define SERVO_PWM_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define SERVO_PWM_PWMUDB_genblk8_stsreg__3__POS 3
#define SERVO_PWM_PWMUDB_genblk8_stsreg__MASK 0x0Fu
#define SERVO_PWM_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B0_UDB01_MSK
#define SERVO_PWM_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define SERVO_PWM_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define SERVO_PWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define SERVO_PWM_PWMUDB_genblk8_stsreg__STATUS_CNT_REG CYREG_B0_UDB01_ST_CTL
#define SERVO_PWM_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB01_ST_CTL
#define SERVO_PWM_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B0_UDB01_ST
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB01_02_A0
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB01_02_A1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB01_02_D0
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB01_02_D1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB01_02_F0
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB01_02_F1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B0_UDB01_A0_A1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B0_UDB01_A0
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B0_UDB01_A1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B0_UDB01_D0_D1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B0_UDB01_D0
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B0_UDB01_D1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B0_UDB01_F0_F1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B0_UDB01_F0
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B0_UDB01_F1
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define SERVO_PWM_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "E-Throttle-Mainboard-Deprecated"
#define CY_VERSION "PSoC Creator  3.2 SP1"
#define CYDEV_CHIP_DIE_GEN4 2u
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 13u
#define CYDEV_CHIP_DIE_PSOC4A 6u
#define CYDEV_CHIP_DIE_PSOC5LP 12u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 6u
#define CYDEV_CHIP_MEMBER_4C 10u
#define CYDEV_CHIP_MEMBER_4D 3u
#define CYDEV_CHIP_MEMBER_4E 5u
#define CYDEV_CHIP_MEMBER_4F 7u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 4u
#define CYDEV_CHIP_MEMBER_4L 9u
#define CYDEV_CHIP_MEMBER_4M 8u
#define CYDEV_CHIP_MEMBER_5A 12u
#define CYDEV_CHIP_MEMBER_5B 11u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_GEN4_ES 17u
#define CYDEV_CHIP_REV_GEN4_ES2 33u
#define CYDEV_CHIP_REV_GEN4_PRODUCTION 17u
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000003u
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x0000000Fu
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */