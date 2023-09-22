#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

typedef struct Employee
{
    char name[30];
    char title[30];
    int age;
    int salary;
    char id[30];

}employee_t;

void Add_New_Employee();                     ///Add Employee to List
void Delete_EmployeeData();                  ///Remove Employee from List
void Modify_EmployeeData();                  ///Edit Employee Data
void View_EmployeeData(employee_t *e);       ///print Employee name,id,age,salary,title for each line
void View_All_EmployeeData();                ///print All Employee Data in Current List
void Exit_Program();                         ///End the program By Free all Data in list

#endif // APP_H_INCLUDED
