#include <stdio.h>
#include <stdlib.h>

void pedirString(char mensaje[], char input[], int limite);
void getString(char mensaje[], char input[]);
void getValidString(char mensaje[], char error[], char input[], int limite);

int main()
{
    char confirma[3];
    char nombreIngresado[6];
    /*
    pedirString("\nConfirma esta accion? (S/N): ", confirma, 3);
    if(stricmp(confirma, "S") != 0 && stricmp(confirma, "N") != 0)
    {
        printf("Debe ingresar S o N. Por favor reingrese\n");
    }
    else
    {
        printf("\nAccion confirmada");
    }
    */
    getValidString("Ingrese nombre\n", "Nombre muy largo\n", nombreIngresado, 6);
    printf("Nombre ingresado: %s\n", nombreIngresado);

    return 0;
}

void pedirString(char mensaje[], char input[], int limite)
{
    printf("%s", mensaje);
    gets(input);
}

/**< PIDE UN STRING DE CARACTERES */
void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    gets(input);
}

/**< VALIDA TAMAÑO DE STRING */
void getValidString(char mensaje[], char error[], char input[], int limite)
{
    int j;
    char auxString[limite+50]; //por si se pasa

    do
    {
        fflush(stdin);
        getString(mensaje, input);
        j= strlen(input);

        if(j>= limite)
        {
            printf("Ha ingresado %d caracteres\n %s", j, error);
        }
        else
        {
            strcpy(auxString, input);
        }
    }while(j>= limite);

}
