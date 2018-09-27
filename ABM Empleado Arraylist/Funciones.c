#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Arraylist.h"
#include "Funciones.h"

#define LIBRE 0
#define OCUPADO 1


void mostrarMenu()
{
    system("cls");

    printf("\nMENU>>> Seleccione una opcion: \n\n");

    printf("1- ALTA\n");
    printf("2- \n");
    printf("3- \n");
    printf("4- LISTAR\n");
    printf("5- SALIR\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}

eEmpleado* newEmpleado()
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado= (eEmpleado*) malloc(sizeof(eEmpleado));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo= 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->sexo= ' ';
        nuevoEmpleado->sueldo= 0;
        nuevoEmpleado->isEmpty= 0;
        nuevoEmpleado->idSector= 0;
    }

    return nuevoEmpleado;
}

eEmpleado* newEmpleadoParametrizado(int legajo, char* nombre, char sexo, float sueldo, int isEmpty, int idSector)
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado= newEmpleado();

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo= legajo;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sexo= sexo;
        nuevoEmpleado->sueldo= sueldo;
        nuevoEmpleado->isEmpty= OCUPADO;
        nuevoEmpleado->idSector= idSector;

    }

    return nuevoEmpleado;
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


int buscarEmpleado(ArrayList *listaEmpleados, int legajo)
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

void agregarEmpleado(ArrayList* listaEmpleados, eSector listaSectores[], int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;




        printf("\nIngrese legajo: ");
        scanf("%d", &legajo);

        esta= buscarEmpleado(ArrayList, tam, legajo);//hacer la funcion buscar empleado recibe el arraylist, legajo

        if(esta != -1)
        {
            printf("\nYa existe un empleado con el legajo %d\n", legajo);
            printEmpleadoPorReferencia((listaEmpleados + esta), listaSectores, tamSector);
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

            *(listaEmpleados + indice)= newEmpleadoParametrizado();

            //hacer el add
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

