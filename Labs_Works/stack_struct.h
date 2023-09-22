#ifndef STACK_STRUCT_H_INCLUDED
#define STACK_STRUCT_H_INCLUDED

#define MaxSizeOfStaticStack 5

typedef char dataIn_t;

typedef enum Stack_Status{
     StackIsOK, StackIsEmpty, StackIsFull,Stack_Not_Ok
}stack_s;

typedef struct Static_Stack
{
    int arr[MaxSizeOfStaticStack];
    int HeadIndex;
}sStack_t;

typedef struct Dynamic_Stack
{
    int *P2Arr;
    int SizeOfDystack;
    int HeadIndex;
}DyStack_t;

void init_SStack(sStack_t *s);
DyStack_t* init_DStack(int sizeDyStack);
void FreeDyStack(DyStack_t *s);

stack_s IsEmpty_SStack(sStack_t *s);
stack_s IsFull_SStack (sStack_t *s);

void PushTo_SStack(sStack_t *s,dataIn_t value);
dataIn_t PopFrom_SStack(sStack_t *s);


stack_s IsEmpty_DStack(DyStack_t *s);
stack_s IsFull_DStack (DyStack_t *s);

void PushTo_DStack (DyStack_t *s,dataIn_t value);
dataIn_t PopFrom_DStack(DyStack_t *s);


#endif // STACK_STRUCT_H_INCLUDED
