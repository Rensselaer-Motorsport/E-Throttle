/* ========================================
    A collection of functions that do the brunt
    of the I/O processing and calculation work
    needed for the E-Throttle.

    Author: Mitchell Mellone (mellom3@rpi.edu)
    Date Created: 12/27/15
    Most Recent Modification: 12/30/15

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
    #include <math.h>

    /* Constant Definitions */
    #define MAX_TPS_COUNT 4095.0 /* 12-bit resolution */
    #define MAX_APPS_COUNT 4095.0 /* 12-bit resolution */
    #define MAX_BRAKE_COUNT 16383.0 /* 14-bit resolution */
    #define OPEN_SHORT_CIRCUIT 0 /* TODO: confirm count is 0 iff open/short circuit achieved */
    #define ERROR 0
    #define fERROR 0.0
    #define NO_ERROR 1 /* must be different from ERROR */
    #define TIMER_FREQ 32000 /* 75 kHz */
    #define TP_ERR_CUTOFF 10.0 /* should be 10.0 by rule IC1.15.2 */
    #define BRAKE_ERR_CUTOFF 90.0 /* percentage of brake implausibilities
                                     during the previous second to warrant a shut-off */

    /* Enumerations */
    typedef enum sensor {
        TPS,
        APPS,
        BRAKE
    } sensor;

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
    unsigned char signalCheck(uint16, uint16, uint16, uint16, uint16);
    unsigned char localImplausibility(float, float);
    unsigned char globalImplausibility(float, float, float, Error_Buffer *);
    unsigned char brakeErrorCheck(float, float);
    void writeToServo(float);
    void handleError(); /* TODO: Implement handleError */

#endif
