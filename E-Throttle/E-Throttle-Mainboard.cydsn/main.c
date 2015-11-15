/* 
The main thread to run the E-Throttle on RM-21

Author: Mitchell Mellone (mellom3@rpi.edu)
Date Created: 11/15/15
Most Recent Modification: 11/15/15

Copyright (c) 2015 Rensselaer Motorsport
Distributed under the MIT License.
See "LICENSE" for more information.
*/

#include <project.h>
#include "local_handling.h"

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    float tps_percentage;
    float apps_percentage;
    
    /* INITIALIZATIONS */
    /* init tps and apps analog->digital converters */
    TPS_ADC_Start();
    APPS_ADC_Start();
    /* begin tps and apps analog->digital conversions */
    TPS_ADC_StartConvert();
    APPS_ADC_StartConvert();
    /* wait to fully convert all channels */
    TPS_ADC_IsEndConversion(TPS_ADC_WAIT_FOR_RESULT);
    APPS_ADC_IsEndConversion(APPS_ADC_WAIT_FOR_RESULT);
    
    for(;;)
    {
        /* Get the average tps and apps values */
        tps_percentage = tps_avg();
        apps_percentage = apps_avg();
        
        
        
        /* Wait for the next complete sampling of the TPS and APPS sensors */
        TPS_ADC_IsEndConversion(TPS_ADC_WAIT_FOR_RESULT);
        APPS_ADC_IsEndConversion(APPS_ADC_WAIT_FOR_RESULT);
    }
}

/* [] END OF FILE */
