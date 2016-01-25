 /* ========================================
    A collection of functions that do the brunt
    of the I/O processing and calculation work
    needed for the E-Throttle.

    Author: Mitchell Mellone (mellom3@rpi.edu)
    Date Created: 12/28/15
    Most Recent Modification: 12/28/15
    Version 0.1.0

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#include "signal_processing.h"
#include "error.h"

/*
parameters: count - The current count returned by
                   an ADC
            type - The type of sensor
return: A percentage of the maximum possible count
        If the type is not defined it will return 0.0
*/
float convertToPercent(uint16 count, sensor type) {
    float percent;
    switch (type) {
        case TPS:
            percent = (float) count / MAX_TPS_COUNT;
            break;
        case APPS:
            percent = (float) count / MAX_APPS_COUNT;
            break;
        default:
            percent = 0.0;
    }
    return percent;
}

/*
parameters: s0 - Percent that sensor 0 is open
            s1 - Percent that sensor 1 is open
effect: Checks for implausibility, then averages 
        the values
return: ERROR if there is an implausibility,
        The average of the sensors otherwise
*/
float average(float s0, float s1) {
    if(localImplausibility(s0, s1) == ERROR) {
        return ERROR;
    }
    return ((s0 + s1) / 2.0);
}

/*
parameters: tpsPos - The current throttle percentage
            appsPos - The requested throttle percentage
effect: Checks for implausability between the tps and apps
        signals, and then calculates the next position of
        the throttle actuator.
return: ERROR if there is an implausibility, the next
        desired servo position otherwise.
*/

float nextThrottlePosition(float requested_pos, float current_pos) {
    return 0.0;
}
    

/* [] END OF FILE */
