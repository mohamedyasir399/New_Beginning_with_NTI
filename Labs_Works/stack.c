#include "stack.h"



//function to create the stack 
stack_t * create_stack()
{
    stack_t * cs = malloc(1*sizeof(stack_t));
    if(cs == NULL)
    {
        return cs; 
    }
    cs->size = STACK_MAX; 
    //stack is empty 
    cs->head = -1;

    return cs; 
}



//funciton to free the stack 
void free_stack(stack_t * s)
{
    free(s); 
}


//function to push data into stack 
EN_stack_status_t pushToStack(stack_t * s , unitstack_t val)
{
    if(s == NULL)
    {
        return STACK_NULL_POINTER; 
    }

    if(isFull_stack(s) == STACK_FULL)
    {
        printf("push failed : stack if full\n"); 
        return STACK_FULL; 
    }

    s->head++; 
    s->arr[s->head] = val; 
    return STACK_OK; 
}



//function to pop data from stack 
EN_stack_status_t PopFromStack(stack_t * s , unitstack_t *RetVal)
{
    if(s == NULL)
    {
        return STACK_NULL_POINTER; 
    }

    if(isEmpty_stack(s) == STACK_EMPTY)
    {
        printf("pop failed: stack is empty \n"); 
        return STACK_EMPTY; 
    }

    *RetVal = s->arr[s->head]; 
    s->head--; 
    return STACK_OK; 
}



//function to check if the stack is full 
EN_stack_status_t isFull_stack(stack_t * s)
{
    if(s == NULL)
    {
        return STACK_NULL_POINTER; 
    }

    return (s->head >= s->size-1)? STACK_FULL : STACK_OK;  
}

//function to check if the stack if empty 
EN_stack_status_t isEmpty_stack(stack_t *s)
{
    if(s == NULL)
    {
        return STACK_NULL_POINTER; 
    }

    return (s->head <= -1)? STACK_EMPTY : STACK_OK; 

}