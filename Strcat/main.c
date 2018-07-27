#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* p_nombre;
    char* p_nombre_completo;

    p_nombre= (char*)malloc(sizeof(char)*10);

    strcpy(p_nombre, "Mercedes");
    printf("Nombre: %s\n", p_nombre);

    p_nombre_completo= (char*)realloc(p_nombre, (sizeof(char)*30));

    strcat(p_nombre_completo, " Guerrero");

    printf("Nombre completo: %s\n", p_nombre_completo);


    free(p_nombre_completo);

    return 0;
}
