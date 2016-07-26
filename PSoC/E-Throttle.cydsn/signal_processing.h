/* ========================================
    A collection of functions that do the brunt
    of the I/O processing and calculation work
    needed for the E-Throttle.

    Author: Mitchell Mellone (mellom3@rpi.edu)

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#ifndef _SIGNAL_PROCESSING_H_
#define _SIGNAL_PROCESSING_H_

    /* Imports */
    #include <cytypes.h>
    #include "queue.h"
    #include "global_constants.h"
    #include <math.h>

    /* Struct Declaration */
    typedef struct Error_Buffer {
        struct Queue * error_queue;
        float TPS_APPS_sum, TPS_APPS_avg, percent_brake_errs;
        int num_brake_errs, size, total_time;
    } Error_Buffer;

    /* Function Declarations */
    float convertToPercent(uint16, sensor);
    float average(float, float);
    float nextThrottlePosition(float, float, float, float, Error_Buffer*);
    Error_Buffer * createErrorBuffer();
    void updateErrorBuffer(Error_Buffer *, unsigned char, float);
    int signalCheck(uint16, uint16, uint16, uint16, uint16);
    bool localImplausibility(float, float);
    bool globalImplausibility(float, float, float, Error_Buffer *);
    bool brakeErrorCheck(float, float);
    void writeToServo(float);
    void handleError(); /* TODO: Implement handleError */

#endif
