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

void agregarEmpleado(eEmpleado *listaEmpleados, eSector listaSectores[], int tam)
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
            printf("\n%d: %s\t%d: %s\t%d: %s \nIngrese sector: ", listaSectores[0].id, listaSectores[0].descripcion, listaSectores[1].id, listaSectores[1].descripcion, listaSectores[2].id, listaSectores[2].descripcion);
            scanf("%d", &nuevoEmpleado.idSector);

            *(listaEmpleados + indice)= nuevoEmpleado;
        }
    }
}

void id_to_sector(int id, char sector[])
{
    switch(id)
    {
        case 1:
            strcpy(sector,"VENTAS");
            break;
        case 2:
            strcpy(sector,"COMPRAS");
            break;
        case 3:
            strcpy(sector, "RRHH");
            break;
    }
}

void printEmpleado(eEmpleado unEmpleado)
{
    if(unEmpleado.idSector==1)
    {
        printf("%d -- %s -- %c -- %.2f -- %s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo, "VENTAS");
    }
    else if(unEmpleado.idSector==2)
    {
        printf("%d -- %s -- %c -- %.2f -- %s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo, "COMPRAS");
    }
    else if(unEmpleado.idSector==3)
    {
        printf("%d -- %s -- %c -- %.2f -- %s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo, "RRHH");
    }


}

void printEmpleadoPorReferencia(eEmpleado *unEmpleado)
{
    if(unEmpleado->idSector==1)
    {
        printf("%d -- %s -- %c -- %.2f -- %s\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo, unEmpleado->sueldo, "VENTAS");
    }
    if(unEmpleado->idSector==2)
    {
        printf("%d -- %s -- %c -- %.2f -- %s\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo, unEmpleado->sueldo, "COMPRAS");
    }
    if(unEmpleado->idSector==3)
    {
        printf("%d -- %s -- %c -- %.2f -- %s\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo, unEmpleado->sueldo, "RRHH");
    }

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

