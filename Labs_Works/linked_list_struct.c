#include "linked_list_struct.h"

///Singly Linked List functions

///initialization & create the Singly Linked List


sLinkedList_t* init_sLinkedList()
{
   sLinkedList_t * newList = calloc(1 ,sizeof(sLinkedList_t));
    if(newList == NULL)
    {
        return NULL;
    }

    newList->headNode= NULL;
    newList->tailNode= NULL;
    newList->size = 0 ;

    return newList;
}


//create node
sNode_t* init_node(data_t value)
{
    sNode_t * newNode = calloc(1,sizeof(sNode_t));
    if(newNode ==NULL)
    {
        return NULL;
    }

    newNode->data = value;
    newNode->p2next = NULL;

    return newNode;

}

///free data from memory by the end of program
slinkedList_s free_LinkedList(sLinkedList_t* sll)
{
     if(sll == NULL)
    {
        return;
    }

    if(sll->headNode == NULL)
    {
        printf("empty list \n");
        return;
    }

    sNode_t * current = sll->headNode;

    while (current !=NULL)
    {
        sll->headNode = sll->headNode->p2next;
        free(current);
        current = sll->headNode;
        sll->size--;
    }

   // printf("size = %d , head = %d \n" ,sll->size , sll->headNode);

    free(sll);
}

//function to append node
slinkedList_s append_sNode(sLinkedList_t * sll , data_t value )
{
    if(sll == NULL)
    {
        return SLL_NULL_POINTER;
    }

    //create newNode
    sNode_t * newNode = init_node(value);
    if(newNode == NULL)
    {
        return SLL_NODE_NOT_CREATED;
    }
    sNode_t * current = sll->headNode;
    //check if the list is empty

    if(sll->headNode == NULL)       ///at first addition make head node point to newNode
    {
        sll->headNode = newNode;
    }else{
        while (current->p2next !=NULL)
        {
            current = current->p2next;
        }
        ///now current points at the last node in the list
        current->p2next = newNode;
    }

    sll->size++;
    return SLL_OK;

}

//funciton to display list
slinkedList_s dipslay_sll(sLinkedList_t * sll){
    if(sll == NULL)
    {
        return  SLL_NULL_POINTER;
    }

    if(sll->headNode == NULL)
    {
        printf("empty list \n");
        return SLL_EMPTY_LIST;
    }

    sNode_t * current = sll->headNode;

    while (current !=NULL)
    {
        printf("%d " , current->data);
        //printf("%d  , address = %d , next = %d\n" , current->data , current , current->next);
        current = current->p2next;
    }
    printf("\n");

    return SLL_OK;
}
