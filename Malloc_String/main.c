#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre [20];
    char* p_nombre;
    int longitud;

    strcpy(nombre, "Mercedes");

    longitud= strlen(nombre);

    p_nombre= (char*)malloc((longitud+1)*sizeof(char));

    strcpy(p_nombre, nombre);

    printf("El nombre es: %s\n", p_nombre);

    free(p_nombre);

    printf("El nombre es: %s\n", p_nombre);

    return 0;
}
