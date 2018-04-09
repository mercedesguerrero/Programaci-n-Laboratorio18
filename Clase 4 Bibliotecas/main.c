#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Pide al usuario un número entero y lo valida
 *
 * \param El texto del mensaje a mostrar
 * \param El valor minimo del intervalo de validación
 * \param El valor máximo del intervalo de validación
 * \return Un número entero validado
 *
 */


int main()
{
    int edad;
    int legajo;

    edad = pedirEntero("Ingrese edad\n", 1, 60);
    legajo = pedirEntero("Ingrese numero de legajo \n", 1, 1500);

    printf("La edad es: %d\n", edad);
    printf("El legajo es: %d\n", legajo);
    return 0;
}

