
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
     int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}

void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int idUsuario[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]={"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,105,100,103,104};

    //105 no existe!!!!!!!!!!!!!!!!!!!

    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=idUsuario[i];
        usuarios[i].idUsuario=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}



