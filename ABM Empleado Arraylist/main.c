#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Arraylist.h"
#include "Funciones.h"

#define CANT_SECTORES 5

int main()
{
    char seguir='s';
    int opcion=0;

    eSector listaSector[CANT_SECTORES];
    hardcodearSectores(listaSector, CANT_SECTORES);

    ArrayList* listaEmpleados= al_newArrayList();
    ArrayList* lista2= al_newArrayList();

    //eEmpleado* unEmpleado= newEmpleadoParametrizado(1111, "Mercedes", 'f', 1235, 1, 5);

    if(listaEmpleados== NULL)
    {
        exit(1);
    }
    if(lista2== NULL)
    {
        printf("\nNo hay lugar en memoria para generar la segunda lista");
    }

    parsearEmpleados("MOCK_DATA.csv", listaEmpleados);

    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                //ALTA
                agregarEmpleado(listaEmpleados, listaSector, CANT_SECTORES);

                presionarContinuar();
                break;
            case 2:
                modificarEmpleado(listaEmpleados, listaSector, CANT_SECTORES);
                presionarContinuar();
                break;
            case 3:
                eliminarEmpleado(listaEmpleados, listaSector, CANT_SECTORES);
                presionarContinuar();
                break;
            case 4:
                //LISTAR
                mostrarEmpleados(listaEmpleados, listaSector, CANT_SECTORES);
                presionarContinuar();
                break;
            case 5:
                //LISTAR
                listar_x_sector(listaEmpleados, listaSector, CANT_SECTORES);
                presionarContinuar();
                break;
            case 6:
                //LISTAR
                //listaEmpleados->sort(listaEmpleados, compararEmpleadosSueldo, 0);
                listaEmpleados->sort(listaEmpleados, compararEmpleadosNombre, 1);
                //listaEmpleados->sort(listaEmpleados, compararEmpleadosGenero, 1);
                presionarContinuar();
                break;
            case 7:
                mostrarEmpleadosMasGanadores(listaEmpleados, listaSector, CANT_SECTORES);
                presionarContinuar();
                break;
            case 8:
                filtrarEmpleadosSistemas(listaEmpleados, listaSector, CANT_SECTORES, lista2);
                presionarContinuar();
                break;
            case 9:
                seguir = 'n';
                guardarEmpleados("MOCK_DATA.csv", listaEmpleados);
                break;
        }
    }while(seguir=='s');


    return 0;
}
