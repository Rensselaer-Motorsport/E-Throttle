.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* ADC_Ext_CP_Clk */
.set ADC_Ext_CP_Clk__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set ADC_Ext_CP_Clk__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set ADC_Ext_CP_Clk__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set ADC_Ext_CP_Clk__CFG2_SRC_SEL_MASK, 0x07
.set ADC_Ext_CP_Clk__INDEX, 0x00
.set ADC_Ext_CP_Clk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set ADC_Ext_CP_Clk__PM_ACT_MSK, 0x01
.set ADC_Ext_CP_Clk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set ADC_Ext_CP_Clk__PM_STBY_MSK, 0x01

/* ADC_theACLK */
.set ADC_theACLK__CFG0, CYREG_CLKDIST_ACFG0_CFG0
.set ADC_theACLK__CFG1, CYREG_CLKDIST_ACFG0_CFG1
.set ADC_theACLK__CFG2, CYREG_CLKDIST_ACFG0_CFG2
.set ADC_theACLK__CFG2_SRC_SEL_MASK, 0x07
.set ADC_theACLK__CFG3, CYREG_CLKDIST_ACFG0_CFG3
.set ADC_theACLK__CFG3_PHASE_DLY_MASK, 0x0F
.set ADC_theACLK__INDEX, 0x00
.set ADC_theACLK__PM_ACT_CFG, CYREG_PM_ACT_CFG1
.set ADC_theACLK__PM_ACT_MSK, 0x01
.set ADC_theACLK__PM_STBY_CFG, CYREG_PM_STBY_CFG1
.set ADC_theACLK__PM_STBY_MSK, 0x01

/* LCD_LCDPort */
.set LCD_LCDPort__0__MASK, 0x01
.set LCD_LCDPort__0__PC, CYREG_PRT2_PC0
.set LCD_LCDPort__0__PORT, 2
.set LCD_LCDPort__0__SHIFT, 0
.set LCD_LCDPort__1__MASK, 0x02
.set LCD_LCDPort__1__PC, CYREG_PRT2_PC1
.set LCD_LCDPort__1__PORT, 2
.set LCD_LCDPort__1__SHIFT, 1
.set LCD_LCDPort__2__MASK, 0x04
.set LCD_LCDPort__2__PC, CYREG_PRT2_PC2
.set LCD_LCDPort__2__PORT, 2
.set LCD_LCDPort__2__SHIFT, 2
.set LCD_LCDPort__3__MASK, 0x08
.set LCD_LCDPort__3__PC, CYREG_PRT2_PC3
.set LCD_LCDPort__3__PORT, 2
.set LCD_LCDPort__3__SHIFT, 3
.set LCD_LCDPort__4__MASK, 0x10
.set LCD_LCDPort__4__PC, CYREG_PRT2_PC4
.set LCD_LCDPort__4__PORT, 2
.set LCD_LCDPort__4__SHIFT, 4
.set LCD_LCDPort__5__MASK, 0x20
.set LCD_LCDPort__5__PC, CYREG_PRT2_PC5
.set LCD_LCDPort__5__PORT, 2
.set LCD_LCDPort__5__SHIFT, 5
.set LCD_LCDPort__6__MASK, 0x40
.set LCD_LCDPort__6__PC, CYREG_PRT2_PC6
.set LCD_LCDPort__6__PORT, 2
.set LCD_LCDPort__6__SHIFT, 6
.set LCD_LCDPort__AG, CYREG_PRT2_AG
.set LCD_LCDPort__AMUX, CYREG_PRT2_AMUX
.set LCD_LCDPort__BIE, CYREG_PRT2_BIE
.set LCD_LCDPort__BIT_MASK, CYREG_PRT2_BIT_MASK
.set LCD_LCDPort__BYP, CYREG_PRT2_BYP
.set LCD_LCDPort__CTL, CYREG_PRT2_CTL
.set LCD_LCDPort__DM0, CYREG_PRT2_DM0
.set LCD_LCDPort__DM1, CYREG_PRT2_DM1
.set LCD_LCDPort__DM2, CYREG_PRT2_DM2
.set LCD_LCDPort__DR, CYREG_PRT2_DR
.set LCD_LCDPort__INP_DIS, CYREG_PRT2_INP_DIS
.set LCD_LCDPort__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set LCD_LCDPort__LCD_EN, CYREG_PRT2_LCD_EN
.set LCD_LCDPort__MASK, 0x7F
.set LCD_LCDPort__PORT, 2
.set LCD_LCDPort__PRT, CYREG_PRT2_PRT
.set LCD_LCDPort__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set LCD_LCDPort__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set LCD_LCDPort__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set LCD_LCDPort__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set LCD_LCDPort__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set LCD_LCDPort__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set LCD_LCDPort__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set LCD_LCDPort__PS, CYREG_PRT2_PS
.set LCD_LCDPort__SHIFT, 0
.set LCD_LCDPort__SLW, CYREG_PRT2_SLW

/* PWM_PWMUDB */
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB03_04_ACTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB03_04_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB03_04_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB03_04_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB03_04_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B0_UDB03_04_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB03_04_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB03_04_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB03_04_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK, 0x80
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS, 7
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB03_ACTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG, CYREG_B0_UDB03_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG, CYREG_B0_UDB03_ST_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG, CYREG_B0_UDB03_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG, CYREG_B0_UDB03_ST_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK, 0x80
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB03_MSK_ACTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG, CYREG_B0_UDB03_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB03_MSK_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG, CYREG_B0_UDB02_03_A0
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG, CYREG_B0_UDB02_03_A1
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG, CYREG_B0_UDB02_03_D0
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG, CYREG_B0_UDB02_03_D1
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB02_03_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG, CYREG_B0_UDB02_03_F0
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG, CYREG_B0_UDB02_03_F1
.set PWM_PWMUDB_sP16_pwmdp_u0__A0_A1_REG, CYREG_B0_UDB02_A0_A1
.set PWM_PWMUDB_sP16_pwmdp_u0__A0_REG, CYREG_B0_UDB02_A0
.set PWM_PWMUDB_sP16_pwmdp_u0__A1_REG, CYREG_B0_UDB02_A1
.set PWM_PWMUDB_sP16_pwmdp_u0__D0_D1_REG, CYREG_B0_UDB02_D0_D1
.set PWM_PWMUDB_sP16_pwmdp_u0__D0_REG, CYREG_B0_UDB02_D0
.set PWM_PWMUDB_sP16_pwmdp_u0__D1_REG, CYREG_B0_UDB02_D1
.set PWM_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB02_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u0__F0_F1_REG, CYREG_B0_UDB02_F0_F1
.set PWM_PWMUDB_sP16_pwmdp_u0__F0_REG, CYREG_B0_UDB02_F0
.set PWM_PWMUDB_sP16_pwmdp_u0__F1_REG, CYREG_B0_UDB02_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG, CYREG_B0_UDB03_04_A0
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG, CYREG_B0_UDB03_04_A1
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG, CYREG_B0_UDB03_04_D0
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG, CYREG_B0_UDB03_04_D1
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB03_04_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG, CYREG_B0_UDB03_04_F0
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG, CYREG_B0_UDB03_04_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__A0_A1_REG, CYREG_B0_UDB03_A0_A1
.set PWM_PWMUDB_sP16_pwmdp_u1__A0_REG, CYREG_B0_UDB03_A0
.set PWM_PWMUDB_sP16_pwmdp_u1__A1_REG, CYREG_B0_UDB03_A1
.set PWM_PWMUDB_sP16_pwmdp_u1__D0_D1_REG, CYREG_B0_UDB03_D0_D1
.set PWM_PWMUDB_sP16_pwmdp_u1__D0_REG, CYREG_B0_UDB03_D0
.set PWM_PWMUDB_sP16_pwmdp_u1__D1_REG, CYREG_B0_UDB03_D1
.set PWM_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG, CYREG_B0_UDB03_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u1__F0_F1_REG, CYREG_B0_UDB03_F0_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__F0_REG, CYREG_B0_UDB03_F0
.set PWM_PWMUDB_sP16_pwmdp_u1__F1_REG, CYREG_B0_UDB03_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB03_MSK_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG, CYREG_B0_UDB03_MSK_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__0__MASK, 0x01
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__0__POS, 0
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB03_04_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__16BIT_STATUS_REG, CYREG_B0_UDB03_04_ST
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__2__MASK, 0x04
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__2__POS, 2
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__3__MASK, 0x08
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__3__POS, 3
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__5__MASK, 0x20
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__5__POS, 5
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__MASK, 0x2D
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__MASK_REG, CYREG_B0_UDB03_MSK
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB03_MSK_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB03_MSK_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_AUX_CTL_REG, CYREG_B0_UDB03_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_CNT_REG, CYREG_B0_UDB03_ST_CTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_CONTROL_REG, CYREG_B0_UDB03_ST_CTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_REG, CYREG_B0_UDB03_ST

/* ADC_DSM4 */
.set ADC_DSM4__BUF0, CYREG_DSM0_BUF0
.set ADC_DSM4__BUF1, CYREG_DSM0_BUF1
.set ADC_DSM4__BUF2, CYREG_DSM0_BUF2
.set ADC_DSM4__BUF3, CYREG_DSM0_BUF3
.set ADC_DSM4__CLK, CYREG_DSM0_CLK
.set ADC_DSM4__CR0, CYREG_DSM0_CR0
.set ADC_DSM4__CR1, CYREG_DSM0_CR1
.set ADC_DSM4__CR10, CYREG_DSM0_CR10
.set ADC_DSM4__CR11, CYREG_DSM0_CR11
.set ADC_DSM4__CR12, CYREG_DSM0_CR12
.set ADC_DSM4__CR13, CYREG_DSM0_CR13
.set ADC_DSM4__CR14, CYREG_DSM0_CR14
.set ADC_DSM4__CR15, CYREG_DSM0_CR15
.set ADC_DSM4__CR16, CYREG_DSM0_CR16
.set ADC_DSM4__CR17, CYREG_DSM0_CR17
.set ADC_DSM4__CR2, CYREG_DSM0_CR2
.set ADC_DSM4__CR3, CYREG_DSM0_CR3
.set ADC_DSM4__CR4, CYREG_DSM0_CR4
.set ADC_DSM4__CR5, CYREG_DSM0_CR5
.set ADC_DSM4__CR6, CYREG_DSM0_CR6
.set ADC_DSM4__CR7, CYREG_DSM0_CR7
.set ADC_DSM4__CR8, CYREG_DSM0_CR8
.set ADC_DSM4__CR9, CYREG_DSM0_CR9
.set ADC_DSM4__DEM0, CYREG_DSM0_DEM0
.set ADC_DSM4__DEM1, CYREG_DSM0_DEM1
.set ADC_DSM4__MISC, CYREG_DSM0_MISC
.set ADC_DSM4__OUT0, CYREG_DSM0_OUT0
.set ADC_DSM4__OUT1, CYREG_DSM0_OUT1
.set ADC_DSM4__REF0, CYREG_DSM0_REF0
.set ADC_DSM4__REF1, CYREG_DSM0_REF1
.set ADC_DSM4__REF2, CYREG_DSM0_REF2
.set ADC_DSM4__REF3, CYREG_DSM0_REF3
.set ADC_DSM4__RSVD1, CYREG_DSM0_RSVD1
.set ADC_DSM4__SW0, CYREG_DSM0_SW0
.set ADC_DSM4__SW2, CYREG_DSM0_SW2
.set ADC_DSM4__SW3, CYREG_DSM0_SW3
.set ADC_DSM4__SW4, CYREG_DSM0_SW4
.set ADC_DSM4__SW6, CYREG_DSM0_SW6
.set ADC_DSM4__TR0, CYREG_NPUMP_DSM_TR0
.set ADC_DSM4__TST0, CYREG_DSM0_TST0
.set ADC_DSM4__TST1, CYREG_DSM0_TST1

/* ADC_DEC */
.set ADC_DEC__COHER, CYREG_DEC_COHER
.set ADC_DEC__CR, CYREG_DEC_CR
.set ADC_DEC__DR1, CYREG_DEC_DR1
.set ADC_DEC__DR2, CYREG_DEC_DR2
.set ADC_DEC__DR2H, CYREG_DEC_DR2H
.set ADC_DEC__GCOR, CYREG_DEC_GCOR
.set ADC_DEC__GCORH, CYREG_DEC_GCORH
.set ADC_DEC__GVAL, CYREG_DEC_GVAL
.set ADC_DEC__OCOR, CYREG_DEC_OCOR
.set ADC_DEC__OCORH, CYREG_DEC_OCORH
.set ADC_DEC__OCORM, CYREG_DEC_OCORM
.set ADC_DEC__OUTSAMP, CYREG_DEC_OUTSAMP
.set ADC_DEC__OUTSAMPH, CYREG_DEC_OUTSAMPH
.set ADC_DEC__OUTSAMPM, CYREG_DEC_OUTSAMPM
.set ADC_DEC__OUTSAMPS, CYREG_DEC_OUTSAMPS
.set ADC_DEC__PM_ACT_CFG, CYREG_PM_ACT_CFG10
.set ADC_DEC__PM_ACT_MSK, 0x01
.set ADC_DEC__PM_STBY_CFG, CYREG_PM_STBY_CFG10
.set ADC_DEC__PM_STBY_MSK, 0x01
.set ADC_DEC__SHIFT1, CYREG_DEC_SHIFT1
.set ADC_DEC__SHIFT2, CYREG_DEC_SHIFT2
.set ADC_DEC__SR, CYREG_DEC_SR
.set ADC_DEC__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DEC_M1
.set ADC_DEC__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DEC_M2
.set ADC_DEC__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DEC_M3
.set ADC_DEC__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DEC_M4
.set ADC_DEC__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DEC_M5
.set ADC_DEC__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DEC_M6
.set ADC_DEC__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DEC_M7
.set ADC_DEC__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DEC_M8

/* ADC_IRQ */
.set ADC_IRQ__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set ADC_IRQ__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set ADC_IRQ__INTC_MASK, 0x20000000
.set ADC_IRQ__INTC_NUMBER, 29
.set ADC_IRQ__INTC_PRIOR_NUM, 7
.set ADC_IRQ__INTC_PRIOR_REG, CYREG_NVIC_PRI_29
.set ADC_IRQ__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set ADC_IRQ__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* PWM_out */
.set PWM_out__0__MASK, 0x80
.set PWM_out__0__PC, CYREG_PRT0_PC7
.set PWM_out__0__PORT, 0
.set PWM_out__0__SHIFT, 7
.set PWM_out__AG, CYREG_PRT0_AG
.set PWM_out__AMUX, CYREG_PRT0_AMUX
.set PWM_out__BIE, CYREG_PRT0_BIE
.set PWM_out__BIT_MASK, CYREG_PRT0_BIT_MASK
.set PWM_out__BYP, CYREG_PRT0_BYP
.set PWM_out__CTL, CYREG_PRT0_CTL
.set PWM_out__DM0, CYREG_PRT0_DM0
.set PWM_out__DM1, CYREG_PRT0_DM1
.set PWM_out__DM2, CYREG_PRT0_DM2
.set PWM_out__DR, CYREG_PRT0_DR
.set PWM_out__INP_DIS, CYREG_PRT0_INP_DIS
.set PWM_out__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set PWM_out__LCD_EN, CYREG_PRT0_LCD_EN
.set PWM_out__MASK, 0x80
.set PWM_out__PORT, 0
.set PWM_out__PRT, CYREG_PRT0_PRT
.set PWM_out__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set PWM_out__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set PWM_out__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set PWM_out__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set PWM_out__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set PWM_out__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set PWM_out__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set PWM_out__PS, CYREG_PRT0_PS
.set PWM_out__SHIFT, 7
.set PWM_out__SLW, CYREG_PRT0_SLW

/* Clock */
.set Clock__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set Clock__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set Clock__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set Clock__CFG2_SRC_SEL_MASK, 0x07
.set Clock__INDEX, 0x01
.set Clock__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock__PM_ACT_MSK, 0x02
.set Clock__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock__PM_STBY_MSK, 0x02

/* Pot */
.set Pot__0__MASK, 0x01
.set Pot__0__PC, CYREG_PRT0_PC0
.set Pot__0__PORT, 0
.set Pot__0__SHIFT, 0
.set Pot__AG, CYREG_PRT0_AG
.set Pot__AMUX, CYREG_PRT0_AMUX
.set Pot__BIE, CYREG_PRT0_BIE
.set Pot__BIT_MASK, CYREG_PRT0_BIT_MASK
.set Pot__BYP, CYREG_PRT0_BYP
.set Pot__CTL, CYREG_PRT0_CTL
.set Pot__DM0, CYREG_PRT0_DM0
.set Pot__DM1, CYREG_PRT0_DM1
.set Pot__DM2, CYREG_PRT0_DM2
.set Pot__DR, CYREG_PRT0_DR
.set Pot__INP_DIS, CYREG_PRT0_INP_DIS
.set Pot__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set Pot__LCD_EN, CYREG_PRT0_LCD_EN
.set Pot__MASK, 0x01
.set Pot__PORT, 0
.set Pot__PRT, CYREG_PRT0_PRT
.set Pot__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set Pot__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set Pot__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set Pot__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set Pot__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set Pot__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set Pot__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set Pot__PS, CYREG_PRT0_PS
.set Pot__SHIFT, 0
.set Pot__SLW, CYREG_PRT0_SLW

/* Miscellaneous */
/* -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release */
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_MEMBER_5B, 3
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_DIE_PSOC5LP, 3
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_DIE_PSOC5LP
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E13D069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_5A, 2
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REV_PSOC5LP_PRODUCTION
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC5LP_ES, 0
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_CONFIG_FORCE_ROUTE, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_REQXRES, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x1000
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x4000
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0, 5
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1, 5
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2, 5
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3, 5
.set CYDEV_VIO3_MV, 5000
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif