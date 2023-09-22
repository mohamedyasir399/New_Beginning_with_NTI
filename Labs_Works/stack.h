#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>


#define STACK_MAX 4 

typedef char unitstack_t; 

typedef struct 
{
    unitstack_t arr[STACK_MAX]; 
    int size; 
    int head; 
}stack_t;

typedef enum{
    STACK_OK,
    STACK_EMPTY,
    STACK_FULL,
    STACK_NULL_POINTER
}EN_stack_status_t; 

//function to create the stack 
stack_t * create_stack();


//funciton to free the stack 
void free_stack(stack_t * s);


//function to push data into stack 
EN_stack_status_t pushToStack(stack_t * s , unitstack_t val); 

//function to pop data from stack 
EN_stack_status_t PopFromStack(stack_t * s , unitstack_t *RetVal); 

//function to check if the stack is full 
EN_stack_status_t isFull_stack(stack_t * s); 

//function to check if the stack if empty 
EN_stack_status_t isEmpty_stack(stack_t *s); 






#endif