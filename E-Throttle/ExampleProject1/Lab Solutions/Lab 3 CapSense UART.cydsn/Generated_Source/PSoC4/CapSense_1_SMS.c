/*******************************************************************************
* File Name: CapSense_1_SMS.c
* Version 1.0
*
* Description:
*  This file provides the source code of wrapper between CapSense CSD component 
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
#include "CapSense_1_SMS.h"
#include "CapSense_1_CSHL.h"

#include "cytypes.h"

#if (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING)

/* Declaration the sensetivity seed */
#if(CapSense_1_IDAC1_POLARITY == CapSense_1__IDAC_SINK)
	#if(CYDEV_VDDA_MV == 5000u)
		#define CapSense_1_SENSETIVITY_SEED (4801u)
	#else
		#define CapSense_1_SENSETIVITY_SEED (2653u)
	#endif/* (CYDEV_VDDA_MV == 5000u) */
#else
	#define CapSense_1_SENSETIVITY_SEED (1156u)
#endif /* (CapSense_1_IDAC1_POLARITY == CapSense_1__IDAC_SINK) */

#if(CapSense_1_PRS_OPTIONS != CapSense_1__PRS_NONE)
	extern uint8 CapSense_1_PrescalersTuningDone;
#endif /* (CapSense_1_PRS_OPTIONS == CapSense_1__PRS_NONE) */

#define CapSense_1_CAL_RAW_COUNT           (1024u)
#define CapSense_1_CAL_RAW_COUNT_SPLIT     (1740u)

#if(CYDEV_BCLK__HFCLK__MHZ > 12u)
	#define CapSense_1_IDAC2_MAX      (127u)
#elif(CYDEV_BCLK__HFCLK__MHZ > 6u)
	#define CapSense_1_IDAC2_MAX      (63u)
#else
	#define CapSense_1_IDAC2_MAX      (31u)
#endif /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */

static CapSense_1_ConfigType CapSense_1_Config;

extern const uint8 CapSense_1[];

extern uint16 CapSense_1_SensorRaw[];

extern uint32 CapSense_1_widgetResolution[];
extern uint8 CapSense_1_widgetNumber[];
extern uint8 CapSense_1_rawDataIndex[];
extern uint8 CapSense_1_numberOfSensors[];
extern uint32 CapSense_1_PRSResolutionTbl[];

extern uint8 CapSense_1_idac1Settings[];
extern uint8 CapSense_1_idac2Settings[];

extern uint8 CapSense_1_Clk1DividerVal[];
extern uint8 CapSense_1_Clk2DividerVal[];

extern uint8 CapSense_1_fingerThreshold[];
extern uint8 CapSense_1_noiseThreshold[];
extern uint8 CapSense_1_hysteresis[];

uint8 baNoiseEnvelope[CapSense_1_TOTAL_SCANSLOT_COUNT]; 
uint8 baRunningDifference[CapSense_1_TOTAL_SCANSLOT_COUNT];
uint8 baSignRegister[CapSense_1_TOTAL_SCANSLOT_COUNT];
uint16 waSampleMin[CapSense_1_TOTAL_SCANSLOT_COUNT];
uint16 waSampleMax[CapSense_1_TOTAL_SCANSLOT_COUNT];
uint16 waPreviousSample[CapSense_1_TOTAL_SCANSLOT_COUNT];
uint8 baK[CapSense_1_TOTAL_SCANSLOT_COUNT];              
uint8 baNoiseResetCounter[CapSense_1_TOTAL_SCANSLOT_COUNT];
uint8 waSnsResult[CapSense_1_TOTAL_SCANSLOT_COUNT];



/*******************************************************************************
* Function Name: CapSense_1_AutoTune
********************************************************************************
*
* Summary:
*  Provides tunning procedure for all sensors.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CapSense_1_AutoTune(void)
{
	uint8 curSensor;
    uint8 widget;
    
    CapSense_1_Config.totalScanslotsNum = CapSense_1_TOTAL_SCANSLOT_COUNT;
	CapSense_1_Config.totalWidgetsNum = CapSense_1_END_OF_WIDGETS_INDEX;
    CapSense_1_Config.idac1LevelsTbl = CapSense_1_idac1Settings;
    CapSense_1_Config.idac2LevelsTbl = CapSense_1_idac2Settings;
    CapSense_1_Config.sensetivityTbl = SMS_LIB_SensorSensitivity;
    CapSense_1_Config.chargeDivTbl = CapSense_1_Clk1DividerVal;
    CapSense_1_Config.modDivTbl = CapSense_1_Clk2DividerVal;
    CapSense_1_Config.widgetNubmersTbl = CapSense_1_widgetNumber;
    CapSense_1_Config.resolutionsTbl = CapSense_1_widgetResolution;
	CapSense_1_Config.rawDataIndex = CapSense_1_rawDataIndex;
	CapSense_1_Config.numberOfSensors = CapSense_1_numberOfSensors; 
    CapSense_1_Config.ptrGetRaw = CapSense_1_GetSensorRaw;
	CapSense_1_Config.IMOFreq_MHz = CYDEV_BCLK__SYSCLK__MHZ;
	CapSense_1_Config.sensetivitySeed = CapSense_1_SENSETIVITY_SEED;
	
	#if(CapSense_1_PRS_OPTIONS == CapSense_1__PRS_NONE)	
		CapSense_1_Config.prsEn = 0u;
	#else
		CapSense_1_Config.prsEn = 1u;
	#endif /* (CapSense_1_PRS_OPTIONS == CapSense_1__PRS_NONE) */
	
	CapSense_1_SetAnalogSwitchesSrc_Prescaler();
    
    for(curSensor = 0u; curSensor < CapSense_1_TOTAL_SCANSLOT_COUNT; curSensor++)
    {
        
        widget = CapSense_1_widgetNumber[curSensor];
        CapSense_1_widgetResolution[widget] = CapSense_1_RESOLUTION_11_BITS;
    }
    
    CapSense_1_DisableBaselineIDAC();
	
    CalibrateSensors(&CapSense_1_Config, CapSense_1_CAL_RAW_COUNT);
	
    TunePrescalers(&CapSense_1_Config);
	
	#if(CapSense_1_PRS_OPTIONS != CapSense_1__PRS_NONE)
		CapSense_1_PrescalersTuningDone = 1u;
	#endif /* (CapSense_1_PRS_OPTIONS == CapSense_1__PRS_NONE) */
	
	CapSense_1_NormalizeWidgets(CapSense_1_END_OF_WIDGETS_INDEX, CapSense_1_Clk1DividerVal);
	
    #if(CapSense_1_PRS_OPTIONS == CapSense_1__PRS_AUTO)
        CapSense_1_Calc_PRS_Resolution();
    #endif/* (CapSense_1_PRS_OPTIONS == CapSense_1__PRS_AUTO) */
    
	CapSense_1_EnableBaselineIDAC(&CapSense_1_Config);
    
    for(curSensor = 0u; curSensor < CapSense_1_TOTAL_SCANSLOT_COUNT; curSensor++)
    {
        widget = CapSense_1_widgetNumber[curSensor];
        
		#if(CapSense_1_FRACT_DIVIDERS_ENABLED == 1u)
			CapSense_1_widgetResolution[widget] = 0x09D80000;
		#else
			CapSense_1_widgetResolution[widget] = CapSense_1_RESOLUTION_11_BITS;
		#endif /* (CapSense_1_FRACT_DIVIDERS_ENABLED == 1u) */
    }
    
    CalibrateSensors(&CapSense_1_Config, CapSense_1_CAL_RAW_COUNT_SPLIT);
    
    TuneSensitivity(&CapSense_1_Config);
    
    for(curSensor = 0u; curSensor < CapSense_1_TOTAL_SCANSLOT_COUNT; curSensor++)
    {
        CapSense_1_CalculateThresholds(curSensor);
    }
}


/*******************************************************************************
* Function Name: CapSense_1_CalculateThresholds
********************************************************************************
*
* Summary:
*  Computes the noise and finger thresholds based on the high frequency noise
*  found in Noise_Calc and the amplitude of the signal from a recent finger
*  press.
*
* Parameters:
*  sensor: Sensor number.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_CalculateThresholds(uint8 sensor)
{
	uint32 fingerThleshold;
	uint8 widget;
	
	widget = CapSense_1_widgetNumber[sensor];
	
    CalculateThresholds(sensor, CapSense_1_SensorRaw, widget, 
                        CapSense_1_fingerThreshold, CapSense_1_noiseThreshold);
	
	fingerThleshold = CapSense_1_fingerThreshold[widget];
	
	if(fingerThleshold < 220u)
	{
		CapSense_1_hysteresis[widget] = fingerThleshold >> 3u;
	}
	else if(fingerThleshold <  237u)
	{
		CapSense_1_hysteresis[widget] = fingerThleshold >> 4u;
	}
	else if(fingerThleshold <  245u)
	{
		CapSense_1_hysteresis[widget] = fingerThleshold >> 5u;
	}
	else if(fingerThleshold <  250)
	{
		CapSense_1_hysteresis[widget] = fingerThleshold >> 6u;
	}
	else
	{
		CapSense_1_hysteresis[widget] = 0u;
	}                 
}

/*******************************************************************************
* Function Name: CapSense_1_DisableBaselineIDAC
********************************************************************************
*
* Summary:
*  Intended to disabling the baselining IDAC. 
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CapSense_1_DisableBaselineIDAC(void)
{
	CapSense_1_CSD_IDAC_REG &= ~(CapSense_1_CSD_IDAC1_MODE_MASK);
    CapSense_1_CSD_IDAC_REG &= ~(CapSense_1_CSD_IDAC2_MODE_MASK);
    
	CapSense_1_CSD_IDAC_REG |= CapSense_1_CSD_IDAC1_MODE_VARIABLE;
    CapSense_1_CSD_IDAC_REG |= CapSense_1_CSD_IDAC2_MODE_OFF;
}

/*******************************************************************************
* Function Name: CapSense_1_SetAnalogSwitchesSrc_PRS
********************************************************************************
*
* Summary:
*  Intended to enabling the baselining IDAC. 
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void  CapSense_1_EnableBaselineIDAC(CapSense_1_ConfigType *config)
{
    uint8 curSensor;
    
    for(curSensor = 0u; curSensor < config->totalScanslotsNum; curSensor++)
    {
        config->idac2LevelsTbl[curSensor] = CapSense_1_IDAC2_MAX;
    }
    
	CapSense_1_CSD_IDAC_REG &= ~(CapSense_1_CSD_IDAC1_MODE_MASK);
    CapSense_1_CSD_IDAC_REG &= ~(CapSense_1_CSD_IDAC2_MODE_MASK);
    
	CapSense_1_CSD_IDAC_REG |= CapSense_1_CSD_IDAC1_MODE_FIXED;
    CapSense_1_CSD_IDAC_REG |= CapSense_1_CSD_IDAC2_MODE_VARIABLE;
}

/*******************************************************************************
* Function Name: CapSense_1_GetSensorRaw
********************************************************************************
*
* Summary:
*  Intended to updatind and riding uprated raw data from sensor.
*
* Parameters:
*  sensor - Sensor number.
*
* Return:
*  Returns current raw data value for defined sensor number.
*
*******************************************************************************/
uint16  CapSense_1_GetSensorRaw(uint8 sensor, uint8 avgSamples)
{
	uint8 curSample;
	uint32 avgVal = 0u;
	
	for(curSample = 0u; curSample < avgSamples; curSample++)
	{
    
		CapSense_1_ScanSensor(sensor);
	    while(CapSense_1_IsBusy());
		avgVal += CapSense_1_ReadSensorRaw(sensor);
	}
    
    return(avgVal / avgSamples);
}

/*******************************************************************************
* Function Name: CapSense_1_NormalizeWidgets
********************************************************************************
*
* Summary:
*  Intended to align all parameters of widget to maximum paramrter.
*
* Parameters:
*  widgetsNum - Number of widgets.
*  datsPrt - pointer ro array with widget parameters.	
*
* Return:
*  None
*
*******************************************************************************/
void CapSense_1_NormalizeWidgets(uint32 widgetsNum, uint8 *dataPtr)
{
	uint32 currentWidget;
	uint32 currentSensor = 0u;
	uint32 lastSensor = 0u;
	uint32 sensorsPerWidget;
	uint32 maxPerWidget;
	
	
	for(currentWidget = 0u; currentWidget < widgetsNum; currentWidget++)
	{
		maxPerWidget = 0u;
		
		sensorsPerWidget = CapSense_1_numberOfSensors[currentWidget];
		currentSensor = CapSense_1_rawDataIndex[currentWidget];
		lastSensor = currentSensor + sensorsPerWidget;
		
		while(currentSensor < lastSensor)
		{
			if(maxPerWidget < dataPtr[currentSensor])
			{
				maxPerWidget = dataPtr[currentSensor];
			}
			currentSensor++;
		}
		
		currentSensor = CapSense_1_rawDataIndex[currentWidget];
		
		while(currentSensor < lastSensor)
		{
			dataPtr[currentSensor] = maxPerWidget;
			currentSensor++;
		}
	}
}


/*******************************************************************************
* Function Name: CapSense_1_SetAnalogSwitchesSrc_Prescaler
********************************************************************************
*
* Summary:
*  Intedned to switching charge clock source to prescaler. 
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CapSense_1_SetAnalogSwitchesSrc_Prescaler(void)
{
	CapSense_1_CSD_CFG_REG &= ~(CapSense_1_CSD_CFG_PRS_SELECT);
}

#endif /* (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING) */

/* [] END OF FILE */
