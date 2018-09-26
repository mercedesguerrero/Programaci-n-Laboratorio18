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
    printf(" >>>MENU >>>\n\n");
    printf(" 1- Alta");
    printf("\n 2- Baja");
    printf("\n 3- Modificar");
    printf("\n 4- Ordenar");
    printf("\n 5- Listar");
    printf("\n 6- Listar empleados por sector");
    printf("\n 7- Ordenar empleados por sector y por nombre");
    printf("\n 8- Mostrar los datos de los empleados que mas ganan por sector");
    printf("\n 9- Salir\n");

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

void hardcodearSectores(eSector *listaSectores, int tamSector)
{
    eSector aux[]=
    {
        {1, "Ventas"},
        {2, "Compras"},
        {3, "RRHH"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    for(int i=0; i<tamSector; i++)
    {
        *(listaSectores +i) = *(aux +i);
    }
}

void hardcodearEmpleados(eEmpleado *listaEmpleados)
{
    eEmpleado aux[]=
    {
        {1111, "Juan", 'm', 1000, OCUPADO, 1},
        {2222, "Mer", 'f', 2500, OCUPADO, 2},
        {3333, "Matias", 'm', 3000, OCUPADO, 3},
        {4444, "Luis", 'm', 3500, OCUPADO, 4},
        {5555, "Juana", 'f', 2000, OCUPADO, 5},
        {7777, "Mariela", 'f', 1800, OCUPADO, 2},
        {8888, "Carlos", 'm', 1900, OCUPADO, 3},
        {9999, "Andrea", 'f', 2500, OCUPADO, 2},
        {1000, "Leandro", 'm', 1000, OCUPADO, 1}
    };

    for(int i=0; i<9; i++)
    {
        *(listaEmpleados +i) = *(aux +i);
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

void agregarEmpleado(eEmpleado *listaEmpleados, eSector listaSectores[], int tam, int tamSector)
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
            mostrarSectores(listaSectores, tamSector);
            printf("\n\nIngrese id de sector: ");
            scanf("%d", &nuevoEmpleado.idSector);

            *(listaEmpleados + indice)= nuevoEmpleado;
        }
    }
}

void mostrarSectores(eSector listaSectores[], int tamSector)
{
    for(int i=0; i<tamSector; i++)
    {
        printf("\n%d: %s\t", listaSectores[i].id, listaSectores[i].descripcion);
    }
}

void id_to_sector(int id, char sector[]) /**< o hacer la funcion cargarDescripcion si id de eSector == idSector strcpy PASAR EL ARRAY DE SECTORES Y EL TAMA�O*/
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
        case 4:
            strcpy(sector, "CONTABLE");
            break;
        case 5:
            strcpy(sector, "SISTEMAS");
            break;
    }
}

void printEmpleado(eEmpleado unEmpleado)
{
    char sectorDescripcion[10];

    id_to_sector(unEmpleado.idSector, sectorDescripcion);

    printf("\t%d\t%s\t%c\t%.2f\t%s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo, sectorDescripcion);

}

void printEmpleadoPorReferencia(eEmpleado *unEmpleado)
{
    char sectorDescripcion[10];

    id_to_sector(unEmpleado->idSector, sectorDescripcion);

    printf("\t%d\t%s\t%c\t%.2f\t%s\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo, unEmpleado->sueldo, sectorDescripcion);

}

void mostrarEmpleados(eEmpleado *listaEmpleados, int tam)
{
    printf("\n\n");
    printf("\tID\tNombre \tGenero\tSueldo\tSector\n\n");
    for(int i=0; i<tam; i++)
    {
        if((listaEmpleados + i)->isEmpty == 1)
        {
            printEmpleadoPorReferencia(listaEmpleados + i);
        }
    }
}

void listar_x_sector(eEmpleado *listaEmpleados, eSector *listaSectores, int tam, int tamSector)
{
    int idSector;
    int flag= 0;
    char descripcion[20];

    mostrarSectores(listaSectores, tamSector);
    printf("\n\nIngrese id de sector: ");
    scanf("%d", &idSector);

    system("cls");

    id_to_sector(idSector, descripcion);
    printf("Empleados del sector: %s\n\n", descripcion);

    for(int i=0; i<tam; i++)
    {
        if((listaEmpleados+ i)->isEmpty == OCUPADO && (listaEmpleados+i)->idSector == idSector)
        {
            printEmpleadoPorReferencia(listaEmpleados+i);
            flag=1;
        }
    }


    if(flag== 0)
    {
        printf("\nNo hay empleados para mostrar\n");
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

void ordenar_xSector_xNombre(eEmpleado *listaEmpleados, int tam)
{
    eEmpleado auxEmpleado;
    int i;
    int j;
    char descipcionI[20];
    char descripcionJ[20];

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {


            if(strcmp(descipcionI, descripcionJ) >0)
            {
                auxEmpleado = *(listaEmpleados + i);
                *(listaEmpleados + i) = (listaEmpleados + j);
                *(listaEmpleados + j) = auxEmpleado;
            }
            else if(strcmp(descipcionI, descripcionJ)== 0 && strcmp((listaEmpleados+i)->nombre, (listaEmpleados+j)->nombre)> 0)
            {
                auxEmpleado = *(listaEmpleados + i);
                *(listaEmpleados + i) = (listaEmpleados + j);
                *(listaEmpleados + j) = auxEmpleado;
            }
        }
    }
    printf("\nSe ordenaron los empleados con exito\n");
}

void mostrarEmpleadosQueMasGanan(eSector listaSector, int tamSector)
{
    float maxSueldo;
    int flag;
}

/*
O HACER UNA FUNCION GENERICA QUE COMPARE:
----------------------------

  if(strcmp(*(listaEmpleados + i)->nombre, *(listaEmpleados + j)->nombre)>0)
            {
                auxEmpleado = *(listaEmpleados + i);
                *(listaEmpleados + i) = *(listaEmpleados + j);
                *(listaEmpleados + j) = auxEmpleado;

*/


