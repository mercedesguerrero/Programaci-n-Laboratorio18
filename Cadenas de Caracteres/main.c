#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena[10];
    int len;

    printf("Ingrese una palabra: \n");
    gets(cadena);

    len= strlen(cadena);

    //puts(cadena); MUESTRA LA CADENA
    printf("La palabra ingresada es: %s\n y tiene %d caracteres\n", cadena, len);


    return 0;
}
