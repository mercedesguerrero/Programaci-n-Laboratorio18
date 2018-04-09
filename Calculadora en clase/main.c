#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Calculadora.h"

int main()
{
    float numeroA;
    float numeroB;
    char operacion;
    float resultado;

    printf("Ingrese un numero para operar: \n");
    scanf("%f", &numeroA);
    printf("Ingrese la operacion que desea realizar: \n");
    operacion= getche();
    printf("Ingrese siguiente numero para completar la operacion \n");
    scanf("%f", &numeroB);

    switch(operacion)
    {
    case '+':
        resultado= sumar(numeroA, numeroB);
        break;

    }


    printf("el resultado es = %.2f \n", resultado);

    return 0;
}
