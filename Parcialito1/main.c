#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<limits.h>

int main()
{
    int numeroingresado;
    char respuesta;
    int numerospares;
    int numerosimpares;
    int contadorpares=0;
    int contadorimpares=0;
    float porcentajePares;
    float porcentajeImpares;



    while (respuesta!='n')
    {
    printf("\nIngrese un numero entero distinto de 0: \n");
    scanf("%d", &numeroingresado);

    /*
    if(numero1==0)
        {
        printf("Ingrese un numero entero distinto de 0: \n")
        }
    else
        {

        }

    */

        if(numeroingresado %2==0 && numeroingresado!=0)
        {
            numeroingresado == numerospares;
            contadorpares ++;
        }
        else
        {
            if (numeroingresado!=0)
            {
                numeroingresado == numerosimpares;
                contadorimpares ++;
            }


        }

    printf("\nDesea ingresar otro numero s/n? \n");
    respuesta = getche();

    }

    printf("\nLa cantidad de numeros pares es: %d \n", contadorpares);
    printf("\nLa cantidad de numeros impares es: %d \n", contadorimpares);


    return 0;
}
