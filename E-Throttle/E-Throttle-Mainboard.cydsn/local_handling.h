/* 
The following functions (and their impelmentations in "local_hadling.c"
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
#ifndef LOCAL_HANDLING
#define LOCAL_HANDLING
    
#include <project.h>
#include <stdlib.h>

#define TPS_MAX 500 /* TODO: Find correct value */
#define APPS_MAX 500 /* TODO: Find correct value */

typedef enum {
    NONE_FAIL,
    SENSOR_0_FAIL,
    SENSOR_1_FAIL,
    SENSOR_2_FAIL,
    TOTAL_FAIL
} sensor_status;

typedef struct {
    uint16 sens_0_value;
    uint16 sens_1_value;
    uint16 sens_2_value;
} sensor_values;

typedef int value_type;
#define TPS_TYPE 0
#define APPS_TYPE 1

#define NUM_ALL_CHANNELS 3
#define MIN_NUM_CHANNELS 2
#define FAIL_AVERAGE -1.0

    /* scales values to a percent (0-100) throttle/pedal open */
    float normalize(uint16, value_type);
    float normalize_tps_value(uint16);
    float normalize_apps_value(uint16);
    
    /* returns info on which sensor(s) (if any) have failed,
       according to the sensor_status enum.
    */
    sensor_status get_sensor_status(sensor_values *);
    
    /* returns 10% of the smallest value, used to test for implausibility */
    uint16 get_max_delta(sensor_values *);
       
    /* tps_avg() and apps_avg() are intended to be called in main
       averate() is a helper function for these where most of the
       work is to be done
    
       returns average of sensor values (within 10% of each other)
       as a percentage
       -1.0 is returned if there is an implausibility in more than 2 sensors
    */
    float tps_avg(void);
    float apps_avg(void);
    float average(sensor_values *, sensor_status, value_type);
    
#endif


/* [] END OF FILE */
