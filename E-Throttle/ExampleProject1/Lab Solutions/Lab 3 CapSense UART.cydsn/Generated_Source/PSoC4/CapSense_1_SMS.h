/*******************************************************************************
* File Name: CapSense_1_SMS.h
* Version 1.0
*
* Description:
*  This file provides the declarations of wrapper between CapSense CSD component 
*  and Auto Tuning library.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_CAPSENSE_CSD_SMS_CapSense_1_H)
#define CY_CAPSENSE_CSD_SMS_CapSense_1_H

#include "CapSense_1.h"

#define CapSense_1_FRACT_DIVIDERS_ENABLED (0u)

typedef struct
{
    uint8 totalScanslotsNum;
	uint8 totalWidgetsNum;
    uint8 *idac1LevelsTbl;
    uint8 *idac2LevelsTbl;
    const uint8 *sensetivityTbl;
    uint8 *chargeDivTbl;
    uint8 *modDivTbl;
    uint8  *widgetNubmersTbl;
    uint32 *resolutionsTbl;
	uint8  *rawDataIndex;
	uint8  *numberOfSensors;
    uint16 IMOFreq_MHz;
    uint16 (*ptrGetRaw)(uint8 sensor, uint8 avgSamples);
	uint16 sensetivitySeed;
	uint8 prsEn;
}CapSense_1_ConfigType;

void CapSense_1_AutoTune(void);
void CapSense_1_CalculateThresholds(uint8 sensor);

void CapSense_1_DisableBaselineIDAC(void);
void CapSense_1_EnableBaselineIDAC(CapSense_1_ConfigType *config);

void CapSense_1_SetAnalogSwitchesSrc_Prescaler(void);

uint16  CapSense_1_GetSensorRaw(uint8 sensor, uint8 avgSamples);

void CapSense_1_NormalizeWidgets(uint32 widgetsNum, uint8 *dataPtr);

void TunePrescalers(CapSense_1_ConfigType *config);
void TuneSensitivity(CapSense_1_ConfigType *config);
void CalculateThresholds(const uint8 bSensorNumber, const uint16 *rawData, const uint8 widget, uint8 *bFingerThres, uint8 *bNoiseThres);
void CalibrateSensors(CapSense_1_ConfigType *config, uint16 rawLevel);

#endif  /* (CY_CAPSENSE_CSD_SMS_CapSense_1_H) */

//[] END OF FILE
