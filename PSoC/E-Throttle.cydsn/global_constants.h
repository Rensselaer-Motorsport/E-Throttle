/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef _GLOBAL_CONSTANTS_H_
#define _GLOBAL_CONSTANTS_H_
    
    /* Constants */
    #define MAX_TPS_COUNT 4095.0 /* 12-bit resolution */
    #define MAX_APPS_COUNT 4095.0 /* 12-bit resolution */
    #define MAX_BRAKE_COUNT 16383.0 /* 14-bit resolution */
    #define OPEN_SHORT_CIRCUIT 0 /* TODO: confirm count is 0 iff open/short circuit achieved */
    #define ERROR -1
    #define fERROR -1.0
    #define NO_ERROR 1 /* must be different from ERROR */
    #define TIMER_FREQ 32000 /* 75 kHz */
    #define TP_ERR_CUTOFF 10.0 /* should be 10.0 by rule IC1.15.2 */
    #define BRAKE_ERR_CUTOFF 90.0 /* percentage of brake implausibilities
                                     during the previous second to warrant a shut-off */

    /* Enumerations */
    typedef enum sensor {
        TPS,
        APPS,
        BRAKE,
        TPS0,
        TPS1,
        APPS0,
        APPS1
    } sensor;

#endif
/* [] END OF FILE */
