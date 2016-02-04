 /* ========================================
    A collection of functions that do the brunt
    of the I/O processing and calculation work
    needed for the E-Throttle.

    Author: Mitchell Mellone (mellom3@rpi.edu)
    Date Created: 12/28/15
    Most Recent Modification: 12/30/15

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#include "signal_processing.h"

/*
parameters: count - The current count returned by
                   an ADC
            type - The type of sensor
return:     A percentage of the maximum possible count
            ** From 0.0 - 100.0 **
            If the type is not defined it will return 0.0
*/
float convertToPercent(uint16 count, sensor type) {
    /* TODO:    check bounds on these percents,
                expecially the BRAKE case (sigdel
                ADC gave a little over MAX_BRAKE_COUNT
                in prelim. test)
    */
    float percent;
    switch (type) {
        case TPS:
            percent = (float) count / MAX_TPS_COUNT;
            break;
        case APPS:
            percent = (float) count / MAX_APPS_COUNT;
            break;
        case BRAKE:
            percent = (float) count / MAX_BRAKE_COUNT;
        default:
            percent = 0.0;
    }
    return percent * 100.0;
}

/*
parameters: s0 - Percent that sensor 0 is open (0.0-100.0)
            s1 - Percent that sensor 1 is open (0.0-100.0)
effect:     Checks for implausibility, then averages
            the values
return:     ERROR if there is an implausibility,
            The average of the sensors otherwise
*/
float average(float s0, float s1) {
    if(localImplausibility(s0, s1) == ERROR) {
        return ERROR;
    }
    return ((s0 + s1) / 2.0);
}

/*
parameters: tpsPos - The current throttle percentage (% open, 0.0-100.0)
            appsPos - The requested throttle percentage (% open, 0.0-100.0)
effect:     Checks for implausability between the tps and apps
            signals, and then calculates the next position of
            the throttle actuator.
return:     ERROR if there is an implausibility, the next
            desired servo position otherwise.
*//*
TODO: Figure out something better...

float nextThrottlePosition(float requested_pos, float curr_pos,
                           float prev_request, Error_Buffer * errs) {
    if (globalImplausibility(curr_pos, prev_request, errs) == ERROR) {
        return ERROR;
    }
    return requested_pos;
}*/

/*
return: An Error_Buffer initialized with all 0.0s
*/
Error_Buffer * createErrorBuffer() {
    Error_Buffer * eb = (Error_Buffer*)malloc(sizeof(Error_Buffer));
    eb->error_queue = createQueue();
    eb->num_brake_errs = 0;
    eb->TPS_APPS_avg = 0.0;
    eb->TPS_APPS_sum = 0.0;
    eb->percent_brake_errs = 0.0;
    eb->size = 0;
    return eb;
}

/*
parameter:  eb - The Error_Buffer to update
            newErr - The new error to update it with (
effect:     Adds the new error to the start of the queue
            Removes the least recent error
            Updates the sum and average accordingly
*/
void updateErrorBuffer(Error_Buffer * eb, unsigned char brake_err, float TPS_APPS_err) {
    Queue * q = eb->error_queue;
    int curr_time = Timer_ReadCounter();
    enqueue(q, brake_err, TPS_APPS_err, curr_time);
    eb->num_brake_errs += brake_err; /* +1 if = BRAKE_ERROR, +0 if = BRAKE_GOOD */
    eb->TPS_APPS_sum += TPS_APPS_err;
    eb->size++;
    while (headTime(q) - curr_time > 1.0) {
        Node * toRemove = dequeue(q);
        eb->num_brake_errs -= toRemove->brake_error;
        eb->TPS_APPS_sum -= toRemove->TPS_APPS_error;
        eb->size--;
    }
    eb->TPS_APPS_avg = eb->TPS_APPS_sum / ((float)eb->size);
    eb->percent_brake_errs = ((float)eb->num_brake_errs) / ((float)eb->size);
}

/*
parameter:  sens_0 - The first sensor (% open, 0.0-100.0)
            sens_1 - The second sensor (% open, 0.0-100.0)
effect:     Checks to make sure both sensors are within 10%
            of each other
return:     ERROR if there is an error, a non-error output
            otherwise
*/
unsigned char localImplausibility(float sens_0, float sens_1) {
    float diff = fabs(sens_0 - sens_1);
    if (diff < 0.10 && diff > -0.10) {
        return NO_ERROR;
    } else {
        return ERROR;
    }
}

/*
parameter:  curr_tps - The current TPS reading (% open, 0.0-100.0)
            exp_tps - The expected TPS reading (% open, 0.0-100.0)
            brake - The current brake reading (% open, 0.0-100.0)
effect:     Checks to make average error between current and
            expected TPS reading has not been greater than 10%
            for > 1 sec, and that the brake and is not above a
            desired threshold for a certain amount of time.
            ** NOTE: Each "Error" is a percent error, 
                        i.e. (|(expected - actual)| / (expected)) * 100.0
return:     ERROR if there is an error, a non-error output
            otherwise
*/
unsigned char globalImplausibility(float curr_tps, float expected_tps,
                            float brake, Error_Buffer * eb) {
    float tp_err = (fabs(curr_tps - expected_tps) / expected_tps) * 100.0;
    unsigned char brake_err = brakeErrorCheck(brake, curr_tps);
    
    updateErrorBuffer(eb, brake_err, tp_err);
    
    if (eb->TPS_APPS_avg > TP_ERR_CUTOFF
            || eb->percent_brake_errs > BRAKE_ERR_CUTOFF) {
        return ERROR;
    } else {
        return NO_ERROR;
    }
}
                            
/*
parameter:  brake - The current brake position reading (% open, 0.0-100.0)
            tps - The current TPS reading (% open, 0.0-100.0)
return:     BRAKE_ERROR If the brake is applied above a given throttle threshold
            BRAKE_GOOD If there is no current brake implausibility
*/
unsigned char brakeErrorCheck(float brake, float tps) {
    /* TODO: Find and program a valid relationship. I just put in some 
             simple numbers
    */
    if (brake > 5.0 && tps > 10.0) {
        return BRAKE_ERROR;
    } else {
        return BRAKE_GOOD;
    }
}   

/* [] END OF FILE */
