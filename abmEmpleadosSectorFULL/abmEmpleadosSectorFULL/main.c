#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"

#define TAM 40

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

int compararEmpleadosSueldo(void* x, void* y);
int compararEmpleadosNombre(void* x, void* y);
int compararEmpleadosSexo(void* x, void* y);
int compararEmpleadosLegajo(void* x, void* y);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo, int idSector);
int buscarEmpleado(ArrayList* x, int legajo);
void mostrarEmpleado(eEmpleado* emp, eSector* sectores, int tamSector);
void mostrarEmpleados(ArrayList* nomina, eSector* sectores, int tamSector);
void agregarEmpleado(ArrayList* empleados, eSector* sectores, int tamSector);
void eliminarEmpleado(ArrayList* empleados, eSector* sectores, int tamSector);
void modificarEmpleado(ArrayList* empleados, eSector* sectores, int tamSector);
int elegirSector(eSector* sectores, int tam);
void cargarDescripcion(eSector* sectores, int tamSector, int idSector, char* cadena);
void listarEmpleadosXSector(ArrayList* x, eSector* sectores, int tamSector);
void ordenarXSectorYNombre(ArrayList* x, eSector* sectores, int tamSector);
void mostrarEmpleadosMasGanadores(ArrayList* x, eSector* sectores, int tamSector);
void filtrarEmpleadosSistemas(ArrayList* lista,eSector* sectores,int tamSector,ArrayList* lista2);
void parsearEmpleados(char* path, ArrayList* listaEmpleados);
void guardarEmpleados(char* path, ArrayList* listaEmpleados);
int menu();

int main()
{

    char seguir = 's';
    ArrayList* lista = al_newArrayList();
    ArrayList* lista2 = al_newArrayList();

    if(lista == NULL)
    {
        exit(1);
    }
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    parsearEmpleados("empleados.csv", lista);

    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, sectores, 5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, sectores, 5);
            system("pause");
            break;
        case 5:
            listarEmpleadosXSector(lista, sectores, 5);
            system("pause");
            break;
        case 6:
          //  ordenarXSectorYNombre(lista, sectores, 5);
            lista->sort(lista, compararEmpleadosLegajo, 1);
            system("pause");
            break;
        case 7:
            mostrarEmpleadosMasGanadores(lista, sectores, 5);
            system("pause");
            break;
            case 8:
            filtrarEmpleadosSistemas(lista, sectores, 5, lista2);
            system("pause");
            break;
        case 10:
            seguir = 'n';
            guardarEmpleados("empleados.csv", lista);
            break;
        }

    }
    while(seguir == 's');



    return 0;
}





int buscarEmpleado(ArrayList* x, int legajo)
{
    int indice = -1;
    eEmpleado* unEmpleado;

    for(int i=0; i < x->len(x); i++)
    {
        unEmpleado = (eEmpleado*)x->get(x, i);
        if( unEmpleado->legajo == legajo && unEmpleado->isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n      ***Menu de Opciones***\n\n");
    printf("   1- Alta\n");
    printf("   2- Baja\n");
    printf("   3- Modificar\n");
    printf("   4- Listar\n");
    printf("   5- Listar todos los empleados de un sector\n");
    printf("   6- Ordenar empleados por sector y dentro del sector por nombre\n");
    printf("   7- Mostrar los datos de el o los empleados que mas ganan por sector\n");
    printf("   8- Crear Arraylist con empleados de Sistemas\n");
    printf("  10- Salir\n");
    printf("\n   Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void agregarEmpleado(ArrayList* empleados, eSector* sectores, int tamSector)
{
    eEmpleado* nuevoEmpleado;

    int esta;
    int legajo;

    system("cls");
    printf("\n   *** Alta Empleado ***\n\n");




        printf(" Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( (eEmpleado*)empleados->get(empleados,esta), sectores, tamSector);
        }
        else
        {
            nuevoEmpleado = newEmpleado();

            if(nuevoEmpleado != NULL){

            nuevoEmpleado->legajo = legajo;

            printf(" Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado->nombre);

            printf(" Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado->sexo);

            printf(" Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado->sueldo);

            nuevoEmpleado->idSector = elegirSector(sectores, 5);

            nuevoEmpleado->isEmpty = 1;

            empleados->add(empleados, nuevoEmpleado);

            }
    }
    printf("\n");

}

void mostrarEmpleado(eEmpleado* emp, eSector* sectores, int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp->idSector, descripcion);

    printf(" %4d %10s  %2c   %6.2f %10s \n\n", emp->legajo, emp->nombre, emp->sexo, emp->sueldo, descripcion);

}


void mostrarEmpleados(ArrayList* nomina, eSector* sectores, int tamSector)
{
    eEmpleado* unEmpleado;
    system("cls");
    printf("------------------------------------------\n");
    printf(" Legajo   Nombre  Sexo   Sueldo     Sector\n");
    printf("------------------------------------------\n\n");
    for(int i=0; i< nomina->len(nomina); i++)
    {
        unEmpleado = (eEmpleado*) nomina->get(nomina, i);
        if( unEmpleado->isEmpty == 1)
        {

            mostrarEmpleado(unEmpleado, sectores, tamSector);
        }
    }
    printf("------------------------------------------\n\n");
}

void eliminarEmpleado(ArrayList* empleados, eSector* sectores, int tamSector)
{

    int legajo;
    int indice;
    char borrar;
    eEmpleado* unEmpleado;
    system("cls");
    printf("\n*** Borrar Empleado ***\n\n");
    printf(" Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        printf("\nEmpleado encontrado!!!\n\n");
        unEmpleado = (eEmpleado*)empleados->get(empleados, indice);
        mostrarEmpleado( unEmpleado, sectores, tamSector);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            unEmpleado->isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(ArrayList* empleados, eSector* sectores, int tamSector)
{

    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;
    eEmpleado* unEmpleado;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        unEmpleado = (eEmpleado*)empleados->get(empleados, indice);
        mostrarEmpleado( unEmpleado, sectores, tamSector);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            unEmpleado->sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
    }

}


int elegirSector(eSector* sectores, int tam)
{
    int idSector;
    printf("\n  ***Sectores***\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("  %d %s\n", (sectores + i)->id, (sectores + i)->descripcion);
    }
    printf("\n Seleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void cargarDescripcion(eSector* sectores, int tamSector, int idSector, char* cadena)
{
    for(int i=0; i < tamSector; i++)
    {
        if( (sectores + i)->id == idSector)
        {
            strcpy(cadena, (sectores + i)->descripcion);
            break;
        }
    }
}

void listarEmpleadosXSector(ArrayList* x, eSector* sectores, int tamSector)
{
    int idSector;
    char descripcion[20];
    int flag = 0;
    eEmpleado* unEmpleado;

    idSector = elegirSector(sectores, tamSector);

    cargarDescripcion(sectores, tamSector, idSector, descripcion);

    system("cls");
    printf("Empleados del sector %s\n\n", descripcion);
    for(int i=0; i< x->len(x); i++)
    {
        unEmpleado = (eEmpleado*)x->get(x,i);
        if( unEmpleado->isEmpty == 1 && unEmpleado->idSector == idSector)
        {
            mostrarEmpleado(unEmpleado, sectores, tamSector);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }

}

/*void ordenarXSectorYNombre(ArrayList* x, eSector* sectores, int tamSector)
{

    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado auxEmpleado;


            cargarDescripcion(sectores, tamSector, (x + i)->idSector, descripcionI);
            cargarDescripcion(sectores, tamSector, (x + j)->idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = *(x + i);
                *(x + i) = *(x + j);
                *(x + j) = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && (x + i)->sexo > (x + j)->sexo)
            {
                auxEmpleado = *(x + i);
                *(x + i) = *(x + j);
                *(x + j) = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && (x + i)->sexo == (x + j)->sexo && strcmp((x + i)->nombre, (x + j)->nombre) > 0)
            {
                auxEmpleado = *(x + i);
                *(x + i) = *(x + j);
                *(x + j) = auxEmpint buscarEmpleado(ArrayList x, int legajo)leado;
            }
        }
    }
    system("pause");
    printf("\nEmpleados ordenados con exito!!!\n\n");

}
*/
void mostrarEmpleadosMasGanadores(ArrayList* x, eSector* sectores, int tamSector)
{
    float maxSueldo;
    char descripcion[20];
    eEmpleado* unEmpleado;
    int flag;

    for(int i=0; i < tamSector; i++)
    {
        cargarDescripcion(sectores, tamSector, (sectores + i)->id, descripcion);
        printf("Sector %s\n", descripcion);
        flag = 0;
        for(int j=0; j < x->len(x); j++)
        {
            unEmpleado = (eEmpleado*)x->get(x,j);
            if(( unEmpleado->sueldo > maxSueldo && unEmpleado->isEmpty == 1 && unEmpleado->idSector == (sectores + i)->id) || ((flag == 0&& unEmpleado->isEmpty == 1 && unEmpleado->idSector == (sectores + i)->id)))
            {
                maxSueldo = unEmpleado->sueldo;
                flag = 1;
            }
        }

        for(int j=0; j < x->len(x); j++)
        {
            unEmpleado = (eEmpleado*)x->get(x,j);
            if( unEmpleado->sueldo == maxSueldo && unEmpleado->idSector == (sectores + i)->id &&  unEmpleado->isEmpty == 1)
            {
                mostrarEmpleado(unEmpleado, sectores, tamSector);
            }
        }

    }

}


void parsearEmpleados(char* path, ArrayList* listaEmpleados)
{

    FILE* f;
    eEmpleado* nuevoEmpleado;

    int cant;
    char buffer[6][128];

    f = fopen(path, "r");

    if(f != NULL && listaEmpleados != NULL)
    {

        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

        while( !feof(f))
        {

            cant =  fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

            if(cant == 6)
            {
                nuevoEmpleado = newEmpleado();

                if(nuevoEmpleado != NULL){

                nuevoEmpleado->legajo = atoi(buffer[0]);
                strcpy(nuevoEmpleado->nombre, buffer[1]);
                nuevoEmpleado->sexo = buffer[2][0];
                nuevoEmpleado->sueldo = atof(buffer[3]);
                nuevoEmpleado->idSector =  atoi(buffer[4]);
                nuevoEmpleado->isEmpty =  atoi(buffer[5]);

                listaEmpleados->add(listaEmpleados, nuevoEmpleado);// si

                //al_add(listaEmpleados, nuevoEmpleado); no

                }

            }
            else
            {
                break;
            }

        }

        fclose(f);
    }



}

void guardarEmpleados(char* path, ArrayList* listaEmpleados)
{

    FILE* f;

    f = fopen(path, "w");
    eEmpleado* unEmpleado;

    if(f != NULL)
    {

        fprintf(f, "legajo,nombre,sexo,sueldo,idSector,isEmpty\n");

        for(int i=0; i <  listaEmpleados->len(listaEmpleados); i++)
        {
            unEmpleado = (eEmpleado*)listaEmpleados->get(listaEmpleados, i);
            fprintf(f,"%d,%s,%c,%.2f,%d,%d\n", unEmpleado->legajo,  unEmpleado->nombre,  unEmpleado->sexo,  unEmpleado->sueldo,  unEmpleado->idSector,  unEmpleado->isEmpty );

        }

        fclose(f);

    }

}

eEmpleado* newEmpleado(){

eEmpleado* nuevoEmpleado = (eEmpleado*)malloc(sizeof(eEmpleado));

if( nuevoEmpleado != NULL){

    nuevoEmpleado->legajo = 0;
    strcpy(nuevoEmpleado->nombre, "");
    nuevoEmpleado->sexo = ' ';
    nuevoEmpleado->sueldo = 0;
    nuevoEmpleado->idSector = 0;
    nuevoEmpleado->isEmpty = 0;
}
return nuevoEmpleado;

}

eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo, int idSector){

eEmpleado* nuevoEmpleado = newEmpleado();

if( nuevoEmpleado != NULL){

    nuevoEmpleado->legajo = legajo;
    strcpy(nuevoEmpleado->nombre, nombre);
    nuevoEmpleado->sexo = sexo;
    nuevoEmpleado->sueldo = sueldo;
    nuevoEmpleado->idSector = idSector;
    nuevoEmpleado->isEmpty = 1;
}
return nuevoEmpleado;

}

int compararEmpleadosSueldo(void* x, void* y){

 eEmpleado* emp1 = (eEmpleado*)x;
 eEmpleado* emp2 = (eEmpleado*)y;
 int retorno;

  if(emp1->sueldo == emp2->sueldo){

    retorno = 0;
  }
  else if( emp1->sueldo > emp2->sueldo){

    retorno = 1;
  }
  else{
    retorno = -1;
  }

  return retorno;

}


int compararEmpleadosNombre(void* x, void* y){

 eEmpleado* emp1 = (eEmpleado*)x;
 eEmpleado* emp2 = (eEmpleado*)y;

 return strcmp(emp1->nombre, emp2->nombre);

}

int compararEmpleadosSexo(void* x, void* y){

 eEmpleado* emp1 = (eEmpleado*)x;
 eEmpleado* emp2 = (eEmpleado*)y;
 int retorno;

  if(emp1->sexo == emp2->sexo){

    retorno = 0;
  }
  else if( emp1->sexo > emp2->sexo){

    retorno = 1;
  }
  else{
    retorno = -1;
  }

  return retorno;

}



int compararEmpleadosLegajo(void* x, void* y){

 eEmpleado* emp1 = (eEmpleado*)x;
 eEmpleado* emp2 = (eEmpleado*)y;
 int retorno;

  if(emp1->legajo == emp2->legajo){

    retorno = 0;
  }
  else if( emp1->legajo > emp2->legajo){

    retorno = 1;
  }
  else{
    retorno = -1;
  }

  return retorno;

}

void filtrarEmpleadosSistemas(ArrayList* lista,eSector* sectores,int tamSector,ArrayList* lista2){

eEmpleado* unEmpleado;

  for(int i= 0; i < lista->len(lista); i++){
    unEmpleado = (eEmpleado*)lista->get(lista, i);

    if(unEmpleado->idSector == 5){
        lista2->add(lista2, unEmpleado);
    }

  }

  mostrarEmpleados(lista2, sectores, tamSector);

}

