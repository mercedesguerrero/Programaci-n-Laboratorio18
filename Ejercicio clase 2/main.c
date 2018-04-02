#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

int main()
{
    int porcentajeAumento;
    float sueldo;
    char nombre;
    float aumentoDeSueldo;
    float sueldoConAumento;

    printf("Ingrese porcentaje de aumento de sueldo \n");
    scanf("%d", &porcentajeAumento);
    printf("\nIngrese nombre \n");
    nombre=getche();
    printf("\nIngrese sueldo \n");
    scanf("%f", &sueldo);

    aumentoDeSueldo = (porcentajeAumento * sueldo/ 100);

    sueldoConAumento = (sueldo + aumentoDeSueldo);

    printf("\nNombre: %c\nSueldo: %f\nAumento de Sueldo: %f\nSueldo con aumento: %f\nPorcentaje de aumento: %d%%\n", nombre, sueldo, aumentoDeSueldo, sueldoConAumento, porcentajeAumento);


    return 0;
}
