#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

}eEmpleado;

int printUnEmpleado(eEmpleado employee);


int main()
{
    eEmpleado unEmpleado;
    eEmpleado cargarEmpleado;
    eEmpleado otroEmpleado= {1245, "Analia", 'f', 12.45, {11, 4, 2001}};
    //eFecha unaFecha;

    unEmpleado.legajo= 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo= 'm';
    unEmpleado.sueldo= 123.23;
    unEmpleado.fechaIngreso.dia= 6;
    unEmpleado.fechaIngreso.mes= 11;
    unEmpleado.fechaIngreso.anio= 1988;

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
    printf("Ingrese dia: \n");
    scanf("%d", &cargarEmpleado.fechaIngreso.dia);
    printf("Ingrese mes: \n");
    scanf("%d", &cargarEmpleado.fechaIngreso.mes);
    printf("Ingrese anio: \n");
    scanf("%d", &cargarEmpleado.fechaIngreso.anio);

    //cargarEmpleado.fechaIngreso= unaFecha;

    system("cls");
    printf("\n\n");
    printUnEmpleado(otroEmpleado);
    printf("\n\n");
    printUnEmpleado(unEmpleado);
    printf("\n\n");
    printUnEmpleado(cargarEmpleado);
    printf("\n\n");

    return 0;
}

int printUnEmpleado(eEmpleado employee)
{
    printf("Legajo: %d\nNombre: %s\nSexo: %c\nSueldo: %.2f\nFecha de ingreso: %02d/%02d/%02d\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo, employee.fechaIngreso.dia, employee.fechaIngreso.mes, employee.fechaIngreso.anio);

    return 0;
}
