#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* empleados;

    empleados= al_newArrayList(); //constructor da espacio en memoria para el array list

    int index;

    FILE* pFile;

    pfile= fopen(data,"r");

    /*HARDCODEO DE DATOS

    Employee* e; //={1, "Juan", "Gomez", 1};
    Employee* aux;

    e= (Employee*)malloc(sizeof(Employee));
    e->id=5;
    strcpy(e->name, "Juan");

    al_add(empleados, e);

    Employee* e2; //={1, "Juana", "Goma", 1};

    e2= (Employee*)malloc(sizeof(Employee));
    e2->id=6;
    strcpy(e2->name, "Ana");

    al_add(empleados, e2);

    al_sort(empleados, employee_compareByID, 1);

    //al_sort(empleados, employee_compareByName, 1);

    */

    if(pFile== NULL)
    {
        printf("No se encontró el archivo\n")
    }

    else
    {
        index= parserEmployee(pFile, empleados, al_len(empleados));
    }

    printf("Hay %d elementos: \n", al_len(empleados));

    for(i=0; i<al_len(empleados); i++)
    {
        aux= (Employee*)al_get(empleados, i); //hacer una funcion
        printf("%d----%s\n", aux->id, aux->name); //hacer una funcion
    }


    return 0;
}
