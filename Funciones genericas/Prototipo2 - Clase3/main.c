#include <stdio.h>
#include <stdlib.h>

/** \brief Pide al usuario 2 números enteros y los suma
 *
 * \param
 * \param
 * \return No retorna nada a main
 *
 */


void sumarNumeros(int, int);

int main()
{
    int numero1;
    int numero2;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

    printf("Ingrese un numero: ");
    scanf("%d", &numero2);

    sumarNumeros(numero1, numero2);

    return 0;
}

//desarrollo o implementación de la función

void sumarNumeros(int numero1, int numero2)
{
    int retorno;

    retorno = numero1 + numero2;

    printf("La suma es: %d", retorno);
}
