#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct empleado
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
};
*/

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;

}eEmpleado;

int printUnEmpleado(eEmpleado employee);

int main()
{
    //struct empleado unEmpleado;
    eEmpleado unEmpleado;
    eEmpleado otroEmpleado= {1245, "Analia", 'f', 12.45};
    eEmpleado cargarEmpleado;
    eEmpleado empleado4;

    empleado4= otroEmpleado;

    unEmpleado.legajo= 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo= 'm';
    unEmpleado.sueldo= 123.23;

    printf("Ingrese legajo: \n");
    scanf("%d", &cargarEmpleado.legajo);
    printf("Ingrese nombre: \n");
    fflush(stdin);
    gets(cargarEmpleado.nombre);
    printf("Ingrese sexo: \n");
    fflush(stdin);
    scanf("%c", &cargarEmpleado.sexo);
    printf("Ingrese sueldo: \n");
    scanf("%f", &cargarEmpleado.sueldo);

    printUnEmpleado(unEmpleado);
    printf("\n\n");
    printUnEmpleado(otroEmpleado);
    printf("\n\n");
    printUnEmpleado(cargarEmpleado);
    printf("\n\n");
    printUnEmpleado(empleado4);
    printf("\n\n");


    return 0;
}

int printUnEmpleado(eEmpleado employee)
{
    printf("Legajo: %d\nNombre: %s\nSexo: %c\nSueldo: %.2f\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);

    return 0;
}
