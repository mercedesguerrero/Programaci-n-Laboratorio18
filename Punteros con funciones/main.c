#include <stdio.h>
#include <stdlib.h>


void cargarPuntero(int*, int);
void mostrarPuntero(int*, int);

int main()
{
    int vec[3];

    cargarPuntero(vec, 3);
    mostrarPuntero(vec, 3);

    return 0;
}

void cargarPuntero(int *elVector, int t)
{
    int i;

    for(i=0; i<t; i++)
    {
        printf("Ingrese valor a cargar");
        scanf("%d", elVector+i);
    }
}

void mostrarPuntero(int* elVector, int t)
{
    int i;

    for(i=0; i<t; i++)
    {
        printf("%d\n", *(elVector+i));
    }
}
