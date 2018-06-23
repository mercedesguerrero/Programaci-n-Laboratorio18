#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compareByName(void* pEmployeeA,void* pEmployeeB)
{
    Employee* e= (Employee*)pEmployeeA;
    Employee* e2= (Employee*)pEmployeeB;

    return strcmp(e->name, e2->name);
}

int employee_compareByID(void* pEmployeeA,void* pEmployeeB)
{
    int retorno= -2;

    Employee* e= (Employee*)pEmployeeA;
    Employee* e2= (Employee*)pEmployeeB;


    if(e->id==e2->id)
    {
        retorno= 0;
    }
    else
    {
        if (e->id > e2->id)
        {
            retorno= 1;
        }
        else if (e->id < e2->id)
        {
            retorno= -1;
        }
    }

    return retorno;
}

void employee_print(Employee* this)
{
    printf("\n%d\t %s\t       %s", this->id, this->name, this->lastName);
}

void employee_print_all(ArrayList* pArrayListEmployee)
{
  Employee* aux;
  int len;
  int i;
  len= al_len(pArrayListEmployee);

  for(i=0; i<len; i++)
  {
    if(i% 50== 0)
    {
        printf("\n");
        system("pause");
    }
    aux= (Employee*)al_get(pArrayListEmployee, i);
    employee_print(aux);
  }
}

Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


