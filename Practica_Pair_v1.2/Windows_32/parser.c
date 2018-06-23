#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee, int len)
{
    Employee* aux_empleado;

    int i=0;
    int read;
    int retorno= 0;
    char aux_id[50];
    char aux_name[50];
    char aux_last_name[50];
    char aux_status[50];

    do{
        aux_empleado= (Employee*) malloc(sizeof(Employee));

        read= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", aux_id, aux_name, aux_last_name, aux_status);

        if (read==4)
        {
            aux_empleado[i].id= atoi(aux_id);
            strncpy(aux_empleado[i].name, aux_name, sizeof(aux_empleado[i].name));
            strncpy(aux_empleado[i].lastName, aux_last_name, sizeof(aux_empleado[i].lastName));

            if(strcmp(aux_status,"true")==0)
            {
                aux_empleado[i].isEmpty= 1;
            }
            else if(strcmp(aux_status,"false")==0)
            {
                aux_empleado[i].isEmpty= 0;
            }

            al_add(pArrayListEmployee, (aux_empleado));

            i++;

            retorno= 0;
        }
        else
        {
            retorno= -1;
            break;
        }

    }while(!feof(pFile) && i< len);

    return retorno;
}
