#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
    char cadena[50]= {"Hola"};

    pArchivo= fopen("c:\\TEST\\Mercedes Guerrero\\fichero.txt", "w"); //ACA ES DONDE LE DIGO COMO LO VA A LEER O ESCRIBIR


    if(pArchivo!= NULL)
    {
        fprintf(pArchivo,"%s %d", cadena, 156);
        fclose(pArchivo);
    }


    return 0;
}
