#include <stdio.h>
#include <stdlib.h>

//prototipo o declaraci�n de la funci�n
//int: tipo de dato devuelto (int, float, char, double, void) por la funci�n
//sumarNumeros: Identificador de la funci�n
//(int, int) representa los par�metros que recibe la funci�n

/** \brief Permite sumar dos n�meros enteros
 *
 * \param el primer n�mero a sumar
 * \param el segundo n�mero a sumar
 * \return la suma de los n�meros
 *
 */


int sumarNumeros(int, int);

int main()
{
    int resultado;
    int numero1 = 5;
    int numero2 = 9;

    //llamada a la funci�n

    resultado = sumarNumeros(numero1, numero2);

    printf("El resultado de la suma es: %d\n", resultado);
    return 0;
}

//desarrollo o implementaci�n de la funci�n

int sumarNumeros(int primerNumero, int segundoNumero)
{
    int retorno;

    retorno = primerNumero + segundoNumero;

    return retorno;
}


