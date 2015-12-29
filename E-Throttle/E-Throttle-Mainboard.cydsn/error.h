/* ========================================
A collection of functions that check for and
report errors or implausibilities in the
E-throttle system

Author: Mitchell Mellone (mellom3@rpi.edu)
Date Created: 12/27/15
Most Recent Modification: 12/28/15
Version: 0.1.1

Copyright (c) 2015 Rensselaer Motorsport
Distributed under the MIT License.
See "LICENSE" for more information.
 * ========================================
*/

#ifndef _ERROR_H_
#define _ERROR_H_
    
    /* Constant Definitions */
    #define ERROR -1
    
    /* Function Declarations */
    int localImplausibility(float sens_1, float sens_2);
    int globalImplausibility(float tps, float apps);
    
    
#endif

/* [] END OF FILE */
