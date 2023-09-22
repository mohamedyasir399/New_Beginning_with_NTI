/**
written By : Mohamed Yasser Ahmed
Repo on GitHub:https://github.com/mohamedyasir399/New_Beginning_with_NTI.git
Testing Video On Google Drive: https://drive.google.com/file/d/1ANLHkCkbyEaF7qLUlgXqnS2BJWmEjHHQ/view?usp=sharing
**/
#include "App.h"
typedef enum{
    AddEmployee=1,DeleTEmployee,ModifyData,ViewEmployeeData,ViewALLEmployeeData,Exit
}state;
int main()
{
    state s;
    printf("\n           Hello in Employee Application\n\n");
    sll_t *sll = create_sll();
    while(s !=Exit)
    {
        char state[2];
        printf("*****Please Enter What you Want from This List Of Command*****\n");
        printf("1-Add Employee to the list\n");
        printf("2-Delete Employee from list\n");
        printf("3-Modify Data of Employee\n");
        printf("4-View Employee Data from list\n");
        printf("5-View ALL Employee Data\n");
        printf("6-Exit from program\n==> ");
        gets(state);
        s = atoi(state);
        if(s== AddEmployee){
            data_t *employeeData = getData();
            if(Check_ID(sll,employeeData)==Existing_ID)
            {
                printf("****Sorry this id has been Existing****\n");
            }else{
                Add_New_Employee(sll,employeeData);
                printf("\n***the Operation Success***\n\n");
            }
        }
        else if(s==DeleTEmployee )
        {
            printf("Please Enter name or id for employee that wanted to delete\n==> ");
            char value[30];
            gets(value);
            Delete_EmployeeData(sll,value);
            printf("\n***the Operation Success***\n\n");
        }
        else if(s== ModifyData)
        {
            printf("Please Enter name or id for employee that wanted to modify\n==> ");
            char value[30],m[2];
            gets(value);
            printf("****Please Enter number which data that wanted to modify****\n");
            printf("1-name, 2-title, 3-id, 4-age, 5-salary, 6-allData\n==> ");
            gets(m);
            int key = atoi(m);
            Modify_EmployeeData(sll,value,key);
            printf("\n***the Operation Success***\n\n");
        }
        else if(s== ViewEmployeeData)
        {
            printf("Please Enter name or id for employee that wanted to veiw\n==> ");
            char value[30];
            gets(value);
            View_EmployeeData(sll,value);
        }
        else if(s== ViewALLEmployeeData)
        {
            View_All_EmployeeData(sll);
        }
        else if(s== Exit)
        {
            free_sll(sll);
            s = Exit;
            printf("****Good Bye Thanks for Your Time****\n");
        }
        else{
            printf("**Wrong Input**\n");
        }
        printf("\n-----------------------------------------\n");
        fflush(stdin);
    }
    return 0;
}
