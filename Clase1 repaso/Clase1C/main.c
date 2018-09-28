#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[]= {32,45,18,23,9};

    printf("%d\n", *numeros);
    printf("%d\n", numeros[3]);
    printf("%d\n", *(numeros+3));


    return 0;
}
