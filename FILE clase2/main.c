#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* miArchivo;
    int numero = 64; //guarda 8 bits el valos ascii

    miArchivo= fopen("prueba1.txt", "w"); //wb write binary w= write

    fwrite(&numero, sizeof(int),1, miArchivo);// una manera

    //fread(&numero, sizeof(int),1, miArchivo);

    fclose(miArchivo);

    printf("Numero: %d", numero);

    return 0;
}
