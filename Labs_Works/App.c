#include "App.h"

void View_EmployeeData(employee_t *e)
{
    printf("\n-----------------------------------------\n");
    printf("-the Employee name = %s\n-His ID= %s\n-His Age = %d\n",e->name,e->id,e->age);
    printf("-his Title = %s\n-His Salary= %d",e->title,e->salary);
    printf("\n-----------------------------------------\n");
}
