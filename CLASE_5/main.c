#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"



int main()
{
    int edad[CANT_EMPLEADOS];
    float salario[CANT_EMPLEADOS];

   obtenerDatos ( edad, salario);
   mostrarDatos(edad, salario);

            return 0;
}
