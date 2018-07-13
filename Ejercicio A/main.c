#include <stdio.h>
#include <stdlib.h>

int esPar(int numero);

int main()
{
    int i;
    int suma=0;
    int numeroIngresado;
    int numeroIngresadoB;
    int aux_par;
    int factorial=1;

    for(i=1; i<=10; i++)
    {
        if(i%2==00)
        {
            suma+=i;
        }
    }

    printf("La suma de los numeros pares del al 10 es: %d\n", suma);

    printf("\nIngrese un numero para hallar el factorial: ");
    scanf("%d", &numeroIngresado);

    for(i=1; i<=numeroIngresado; i++)
    {
        factorial= factorial*i; //factorial*=i
    }

    printf("\nEl factorial del numero ingresado es: %d", factorial);

    printf("\nIngrese un numero: ");
    scanf("%d", &numeroIngresadoB);

    aux_par= esPar(numeroIngresadoB);

    if(aux_par==0)
    {
        printf("El numero ingresado es par\n");
    }
    else
    {
        printf("El numero ingresado es impar\n");
    }

    return 0;
}

int esPar(int numero)
{
    int retorno= -1;

    if(numero%2==0)
    {
        retorno=0;
    }
    else
    {
        retorno=1;
    }

    return retorno;
}
