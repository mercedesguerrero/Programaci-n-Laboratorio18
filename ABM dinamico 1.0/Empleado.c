#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"

#define LIBRE 0
#define OCUPADO 1

int menu()
{
    int opcion;

    system("cls");
    printf(">>>MENU >>>\n\n");
    printf("1- Alta");
    printf("\n2- Baja");
    printf("\n3- Modificar");
    printf("\n4- Listar");
    printf("\n5- Salir\n");

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

int printUnEmpleado(eEmpleado employee)
{
    printf("Legajo: %d\nNombre: %s\nSexo: %c\nSueldo: %.2f\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);

    return 0;
}

void inicializarEmpleados(eEmpleado *listaEmpleados, int tam)
{
    for(int i=0; i<tam; i++)
    {
        (listaEmpleados+i)->isEmpty= LIBRE;
    }
}

int buscarLibre(eEmpleado *listaEmpleados, int tam)
{
    int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if((listaEmpleados+i)->isEmpty== LIBRE)
        {
            indice= i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado *listaEmpleados, int tam, int legajo)
{
    int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if((listaEmpleados+i)->legajo == legajo && (listaEmpleados+i)->isEmpty == OCUPADO)
        {
            indice= i;
            break;
        }
    }

    return indice;
}

void agregarEmpleado(eEmpleado *listaEmpleados, int tam)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice= buscarLibre(listaEmpleados, tam);

    if(indice== -1)
    {
        printf("\nNo hay lugar\n");
    }
    else
    {
        printf("\nIngrese legajo: ");
        scanf("%d", &legajo);

        esta= buscarEmpleado(listaEmpleados, tam, legajo);

        if(esta != -1)
        {
            printf("\nYa existe un empleado con el legajo %d\n", legajo);
            printEmpleado(*(listaEmpleados + esta));
        }
        else
        {
            nuevoEmpleado.legajo= legajo;
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("\nIngrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);
            printf("\nIngrese sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);
            nuevoEmpleado.isEmpty= OCUPADO;

            *(listaEmpleados + indice)= nuevoEmpleado;

            /**< AGREGAR SECTOR */
        }
    }
}

void printEmpleado(eEmpleado unEmpleado)
{
    printf("%d -- %s -- %c -- %.2f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo);
}

void printEmpleadoPorReferencia(eEmpleado *unEmpleado)
{
    printf("%d -- %s -- %c -- %.2f\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo, unEmpleado->sueldo);
}

void mostrarEmpleados(eEmpleado *listaEmpleados, int tam)
{
    printf("\n\n");
    for(int i=0; i<tam; i++)
    {
        if((listaEmpleados + i)->isEmpty == 1)
        {
            printEmpleadoPorReferencia(listaEmpleados + i);
        }
    }
}

void eliminarEmpleado(eEmpleado *listaEmpleados, int tam)
{
    int legajo;
    int indice;
    char respuesta;

    printf("\nIngrese legajo: ");
    scanf("%d", &legajo);

    indice= buscarEmpleado(listaEmpleados, tam, legajo);

    if(indice == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", legajo);
    }
    else
    {
        printEmpleadoPorReferencia(listaEmpleados + indice);

        printf("\nConfirma borrado? s/n ");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta != 's')
        {
            printf("\nBorrado cancelado\n");
        }
        else
        {
            (listaEmpleados + indice)->isEmpty = LIBRE;
            printf("\nSe ha eliminado el empleado\n\n");
        }
    }
}

void modificarEmpleado(eEmpleado *listaEmpleados, int tam)
{
    int legajo;
    int indice;
    char respuesta;
    float nuevoSueldo;

    printf("\nIngrese legajo: ");
    scanf("%d", &legajo);

    indice= buscarEmpleado(listaEmpleados, tam, legajo);

    if(indice == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", legajo);
    }
    else
    {
        printEmpleadoPorReferencia(listaEmpleados + indice);

        printf("\nModifica sueldo? s/n ");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta != 's')
        {
            printf("\nModificacion cancelada\n");
        }
        else
        {
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            (listaEmpleados + indice)->sueldo = nuevoSueldo;
            printf("\nSe ha modificado el sueldo\n\n");
        }
    }
}

