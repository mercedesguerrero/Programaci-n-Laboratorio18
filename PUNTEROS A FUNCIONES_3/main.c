#include <stdio.h>
#include <stdlib.h>

void saludar();
void despedir();

int main()
{
    void (*f[2])(void)={saludar, despedir};//puntero que guarda 2 funciones
    int i;

    for(i=0; i<2; i++)
    {
        f[i]();
    }

    return 0;
}

void saludar()
{
    printf("Holo\n");
}

void despedir()
{
    printf("\nChau\n");
}

