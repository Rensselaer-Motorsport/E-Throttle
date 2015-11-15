/* 
The following functions (and their declarations in "local_hadling.h"
are used in the E-Throttle system to check the redundant input from
the 3 TPS/APPSs for any local implausibilities (no 2 sensors agree within
10% of each other) and averages the sensor values to get a single value
to use in the rest of the system.

Author: Mitchell Mellone (mellom3@rpi.edu)
Date Created: 11/15/15
Most Recent Modification: 11/15/15

Copyright (c) 2015 Rensselaer Motorsport
Distributed under the MIT License.
See "LICENSE" for more information.
*/

#include "local_handling.h"

float normalize(uint16 raw_value, value_type v) {
    if (v == TPS_TYPE) {
        return normalize_tps_value(raw_value);
    } else {
        return normalize_apps_value(raw_value);
    }
}

float normalize_tps_value(uint16 raw_value) {
    return raw_value / TPS_MAX;
}

float normalize_apps_value(uint16 raw_value) {
    return raw_value / APPS_MAX;
}

sensor_status get_sensor_status(sensor_values * s) {
    uint16 max_delta = get_max_delta(s);
    int status;
    uint16 sens0_1_delta = abs(s->sens_0_value - s->sens_1_value);
    uint16 sens0_2_delta = abs(s->sens_0_value - s->sens_2_value);
    uint16 sens1_2_delta = abs(s->sens_1_value - s->sens_2_value);
    
    if (sens0_1_delta < max_delta && sens0_2_delta < max_delta && sens1_2_delta < max_delta) {
        /*  no fails */
        status = NONE_FAIL;
    } else if (sens1_2_delta < max_delta) {
        /* bad sensor 0 */
        status = SENSOR_0_FAIL;
    } else if (sens0_2_delta < max_delta) {
        /* bad sensor 1 */
        status = SENSOR_1_FAIL;
    } else if (sens0_1_delta < max_delta) {
        /* bad sensor 2 */
        status = SENSOR_2_FAIL;
    } else {
        /* all bad sensors */
        status = TOTAL_FAIL;
    }
    return status;
}

uint16 get_max_delta(sensor_values * s) {
    /* find the min value */
    uint16 max = s->sens_0_value;
    if (s->sens_1_value > max) {
        max = s->sens_1_value;
    }
    if (s->sens_2_value > max) {
        max = s->sens_2_value;
    }
    /* return 10% of max value */
    return max / 10;
}

float tps_avg(void) {
    sensor_values s = {TPS_ADC_GetResult16(0), TPS_ADC_GetResult16(1), TPS_ADC_GetResult16(2)};
    return average(&s, get_sensor_status(&s), TPS_TYPE);
}

float apps_avg(void) {
    sensor_values s = {APPS_ADC_GetResult16(0), APPS_ADC_GetResult16(1), APPS_ADC_GetResult16(2)};
    return average(&s, get_sensor_status(&s), APPS_TYPE);
}

float average(sensor_values * s, sensor_status status, value_type v) {
    float avg;
    uint16 temp;
    switch (status) {
        case NONE_FAIL:
            temp = (s->sens_0_value + s->sens_1_value + s->sens_2_value) / NUM_ALL_CHANNELS;
            avg = normalize(temp, v);
            break;
        case SENSOR_0_FAIL:
            temp = (s->sens_1_value + s->sens_2_value) / MIN_NUM_CHANNELS;
            avg = normalize(temp, v);
            break;
        case SENSOR_1_FAIL:
            temp = (s->sens_0_value + s->sens_2_value) / MIN_NUM_CHANNELS;
            avg = normalize(temp, v);
            break;
        case SENSOR_2_FAIL:
            temp = (s->sens_0_value + s->sens_1_value) / MIN_NUM_CHANNELS;
            avg = normalize(temp, v);
            break;
        default:
            avg = FAIL_AVERAGE;
    }
    return avg;
}
    

/* [] END OF FILE */
