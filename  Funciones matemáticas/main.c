#include <stdio.h>
#include <stdlib.h>

void funcion_matematica();

int main()
{
    funcion_matematica();

    return 0;
}

void funcion_matematica()
{
    int numeroIngresadoA;
    int numeroIngresadoB;
    float numeroIngresado;
    float resultado=0;
    int resultado2=0;

    printf("Ingrese un numero: ");
    scanf("%f", &numeroIngresado);

    //resultado= ceil(numeroIngresado);//REDONDEA AL PROXIMO ENTERO MAS CERCANO
    //resultado= fabs(numeroIngresado);//DEVUELVE EL VALOR ABSOLUTO DEL NUMERO
    //resultado= floor(numeroIngresado);//REDONDEA PARA ABAJO
    resultado= sqrt(numeroIngresado);//DEVUELVE LA RAIZ CUADRADA DEL NUMERO

    printf("\nEl numero es: %.2f\n", resultado);

    printf("\nIngrese dos numeros: ");
    scanf("%d %d", &numeroIngresadoA, &numeroIngresadoB);

    //resultado2= fmod(numeroIngresadoA, numeroIngresadoB);//CALCULA EL RESTO DE LA DIVISION ENTRE DOS NUMEROS
    resultado2= pow(numeroIngresadoA, numeroIngresadoB);//CALCULA NUMERO A ELEVADO A LA POTENCIA NUMERO B

    printf("\nEl resultado de la operacion es: %d", resultado2);


}
