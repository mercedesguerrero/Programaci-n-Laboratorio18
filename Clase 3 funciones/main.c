#include <stdio.h>
#include <stdlib.h>

//prototipo o declaración de la función
//int: tipo de dato devuelto (int, float, char, double, void) por la función
//sumarNumeros: Identificador de la función
//(int, int) representa los parámetros que recibe la función

/** \brief Permite sumar dos números enteros
 *
 * \param el primer número a sumar
 * \param el segundo número a sumar
 * \return la suma de los números
 *
 */


int sumarNumeros(int, int);

int main()
{
    int resultado;
    int numero1 = 5;
    int numero2 = 9;

    //llamada a la función

    resultado = sumarNumeros(numero1, numero2);

    printf("El resultado de la suma es: %d\n", resultado);
    return 0;
}

//desarrollo o implementación de la función

int sumarNumeros(int primerNumero, int segundoNumero)
{
    int retorno;

    retorno = primerNumero + segundoNumero;

    return retorno;
}


