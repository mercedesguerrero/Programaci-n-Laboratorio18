#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu()
{
    system("cls");

    printf("\nMONEDA>>> Seleccione una opcion: \n\n");

    printf("1- ALTA \n");
    printf("2- OPCION2\n");
    printf("3- OPCION3\n");
    printf("4- OPCION4\n");
    printf("5- Salir\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

void altaDeMoneda(eMoneda *lista, int limite)
{
    if(limite>0 && lista!= NULL)
    {
        for(int i=0; i<limite; i++)
        {
            if(i> 2)
            {
                printf("Ingrese país: \n");
                gets((lista+i)->pais);
                fflush(stdin);
                printf("Ingrese id: \n");
                scanf("%d", &((lista+i)->id));
                fflush(stdin);
                printf("Ingrese moneda: \n");
                gets((lista+i)->nombre);

            }
        }

    }
}

void cargaFILE(eMoneda *lista, int limite)
{
    FILE *fp;

    fp = fopen("c:\\TEST\\Mercedes Guerrero\\fichero_moneda.txt", "w");

    fprintf(fp, "Euro\n");
    fprintf(fp, "Libra\n");
    fprintf(fp, "Rublo\n");
    fprintf(fp, "Soles\n");

    fclose(fp);

}

void moneda_mostrarListado(eMoneda *lista, int limite)
{
    //verificar que no sea null y listado y lim>0

    if(limite>0 && lista!= NULL)
    {
        for(int i=0; i<limite; i++)
        {
            printf("%s--%d--%s\n", (lista+i)->pais, (lista+i)->id, (lista+i)->nombre);
        }
    }
}

void bajaDeMoneda(eMoneda *lista, int limite)
{
    //moneda_mostrarListado(*lista, limite);

    //printf("Ingrese id que desea dar de baja\n");
    //scanf("%d", &((lista+i)->id));


}
