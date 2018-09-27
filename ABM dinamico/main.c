#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#define CANTIDAD 40
#define CANT_SECTORES 5

/**< TAREA: UNA FUNCION QUE ABRA UN ARCHIVO Y GUARDE Y CUANDO SE ABRE EL PROGRAMA QUE LEA DE UN ARCHIVO Y LO CARGUE EN EL ARRAY
        INFORMES:
        - MOSTRAR EL EMPLEADO QUE MAS GANA Y MENOS GANA
        - MOSTRAR TODOS LOS HOMBRES
        ORDENAR ARRAY
 */

int main()
{
    char seguir= 's';
    eEmpleado* lista= (eEmpleado*)malloc(sizeof(eEmpleado)*CANTIDAD);
    eSector listaSector[CANT_SECTORES];

    if(lista==NULL)
    {
        exit(1);
    }

    hardcodearSectores(listaSector, CANT_SECTORES);
    //eSector sectores[]= {{1, "Ventas"}, {2, "Compras"}, {3, "RRHH"}, {4, "Contable"}, {5, "Sistemas"}};
    inicializarEmpleados(lista, CANTIDAD);
    //hardcodearEmpleados(lista);
    parsearEmpleados("MOCK_DATA.csv", lista, CANTIDAD);

    /**<  COMO COMPROBAR SI BUSCAR EMPLEADO FUNCIONA OK

    eEmpleado r= {1234, "Juan", 'm', 1000, 1};
    int indice;

    *(lista+3)= r;

    indice= buscarEmpleado(lista, CANTIDAD, 1234);

    printf("%d", indice);

    */

    do
    {
        switch(menu())
        {
            case 1:
                agregarEmpleado(lista, CANTIDAD, listaSector, CANT_SECTORES);

                presionarContinuar();
                break;
            case 2:
                eliminarEmpleado(lista, CANTIDAD, listaSector, CANT_SECTORES);

                presionarContinuar();
                break;
            case 3:
                modificarEmpleado(lista, CANTIDAD, listaSector, CANT_SECTORES);

                presionarContinuar();
                break;
            case 4:
                //ordenarEmpleadosPorNombre(lista, CANTIDAD);
                mostrarEmpleados(lista, CANTIDAD, listaSector, CANT_SECTORES);

                presionarContinuar();
                break;
            case 5:
                mostrarEmpleados(lista, CANTIDAD, listaSector, CANT_SECTORES);

                presionarContinuar();
                break;
            case 6:
                listar_x_sector(lista, listaSector, CANTIDAD, CANT_SECTORES);

                presionarContinuar();
                break;
            case 7:


                presionarContinuar();
                break;
            case 8:


                presionarContinuar();
                break;
            case 9:
                seguir= 'n';
                guardarEmpleados("MOCK_DATA.csv", lista, CANTIDAD);
                break;
        }

    }while(seguir=='s');


    return 0;
}


