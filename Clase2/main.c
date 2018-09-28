#include <stdlib.h>
#include <stdio.h>
#include "Alumno.h"
#define CANTIDAD 3

/**< hacer una funcion que cargue en el primer lugar libre y la funcion que devuelva el primer lugar libre si es que hay lugar
y una funcion que sea cargar una opcion */

int main()
{
    int i;
    sMenu miMenu;

    miMenu= inicializarMenu(miMenu);

    for(i=0; i<5; i++)
    {
        printf("\nEl array esta vacio: %d", miMenu.listadoDeOpciones[i].isEmpty);
    }
    printf("\n\n");
    presionarContinuar();
    system("cls");

    miMenu= cargaDeMenu(miMenu);
    mostrarMenu(miMenu);

    miMenu= eliminaUnaOpcion(miMenu);
    mostrarMenu(miMenu);


    //opcionSeleccionada= RetornarOpcion(listadoOpcionesMain, CANTIDAD);

    //printf("\n\tOpcion seleccionada %d:\t %s", opcionSeleccionada.numero, opcionSeleccionada.texto);
    //printf("\nLa opcion seleccionada es: ");
    //mostrarOpcion(opcionSeleccionada);

    printf("\n\n");

    /*
    char seguir='s';
    int opcion=0;

    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                cargarListadoDeAlumnos(listadoMain, A);
                presionarContinuar();
                break;
            case 2:
                mostrarListadoDeAlumnos(listadoMain, A);
                presionarContinuar();
                break;
            case 3:
                printf("Ordenar\n");
                ordenarListadoDeAlumnosPorNombre(listadoMain, A);
                mostrarListadoDeAlumnos(listadoMain, A);

                presionarContinuar();

                break;
            case 4:

                presionarContinuar();

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    */



    return 0;
}
