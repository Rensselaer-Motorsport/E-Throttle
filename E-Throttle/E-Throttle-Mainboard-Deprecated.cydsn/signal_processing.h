 /* ========================================
    A collection of functions that do the brunt
    of the I/O processing and calculation work
    needed for the E-Throttle.

    Author: Mitchell Mellone (mellom3@rpi.edu)
    Date Created: 12/27/15
    Most Recent Modification: 12/28/15
    Version 0.1.1

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#ifndef _SIGNAL_PROCESSING_H_
#define _SIGNAL_PROCESSING_H_
    
    /* Imports */
    #include <cytypes.h>
        
    /* Constant Definitions */
    #define MAX_TPS_COUNT 400.0 /* !!TODO!! find real count */
    #define MAX_APPS_COUNT 400.0 /* !!TODO!! find real count */
        
    /* Enumerations */
    typedef enum {
        TPS,
        APPS
    } sensor;
    
    /* Function Declarations */
    float convertToPercent(uint16, sensor);
    float average(float, float);
    //float nextThrottlePosition(float, float);
    
#endif

/* [] END OF FILE */
