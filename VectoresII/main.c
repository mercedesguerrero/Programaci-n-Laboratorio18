#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define TAM 5

/**< BURBUJEO */

void mostrarVector(int[], int);
void cargarVector(int[], int);
void ordenarVector(int[], int);
int buscarMaximo(int[], int);


int main()
{
    int vector[TAM] ={1,3,4,2,9};
    int i;
    int j;
    int aux;
    int maximo;

    maximo= buscarMaximo(vector, TAM);
    printf("El valor maximo del vector es: %d\n", maximo);

    printf("Vector ordenado \n");
    mostrarVector(vector, 5);


    /*
    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);
    }

    for(i=0; i<5; i++)
    {
        printf("%d\n", &vector[i]);
    }

    mostrarVector(vector, 5);

    */

    return 0;
}

void mostrarVector(int vector[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d\n", vector[i]);
    }
}

void cargarVector(int vector[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d\n", &vector[i]);
    }
}

void ordenarVector(int vector[], int tam)
{
    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(vector[i]< vector[j]) //Criterio de ordenamiento
            {
                aux= vector[i];
                vector[i]= vector[j];
                vector[j]= aux;
            }
        }
    }
}

int buscarMaximo(int vector[], int tam)
{
    int i;
    int maximo;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(flag==0 || vector[tam]> maximo)
        {
            maximo= vector[i];
            flag= 1;
        }
    }

    return maximo;
}
