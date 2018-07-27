#include <stdio.h>
#include <stdlib.h>

int cuenta_vocales(char *nombre);

int main()
{
    char nombreIngresado[20];

    printf("Ingrese un nombre: ");
    gets(nombreIngresado);

    printf("\nTiene %d vocales", cuenta_vocales(nombreIngresado));

    return 0;
}

int cuenta_vocales(char *nombre)
{
    int contador=0;

    while(*nombre)//mientras no sea nulo o sea (*nombre)!=' '
    {
        switch(*nombre)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': contador++;
        }
        nombre++;
    }

    return contador;
}
