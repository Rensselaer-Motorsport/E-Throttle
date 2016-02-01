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
    return percent;
}

/*
parameters: s0 - Percent that sensor 0 is open
            s1 - Percent that sensor 1 is open
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
parameters: tpsPos - The current throttle percentage
            appsPos - The requested throttle percentage
effect:     Checks for implausability between the tps and apps
            signals, and then calculates the next position of
            the throttle actuator.
return:     ERROR if there is an implausibility, the next
            desired servo position otherwise.
*/

float nextThrottlePosition(float requested_pos, float curr_pos,
                           float prev_request, Error_Buffer * errs) {
    if (globalImplausibility(curr_pos, prev_request, errs) == ERROR) {
        return ERROR;
    }
    return requested_pos;
}

/*
return: An Error_Buffer initialized with all 0.0s
*/
Error_Buffer * createErrorBuffer() {
    Error_Buffer * eb = (Error_Buffer*)malloc(sizeof(Error_Buffer));
    eb->error_queue = createQueue(ERROR_BUFFER_SIZE);
    eb->brake_sum = 0.0;
    eb->brake_avg = 0.0;
    eb->TPS_APPS_avg = 0.0;
    eb->TPS_APPS_sum = 0.0;
    eb->size = 0;
    return eb;
}

/*
parameter:  eb - The Error_Buffer to update
            newErr - The new error to update it with
effect:     Adds the new error to the start of the queue
            Removes the least recent error
            Updates the sum and average accordingly
*/
void updateErrorBuffer(Error_Buffer * eb, float brake_err, float TPS_APPS_err) {
    Queue * q = eb->error_queue;
    int curr_time = Timer_ReadCounter();
    enqueue(q, brake_err, TPS_APPS_err, curr_time);
    eb->brake_sum += brake_err;
    eb->TPS_APPS_sum += TPS_APPS_err;
    eb->size++;
    while (headTime(q) - curr_time > 1.0) {
        Node * toRemove = dequeue(q);
        eb->brake_sum -= toRemove->brake_error;
        eb->TPS_APPS_sum -= toRemove->TPS_APPS_error;
        eb->size--;
    }
    eb->TPS_APPS_avg = eb->TPS_APPS_sum / ((float)eb->size);
    eb->brake_avg = eb->brake_sum / ((float)eb->size);
}

/*
parameter:  sens_0 - The first sensor
            sens_1 - The second sensor
effect:     Checks to make sure both sensors are within 10%
            of each other
return:     ERROR if there is an error, a non-error output
            otherwise
*/
int localImplausibility(float sens_0, float sens_1) {
    float diff = fabs(sens_0 - sens_1);
    if (diff < 0.10 && diff > -0.10) {
        return 1;
    } else {
        return ERROR;
    }
}

/*
parameter:  curr_tps - The current TPS reading
            exp_tps - The expected TPS reading
effect:     Checks to make average error between current and
            expected TPS reading has not been greater than 10%
            for > 1 sec
return:     ERROR if there is an error, a non-error output
            otherwise
*/
int globalImplausibility(float curr_tps, float expected_tps,
                            Error_Buffer * eb) {
    float newErr = fabs(curr_tps - expected_tps);
    /* FIX THIS!! updateErrorBuffer(eb, newErr); FIX THIS!!!
    if (eb->avg > 0.10) {
        return ERROR;
    } else {
        return 1;
    } FIX THIS!!! */
    return 0;
}


/* [] END OF FILE */
