#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int suma=0;

    printf("Ingrese dos numeros\n");
    scanf("%d %d", &num1, &num2);

    suma= num1+num2;
    printf("La suma es: %d", suma);

    return 0;
}
