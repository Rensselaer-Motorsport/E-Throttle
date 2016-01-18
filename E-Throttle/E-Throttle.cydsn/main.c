/* ========================================
    The main thread to run the E-Throttle code.

    Author: Mitchell Mellone (mellom3@rpi.edu)
    Date Created: 12/30/15
    Most Recent Modification: 12/30/15

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#include <project.h>
#include "signal_processing.h"


int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    int16 apps0_raw, apps1_raw, tps0_raw, tps1_raw, brake_raw;
    float apps0_percent, apps1_percent, tps0_percent, tps1_percent, brake_percent;
    float apps_avg, tps_avg;

    /* Initializations */
    Error_Buffer * err_buff = createErrorBuffer();
    APPS_ADC_Start();
    TPS_ADC_Start();
    APPS_ADC_StartConvert();
    TPS_ADC_StartConvert();

    for(;;)
    {
        /* Get the raw APPS result */
        APPS_ADC_StartConvert();
        APPS_ADC_IsEndConversion(APPS_ADC_WAIT_FOR_RESULT);
        apps0_raw = APPS_ADC_GetResult16(0);
        apps1_raw = APPS_ADC_GetResult16(1);
        /* Get the raw TPS result */
        TPS_ADC_StartConvert();
        TPS_ADC_IsEndConversion(TPS_ADC_WAIT_FOR_RESULT);
        tps0_raw = TPS_ADC_GetResult16(0);
        tps1_raw = TPS_ADC_GetResult16(1);
        /* Get the brake encoder result */
        brake_raw = BRAKE_ADC_Read16();
    
        /* Convert to percents */
        apps0_percent = convertToPercent(apps0_raw, APPS);
        apps1_percent = convertToPercent(apps1_raw, APPS);
        tps0_percent = convertToPercent(tps0_raw, TPS);
        tps1_percent = convertToPercent(tps1_raw, TPS);
        brake_percent = convertToPercent(brake_raw, BRAKE);
        
        /* Average and check for error */
        apps_avg = average(apps0_percent, apps1_percent);
        tps_avg = average(tps0_percent, tps1_percent);
        if (apps_avg == ERROR || tps_avg == ERROR) {
            /* TODO: Handle error */
            return ERROR;
        }
        
        /* TODO: Figure out how to write value to servo out */
    }
}

/* [] END OF FILE */
