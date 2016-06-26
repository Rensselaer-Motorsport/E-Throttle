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
#include "communication.h"

void commTest() {
    float tps0, tps1, apps0, apps1, brake; //simulated percents open
    float* sensors[5];
    sensors[0] = &tps0;
    sensors[1] = &tps1;
    sensors[2] = &apps0;
    sensors[3] = &apps1;
    sensors[4] = &brake;
    int i;
    for (i = 0; i < 5; ++i) {
        *sensors[i] = 0;
    }
    
    for (;;) {
        int i;
        for (i = 0; i < 5; i++) {
            *sensors[i] += 0.5;
            if (*sensors[i] > 100.0) {
                *sensors[i] = 0.0;
            }
        }
        send_pot_data(TPS0, tps0);
        send_pot_data(TPS1, tps1);
        send_pot_data(APPS0, apps0);
        send_pot_data(APPS1, apps1);
        send_pot_data(BRAKE, brake);
        CyDelay(50);
    }
}

int main()
{
    UART_Start();
    commTest();
//    for(;;) {
//        UART_PutChar('A');
//    }
    return 0;
//    CyGlobalIntEnable; /* Enable global interrupts. */
//    
//    uint16 apps0_count, apps1_count, tps0_count, tps1_count, brake_count;
//    float apps0_percent, apps1_percent, tps0_percent, tps1_percent, brake_percent;
//    float apps_avg, tps_avg, prev_throttle_pos;
//    
//
//    /* Initializations */
//    Error_Buffer * err_buff = createErrorBuffer();
//    Timer_Start();
//    APPS_ADC_Start();
//    TPS_ADC_Start();
//    BRAKE_ADC_Start();
//    APPS_ADC_StartConvert();
//    TPS_ADC_StartConvert();
//    BRAKE_ADC_StartConvert();
//    prev_throttle_pos = 0.0;
//
//    for(;;)
//    {
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
//    
//        /* Convert to percents */
//        apps0_percent = convertToPercent(apps0_count, APPS);
//        apps1_percent = convertToPercent(apps1_count, APPS);
//        tps0_percent = convertToPercent(tps0_count, TPS);
//        tps1_percent = convertToPercent(tps1_count, TPS);
//        brake_percent = convertToPercent(brake_count, BRAKE);
//        
//        /* Average and check for local errors */
//        apps_avg = average(apps0_percent, apps1_percent);
//        tps_avg = average(tps0_percent, tps1_percent);
//        if (apps_avg == fERROR || tps_avg == fERROR) {
//            handleError();
//        }
//        
//        /* Get next throttle position */
//        int next_throttle_pos = 
//            nextThrottlePosition(apps_avg, tps_avg, prev_throttle_pos, brake_percent, err_buff);
//        if (next_throttle_pos == fERROR) {
//            handleError();
//        }
//            
//        /* TODO: Figure out how to write value to servo out */
//    }
}

/* [] END OF FILE */
