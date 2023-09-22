#ifndef QUEUE_STRUCT_H_INCLUDED
#define QUEUE_STRUCT_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#define LINEAR_QUEUE 1

typedef char uQueue_t;

typedef struct Queue_Structure
{
    uQueue_t * arr;
    int size;
    int front;
    int rear;
}queue_t;
typedef enum Queue_Statue{
    QUEUE_OK,
    QUEUE_NOT_OK,
    QUEUE_FULL,
    QUEUE_NOT_FULL,
    QUEUE_EMPTY,
    QUEUE_NOT_EMPTY,
    Queue_Finsh_Display,
    Queue_IsFree
}queue_s;

queue_t * init_queue(int size);                        ///it take size and return pointer of Queue init by zeros
queue_s Queue_isEmpty(queue_t * q);                    ///check if it is an Empty Queue
queue_s Queue_isFull(queue_t * q);                     ///check if it is a full or not
queue_s enQueue(queue_t * q , uQueue_t val);           ///input value to Queue's Array
queue_s deQueue ( queue_t * q , uQueue_t * retVal);    ///return value from Queue's Array "it's Call Result by reference"
queue_s DisplayQueue(queue_t *q);                      ///display all data in Queue
queue_s free_queue(queue_t * q);                       ///free memory by the end of program

#endif // QUEUE_STRUCT_H_INCLUDED
