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

typedef struct Node {
    float data;
    struct Node * next;
} Node;
Node *front, *back;

/* Note that nodes are inserted at the back and
   removed at the front */

/*
parameter:  size - The initial size of the queue
effect:     Creates an linked list queue of size
            'size', with each element initialized
            to 0.0
*/
Queue * createQueue(int size) {
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->enq = enq;
    q->deq = deq;
    q->isEmpty = isEmpty;
    front = back = NULL;
    int i;
    for (i = 0; i < size; ++i) {
        q->enq(0.0);
    }
    return q;
}

/*
parameter:  val - The value to add to the queue
effect:     Adds val to the back of the queue
modifies:   back & (front if (back == NULL))
*/
void enq(float val) {
    if (back == NULL) {
        back = (Node *)malloc(sizeof(Node));
        back->next = NULL;
        back->data = val;
        front = back;
    } else {
        Node *temp = (Node *)malloc(sizeof(Node));
        back->next = temp;
        temp->data = val;
        temp->next = NULL;
        back = temp;
    }
}

/*
effect: Removes the next element in the queue
return: the value of the next element in the queue
        -1.0 if there is no elements
*/
float deq() {
    float toReturn;
    if (front == NULL) {
        toReturn = -1.0;
    } else {
        toReturn = front->data;
        Node * oldFront = front;
        front = front->next;
        free(oldFront);
        if (front == NULL) {
            back = NULL;
        }
    }
    return toReturn;
}

/*
return: 1 if the queue is empty (front == back == NULL)
        0 if the queue is NOT empty
*/
int isEmpty() {
    if (front == NULL) {
        return 1;
    } else {
        return 0;
    }
}


/* [] END OF FILE */
