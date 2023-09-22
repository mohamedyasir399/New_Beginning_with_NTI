#include "queue_struct.h"

//initialization & create the queue
queue_t * init_queue(int size)
{
    queue_t * q = calloc ( 1,sizeof(queue_t)); ///make it consists of one element at start
    q->arr = calloc(5,sizeof(uQueue_t));     ///make it's array consists of five elements at start
    q->size = size;
    //queue is empty
    q->front = - 1;
    q->rear = -1;
    return q;
}

//function to check if the queue is empty or not
queue_s Queue_isEmpty(queue_t * q)
{
    if(q==NULL)
        return QUEUE_NOT_OK;
    if(q->rear == -1 && q->front == -1)
    {
        //printf("it's empty\n");
        return QUEUE_EMPTY;
    }
    //printf("It's ok\n");
    return QUEUE_NOT_EMPTY;
}

//function to check if the queue is full or not
queue_s Queue_isFull(queue_t * q)
{
    if(q==NULL)
        return QUEUE_NOT_OK;
    #if (LINEAR_QUEUE ==1)
    //LINEAR QUEUE
    if(q->rear >= q->size)
    {
       // printf("itis Full\n");
        return QUEUE_FULL;
    }
   // printf("it is ok\n");
    return QUEUE_NOT_FULL;
    #elif (LINEAR_QUEUE ==0)
    //circular queue
    if(((q->rear+1)%q->size) == q->front)
        return QUEUE_FULL;
    return QUEUE_NOT_FULL;
    #endif
}

//function to Enqueue
queue_s enQueue(queue_t * q , uQueue_t val)
{
    if(q==NULL)
        return QUEUE_NOT_OK;
    if(Queue_isFull(q) == QUEUE_FULL)
    {
        printf("enQueue failed: queue is full \n");
        return QUEUE_FULL;
    }

    if(Queue_isEmpty(q) == QUEUE_EMPTY)
    {
        q->front = 0;
        q->rear = 0;
    }else{
        #if (LINEAR_QUEUE ==1)
        //LINEAR QUEUE
        q->rear++;
        #elif (LINEAR_QUEUE ==0)
        //circular queue
        q->rear = (q->rear+1)%q->size;
        #endif
    }

    q->arr[q->rear] = val;
    return QUEUE_OK;
}


//function to deQueue
queue_s deQueue ( queue_t * q , uQueue_t * retVal)
{
    if(q==NULL)
        return QUEUE_NOT_OK;
    if(Queue_isEmpty(q) == QUEUE_EMPTY )
    {
        printf("dequeue failed: queue is empty\n");
        return QUEUE_EMPTY;
    }
    *retVal = q->arr[q->front];
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }else{
        #if (LINEAR_QUEUE ==1)
        //LINEAR QUEUE
        q->front++;
        #elif (LINEAR_QUEUE ==0)
        //circular queue
        q->front = (q->front+1)%q->size;
        #endif
    }
    return QUEUE_OK;

}
queue_s DisplayQueue(queue_t *q)
{
    if(q==NULL)
        return QUEUE_NOT_OK;
    if(Queue_isEmpty(q) == QUEUE_EMPTY )
    {
        printf("dequeue failed: queue is empty\n");
        return QUEUE_EMPTY;
    }
    queue_s q_s = QUEUE_OK;                     ///queue_statue in function to exit the loop at end
    int retVal = q->arr[q->front],count=1;
    while (q_s != Queue_Finsh_Display && count <=q->size)
    {
        printf("%d- %d\n",count,retVal);
        if(q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
            q_s = Queue_Finsh_Display;
        }else{
            #if (LINEAR_QUEUE ==1)
            //LINEAR QUEUE
            retVal = q->arr[q->front+count];
            #elif (LINEAR_QUEUE ==0)
            //circular queue
            retVal = q->arr[(q->front+count)%q->size];
            #endif
            count++;
        }
    }
    return QUEUE_OK;
}
//function to free the queue
queue_s free_queue(queue_t * q)
{
    if(q==NULL)
        return;
    free(q->arr);
    free(q);
    return Queue_IsFree;

}
