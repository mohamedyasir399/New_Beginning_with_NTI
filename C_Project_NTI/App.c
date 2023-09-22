#include "App.h"
char checkName(char*n1,char *n2)
{
    if(strlen(n1)== strlen(n2))
    {
        for(int i=0 ;i<strlen(n1);i++)
        {
            if(n1[i] != n2[i])
                return 0;
        }
        return 1;
    }
    return 0;
}

void Print_EmployeeData(data_t *e)
{
    printf("\n-----------------------------------------\n");
    printf("-the Employee name = %s\n-His ID= %s\n-His Age = %d\n",e->name,e->id,e->age);
    printf("-his Title = %s\n-His Salary= %d",e->title,e->salary);
    printf("\n-----------------------------------------\n");
}



data_t* getData()
{
    data_t *e= calloc(1,sizeof(data_t));
    char name[30],title[30],id[30],age[4],salary[8];

    printf("name = ");
    gets(name);
    strcpy(e->name,name);

    printf("title = ");
    gets(title);
    strcpy(e->title,title);

    printf("id = ");
    gets(id);
    strcpy(e->id,id);

    printf("age = ");
    gets(age);
    e->age =atoi(age);

    printf("Salary = ");
    gets(salary);
    e->salary =atoi(salary);
    return e;
}

sll_t * create_sll()
{
    sll_t * newList = calloc(1 ,sizeof(sll_t));
    if(newList == NULL)
    {
        return NULL;
    }
    newList->headNode = NULL;
    newList->size = 0 ;

    return newList;
}


//create node
sNode_t * create_node(data_t *value)
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
sLinkedList_statue free_sll(sll_t * list)
{
    if(list == NULL)
    {
        return SLL_NULL_POINTER;
    }

    if(list->headNode == NULL)
    {
        printf("empty list \n");
        return SLL_FREE_OK;
    }

    sNode_t * current = list->headNode;

    while (current !=NULL)
    {
        list->headNode = list->headNode->p2next;
        free(current->data);                                                        ////+4+4
        free(current);
        current = list->headNode;
        list->size--;
    }

   // printf("size = %d , headNode = %d \n" ,list->size , list->headNode);

    free(list);
    return SLL_FREE_OK;
}

void Add_New_Employee(sll_t * list , data_t* value )                    ///Add Employee to List
{
    if(list == NULL)
    {
        return SLL_NULL_POINTER;
    }

    //create newNode
    sNode_t * newNode = create_node(value);
    if(newNode == NULL)
    {
        return SLL_NODE_NOT_CREATED;
    }
    sNode_t * current = list->headNode;
    //check if the list is empty

    if(list->headNode == NULL)          ///at first addition make head node point to newNode
    {
        list->headNode = newNode;
    }else{
        while (current->p2next !=NULL)
        {
            current = current->p2next;
        }
        //now current points at the last node in the list
        if(Check_ID(list,newNode->data->id)!=Existing_ID)
            current->p2next = newNode;
        else
        {
            printf("**Sorry this ID Existing \n ");
        }
    }

    list->size++;
    return SLL_OK;
}

void View_All_EmployeeData(sll_t *list)
{
    if(list == NULL)
    {
        return  SLL_NULL_POINTER;
    }

    if(list->headNode == NULL)
    {
        printf("empty list \n");
        return SLL_EMPTY_LIST;
    }

    sNode_t * current = list->headNode;

    while (current !=NULL)
    {
        Print_EmployeeData(current->data);
        //printf("%d  , address = %d , p2next = %d\n" , current->data , current , current->p2next);
        current = current->p2next;
    }
    printf("\n");

    return SLL_OK;
}

sNode_t * search_Employee(sll_t* list, char* value)
{
    int key=0;
    key = atoi(value);                         ///to copy id number if it input
     if(list ==NULL)
    {
        return NULL;
    }
    if(list->headNode == NULL)
    {
        printf("empty list \n");
        return NULL;
    }
    sNode_t * current = list->headNode;

    while (current != NULL)
    {
        if(key>0)           ///if it success ,key = id number
        {
            if(atoi(current->data->id) == key)
            {
                //printf("i am here\n");
                return current;
            }
        }else
        {
            if(checkName(current->data->name,value))
            {
                //printf("i found him%s\n",value);
                //View_EmployeeData(current->data);
                return current;
            }
        }
        current = current->p2next;
    }

    printf("value not found\n%d",key);
    return NULL;

}

sLinkedList_statue Check_ID(sll_t* list,char* value)
{
    if(list ==NULL)
    {
        return SLL_NULL_POINTER;
    }
    if(list->headNode == NULL)
    {
        return SLL_NODE_NOT_CREATED;
    }
    sNode_t * current = list->headNode;

    while (current != NULL)
    {
        if(checkName(value,current->data->id))
        {
            //printf("how am here\n");
            return Existing_ID;
        }
        current = current->p2next;
    }
    return SLL_OK;
}

void View_EmployeeData(sll_t *list,char *key)
{
    sNode_t *Employee = search_Employee(list,key);
    if(Employee ==NULL)
    {
        return NULL;
    }
    Print_EmployeeData(Employee->data);
}

void Modify_EmployeeData(sll_t* list,char* key,m_data Mdata)   ///Edit Employee Data
{
    data_t *e;
    char name[30],title[30],id[30],age[4],salary[8];
    sNode_t *Employee = search_Employee(list,key);
    if(Employee ==NULL)
    {
        return NULL;
    }

    switch(Mdata)
    {
    case name_t:
        printf("new name = ");
        gets(name);
        strcpy(Employee->data->name,name);
        break;
    case title_t:
        printf("New title = ");
        gets(title);
        strcpy(Employee->data->title,title);
        break;
    case id_t:
        printf("New id = ");
        gets(id);
        if(Check_ID(list,id)==Existing_ID){
            printf("****Sorry this ID has been Existing****\n");
        }else{
            strcpy(Employee->data->id,id);
        }
        break;
    case age_t:
        printf("New age = ");
        gets(age);
        Employee->data->age =atoi(age);
        break;
    case salary_t:
        printf("New Salary = ");
        gets(salary);
        Employee->data->salary =atoi(salary);
        break;
    case allData_t:
        e = getData();
        strcpy(Employee->data->name,e->name);
        strcpy(Employee->data->title,e->title);
        strcpy(Employee->data->id ,e->id);
        Employee->data->age =e->age;
        Employee->data->salary =e->salary;
        free(e);
        break;
    }
}



void Delete_EmployeeData(sll_t *list,char* value)
{
    int key=0;
    key = atoi(value);                         ///to copy id number if it input
    if(list == NULL)
    {
        return  SLL_NULL_POINTER;
    }

    if(list->headNode == NULL)
    {
        printf("empty list \n");
        return SLL_EMPTY_LIST;
    }

    sNode_t * current = list->headNode , *prev;

    if(checkName(list->headNode->data->name, value)||checkName(list->headNode->data->id, value))
    {
        list->headNode = list->headNode->p2next;
        free(current);
        list->size--;
        return SLL_OK;
    }

    while (current!=NULL)
    {
        if(key>0)           ///if it success ,key = id number
        {
            if(atoi(current->data->id) == key)
            {
                //printf("i am here key\n");
                break;
            }
        }else
        {
            if(checkName(current->data->name,value))
            {
                //printf("i found him%s\n",value);
                //View_EmployeeData(current->data);
                break;
            }
        }
        prev =current;
        current = current->p2next;
    }

    if(current == NULL)
    {
        printf("value not found\n");
        return SLL_NODE_NOT_FOUND;
    }

    prev->p2next = current->p2next;

    free(current);
    list->size--;

    return SLL_OK;

}
