#include <stdio.h>
#include <stdlib.h>

/** \brief Pide al usuario 2 números enteros y los suma
 *
 * \param
 * \param
 * \return No recibe nada ni retorna nada a main
 *
 */


void sumarNumeros();

int main()
{
    sumarNumeros();

    return 0;
}

void sumarNumeros(void)
{
    int retorno;
    int numero1;
    int numero2;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

    printf("Ingrese un numero: ");
    scanf("%d", &numero2);


    retorno = numero1 + numero2;

    printf("La suma es: %d", retorno);
}
