#include <stdio.h>
#include<conio.h>

int main()
{
    /*int (ENTERO) --- float (DECIMAL) --- char (CARACTER)*/


    int numero1;
    float numero2;
    char letra;

    printf("Ingrese un numero entero: \n");
    scanf("%d", &numero1);
    printf("Ingrese un numero flotante: \n");
    scanf("%f", &numero2);
    printf("Ingrese una letra: \n");
    /*fflush(stdin);
    scanf("%c", &letra);*/
    letra = getche();

    printf("\nEl numero entero es: %d y el numero flotante es: %.2f \n", numero1, numero2);
    printf("\nLa suma de los numeros es: %.2f \n", numero1 + numero2);
    printf("\nLa letra ingresada es: %c \n", letra);


    return 0;
}
