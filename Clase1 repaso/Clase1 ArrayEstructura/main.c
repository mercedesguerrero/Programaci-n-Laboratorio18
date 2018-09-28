#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 6

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;

}eEmpleado;

void printUnEmpleado(eEmpleado employee);
void printArrayEmpleados(eEmpleado personal[], int tamanio);
int ordenarEmpleados(eEmpleado employee[], int tamanio);


int main()
{
    //eEmpleado lista[TAM];

    eEmpleado lista[TAM]={
        {1111, "Juan", 'm', 1000},
        {2222, "Ana", 'f', 2000},
        {3333, "Luisa", 'f', 3000},
        {4444, "Juana", 'f', 1200},
        {5555, "Analia", 'f', 2500},
        {7777, "Fernando", 'm', 3800}
    };

    /*
    for(int i=0; i<2; i++)
    {
        system("cls");
        printf("Ingrese legajo: \n");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: \n");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese sueldo: \n");
        scanf("%f", &lista[i].sueldo);
    }
    system("cls");
    */

    printArrayEmpleados(lista, TAM);

    ordenarEmpleados(lista, TAM);

    printf("---------------------------------------------------");

    printArrayEmpleados(lista, TAM);

    return 0;
}

void printUnEmpleado(eEmpleado employee)
{
    printf("\n");
    printf("Legajo: %d\nNombre: %s\nSexo: %c\nSueldo: %.2f\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
    printf("\n");

}

void printArrayEmpleados(eEmpleado personal[], int tamanio)
{
    for(int i=0; i<tamanio; i++)
    {
        printUnEmpleado(personal[i]);
    }
}

/**< ordena de mayor a menor */
int ordenarEmpleados(eEmpleado employee[], int tamanio)
{
    eEmpleado auxEmpleado;

    for(int i=0; i<tamanio-1; i++)
    {
        for(int j=i+1; j<tamanio; j++)
        {
            if(employee[i].sexo < employee[j].sexo)
            {
                auxEmpleado= employee[i];
                employee[i]= employee[j];
                employee[j]= auxEmpleado;
            }
            else if(employee[i].sexo == employee[j].sexo && strcmp(employee[i].nombre, employee[j].nombre)>0)
            {
                auxEmpleado= employee[i];
                employee[i]= employee[j];
                employee[j]= auxEmpleado;
            }
        }
    }

    return 0;
}
