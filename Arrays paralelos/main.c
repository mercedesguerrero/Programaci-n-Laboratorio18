#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarAlumnos(int[], char[][50], int[],  int[], float[], int);
int buscarLibre(int[], int[]);

int main()
{

    int legajos[TAM]={};
    int nota1[TAM];//={5,9,3,4,7};
    int nota2[TAM];//={2,9,7,8,2};
    float promedios[TAM];//={3.5,9,5,6,4.5};
    char nombres[TAM][50];//={"Juan", "Maria", "Ana", "Carlos", "Beatriz"};
    int i;
    int j;
    int auxInt;
    float auxfloat;
    char auxstring;
    int index;
    int respuesta;
    int encontro= 0;

    do
    {
        printf("1.Altas\n2.Bajas\n3.Modificacion\n4.Mostrar\n5.Ordenar\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                index= buscarLibre(legajos, TAM);
                if(index==-1)
                {
                    printf("Capacidad agotada!");
                }
                break;
            case 2:
                for(i=0; i<TAM; i++)
                {
                    printf("Ingrese numero de legajo: \n");
                    scanf("%d", &legajos[i]);
                    printf("Ingrese su nombre: ");
                    fflush(stdin);
                    gets(nombres[i]);

                    printf("Ingrese nota 1: \n");
                    scanf("%d", &nota1[index]);
                    printf("Ingrese nota 2: \n");
                    scanf("%d", &nota2[index]);

                    promedios[index]= (float)(nota1[i]+ nota2[i])/2;
                }
                break;
            case 3:
                mostrarAlumnos(legajos, nombres, nota1, nota2, promedios, cant);
                printf("Ingrese el legajo que desea modificar: ");
                scanf("%d", &auxInt);
                for(I=0; i<auxInt; i++)
                {
                    if(auxInt==legajos[i])//encuentro el alumno
                    {
                        //mostrar el alumno

                        printf("Reingrese valor de nota 1: ");
                        scanf("%d" &auxInt);
                        printf("Está seguro de realizar la modificacion? ");
                        respuesta= getche();
                        if(respuesta=='s')
                        {
                            nota1[i]= auxInt;
                            promedios[index]= (float)(nota1[i]+ nota2[i])/2;
                        }
                        else
                        {
                            printf("Accion cancelada por el usuario ")
                        }
                        encontro=1;
                    }


                }
                if(encontro==0)
                    {
                        printf("Legajo no encontrado ");
                    }
                break;

            case 4:
                break;

            case 5:
                break;
        }

    system(pause);
    system(cls);

    }while(opcion =! 5);

    /*
    for(i=0; i<TAM; i++)
    {
        printf("Ingrese numero de legajo: \n");
        scanf("%d", &legajos[i]);
        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese nota 1: \n");
        scanf("%d", &nota1[index]);
        printf("Ingrese nota 2: \n");
        scanf("%d", &nota2[index]);

        promedios[index]= (float)(nota1[i]+ nota2[i])/2;

    }
    */


    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {

            if(strcmp(nombres[i], nombres[j])>0)
            {

            }
            if(promedios[i]< promedios[j]) //Criterio de ordenamiento
            {
                auxfloat= promedios[i];
                promedios[i]= promedios[j];
                promedios[j]= auxfloat;

                /**< AHÍ ORDENÓ SÓLO EL PROMEDIO */
                //SWAP PARA LEGAJO
                //SWAP PARA EL NOMBRE
                //SWAP NOTA 1
                //SWAP NOTA 2

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxfloat = promedios[i];
                nota2[i] = nota2[j];
                nota2[j] = auxfloat;

                strcpy(auxstring, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxstring);
            }
        }
    }


    return 0;
}

void mostrarAlumnos(int legajos[], char nombres[][50], int nota1[],  int nota2[], float promedios[], int cant)
{
    int i;
    int legajos;
    char nombres;
    int nota1;
    int nota2;
    float promedios;
    int cant;


    for(i=0; i<cant; i++)
    {
        if(legajos[i] =! 0)
        {
            printf("%5d %10s %3d %3d %5.2f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedios[i]);
        }
    }

}

int buscarLibre(int legajos[], int cant)
{
    int i;
    int index=-1;

    for(i=0; i<cant; i++)
    {
        if[legajos[i]==0)
        {
            index =i;
            break;
        }
    }
    return index;
}


