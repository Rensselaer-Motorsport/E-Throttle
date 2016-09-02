/* ========================================
    A collection of functions that are used
    to communicate between the PSoC board
    and outside computers.

    Author: Mitchell Mellone (mellom3@rpi.edu)

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_
    
    #include "global_constants.h"
    #include <project.h>
    
    void send_pot_data(sensor, float);
    void output_int(int);
    void output_pad();
    
#endif

/* [] END OF FILE */
