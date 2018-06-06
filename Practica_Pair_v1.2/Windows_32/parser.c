#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , empleados, len)
{
    int i=0;
    int r;
    int retorno= -1;
    char aux_id[50];
    char aux_name[50];
    char aux_last_name[50];
    char aux_status[50];

    do{
        r= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", aux_id, aux_name, aux_last_name, aux_status);

        if (r==4)
        {
            empleados[i].id= atoi(aux_id);
            strncpy(empleados[i].name, aux_name, sizeof(empleados[i].name));
            strncpy(empleados[i].lastName, aux_last_name, sizeof(empleados[i].lastName));
            empleados[i].isEmpty= atoi(aux_status);

            retorno= i;
        }
        else
        {
            retorno= -2;
            break;
        }

    }while(!feof(pFile)&& i< len);

    return retorno;
}
