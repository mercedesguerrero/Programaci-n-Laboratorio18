#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
float sumar(int numero1, int numero2); /*funciones*/

int main()
{
    int numero1;
    int numero2;
    char operacion;
    float resultado;

    printf("inggrese un numero para operar:");
    scanf("%d", &numero1);
    printf("ingrese la operacion que desea realizar:");
    scanf("%d", &numero2 );
    printf("ingrese siguiente numero para completar la operacion");
    operacion= getche();

    switch(operacion)
    {
    case '+':
        resultado= numero1 + numero2;

    case '/':
         resultado= numero1 /numero2;

    case '-':
       resultado= numero1 -numero2;

    case '*':
        resultado= numero1 *numero2;
        break;

    }

    printf("el resultado es = %.2f \n")


}
float sumar(int numero1, int numero2)
{
    float resultado;

resultado = numero1 + numero2




    return resultado;
}
