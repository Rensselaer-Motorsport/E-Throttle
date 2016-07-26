/* ========================================
    A simple Queue implemented with a linked
    list.

    Author: Mitchell Mellone (mellom3@rpi.edu)

    Copyright (c) 2015 Rensselaer Motorsport
    Distributed under the MIT License.
    See "LICENSE" for more information.
 * ========================================
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

    /* Imports */
    #include <stdlib.h>
    #include "project.h"
    #include "global_constants.h"

    /* NODE Struct Initialization */
    typedef struct Node {
        unsigned char brake_error;
        float TPS_APPS_error;
        uint32 time_count;
        struct Node * next;
    } Node;
    
    /* QUEUE Struct Initialization */  
    typedef struct Queue {
        Node * head, * tail;
    } Queue;

    /* Function Declarations */
    Queue * createQueue();
    void enqueue(Queue *, unsigned char, float, int);
    Node * dequeue(Queue *);
    uint32 headTime(Queue *);

#endif

/* [] END OF FILE */
