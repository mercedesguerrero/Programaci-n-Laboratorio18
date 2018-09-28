#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Arraylist.h"
#include "Funciones.h"

#define CANTIDAD 40
#define CANT_SECTORES 5

int main()
{
    char seguir='s';
    int opcion=0;

    eSector listaSector[CANT_SECTORES];
    hardcodearSectores(listaSector, CANT_SECTORES);
    ArrayList* listaEmpleados= al_newArrayList();

    eEmpleado* unEmpleado= newEmpleadoParametrizado(1111, "Mercedes", 'f', 1235, 1, 5);


    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                //ALTA
                //parseCargaDeDatos(letras, "datos.csv");
                presionarContinuar();
                break;
            case 2:

                presionarContinuar();
                break;
            case 3:

                presionarContinuar();
                break;
            case 4:
                //LISTAR

                presionarContinuar();
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');


    return 0;
}
