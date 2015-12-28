/* ========================================
A collection of functions that check for and
report errors or implausibilities in the
E-throttle system

Author: Mitchell Mellone (mellom3@rpi.edu)
Date Created: 12/27/15
Most Recent Modification: 12/27/15
Version: 0.1.0

Copyright (c) 2015 Rensselaer Motorsport
Distributed under the MIT License.
See "LICENSE" for more information.
 * ========================================
*/

#include "signal_processing.h"

#ifndef _ERROR_H_
#define _ERROR_H_
    
    /* Function Definitions */
    int localImplausibility(sensor_vals s);
    int globalImplausibility(float tps, float apps);
    
#endif

/* [] END OF FILE */
