#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef enum Check_Input_Data
{
    WRONG_ID=0,WRONG_NAME=0,WRONG_SALARY=0,WRONG_TITLE=0,WRONG_AGE=0
}Input_s;

typedef struct employee
{
    char name[30];
    char title[30];
    int age;
    int salary;
    char id[30];

}data_t;

typedef enum dataModefy{
name_t=1,title_t,id_t,age_t,salary_t,allData_t
}m_data;

typedef struct single_Node
{
    data_t* data;
    struct single_Node * p2next;
}sNode_t;


typedef struct
{
    sNode_t* headNode;
    unsigned int size;
}sll_t;

typedef enum{
    SLL_NODE_NOT_CREATED,
    SLL_NODE_NOT_FOUND,
    SLL_OK,
    SLL_NULL_POINTER,
    SLL_EMPTY_LIST,
    SLL_INVALID_POSITION,
    SLL_NOT_OK,
    SLL_APPEND_FLAG,
    SLL_FREE_OK,
    Existing_ID
}sLinkedList_statue;

char checkName(char*n1,char *n2);
data_t* getData();
sll_t * create_sll();
sNode_t * create_node(data_t* value);
///free data from memory by the end of program
sLinkedList_statue free_sll(sll_t * list);

sLinkedList_statue Check_ID(sll_t*list ,data_t* value);
void Add_New_Employee(sll_t * list , data_t* value );                     ///Add Employee to List
void Delete_EmployeeData(sll_t *list,char* value);   ///Remove Employee from List
void Modify_EmployeeData(sll_t* list,char* key,m_data Mdata);   ///Edit Employee Data
sNode_t * search_Employee(sll_t* list,char *value);
void Print_EmployeeData(data_t *e);       ///print Employee name,id,age,salary,title for each line
void View_EmployeeData(sll_t *list,char *key);
void View_All_EmployeeData(sll_t* list);     ///print All Employee Data in Current List
void Exit_Program();                         ///End the program By Free all Data in list

#endif // APP_H_INCLUDED
