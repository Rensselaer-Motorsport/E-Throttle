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

#include "queue.h"


/* Note that nodes are inserted at the back/tail and
   removed at the front/head */

/*
parameter:  size - The initial size of the queue
effect:     Creates an empty linked list based
            queue
*/
Queue * createQueue() {
    // Initialize Queue
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    int i;
    return q;
}

/*
parameter:  val - The value to add to the queue
effect:     Creates and adds a tail to the back of Queue q
modifies:   back & (front if (back == NULL))
*/
void enqueue(Queue * q, unsigned char brake_stat, float TPS_APPS_err, int time) {
    if (q->tail == NULL) {
        /* Queue is empty */
        q->tail = (Node *)malloc(sizeof(Node));
        q->tail->next = NULL;
        q->tail->brake_error = brake_stat;
        q->tail->TPS_APPS_error = TPS_APPS_err;
        q->tail->time_count = time;
        q->head = q->tail;
    } else {
        /* Queue is not empty */
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->next = NULL;
        temp->brake_error = brake_stat;
        temp->TPS_APPS_error = TPS_APPS_err;
        temp->time_count = time;
        q->tail->next = temp;
        q->tail = temp;
    }
}

/*
effect: Removes the head element in the queue
return: The least recent node (head)
*/
Node * dequeue(Queue * q) {
    Node * toReturn;
    if (q->head == NULL) {
        /* Queue is empty */
        toReturn = NULL;
    } else {
        /* Queue is not empty */
        toReturn = q->head;
        Node * oldHead = q->head;
        q->head = q->head->next;
        free(oldHead);
        if (q->head == NULL) {
            /* If dequeueing last element */
            q->tail = NULL;
        }
    }
    return toReturn;
}

/*
return: The time_count value from the queue's head node
        This will be the least recent time in the queue
*/
uint32 headTime(Queue * q) {
    if (q->head == NULL) {
        /* queue is empty */
        return -1;
    } else {
        return q->head->time_count;
    }
}



/* [] END OF FILE */
