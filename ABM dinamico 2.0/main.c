#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#define CANTIDAD 10

/**< TAREA: UNA FUNCION QUE ABRA UN ARCHIVO Y GUARDE Y CUANDO SE ABRE EL PROGRAMA QUE LEA DE UN ARCHIVO Y LO CARGUE EN EL ARRAY
        INFORMES:
        - MOSTRAR EL EMPLEADO QUE MAS GANA Y MENOS GANA
        - MOSTRAR TODOS LOS HOMBRES
        ORDENAR ARRAY
 */

int main()
{
    char seguir= 's';
    eEmpleado *lista= (eEmpleado*)malloc(sizeof(eEmpleado)*10);

    if(lista==NULL)
    {
        exit(1);
    }

    inicializarEmpleados(lista, CANTIDAD);

    eSector sectores[]= {{1, "Ventas"}, {2, "Compras"}, {3, "RRHH"}};

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
                agregarEmpleado(lista, sectores, CANTIDAD);

                presionarContinuar();
                break;
            case 2:
                eliminarEmpleado(lista, CANTIDAD);

                presionarContinuar();
                break;
            case 3:
                modificarEmpleado(lista, CANTIDAD);

                presionarContinuar();
                break;
            case 4:
                ordenarEmpleadosPorNombre(lista, CANTIDAD);
                mostrarEmpleados(lista, CANTIDAD);

                presionarContinuar();
                break;
            case 5:
                mostrarEmpleados(lista, CANTIDAD);

                presionarContinuar();
                break;
            case 6:
                seguir= 'n';
                break;
        }

    }while(seguir=='s');


    return 0;
}


