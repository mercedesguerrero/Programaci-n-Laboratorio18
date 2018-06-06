#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char bufferIn[100];

    FILE *fp;

    fp = fopen("c:\\TEST\\Mercedes Guerrero\\fichero.txt", "r");



    while(!feof(fp)) //llegó al final del archivo?
    {
        fgets(bufferIn,100,fp);//lee una sola línea del archivo
        puts(bufferIn);
    }

    fclose(fp);

    /*
    FILE *fp;

    char buffer[100] = "Esto es un texto en el fichero\n";
    fp = fopen("c:\\TEST\\Mercedes Guerrero\\fichero.txt", "w");//Abre el fichero, devuelve un puntero a file

    fprintf(fp, "hola\n");//imprime sobre FILE
    fprintf(fp, buffer);
    fprintf(fp, "%s", "Esto es otro texto\n");

    */

    //remove("c:\\TEST\\Mercedes Guerrero\\fichero.txt"); PARA BORRAR EL FILE



    return 0;
}
