#include <stdio.h>
#include <stdlib.h>

/** \brief Pide al usuario 2 números enteros y los suma
 *
 * \param
 * \param
 * \return La suma de los números
 *
 */


int sumarNumeros(void);

int main()
{
    int retorno;

    retorno = sumarNumeros();
    printf("La suma es: %d", retorno);

    return 0;
}

int sumarNumeros(void)
{
    int retorno;
    int numero1;
    int numero2;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

    printf("Ingrese un numero: ");
    scanf("%d", &numero2);

    retorno = numero1 + numero2;

    return retorno;

}
