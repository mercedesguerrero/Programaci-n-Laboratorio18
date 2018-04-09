#include <stdio.h>
#include <stdlib.h>



int main()
{
    int numero=5;
    int factor;

    factor = factorial(numero);


    printf("El factorial del numero ingresado es: %d\n", factor);


}

int factorial(int numero)
{

    int retorno;

    if(numero==0)
    {
        retorno= 1;
    }
    else
    {
        retorno= numero *factorial(numero -1);
    }

    return retorno;
}
