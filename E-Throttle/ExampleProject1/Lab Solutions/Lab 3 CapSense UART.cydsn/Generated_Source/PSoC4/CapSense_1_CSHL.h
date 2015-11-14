/*******************************************************************************
* File Name: CapSense_1_CSHL.h
* Version 2.20
*
* Description:
*  This file provides constants and parameter values for the High Level APIs
*  for CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_CSHL_CapSense_1_H)
#define CY_CAPSENSE_CSD_CSHL_CapSense_1_H

#include "CapSense_1.h"


/***************************************
*   Condition compilation parameters
***************************************/

#define CapSense_1_SIGNAL_SIZE                    (8u)
#define CapSense_1_AUTO_RESET                     (0u)
#define CapSense_1_RAW_FILTER_MASK                (0u)

/* Signal size definition */
#define CapSense_1_SIGNAL_SIZE_UINT8              (8u)
#define CapSense_1_SIGNAL_SIZE_UINT16             (16u)

/* Auto reset definition */
#define CapSense_1_AUTO_RESET_DISABLE             (0u)
#define CapSense_1_AUTO_RESET_ENABLE              (1u)

/* Mask for RAW and POS filters */
#define CapSense_1_MEDIAN_FILTER                  (0x01u)
#define CapSense_1_AVERAGING_FILTER               (0x02u)
#define CapSense_1_IIR2_FILTER                    (0x04u)
#define CapSense_1_IIR4_FILTER                    (0x08u)
#define CapSense_1_JITTER_FILTER                  (0x10u)
#define CapSense_1_IIR8_FILTER                    (0x20u)
#define CapSense_1_IIR16_FILTER                   (0x40u)
#define CapSense_1_RAW_FILTERS_ENABLED            (0x01u)                                                   
#define CapSense_1_RAW_FILTERS_DISABLED           (0x00u) 

/***************************************
*           API Constants
***************************************/

/* Widgets constants definition */
#define CapSense_1_LINEARSLIDER0__LS        (0u)

#define CapSense_1_TOTAL_DIPLEXED_SLIDERS_COUNT        (0u)
#define CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT          (1u)
#define CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT          (0u)
#define CapSense_1_TOTAL_TOUCH_PADS_COUNT              (0u)
#define CapSense_1_TOTAL_TOUCH_PADS_BASIC_COUNT        (0u)
#define CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT       (0u)
#define CapSense_1_TOTAL_BUTTONS_COUNT                 (0u)
#define CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT          (0u)
#define CapSense_1_TOTAL_GENERICS_COUNT                (0u)

#define CapSense_1_POS_FILTERS_MASK                    (0x8u)
#define CapSense_1_LINEAR_SLIDERS_POS_FILTERS_MASK     (0x8u)
#define CapSense_1_RADIAL_SLIDERS_POS_FILTERS_MASK     (0x0u)
#define CapSense_1_TOUCH_PADS_POS_FILTERS_MASK         (0x0u)
#define CapSense_1_TRACKPAD_GEST_POS_FILTERS_MASK      (0x0u)

#define CapSense_1_UNUSED_DEBOUNCE_COUNTER_INDEX       (0u)

#define CapSense_1_TOTAL_PROX_SENSORS_COUNT            (0u)

#define CapSense_1_END_OF_SLIDERS_INDEX                (0u)
#define CapSense_1_END_OF_TOUCH_PAD_INDEX              (0u)
#define CapSense_1_END_OF_BUTTONS_INDEX                (0u)
#define CapSense_1_END_OF_MATRIX_BUTTONS_INDEX         (0u)
#define CapSense_1_END_OF_WIDGETS_INDEX                (1u)



#define CapSense_1_TOTAL_SLIDERS_COUNT            ( CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT + \
                                                          CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT )
                                                          
#define CapSense_1_TOTAL_CENTROIDS_COUNT          ( CapSense_1_TOTAL_SLIDERS_COUNT + \
                                                         (CapSense_1_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u) +\
														 (CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT * 4u))

#define CapSense_1_TOTAL_CENTROIDS_BASIC_COUNT    ( CapSense_1_TOTAL_SLIDERS_COUNT + \
                                                         (CapSense_1_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u))

#define CapSense_1_TOTAL_CENTROID_AXES_COUNT      ( CapSense_1_TOTAL_SLIDERS_COUNT + \
                                                         (CapSense_1_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u) +\
														 (CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT * 2u))

#define CapSense_1_TOTAL_WIDGET_COUNT             ( CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT + \
                                                          CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT + \
                                                          CapSense_1_TOTAL_TOUCH_PADS_COUNT + \
                                                          CapSense_1_TOTAL_BUTTONS_COUNT + \
                                                          CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT )
                                                           
#define CapSense_1_ANY_POS_FILTER                 ( CapSense_1_MEDIAN_FILTER | \
                                                          CapSense_1_AVERAGING_FILTER | \
                                                          CapSense_1_IIR2_FILTER | \
                                                          CapSense_1_IIR4_FILTER | \
                                                          CapSense_1_JITTER_FILTER )
                                                         
#define CapSense_1_IS_DIPLEX_SLIDER               ( CapSense_1_TOTAL_DIPLEXED_SLIDERS_COUNT > 0u)

#define CapSense_1_IS_NON_DIPLEX_SLIDER           ( (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT - \
                                                           CapSense_1_TOTAL_DIPLEXED_SLIDERS_COUNT) > 0u)
#define CapSense_1_ADD_SLIDER_TYPE                ((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT > 0u) ? \
                                                        ((CapSense_1_TOTAL_TOUCH_PADS_COUNT > 0u) || \
                                                         (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT > 0u)) : 0u)

#define CapSense_1_TOTAL_PROX_SENSOR_COUNT		(CapSense_1_TOTAL_PROX_SENSORS_COUNT)

#define CapSense_1_WIDGETS_TBL_SIZE               ( CapSense_1_TOTAL_WIDGET_COUNT + \
                                                          CapSense_1_TOTAL_GENERICS_COUNT)
                                                          
#define CapSense_1_WIDGET_PARAM_TBL_SIZE		    (CapSense_1_TOTAL_BUTTONS_COUNT + \
														 CapSense_1_TOTAL_SLIDERS_COUNT +\
                                                         CapSense_1_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u + \
														 CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT * 2u +\
                                                         CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT * 2u)

#define CapSense_1_THRESHOLD_TBL_SIZE			(CapSense_1_WIDGET_PARAM_TBL_SIZE)
#define CapSense_1_DEBOUNCE_CNT_TBL_SIZE		(CapSense_1_WIDGET_PARAM_TBL_SIZE)
#define CapSense_1_RAW_DATA_INDEX_TBL_SIZE	(CapSense_1_WIDGET_PARAM_TBL_SIZE +\
													 CapSense_1_TOTAL_GENERICS_COUNT)

#define CapSense_1_RES_MULT               	(256u)


#define CapSense_1_NOT_WIDGET		                (0xFFFFFFFFu)
														  
/*Types of centroids */
#define CapSense_1_TYPE_RADIAL_SLIDER             (0x01u)
#define CapSense_1_TYPE_LINEAR_SLIDER             (0x02u)
#define CapSense_1_TYPE_GENERIC                   (0xFFu)

/* Defines if sensors or widgets are active */
#define CapSense_1_SENSOR_IS_ACTIVE               (0x01u)
#define CapSense_1_SENSOR_1_IS_ACTIVE     		(0x01u)
#define CapSense_1_SENSOR_2_IS_ACTIVE     		(0x02u)
#define CapSense_1_WIDGET_IS_ACTIVE               (0x01u)

/* Defines diplex type of Slider */
#define CapSense_1_IS_DIPLEX                      (0x80u)

/* Defines fingers positions on Slider  */
#define CapSense_1_POS_PREV                       (0u)
#define CapSense_1_POS                            (1u)
#define CapSense_1_POS_NEXT                       (2u)
#define CapSense_1_CENTROID_ROUND_VALUE           (0x7F00u)
#define CapSense_1_MAXIMUM_CENTROID               (0xFFu)

#define CapSense_1_NEGATIVE_NOISE_THRESHOLD       (20u)
#define CapSense_1_LOW_BASELINE_RESET             (5u)


/***************************************
*        Function Prototypes
***************************************/

void CapSense_1_InitializeSensorBaseline(uint32 sensor);
void CapSense_1_InitializeAllBaselines(void);
void CapSense_1_InitializeEnabledBaselines(void);
void CapSense_1_UpdateSensorBaseline(uint32 sensor);
void CapSense_1_UpdateBaselineNoThreshold(uint32 sensor);
void CapSense_1_UpdateEnabledBaselines(void);
void CapSense_1_UpdateWidgetBaseline(uint32 widget);
uint16 CapSense_1_GetBaselineData(uint32 sensor);
void CapSense_1_SetBaselineData(uint32 sensor, uint16 data);
void CapSense_1_BaseInit(uint32 sensor);

#if (CapSense_1_IS_DIPLEX_SLIDER)
	uint8 CapSense_1_FindMaximum(uint8 offset, uint8 count, uint8 fingerThreshold, const uint8 *diplex);
#else 
	uint8 CapSense_1_FindMaximum(uint8 offset, uint8 count, uint8 fingerThreshold);
#endif /* (CapSense_1_IS_DIPLEX_SLIDER) */

#if (CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT > 0u)
	uint8 CapSense_1_CalcCentroid(uint8 maximum, uint8 offset, \
                                    uint8 count, uint32 resolution, uint8 noiseThreshold);
#else								
	uint8 CapSense_1_CalcCentroid(uint8 maximum, uint8 offset, \
                                    uint8 count, uint16 resolution, uint8 noiseThreshold);										
#endif /* (CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT > 0u) */


uint8 CapSense_1_GetFingerThreshold(uint32 widget);
uint8 CapSense_1_GetNoiseThreshold(uint32 widget);
uint8 CapSense_1_GetFingerHysteresis(uint32 widget);
uint8 CapSense_1_GetNegativeNoiseThreshold(uint32 widget);

#if(CapSense_1_TUNING_METHOD != CapSense_1__TUNING_NONE)
	void CapSense_1_SetFingerThreshold(uint32 widget, uint8 value);
	void CapSense_1_SetNoiseThreshold(uint32 widget, uint8 value);
	void CapSense_1_SetFingerHysteresis(uint32 widget, uint8 value);
	void CapSense_1_SetNegativeNoiseThreshold(uint32 widget, uint8 value);
	void CapSense_1_SetDebounce(uint32 widget, uint8 value);
	void CapSense_1_SetLowBaselineReset(uint32 sensor, uint8 value);
#endif /* (CapSense_1_TUNING_METHOD != CapSense_1__TUNING_NONE) */

uint8 CapSense_1_GetDiffCountData(uint32 sensor);
void CapSense_1_SetDiffCountData(uint32 sensor, uint8 value);								
							
uint32 CapSense_1_CheckIsSensorActive(uint32 sensor);
uint32 CapSense_1_CheckIsWidgetActive(uint32 widget);
uint32 CapSense_1_CheckIsAnyWidgetActive(void);
void CapSense_1_EnableWidget(uint32 widget);
void CapSense_1_DisableWidget(uint32 widget);
void CapSense_1_EnableRawDataFilters(void);
void CapSense_1_DisableRawDataFilters(void);

#if (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT)
    uint32 CapSense_1_GetMatrixButtonPos(uint32 widget, uint8* pos);
#endif /* (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT) */

#if((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT > 0u))
    uint16 CapSense_1_GetCentroidPos(uint32 widget);
#endif /* ((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT > 0u)) */
#if((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT > 0u))
    uint16 CapSense_1_GetRadialCentroidPos(uint32 widget);
#endif /* #if((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT > 0u)) */
#if (CapSense_1_TOTAL_TOUCH_PADS_COUNT)
    uint32 CapSense_1_GetTouchCentroidPos(uint32 widget, uint16* pos);
#endif /* (CapSense_1_TOTAL_TOUCH_PADS_COUNT) */

uint32 CapSense_1_GetWidgetNumber(uint32 sensor);
uint8 CapSense_1_GetLowBaselineReset(uint32 sensor);
uint8 CapSense_1_GetDebounce(uint32 widget);

/* Filter function prototypes for High level APIs */

/* Median filter function prototype */
#if ( (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_MEDIAN_FILTER)) || \
      (0u != (CapSense_1_POS_FILTERS_MASK & CapSense_1_MEDIAN_FILTER)) || \
      ((CapSense_1_TUNING_METHOD == CapSense_1__TUNING_AUTO)) )
    uint16 CapSense_1_MedianFilter(uint16 x1, uint16 x2, uint16 x3);
#endif /* ( (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_MEDIAN_FILTER)) || \
      (0u != (CapSense_1_POS_FILTERS_MASK & CapSense_1_MEDIAN_FILTER)) || \
      ((CapSense_1_TUNING_METHOD == CapSense_1__TUNING_AUTO)) ) */

/* Averaging filter function prototype */
#if ( (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_AVERAGING_FILTER)) || \
      (0u != (CapSense_1_POS_FILTERS_MASK & CapSense_1_AVERAGING_FILTER)) )
    uint16 CapSense_1_AveragingFilter(uint16 x1, uint16 x2, uint16 x3);
#endif /* CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* IIR2Filter(1/2prev + 1/2cur) filter function prototype */
#if ( (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR2_FILTER)) || \
      (0u != (CapSense_1_POS_FILTERS_MASK & CapSense_1_IIR2_FILTER)) )
    uint16 CapSense_1_IIR2Filter(uint16 x1, uint16 x2);
#endif /* CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* IIR4Filter(3/4prev + 1/4cur) filter function prototype */
#if ( (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR4_FILTER)) || \
      (0u != (CapSense_1_POS_FILTERS_MASK & CapSense_1_IIR4_FILTER)) )
    uint16 CapSense_1_IIR4Filter(uint16 x1, uint16 x2);
#endif /* CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* IIR8Filter(7/8prev + 1/8cur) filter function prototype - RawCounts only */
#if (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR8_FILTER))
    uint16 CapSense_1_IIR8Filter(uint16 x1, uint16 x2);
#endif /* CapSense_1_RAW_FILTER_MASK */

/* IIR16Filter(15/16prev + 1/16cur) filter function prototype - RawCounts only */
#if (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR16_FILTER))
    uint16 CapSense_1_IIR16Filter(uint16 x1, uint16 x2);
#endif /* CapSense_1_RAW_FILTER_MASK */

/* JitterFilter filter function prototype */
#if ( (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_JITTER_FILTER)) || \
      (0u != (CapSense_1_POS_FILTERS_MASK & CapSense_1_JITTER_FILTER)) || \
      (0u != (CapSense_1_TRACKPAD_GEST_POS_FILTERS_MASK & CapSense_1_JITTER_FILTER))) 
    uint16 CapSense_1_JitterFilter(uint16 x1, uint16 x2);
#endif /* ( (0u != (CapSense_1_RAW_FILTER_MASK & CapSense_1_JITTER_FILTER)) || \
       *    (0u != (CapSense_1_POS_FILTERS_MASK & CapSense_1_JITTER_FILTER)) )
	   *    (0u != (CapSense_1_TRACKPAD_GEST_POS_FILTERS_MASK & CapSense_1_JITTER_FILTER)) )
       */


/***************************************
*     Vars with External Linkage
***************************************/
extern uint16 CapSense_1_sensorBaseline[CapSense_1_TOTAL_SENSOR_COUNT];
extern uint8  CapSense_1_sensorBaselineLow[CapSense_1_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_1_sensorSignal[CapSense_1_TOTAL_SENSOR_COUNT];
extern uint8  CapSense_1_sensorOnMask[CapSense_1_TOTAL_SENSOR_MASK];

extern uint8 CapSense_1_lowBaselineResetCnt[CapSense_1_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_1_lowBaselineReset[CapSense_1_TOTAL_SENSOR_COUNT];

/* Generated by Customizer */
#if (CapSense_1_TUNING_METHOD != CapSense_1__TUNING_NONE)
	extern uint8 CapSense_1_fingerThreshold[CapSense_1_WIDGET_PARAM_TBL_SIZE];
	extern uint8 CapSense_1_noiseThreshold[CapSense_1_WIDGET_PARAM_TBL_SIZE];
	extern uint8 CapSense_1_negativeNoiseThreshold[CapSense_1_WIDGET_PARAM_TBL_SIZE];
	extern uint8 CapSense_1_hysteresis[CapSense_1_WIDGET_PARAM_TBL_SIZE];
	extern uint8  CapSense_1_debounce[CapSense_1_WIDGET_PARAM_TBL_SIZE];
#else
	extern const uint8 CapSense_1_fingerThreshold[CapSense_1_WIDGET_PARAM_TBL_SIZE];
	extern const uint8 CapSense_1_noiseThreshold[CapSense_1_WIDGET_PARAM_TBL_SIZE];
	extern const uint8 CapSense_1_hysteresis[CapSense_1_WIDGET_PARAM_TBL_SIZE];
	extern const uint8  CapSense_1_debounce[CapSense_1_WIDGET_PARAM_TBL_SIZE];
#endif /* (CapSense_1_TUNING_METHOD != CapSense_1__TUNING_NONE) */

extern const uint8 CapSense_1_rawDataIndex[CapSense_1_RAW_DATA_INDEX_TBL_SIZE];
extern const uint8 CapSense_1_numberOfSensors[CapSense_1_RAW_DATA_INDEX_TBL_SIZE];

#if (0u != CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT)
    #if (CapSense_1_TUNING_METHOD != CapSense_1__TUNING_NONE)
		extern uint8 CapSense_1_posFiltersMask[CapSense_1_TOTAL_CENTROID_AXES_COUNT];
	#else
		extern const uint8 CapSense_1_posFiltersMask[CapSense_1_TOTAL_CENTROID_AXES_COUNT];
	#endif /* (CapSense_1_TUNING_METHOD != CapSense_1__TUNING_NONE) */

	extern uint32 CapSense_1_centroidMult[CapSense_1_TOTAL_CENTROID_AXES_COUNT];
#endif /* (0u != CapSense_1_TOTAL_TRACKPAD_GESTURES_COUNT) */	

/***************************************
*        Obsolete Names
***************************************/
#define CapSense_1_SensorRaw				CapSense_1_sensorRaw
#define CapSense_1_SensorEnableMask		CapSense_1_sensorEnableMask
#define CapSense_1_SensorBaseline			CapSense_1_sensorBaseline
#define CapSense_1_SensorBaselineLow		CapSense_1_sensorBaselineLow
#define CapSense_1_SensorSignal			CapSense_1_sensorSignal
#define CapSense_1_SensorOnMask			CapSense_1_sensorOnMask
#define CapSense_1_LowBaselineResetCnt	CapSense_1_lowBaselineResetCnt

#endif /* CY_CAPSENSE_CSD_CSHL_CapSense_1_H */

/* [] END OF FILE */
