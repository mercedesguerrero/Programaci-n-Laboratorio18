#include <stdio.h>
#include <stdlib.h>

/**< UNA FUNCI�N RECURSIVA ES UNA FUNCI�N QUE SE LLAMA A S� MISMA */

long factorial(int n);

int main()
{
    int numero;

    printf("Ingrese un numero para calcular factorial: \n");
    scanf("%d", &numero);

    printf("\nEl factorial es: %ld", factorial(numero));

    return 0;
}

long factorial(int n)
{
    int retorno= -1;

    if(n<=1)
    {
        retorno= 1;
    }
    else
    {
        retorno= (n*factorial(n-1));
    }

    return retorno;
}
