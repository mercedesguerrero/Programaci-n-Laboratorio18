#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Propietario.h"

#define TAMPROPIETARIO 50
#define TAMAUTOS 20


int main()
{

    char seguir='s';
    int opcion=0;

    int id_temp;


    ePropietario listadoPropietarios[TAMPROPIETARIO];

    ePropietario_init(listadoPropietarios, TAMPROPIETARIO);

    inicializarPropietariosHardCode(listadoPropietarios);


    eAuto listadoAutos[TAMAUTOS];

    eAuto_init(listadoAutos, TAMAUTOS);

    inicializarAutosHardCode(listadoAutos);


    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                ePropietario_alta(listadoPropietarios, TAMPROPIETARIO);

                presionarContinuar();
                break;
            case 2://alta autos
                mostrarListadoPropietarios(listadoPropietarios, TAMPROPIETARIO);
                id_temp= pedirNumEntero("\nIngrese ID del propietario: ");

                if(ePropietario_buscarPorId(listadoPropietarios, TAMPROPIETARIO, id_temp) >=0)
                {
                    eAuto_alta(listadoAutos, TAMAUTOS, id_temp);
                }

                presionarContinuar();
                break;
            case 3:
                mostrarListadoPropietarios(listadoPropietarios, TAMPROPIETARIO);

                ePropietario_modificacion(listadoPropietarios, TAMPROPIETARIO, ePropietario_buscarPorId(listadoPropietarios, TAMPROPIETARIO, pedirNumEntero("\nIngrese ID a modificar: ")));

                presionarContinuar();
                break;
            case 4:
                mostrarListadoPropietarios(listadoPropietarios, TAMPROPIETARIO);

                ePropietario_baja(listadoPropietarios, TAMPROPIETARIO, ePropietario_buscarPorId(listadoPropietarios, TAMPROPIETARIO, pedirNumEntero("\nIngrese ID a dar de baja: ")));

                presionarContinuar();
                break;
            case 5:
                mostrarListadoPropietarios(listadoPropietarios, TAMPROPIETARIO);

                presionarContinuar();

                break;
            case 6:
                mostrarListadoAutos(listadoAutos, TAMAUTOS);

                presionarContinuar();
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    presionarContinuar();

    return 0;
}
