#include <stdio.h>
#include <stdlib.h>

void duplicarEntero(int *valor);

int main()
{
    int x=10;
    char letra= 'A';
    char letraAux;
    char nombre[10]= "JUAN";

    printf("En main la variable vale %d\n\n", x);
    duplicarEntero(&x);
    printf("En main ahora la variable vale %d\n\n", x);

    printf("Letra %c\n", letra);
    letraAux= tolower(letra);
    printf("Letra %c\n", letraAux);

    printf("Nombre: %s\n", nombre);
    strlwr(nombre);
    printf("Nombre %s\n", nombre);

    return 0;
}

void duplicarEntero(int *valor)
{
    *valor= *valor *2;
}
