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
    //#include <cytypes.h>
    #include "queue.h"
    #include <math.h>

    /* Constant Definitions */
    #define MAX_TPS_COUNT 4095.0 /* 12-bit resolution */
    #define MAX_APPS_COUNT 4095.0 /* 12-bit resolution */
    #define MAX_BRAKE_COUNT 16383.0 /* 14-bit resolution */
    #define ERROR -1
    #define ERROR_BUFFER_SIZE 5

    /* Enumerations */
    typedef enum sensor {
        TPS,
        APPS,
        BRAKE
    } sensor;

    /* Struct Declaration */
    typedef struct Error_Buffer {
        /* DONE:    Test and verify queue
                    data type and error buffer
                    effectiveness

           TODO:   Figure out error buffer timing
        */
        struct Queue * errQ;
        float sum;
        float avg;
    } Error_Buffer;

    /* Function Declarations */
    float convertToPercent(uint16, sensor);
    float average(float, float);
    float nextThrottlePosition(float, float, float, Error_Buffer*);
    Error_Buffer * createErrorBuffer();
    void updateErrorBuffer(Error_Buffer *, float);
    int localImplausibility(float, float);
    int globalImplausibility(float, float, Error_Buffer *);


#endif
