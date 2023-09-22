#include <stdio.h>
#include <stdlib.h>
#include "stack_struct.h"

void init_SStack(sStack_t *s)           ///initialization of Dynamic stack
{
    s->HeadIndex = -1;
}

                                        ///check status of Dynamic stack

stack_s IsEmpty_SStack(sStack_t *s)
{
    if(s->HeadIndex <= -1)
    {
        printf("Empty Static Stack!!\n");
        return StackIsEmpty;
    }
    return 0;
}

stack_s IsFull_SStack (sStack_t *s)
{
    if(s->HeadIndex >= MaxSizeOfStaticStack-1)
    {
        printf("Full Static Stack!!\n");
        return StackIsEmpty;
    }
    return 0;
}

                                        ///push && pop data from &to static stack

void PushTo_SStack (sStack_t *s,dataIn_t value)
{
    if(IsFull_SStack(s))
        return 0;
    s->HeadIndex++;
    s->arr[s->HeadIndex]= value;

}

dataIn_t PopFrom_SStack(sStack_t *s)
{
    if(IsEmpty_SStack(s))
        return 0;
    s->HeadIndex--;
    return s->arr[s->HeadIndex+1];
}

//////////////////////////////////////////////////////////////////////////////
////////Dynamic Stack Functions

DyStack_t* init_DStack(int sizeDyStack)   ///initialization of Dynamic stack
{
    DyStack_t *s = calloc(1,sizeof(DyStack_t));
    s->SizeOfDystack = sizeDyStack;
    s->P2Arr = calloc(s->SizeOfDystack,sizeof(int));
    s->HeadIndex = -1;
    return s;
}
void FreeDyStack(DyStack_t *s)                  ///Free Dynamic stack from memory after finch program
{
    free(s->P2Arr);
    free(s);
}

                                                ///check status of Dynamic stack

stack_s IsEmpty_DStack(DyStack_t *s)
{
    if (s == NULL)
        return Stack_Not_Ok;
    if(s->HeadIndex <= -1)
    {
        printf("Empty Dynamic Stack!!\n");
        return StackIsEmpty;
    }
    return 0;
}
stack_s IsFull_DStack (DyStack_t *s)
{
    if (s == NULL)
        return Stack_Not_Ok;
    if(s->HeadIndex >= s->SizeOfDystack-1)
    {
        printf("Full Static Stack!!\n");
        return StackIsEmpty;
    }
    return 0;
}

        ///push && pop data from &to dynamic stack

void PushTo_DStack (DyStack_t *s,dataIn_t value)
{
    if (s == NULL)
        return Stack_Not_Ok;
    if(IsFull_DStack(s))
        return 0;
    s->HeadIndex++;
    s->P2Arr[s->HeadIndex]= value;

}
dataIn_t PopFrom_DStack(DyStack_t *s)
{
    if (s == NULL)
        return Stack_Not_Ok;
    if(IsEmpty_DStack(s))
        return 0;
    s->HeadIndex--;
    return s->P2Arr[s->HeadIndex+1];
}

