#include <stdio.h>
#include <stdlib.h>
/*
OTRA MANERA:
for(int i= numeroIngresado; i>=1; i--)
{
    factorial = factorial * i;
}

*/

int main()
{
    int numeroIngresado;
    int i;
    int factorial = 1;

    printf("Ingrese un numero: \n");
    scanf("%d", &numeroIngresado);


    for (i=1; i<=numeroIngresado; i++)
    {
        factorial= i*factorial;
    }

    printf("El factorial del número ingresado es: %d\n", factorial);

    return 0;
}
