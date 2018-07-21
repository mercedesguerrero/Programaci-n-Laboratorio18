#include <stdio.h>
#include <stdlib.h>

void pedirString(char mensaje[], char input[], int limite);
void getString(char mensaje[], char input[]);
int getValidString(char mensaje[], char error[], char input[], int limite);
int esSoloLetras(char str[]);

int main()
{
    char confirma[3];
    char nombreIngresado[50];
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

    if((getValidString("\nIngrese nombre: ", "Puede ingresar hasta 6 letras \n", nombreIngresado, 6))>0)
    {
        printf("\nNombre ingresado: %s\n", nombreIngresado);
    }

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

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   int retorno=1;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           retorno=0;
       i++;
   }
   return retorno;
}

/**< VALIDA TAMAÑO DE STRING */
int getValidString(char mensaje[], char error[], char input[], int limite)
{
    int j;
    char auxString[limite+100]; //por si se pasa
    int retorno=0;

    do
    {
        fflush(stdin);
        getString(mensaje, input);
        j= strlen(input);

        if(j>= limite || esSoloLetras(input)==0)
        {
            printf("%s", error);
        }
        else
        {
            strcpy(auxString, input);
            retorno=1;
        }
    }while(j>= limite || esSoloLetras(input)==0);

    return retorno;
}
