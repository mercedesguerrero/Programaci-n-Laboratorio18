#include <stdio.h>
#include <stdlib.h>
#define TAM 4

typedef struct
{
    char direccion[20];
    int telefono;

}datos;

typedef struct
{
    char nombre[20];
    datos datos_empleado;
    float sueldo;

}empleado;

int main()
{
    empleado empleados[TAM];
    int i;

    for(i=0; i<TAM; i++)
    {
        system("cls");
        fflush(stdin);
        printf("Ingrese nombre: ");
        gets(empleados[i].nombre);
        printf("\nIngrese sueldo: ");
        scanf("%f", &empleados[i].sueldo);
        fflush(stdin);
        printf("\nIngrese direccion: ");
        gets(empleados[i].datos_empleado.direccion);
        printf("\nIngrese telefono: ");
        scanf("%d", &empleados[i].datos_empleado.telefono);
    }

    return 0;
}
