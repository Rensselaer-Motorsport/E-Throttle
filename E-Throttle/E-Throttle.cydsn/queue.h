/* ========================================
    A simple Queue implemented with a linked
    list.

    Author: Mitchell Mellone (mellom3@rpi.edu)
    Date Created: 12/30/15
    Most Recent Modification: 12/30/15

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

    /* Imports */
    #include <stdlib.h>

    /* Typedefs */
    typedef void (*enqueueFunc)(float);
    typedef float (*dequeueFunc)();
    typedef int (*isEmptyFunc)();

    /* Struct Initialization */
    typedef struct Queue {
        enqueueFunc enq;
        dequeueFunc deq;
        isEmptyFunc isEmpty;
    } Queue;

    /* Function Declarations */
    Queue * createQueue(int);
    void enq(float);
    float deq();
    int isEmpty();

#endif

/* [] END OF FILE */
