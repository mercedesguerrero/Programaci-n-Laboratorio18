#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<limits.h>

int main()
{
    int numeroingresado;
    char respuesta;
    int contadorpares=0;
    int contadorimpares=0;
    float contadorPositivos=0;
    float contadorNegativos=0;
    int contadorIngresados=0;
    int max = INT_MIN;
    int min = INT_MAX;
    int maxPar = INT_MIN;


    while (respuesta!='n')
    {
    contadorIngresados++;
    printf("\nIngrese un numero entero distinto de 0: \n");
    scanf("%d", &numeroingresado);


        if(numeroingresado>0 && numeroingresado!=0)
        {
            contadorPositivos ++;
        }

        if (numeroingresado<0 && numeroingresado!=0)
        {
            contadorNegativos ++;
        }


        if(numeroingresado %2==0 && numeroingresado!=0)
        {
            contadorpares ++;

            maxPar= numeroingresado;

            if(maxPar> max)
            {
                max = maxPar;
            }
        }

        if(numeroingresado> max)
        {
            max= numeroingresado;
        }
        if(numeroingresado< min)
        {
            min= numeroingresado;
        }

        else
        {
            if (numeroingresado!=0)
            {
                contadorimpares ++;
            }
        }


    printf("\nDesea ingresar otro numero s/n? \n");
    respuesta = getche();

    }

    printf("\nLa cantidad de numeros pares es: %d \n", contadorpares);
    printf("\nEl maximo numero par ingresado es: %d \n", maxPar);
    printf("\nLa cantidad de numeros impares es: %d \n", contadorimpares);
    printf("\nEl porcentaje de numeros positivos es: %.2f%c \n", (contadorPositivos*100)/contadorIngresados, 37);
    printf("\nEl porcentaje de numeros negativos es: %.2f%c \n", (contadorNegativos*100)/contadorIngresados, 37);
    printf("\nEl maximo valor ingresado es: %d \n", max);
    printf("\nEl minimo valor ingresado es: %d \n", min);


    return 0;
}
