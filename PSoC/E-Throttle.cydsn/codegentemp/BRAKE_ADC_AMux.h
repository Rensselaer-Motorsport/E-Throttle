/*******************************************************************************
* File Name: BRAKE_ADC_AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_BRAKE_ADC_AMux_H)
#define CY_AMUX_BRAKE_ADC_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void BRAKE_ADC_AMux_Start(void) ;
#define BRAKE_ADC_AMux_Init() BRAKE_ADC_AMux_Start()
void BRAKE_ADC_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void BRAKE_ADC_AMux_Stop(void); */
/* void BRAKE_ADC_AMux_Select(uint8 channel); */
/* void BRAKE_ADC_AMux_Connect(uint8 channel); */
/* void BRAKE_ADC_AMux_Disconnect(uint8 channel); */
/* void BRAKE_ADC_AMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define BRAKE_ADC_AMux_CHANNELS  2u
#define BRAKE_ADC_AMux_MUXTYPE   1
#define BRAKE_ADC_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define BRAKE_ADC_AMux_NULL_CHANNEL 0xFFu
#define BRAKE_ADC_AMux_MUX_SINGLE   1
#define BRAKE_ADC_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if BRAKE_ADC_AMux_MUXTYPE == BRAKE_ADC_AMux_MUX_SINGLE
# if !BRAKE_ADC_AMux_ATMOSTONE
#  define BRAKE_ADC_AMux_Connect(channel) BRAKE_ADC_AMux_Set(channel)
# endif
# define BRAKE_ADC_AMux_Disconnect(channel) BRAKE_ADC_AMux_Unset(channel)
#else
# if !BRAKE_ADC_AMux_ATMOSTONE
void BRAKE_ADC_AMux_Connect(uint8 channel) ;
# endif
void BRAKE_ADC_AMux_Disconnect(uint8 channel) ;
#endif

#if BRAKE_ADC_AMux_ATMOSTONE
# define BRAKE_ADC_AMux_Stop() BRAKE_ADC_AMux_DisconnectAll()
# define BRAKE_ADC_AMux_Select(channel) BRAKE_ADC_AMux_FastSelect(channel)
void BRAKE_ADC_AMux_DisconnectAll(void) ;
#else
# define BRAKE_ADC_AMux_Stop() BRAKE_ADC_AMux_Start()
void BRAKE_ADC_AMux_Select(uint8 channel) ;
# define BRAKE_ADC_AMux_DisconnectAll() BRAKE_ADC_AMux_Start()
#endif

#endif /* CY_AMUX_BRAKE_ADC_AMux_H */


/* [] END OF FILE */
