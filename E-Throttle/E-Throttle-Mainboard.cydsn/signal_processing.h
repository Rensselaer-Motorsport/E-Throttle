/* ========================================
A collection of functions that do the brunt
of the I/O processing and calculation work
needed for the E-Throttle.

Author: Mitchell Mellone (mellom3@rpi.edu)
Date Created: 12/27/15
Most Recent Modification: 12/27/15
Version 0.1.0

Copyright (c) 2015 Rensselaer Motorsport
Distributed under the MIT License.
See "LICENSE" for more information.
 * ========================================
*/

#include <cytypes.h>

#ifndef _SIGNAL_PROCESSING_H_
#define _SIGNAL_PROCESSING_H_
    
    /* Structure Definitions */
    struct sensor_vals typedef sensor_vals;
    
    /* Function Definitions */
    sensor_vals packageInput(uint16 sens1, uint16 sens2);
    float average(sensor_vals s);
    void setThrottlePosition(float pos);
    
#endif

/* [] END OF FILE */
