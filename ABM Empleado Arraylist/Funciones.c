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
    printf("2- MODIFICAR SUELDO\n");
    printf("3- ELIMINAR EMPLEADO\n");
    printf("4- LISTAR\n");
    printf("5- LISTAR POR SECTOR\n");
    printf("6- OREDENAR\n");
    printf("7- CREAR ARRAYLIST CON EMPLEADOS DE SISTEMAS\n");
    printf("8- SALIR\n");

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


int buscarEmpleado(ArrayList* listaEmpleados, int legajo)
{
    int indice= -1;
    eEmpleado* unEmpleado;

    for(int i=0; i<listaEmpleados->len(listaEmpleados); i++)
    {
        unEmpleado= (eEmpleado*) listaEmpleados->get(listaEmpleados, i);

        if(unEmpleado->legajo == legajo && unEmpleado->isEmpty == OCUPADO)
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

void parsearEmpleados(char* path, ArrayList* listaEmpleados)
{
    FILE* f;
    eEmpleado* nuevoEmpleado;
    int cant;
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
                nuevoEmpleado= newEmpleado();//constructor

                if(nuevoEmpleado != NULL)
                {   //hacer los setters
                    nuevoEmpleado->legajo= atoi(buffer[0]);
                    strcpy(nuevoEmpleado->nombre, buffer[1]);
                    nuevoEmpleado->sexo= buffer[2][0];
                    nuevoEmpleado->sueldo= atof(buffer[3]);
                    //printf("%c", buffer[2][0]);
                    //presionarContinuar();
                    nuevoEmpleado->isEmpty= atoi(buffer[4]);
                    nuevoEmpleado->idSector= atoi(buffer[5]);

                    listaEmpleados->add(listaEmpleados, nuevoEmpleado);
                }
            }
        }

        fclose(f);
    }
}

void agregarEmpleado(ArrayList* listaEmpleados, eSector* listaSectores, int tamSector)
{
    eEmpleado* nuevoEmpleado;

    int esta;
    int legajo;


        printf("\nIngrese legajo: ");
        scanf("%d", &legajo);

        esta= buscarEmpleado(listaEmpleados, legajo);

        if(esta != -1)
        {

            printf("\nYa existe un empleado con el legajo %d\n", legajo);
            printEmpleadoPorReferencia((eEmpleado*)listaEmpleados->get(listaEmpleados, esta), listaSectores, tamSector);
        }
        else
        {
            nuevoEmpleado= newEmpleado();

            if(nuevoEmpleado != NULL)
            {
                nuevoEmpleado->legajo= legajo;
                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(nuevoEmpleado->nombre);
                printf("\nIngrese sexo: ");
                fflush(stdin);
                scanf("%c", &nuevoEmpleado->sexo);
                printf("\nIngrese sueldo: ");
                scanf("%f", &nuevoEmpleado->sueldo);
                nuevoEmpleado->isEmpty= OCUPADO;
                nuevoEmpleado->idSector = elegirSector(listaSectores, tamSector);

                listaEmpleados->add(listaEmpleados, nuevoEmpleado);
            }
        }
}

void guardarEmpleados(char* path, ArrayList* listaEmpleados)
{
    FILE* f;
    eEmpleado* unEmpleado;

    f= fopen(path, "w");

    if(f != NULL)
    {
        fprintf(f, "legajo,nombre,genero,sueldo,isEmpty,id Sector\n");

        for(int i=0; i<listaEmpleados->len(listaEmpleados); i++)
        {
            unEmpleado= (eEmpleado*)listaEmpleados->get(listaEmpleados, i);

            fprintf(f, "%d, %s, %c, %.2f, %d, %d\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo,
                    unEmpleado->sueldo, unEmpleado->isEmpty, unEmpleado->idSector);
        }

        fclose(f);
    }
}

void printEmpleadoPorReferencia(eEmpleado* unEmpleado, eSector* listaSectores, int tamSector)
{
    char sectorDescripcion[10];

    cargarDescripcion(listaSectores, tamSector, unEmpleado->idSector, sectorDescripcion);

    printf("\t%d\t%20s\t%c\t%8.2f\t%s\n", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sexo, unEmpleado->sueldo, sectorDescripcion);

}

void mostrarEmpleados(ArrayList* listaEmpleados, eSector listaSectores[], int tamSector)
{

    eEmpleado* unEmpleado;
    printf("\n\n");
    printf("\tID\t             Nombre \tGenero\t  Sueldo\tSector\n\n");
    for(int i=0; i< listaEmpleados->len(listaEmpleados); i++)
    {
        unEmpleado= (eEmpleado*)listaEmpleados->get(listaEmpleados, i);

        if(unEmpleado->isEmpty == OCUPADO)
        {
            printEmpleadoPorReferencia(unEmpleado, listaSectores, tamSector);
        }
    }
}

void eliminarEmpleado(ArrayList *listaEmpleados, eSector* listaSectores, int tamSector)
{
    int legajo;
    int indice;
    char respuesta;
    eEmpleado* unEmpleado;

    printf("\nIngrese legajo: ");
    scanf("%d", &legajo);

    indice= buscarEmpleado(listaEmpleados, legajo);

    if(indice == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", legajo);
    }
    else
    {
        printf("\nSe encontro el empleado\n");
        unEmpleado= (eEmpleado*)listaEmpleados->get(listaEmpleados, indice);
        printEmpleadoPorReferencia(unEmpleado, listaSectores, tamSector);

        printf("\nConfirma borrado? s/n ");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta != 's')
        {
            printf("\nBorrado cancelado\n");
        }
        else
        {
            unEmpleado->isEmpty = LIBRE;
            printf("\nSe ha eliminado el empleado\n\n");
        }
    }
}

void modificarEmpleado(ArrayList* listaEmpleados, eSector listaSectores[], int tamSector)
{
    int legajo;
    int indice;
    char respuesta;
    float nuevoSueldo;
    eEmpleado* unEmpleado;

    printf("\nIngrese legajo: ");
    scanf("%d", &legajo);

    indice= buscarEmpleado(listaEmpleados, legajo);

    if(indice == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", legajo);
    }
    else
    {
        unEmpleado= (eEmpleado*)listaEmpleados->get(listaEmpleados, indice);
        printEmpleadoPorReferencia(unEmpleado, listaSectores, tamSector);

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

            unEmpleado->sueldo = nuevoSueldo;
            printf("\nSe ha modificado el sueldo\n\n");
        }
    }
}

int compararEmpleadosSueldo(void* x, void* y)
{
    eEmpleado* emp1= (eEmpleado*)x;
    eEmpleado* emp2= (eEmpleado*)y;

    int retorno;

    if(emp1->sueldo == emp2->sueldo)
    {
        retorno= 0;
    }
    else if(emp1->sueldo > emp2->sueldo)
    {
        retorno= 1;
    }
    else
    {
        retorno= -1;
    }

    return retorno;
}

int compararEmpleadosNombre(void* x, void* y)
{
    eEmpleado* emp1= (eEmpleado*)x;
    eEmpleado* emp2= (eEmpleado*)y;

    return strcmp(emp1->nombre, emp2->nombre);
}

int compararEmpleadosLegajo(void* x, void* y)
{
    eEmpleado* emp1= (eEmpleado*)x;
    eEmpleado* emp2= (eEmpleado*)y;

    int retorno;

    if(emp1->legajo == emp2->sueldo)
    {
        retorno= 0;
    }
    else if(emp1->legajo > emp2->sueldo)
    {
        retorno= 1;
    }
    else
    {
        retorno= -1;
    }

    return retorno;
}

int compararEmpleadosGenero(void* x, void* y)
{
    eEmpleado* emp1= (eEmpleado*)x;
    eEmpleado* emp2= (eEmpleado*)y;

    int retorno;

    if(emp1->sexo == emp2->sexo)
    {
        retorno= 0;
    }
    else if(emp1->sexo > emp2->sexo)
    {
        retorno= 1;
    }
    else
    {
        retorno= -1;
    }

    return retorno;
}

void listar_x_sector(ArrayList *listaEmpleados, eSector *listaSectores, int tamSector)
{
    int idSector;
    int flag= 0;
    char descripcion[20];
    eEmpleado* unEmpleado;

    idSector = elegirSector(listaSectores, tamSector);
    cargarDescripcion(listaSectores, tamSector, idSector, descripcion);

    system("cls");

    printf("Empleados del sector: %s\n\n", descripcion);

    for(int i=0; i<listaEmpleados->len(listaEmpleados); i++)
    {
        if(unEmpleado->isEmpty == OCUPADO && unEmpleado->idSector == idSector)
        {
            printEmpleadoPorReferencia(unEmpleado, listaSectores, tamSector);
            flag=1;
        }
    }

    if(flag== 0)
    {
        printf("\nNo hay empleados para mostrar\n");
    }
}

void mostrarEmpleadosMasGanadores(ArrayList* listaEmpleados, eSector* sectores, int tamSector)
{
    float maxSueldo;
    char descripcion[20];
    int flag;
    eEmpleado* unEmpleado;

    for(int i=0; i < tamSector; i++){
         cargarDescripcion(sectores, tamSector, sectores[i].id, descripcion);
         printf("Sector %s\n", descripcion);
         flag = 0;
        for(int j=0; j < listaEmpleados->len(listaEmpleados); j++)//busca el sueldo mas alto
        {
            unEmpleado= (eEmpleado*)listaEmpleados->get(listaEmpleados, j);
            if( (unEmpleado->sueldo > maxSueldo && unEmpleado->isEmpty == 1 && unEmpleado->idSector == (sectores + i)->id) || flag == 0)
            {
                maxSueldo = unEmpleado->sueldo;
                flag = 1;
            }
         }

        for(int j=0; j < listaEmpleados->len(listaEmpleados); j++)// muestra los empleados con mayor sueldo
        {
            unEmpleado= (eEmpleado*)listaEmpleados->get(listaEmpleados, j);
            if( unEmpleado->sueldo == maxSueldo && unEmpleado->idSector == (sectores + i)->id && unEmpleado->isEmpty== OCUPADO)
            {
               // mostrarEmpleado(unEmpleado, sectores, tamSector);
            }
        }

        printf("\n\n");

    }

}

void filtrarEmpleadosSistemas(ArrayList* listaEmpleados, eSector* sectores, int tamSector, ArrayList* lista2)
{
    eEmpleado* unEmpleado;

    for(int i=0; i> listaEmpleados->len(listaEmpleados); i++)
    {
        unEmpleado= (eEmpleado*) listaEmpleados->get(listaEmpleados, i);

        if(unEmpleado->idSector == 5)
        {
            lista2->add(lista2, unEmpleado);
        }
    }

    mostrarEmpleados(lista2, sectores, tamSector);
}





