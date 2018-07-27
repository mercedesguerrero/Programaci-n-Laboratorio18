#include <stdio.h>
#include <stdlib.h>

void mostrarMenu();
void presionarContinuar();
int crear_archivo(char archivo[]);
int agregar_datos(char archivo[]);

struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char email[40];
}datos;

int main()
{
    char seguir='s';
    int opcion=0;
    char archivo[]= "Agenda de correos";

    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(crear_archivo(archivo)==0)
                {
                    printf("\nSe creo el archivo con exito\n");
                }
                presionarContinuar();
                break;
            case 2:
                if(agregar_datos(archivo)==0)
                {
                    printf("\nSe agregaron datos\n");
                }
                else
                {
                    printf("\nNo se agregaron datos");
                }
                presionarContinuar();
                break;
            case 3:

                presionarContinuar();
                break;
            case 4:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    return 0;
}

void mostrarMenu()
{
    system("cls");

    printf("\nAGENDA DE CORREO>>> Seleccione una opcion: \n\n");

    printf("1- Crear archivo\n");
    printf("2- Agregar datos\n");
    printf("3- \n");
    printf("4- Salir\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

int crear_archivo(char archivo[])
{
    FILE* fp;

    int retorno=0;

    fp= fopen(archivo, "a+");

    if(fp== NULL)
    {
        printf("Error al intentar abrir el archivo\n");
        retorno=-1;
    }

    printf(">>>AGENDA DE CORREOS>>>\n");
    fprintf(fp, ">>>AGENDA DE CORREOS>>>\n");

    fclose(fp);

    return retorno;
}

int agregar_datos(char archivo[])
{
    FILE* fp;

    char respuesta;
    int retorno=-1;

    fp= fopen(archivo, "a+");

    do{
        system("cls");

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(datos.nombre);
        printf("\nIngrese apellido: ");
        gets(datos.apellido);
        printf("\nIngrese email: ");
        gets(datos.email);

        fprintf(fp, "\n\nNombre: ");
        fwrite(datos.nombre, 1, strlen(datos.nombre), fp);
        fprintf(fp, "\n\nApellido: ");
        fwrite(datos.apellido, 1, strlen(datos.apellido), fp);
        fprintf(fp, "\n\nemail: ");
        fwrite(datos.email, 1, strlen(datos.email), fp);

        printf("\nDesea agregar mas contactos? s/n ");
        scanf("%c", &respuesta);

        retorno=0;

    }while(respuesta=='s');

    fclose(fp);

    return retorno;
}
