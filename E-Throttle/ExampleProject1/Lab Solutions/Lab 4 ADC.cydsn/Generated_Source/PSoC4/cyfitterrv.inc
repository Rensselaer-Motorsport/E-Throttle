    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; PWM_B_cy_m0s8_tcpwm_1
PWM_B_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
PWM_B_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
PWM_B_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
PWM_B_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
PWM_B_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
PWM_B_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
PWM_B_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
PWM_B_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
PWM_B_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
PWM_B_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
PWM_B_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
PWM_B_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_B_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
PWM_B_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
PWM_B_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
PWM_B_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
PWM_B_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
PWM_B_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

; PWM_G_cy_m0s8_tcpwm_1
PWM_G_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT1_CC
PWM_G_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT1_CC_BUFF
PWM_G_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT1_COUNTER
PWM_G_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT1_CTRL
PWM_G_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT1_INTR
PWM_G_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT1_INTR_MASK
PWM_G_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT1_INTR_MASKED
PWM_G_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT1_INTR_SET
PWM_G_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT1_PERIOD
PWM_G_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT1_PERIOD_BUFF
PWM_G_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT1_STATUS
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x02
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 1
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x200
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 9
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x2000000
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 25
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x20000
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 17
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x02
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 1
PWM_G_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_G_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x02
PWM_G_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 1
PWM_G_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 1
PWM_G_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT1_TR_CTRL0
PWM_G_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT1_TR_CTRL1
PWM_G_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT1_TR_CTRL2

; PWM_R_cy_m0s8_tcpwm_1
PWM_R_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT2_CC
PWM_R_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT2_CC_BUFF
PWM_R_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT2_COUNTER
PWM_R_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT2_CTRL
PWM_R_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT2_INTR
PWM_R_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT2_INTR_MASK
PWM_R_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT2_INTR_MASKED
PWM_R_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT2_INTR_SET
PWM_R_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT2_PERIOD
PWM_R_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT2_PERIOD_BUFF
PWM_R_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT2_STATUS
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x04
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 2
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x400
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 10
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x4000000
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 26
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x40000
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 18
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x04
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 2
PWM_R_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_R_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x04
PWM_R_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 2
PWM_R_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 2
PWM_R_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT2_TR_CTRL0
PWM_R_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT2_TR_CTRL1
PWM_R_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT2_TR_CTRL2

; Pin_1
Pin_1__0__DM__MASK EQU 0x07
Pin_1__0__DM__SHIFT EQU 0
Pin_1__0__DR EQU CYREG_PRT2_DR
Pin_1__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
Pin_1__0__HSIOM_MASK EQU 0x0000000F
Pin_1__0__HSIOM_SHIFT EQU 0
Pin_1__0__INTCFG EQU CYREG_PRT2_INTCFG
Pin_1__0__INTSTAT EQU CYREG_PRT2_INTSTAT
Pin_1__0__MASK EQU 0x01
Pin_1__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin_1__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin_1__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin_1__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin_1__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin_1__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin_1__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin_1__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin_1__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin_1__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin_1__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin_1__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin_1__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin_1__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin_1__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin_1__0__PC EQU CYREG_PRT2_PC
Pin_1__0__PC2 EQU CYREG_PRT2_PC2
Pin_1__0__PORT EQU 2
Pin_1__0__PS EQU CYREG_PRT2_PS
Pin_1__0__SHIFT EQU 0
Pin_1__DR EQU CYREG_PRT2_DR
Pin_1__INTCFG EQU CYREG_PRT2_INTCFG
Pin_1__INTSTAT EQU CYREG_PRT2_INTSTAT
Pin_1__MASK EQU 0x01
Pin_1__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin_1__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin_1__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin_1__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin_1__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin_1__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin_1__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin_1__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin_1__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin_1__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin_1__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin_1__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin_1__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin_1__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin_1__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin_1__PC EQU CYREG_PRT2_PC
Pin_1__PC2 EQU CYREG_PRT2_PC2
Pin_1__PORT EQU 2
Pin_1__PS EQU CYREG_PRT2_PS
Pin_1__SHIFT EQU 0

; Clock_PWM
Clock_PWM__DIVIDER_MASK EQU 0x0000FFFF
Clock_PWM__ENABLE EQU CYREG_CLK_DIVIDER_A00
Clock_PWM__ENABLE_MASK EQU 0x80000000
Clock_PWM__MASK EQU 0x80000000
Clock_PWM__REGISTER EQU CYREG_CLK_DIVIDER_A00

; Pin_RedLED
Pin_RedLED__0__DM__MASK EQU 0x1C0000
Pin_RedLED__0__DM__SHIFT EQU 18
Pin_RedLED__0__DR EQU CYREG_PRT1_DR
Pin_RedLED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
Pin_RedLED__0__HSIOM_MASK EQU 0x0F000000
Pin_RedLED__0__HSIOM_SHIFT EQU 24
Pin_RedLED__0__INTCFG EQU CYREG_PRT1_INTCFG
Pin_RedLED__0__INTSTAT EQU CYREG_PRT1_INTSTAT
Pin_RedLED__0__MASK EQU 0x40
Pin_RedLED__0__OUT_SEL EQU CYREG_UDB_PA1_CFG10
Pin_RedLED__0__OUT_SEL_SHIFT EQU 12
Pin_RedLED__0__OUT_SEL_VAL EQU 0
Pin_RedLED__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
Pin_RedLED__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
Pin_RedLED__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
Pin_RedLED__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
Pin_RedLED__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
Pin_RedLED__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
Pin_RedLED__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
Pin_RedLED__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
Pin_RedLED__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
Pin_RedLED__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
Pin_RedLED__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
Pin_RedLED__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
Pin_RedLED__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
Pin_RedLED__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
Pin_RedLED__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
Pin_RedLED__0__PC EQU CYREG_PRT1_PC
Pin_RedLED__0__PC2 EQU CYREG_PRT1_PC2
Pin_RedLED__0__PORT EQU 1
Pin_RedLED__0__PS EQU CYREG_PRT1_PS
Pin_RedLED__0__SHIFT EQU 6
Pin_RedLED__DR EQU CYREG_PRT1_DR
Pin_RedLED__INTCFG EQU CYREG_PRT1_INTCFG
Pin_RedLED__INTSTAT EQU CYREG_PRT1_INTSTAT
Pin_RedLED__MASK EQU 0x40
Pin_RedLED__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
Pin_RedLED__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
Pin_RedLED__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
Pin_RedLED__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
Pin_RedLED__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
Pin_RedLED__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
Pin_RedLED__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
Pin_RedLED__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
Pin_RedLED__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
Pin_RedLED__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
Pin_RedLED__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
Pin_RedLED__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
Pin_RedLED__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
Pin_RedLED__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
Pin_RedLED__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
Pin_RedLED__PC EQU CYREG_PRT1_PC
Pin_RedLED__PC2 EQU CYREG_PRT1_PC2
Pin_RedLED__PORT EQU 1
Pin_RedLED__PS EQU CYREG_PRT1_PS
Pin_RedLED__SHIFT EQU 6

; Pin_BlueLED
Pin_BlueLED__0__DM__MASK EQU 0xE00
Pin_BlueLED__0__DM__SHIFT EQU 9
Pin_BlueLED__0__DR EQU CYREG_PRT0_DR
Pin_BlueLED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Pin_BlueLED__0__HSIOM_MASK EQU 0x0000F000
Pin_BlueLED__0__HSIOM_SHIFT EQU 12
Pin_BlueLED__0__INTCFG EQU CYREG_PRT0_INTCFG
Pin_BlueLED__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_BlueLED__0__MASK EQU 0x08
Pin_BlueLED__0__OUT_SEL EQU CYREG_UDB_PA0_CFG10
Pin_BlueLED__0__OUT_SEL_SHIFT EQU 6
Pin_BlueLED__0__OUT_SEL_VAL EQU 3
Pin_BlueLED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_BlueLED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_BlueLED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_BlueLED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_BlueLED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_BlueLED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_BlueLED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_BlueLED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_BlueLED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_BlueLED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_BlueLED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_BlueLED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_BlueLED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_BlueLED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_BlueLED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_BlueLED__0__PC EQU CYREG_PRT0_PC
Pin_BlueLED__0__PC2 EQU CYREG_PRT0_PC2
Pin_BlueLED__0__PORT EQU 0
Pin_BlueLED__0__PS EQU CYREG_PRT0_PS
Pin_BlueLED__0__SHIFT EQU 3
Pin_BlueLED__DR EQU CYREG_PRT0_DR
Pin_BlueLED__INTCFG EQU CYREG_PRT0_INTCFG
Pin_BlueLED__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_BlueLED__MASK EQU 0x08
Pin_BlueLED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_BlueLED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_BlueLED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_BlueLED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_BlueLED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_BlueLED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_BlueLED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_BlueLED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_BlueLED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_BlueLED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_BlueLED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_BlueLED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_BlueLED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_BlueLED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_BlueLED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_BlueLED__PC EQU CYREG_PRT0_PC
Pin_BlueLED__PC2 EQU CYREG_PRT0_PC2
Pin_BlueLED__PORT EQU 0
Pin_BlueLED__PS EQU CYREG_PRT0_PS
Pin_BlueLED__SHIFT EQU 3

; Pin_GreenLED
Pin_GreenLED__0__DM__MASK EQU 0x1C0
Pin_GreenLED__0__DM__SHIFT EQU 6
Pin_GreenLED__0__DR EQU CYREG_PRT0_DR
Pin_GreenLED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Pin_GreenLED__0__HSIOM_MASK EQU 0x00000F00
Pin_GreenLED__0__HSIOM_SHIFT EQU 8
Pin_GreenLED__0__INTCFG EQU CYREG_PRT0_INTCFG
Pin_GreenLED__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_GreenLED__0__MASK EQU 0x04
Pin_GreenLED__0__OUT_SEL EQU CYREG_UDB_PA0_CFG10
Pin_GreenLED__0__OUT_SEL_SHIFT EQU 4
Pin_GreenLED__0__OUT_SEL_VAL EQU 1
Pin_GreenLED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_GreenLED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_GreenLED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_GreenLED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_GreenLED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_GreenLED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_GreenLED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_GreenLED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_GreenLED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_GreenLED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_GreenLED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_GreenLED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_GreenLED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_GreenLED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_GreenLED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_GreenLED__0__PC EQU CYREG_PRT0_PC
Pin_GreenLED__0__PC2 EQU CYREG_PRT0_PC2
Pin_GreenLED__0__PORT EQU 0
Pin_GreenLED__0__PS EQU CYREG_PRT0_PS
Pin_GreenLED__0__SHIFT EQU 2
Pin_GreenLED__DR EQU CYREG_PRT0_DR
Pin_GreenLED__INTCFG EQU CYREG_PRT0_INTCFG
Pin_GreenLED__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_GreenLED__MASK EQU 0x04
Pin_GreenLED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_GreenLED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_GreenLED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_GreenLED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_GreenLED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_GreenLED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_GreenLED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_GreenLED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_GreenLED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_GreenLED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_GreenLED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_GreenLED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_GreenLED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_GreenLED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_GreenLED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_GreenLED__PC EQU CYREG_PRT0_PC
Pin_GreenLED__PC2 EQU CYREG_PRT0_PC2
Pin_GreenLED__PORT EQU 0
Pin_GreenLED__PS EQU CYREG_PRT0_PS
Pin_GreenLED__SHIFT EQU 2

; ADC_SAR_Seq_1_Bypass
ADC_SAR_Seq_1_Bypass__0__DM__MASK EQU 0xE00000
ADC_SAR_Seq_1_Bypass__0__DM__SHIFT EQU 21
ADC_SAR_Seq_1_Bypass__0__DR EQU CYREG_PRT1_DR
ADC_SAR_Seq_1_Bypass__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
ADC_SAR_Seq_1_Bypass__0__HSIOM_MASK EQU 0xF0000000
ADC_SAR_Seq_1_Bypass__0__HSIOM_SHIFT EQU 28
ADC_SAR_Seq_1_Bypass__0__INTCFG EQU CYREG_PRT1_INTCFG
ADC_SAR_Seq_1_Bypass__0__INTSTAT EQU CYREG_PRT1_INTSTAT
ADC_SAR_Seq_1_Bypass__0__MASK EQU 0x80
ADC_SAR_Seq_1_Bypass__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
ADC_SAR_Seq_1_Bypass__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
ADC_SAR_Seq_1_Bypass__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
ADC_SAR_Seq_1_Bypass__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
ADC_SAR_Seq_1_Bypass__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
ADC_SAR_Seq_1_Bypass__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
ADC_SAR_Seq_1_Bypass__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
ADC_SAR_Seq_1_Bypass__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
ADC_SAR_Seq_1_Bypass__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
ADC_SAR_Seq_1_Bypass__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
ADC_SAR_Seq_1_Bypass__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
ADC_SAR_Seq_1_Bypass__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
ADC_SAR_Seq_1_Bypass__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
ADC_SAR_Seq_1_Bypass__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
ADC_SAR_Seq_1_Bypass__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
ADC_SAR_Seq_1_Bypass__0__PC EQU CYREG_PRT1_PC
ADC_SAR_Seq_1_Bypass__0__PC2 EQU CYREG_PRT1_PC2
ADC_SAR_Seq_1_Bypass__0__PORT EQU 1
ADC_SAR_Seq_1_Bypass__0__PS EQU CYREG_PRT1_PS
ADC_SAR_Seq_1_Bypass__0__SHIFT EQU 7
ADC_SAR_Seq_1_Bypass__DR EQU CYREG_PRT1_DR
ADC_SAR_Seq_1_Bypass__INTCFG EQU CYREG_PRT1_INTCFG
ADC_SAR_Seq_1_Bypass__INTSTAT EQU CYREG_PRT1_INTSTAT
ADC_SAR_Seq_1_Bypass__MASK EQU 0x80
ADC_SAR_Seq_1_Bypass__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
ADC_SAR_Seq_1_Bypass__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
ADC_SAR_Seq_1_Bypass__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
ADC_SAR_Seq_1_Bypass__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
ADC_SAR_Seq_1_Bypass__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
ADC_SAR_Seq_1_Bypass__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
ADC_SAR_Seq_1_Bypass__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
ADC_SAR_Seq_1_Bypass__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
ADC_SAR_Seq_1_Bypass__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
ADC_SAR_Seq_1_Bypass__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
ADC_SAR_Seq_1_Bypass__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
ADC_SAR_Seq_1_Bypass__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
ADC_SAR_Seq_1_Bypass__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
ADC_SAR_Seq_1_Bypass__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
ADC_SAR_Seq_1_Bypass__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
ADC_SAR_Seq_1_Bypass__PC EQU CYREG_PRT1_PC
ADC_SAR_Seq_1_Bypass__PC2 EQU CYREG_PRT1_PC2
ADC_SAR_Seq_1_Bypass__PORT EQU 1
ADC_SAR_Seq_1_Bypass__PS EQU CYREG_PRT1_PS
ADC_SAR_Seq_1_Bypass__SHIFT EQU 7

; ADC_SAR_Seq_1_cy_psoc4_sar
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_CTRL EQU CYREG_SAR_CTRL
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_INTR EQU CYREG_SAR_INTR
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_INTR_CAUSE EQU CYREG_SAR_INTR_CAUSE
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_INTR_MASK EQU CYREG_SAR_INTR_MASK
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_INTR_MASKED EQU CYREG_SAR_INTR_MASKED
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_INTR_SET EQU CYREG_SAR_INTR_SET
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_NUMBER EQU 0
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_RANGE_COND EQU CYREG_SAR_RANGE_COND
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_RANGE_INTR_MASK EQU CYREG_SAR_RANGE_INTR_MASK
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_RANGE_INTR_MASKED EQU CYREG_SAR_RANGE_INTR_MASKED
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_RANGE_INTR_SET EQU CYREG_SAR_RANGE_INTR_SET
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_RANGE_THRES EQU CYREG_SAR_RANGE_THRES
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_SAMPLE_CTRL EQU CYREG_SAR_SAMPLE_CTRL
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_SAMPLE_TIME01 EQU CYREG_SAR_SAMPLE_TIME01
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_SAMPLE_TIME23 EQU CYREG_SAR_SAMPLE_TIME23
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_SATURATE_INTR_MASK EQU CYREG_SAR_SATURATE_INTR_MASK
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED EQU CYREG_SAR_SATURATE_INTR_MASKED
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_SATURATE_INTR_SET EQU CYREG_SAR_SATURATE_INTR_SET
ADC_SAR_Seq_1_cy_psoc4_sar__SAR_STATUS EQU CYREG_SAR_STATUS

; ADC_SAR_Seq_1_intClock
ADC_SAR_Seq_1_intClock__DIVIDER_MASK EQU 0x0000FFFF
ADC_SAR_Seq_1_intClock__ENABLE EQU CYREG_CLK_DIVIDER_B00
ADC_SAR_Seq_1_intClock__ENABLE_MASK EQU 0x80000000
ADC_SAR_Seq_1_intClock__MASK EQU 0x80000000
ADC_SAR_Seq_1_intClock__REGISTER EQU CYREG_CLK_DIVIDER_B00

; ADC_SAR_Seq_1_IRQ
ADC_SAR_Seq_1_IRQ__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
ADC_SAR_Seq_1_IRQ__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
ADC_SAR_Seq_1_IRQ__INTC_MASK EQU 0x4000
ADC_SAR_Seq_1_IRQ__INTC_NUMBER EQU 14
ADC_SAR_Seq_1_IRQ__INTC_PRIOR_MASK EQU 0xC00000
ADC_SAR_Seq_1_IRQ__INTC_PRIOR_NUM EQU 3
ADC_SAR_Seq_1_IRQ__INTC_PRIOR_REG EQU CYREG_CM0_IPR3
ADC_SAR_Seq_1_IRQ__INTC_SET_EN_REG EQU CYREG_CM0_ISER
ADC_SAR_Seq_1_IRQ__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_GEN4 EQU 2
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 13
CYDEV_CHIP_DIE_PSOC4A EQU 6
CYDEV_CHIP_DIE_PSOC5LP EQU 12
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 6
CYDEV_CHIP_MEMBER_4C EQU 10
CYDEV_CHIP_MEMBER_4D EQU 3
CYDEV_CHIP_MEMBER_4E EQU 5
CYDEV_CHIP_MEMBER_4F EQU 7
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 4
CYDEV_CHIP_MEMBER_4L EQU 9
CYDEV_CHIP_MEMBER_4M EQU 8
CYDEV_CHIP_MEMBER_5A EQU 12
CYDEV_CHIP_MEMBER_5B EQU 11
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_GEN4_ES EQU 17
CYDEV_CHIP_REV_GEN4_ES2 EQU 33
CYDEV_CHIP_REV_GEN4_PRODUCTION EQU 17
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x0100
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_WDT_GENERATE_ISR EQU 0
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END