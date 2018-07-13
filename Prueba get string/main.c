#include <stdio.h>
#include <stdlib.h>

void getString(char mensaje[], char input[]);
void getValidString(char mensaje[], char error[], int limite);

int main()
{
    char confirma[3];

    pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
    if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
    {
        printf("Debe ingresar S o N. Por favor reingrese\n");
    }
    else
    {
        printf("\nAccion confirmada");
    }

    return 0;
}

void pedirString(char mensaje[], char input[], int limite)
{
    printf("%s", mensaje);
    gets(input);
}
