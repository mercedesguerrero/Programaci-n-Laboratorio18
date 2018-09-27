#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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

int elegirSector(eSector listaSectores[], int tamSector)
{
    int idSector;
    printf("\nSectores\n\n");

    for(int i=0; i < tamSector; i++)
    {
        printf("%d %s\n", listaSectores[i].id, listaSectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{

    for(int i=0; i < tamSector; i++)
    {
        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }

}

void parsearEmpleados(char* path, eEmpleado* listaEmpleados, int tam)
{
    FILE* f;
    eEmpleado nuevoEmpleado;
    int cant;
    int indice;
    char buffer[6][128];

    f= fopen(path, "r");


    if(f!= NULL && listaEmpleados!= NULL)
    {
        /**< %[^,]quiero leer todo lo que encuentres hasta la coma  */

        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);// hago 2 leidas fantasmas porq lee mal el archivo sino

        while(!feof(f))
        {
            cant= fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);


            if(cant ==6)
            {

                nuevoEmpleado.legajo= atoi(buffer[0]);
                strcpy(nuevoEmpleado.nombre, buffer[1]);
                nuevoEmpleado.sexo= buffer[2][0];
                nuevoEmpleado.sueldo= atof(buffer[3]);
                nuevoEmpleado.isEmpty= atoi(buffer[4]);
                nuevoEmpleado.idSector= atoi(buffer[5]);

                indice= buscarLibre(listaEmpleados, tam);

                *(listaEmpleados+ indice)= nuevoEmpleado;
            }
        }

        fclose(f);
    }
}

void agregarEmpleado(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector)
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
            printEmpleado(*(listaEmpleados + esta), listaSectores, tamSector);
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
            nuevoEmpleado.idSector = elegirSector(listaSectores, tamSector);

            *(listaEmpleados + indice)= nuevoEmpleado;
        }
    }
}

void guardarEmpleados(char* path, eEmpleado* listaEmpleados, int tam)
{
    FILE* f;

    f= fopen(path, "w");

    if(f != NULL)
    {
        fprintf(f, "legajo,nombre,genero,sueldo,isEmpty,id Sector\n");

        for(int i=0; i<tam; i++)
        {
            fprintf(f, "%d, %s, %c, %.2f, %d, %d\n", (listaEmpleados + i)->legajo, (listaEmpleados + i)->nombre, (listaEmpleados + i)->sexo,
                    (listaEmpleados + i)->sueldo, (listaEmpleados + i)->isEmpty, (listaEmpleados + i)->idSector);
        }

        fclose(f);
    }
}

void printEmpleado(eEmpleado unEmpleado, eSector listaSectores[], int tamSector)
{
    char sectorDescripcion[10];

    cargarDescripcion(listaSectores, tamSector, unEmpleado.idSector, sectorDescripcion);

    printf("\t%d\t%20s\t%c\t%8.2f\t%s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo, sectorDescripcion);

}

void printEmpleadoPorReferencia(eEmpleado *unEmpleado, eSector listaSectores[], int tamSector)
{
    char sectorDescripcion[10];

    cargarDescripcion(listaSectores, tamSector, unEmpleado->idSector, sectorDescripcion);

    printf("\t%d\t%20s\t%c\t%8.2f\t%s\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo, unEmpleado->sueldo, sectorDescripcion);

}

void mostrarEmpleados(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector)
{
    printf("\n\n");
    printf("\tID\t             Nombre \tGenero\t  Sueldo\tSector\n\n");
    for(int i=0; i<tam; i++)
    {
        if((listaEmpleados + i)->isEmpty == OCUPADO)
        {
            printEmpleadoPorReferencia((listaEmpleados + i), listaSectores, tamSector);
        }
    }
}

void listar_x_sector(eEmpleado *listaEmpleados, eSector *listaSectores, int tam, int tamSector)
{
    int idSector;
    int flag= 0;
    char descripcion[20];

    idSector = elegirSector(listaSectores, tamSector);
    cargarDescripcion(listaSectores, tam, idSector, descripcion);

    system("cls");

    printf("Empleados del sector: %s\n\n", descripcion);

    for(int i=0; i<tam; i++)
    {
        if((listaEmpleados+ i)->isEmpty == OCUPADO && (listaEmpleados+i)->idSector == idSector)
        {
            printEmpleadoPorReferencia((listaEmpleados+i), listaSectores, tamSector);
            flag=1;
        }
    }


    if(flag== 0)
    {
        printf("\nNo hay empleados para mostrar\n");
    }
}

void eliminarEmpleado(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector)
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
        printEmpleadoPorReferencia((listaEmpleados + indice), listaSectores, tamSector);

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

void modificarEmpleado(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector)
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
        printEmpleadoPorReferencia((listaEmpleados + indice), listaSectores, tamSector);

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


/*
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

*/


/*
O HACER UNA FUNCION GENERICA QUE COMPARE:
----------------------------

  if(strcmp(*(listaEmpleados + i)->nombre, *(listaEmpleados + j)->nombre)>0)
            {
                auxEmpleado = *(listaEmpleados + i);
                *(listaEmpleados + i) = *(listaEmpleados + j);
                *(listaEmpleados + j) = auxEmpleado;

*/


