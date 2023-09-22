#ifndef LINKED_LIST_STRUCT_H_INCLUDED
#define LINKED_LIST_STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef int data_t;

typedef struct Singly_Node
{
    data_t data;
    struct Singly_Node* p2next;

}sNode_t;

typedef struct Singly_LinkedList
{
    int size;
    sNode_t* headNode;
    sNode_t* tailNode;
}sLinkedList_t;

typedef enum{
    SLL_NODE_NOT_CREATED,
    SLL_NODE_NOT_FOUND,
    SLL_OK,
    SLL_NULL_POINTER,
    SLL_EMPTY_LIST,
    SLL_INVALID_POSITION,
    SLL_NOT_OK,
    SLL_APPEND_FLAG
}slinkedList_s;

sNode_t* init_node(data_t value);
sLinkedList_t* init_sLinkedList();  ///initialization & create the Singly Linked List
slinkedList_s free_LinkedList(sLinkedList_t* sll);      ///free data from memory by the end of program

///function to append node
slinkedList_s append_sNode(sLinkedList_t * sll , data_t value);
///function to display list
slinkedList_s display_sLinkedList(sLinkedList_t * sll);

#endif // LINKED_LIST_STRUCT_H_INCLUDED
