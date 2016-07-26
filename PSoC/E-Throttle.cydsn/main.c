/* ========================================
    The main thread to run the E-Throttle code.

    Author: Mitchell Mellone (mellom3@rpi.edu)

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#include <project.h>
#include "signal_processing.h"
#include "communication.h"
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

/* returns a simulated count value based off of previous pot
count 
*/
int simulatePot(int prev_count, int max_count) {
    int increase = rand() % 2; /* boolean value */
    int mag = rand() % (max_count / 100); /* allow a maximum movement of 1 percent */
    
    int next_count = increase ? prev_count + mag : prev_count - mag;
    
    /* make sure the value stays within 15%-85% max range so
       that errors can always be simulated */
    if (next_count < (int)((double)max_count * 15.0) ) {
        return 0;
    } else if (next_count > max_count - (int)((double)max_count * 15.0)) {
        return max_count-1;
    } else {
        return next_count;
    }
}

/* takes in a current count value and produces one > 10% away
   to simulate an error happending.
*/
float simulateErr(float curr_pct_open) {
    int increase = rand() % 2;
    return increase ? curr_pct_open + 12.0 : curr_pct_open - 12.0;
}

int main()
{
    UART_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    srand(time(0)); /* seed random number generator */

    
    uint16 apps0_count, apps1_count, tps0_count, tps1_count, brake_count;
    float apps0_percent, apps1_percent, tps0_percent, tps1_percent, brake_percent;
    float apps_avg, tps_avg, prev_throttle_pos;
    

    /* Initializations */
    Error_Buffer * err_buff = createErrorBuffer();
    Timer_Start();
    APPS_ADC_Start();
    TPS_ADC_Start();
    BRAKE_ADC_Start();
    APPS_ADC_StartConvert();
    TPS_ADC_StartConvert();
    BRAKE_ADC_StartConvert();
    prev_throttle_pos = 0.0;
    
    /* initialize counts for simulation */
    apps0_count = apps1_count = MAX_APPS_COUNT / 2;
    tps0_count = tps1_count = MAX_TPS_COUNT / 2;
    brake_count = 0; /* keep at 0 for the first set of tests */

    for(;;)
    {
        /* REAL POTS */
//        /* Get the count APPS result */
//        APPS_ADC_StartConvert();
//        APPS_ADC_IsEndConversion(APPS_ADC_WAIT_FOR_RESULT);
//        apps0_count = APPS_ADC_GetResult16(0);
//        apps1_count = APPS_ADC_GetResult16(1);
//        /* Get the count TPS result */
//        TPS_ADC_StartConvert();
//        TPS_ADC_IsEndConversion(TPS_ADC_WAIT_FOR_RESULT);
//        tps0_count = TPS_ADC_GetResult16(0);
//        tps1_count = TPS_ADC_GetResult16(1);
//        /* Get the brake encoder result */
//        brake_count = BRAKE_ADC_Read16();
//        /* Check to make sure there are no open/short circuits */
//        if (signalCheck(tps0_count, tps0_count, apps0_count, apps1_count, brake_count) == ERROR) {
//            handleError();
//        }
        
        /* SIMULATED POTS */
        apps0_count = apps1_count = simulatePot(apps0_count, MAX_APPS_COUNT);
        tps0_count = tps1_count = simulatePot(tps0_count, MAX_TPS_COUNT);
        
        /* Check for open or short circuit signals */
        if (signalCheck(tps0_count, tps1_count, apps0_count, apps1_count, brake_count) == ERROR) {
            handleError();
        }
    
        /* Convert to percents */
        apps0_percent = convertToPercent(apps0_count, APPS);
        apps1_percent = convertToPercent(apps1_count, APPS);
        tps0_percent = convertToPercent(tps0_count, TPS);
        tps1_percent = convertToPercent(tps1_count, TPS);
        brake_percent = convertToPercent(brake_count, BRAKE);
        
        /* Average and check for local errors */
        apps_avg = average(apps0_percent, apps1_percent);
        tps_avg = average(tps0_percent, tps1_percent);
        if (apps_avg == fERROR || tps_avg == fERROR) {
            handleError();
        }
        
        /* Get next throttle position */
        int next_throttle_pos = 
            nextThrottlePosition(apps_avg, tps_avg, prev_throttle_pos, brake_percent, err_buff);
        if (next_throttle_pos == fERROR) {
            handleError();
        }
            
        /* TODO: Figure out how to write value to servo out */
    }
}

/* [] END OF FILE */
