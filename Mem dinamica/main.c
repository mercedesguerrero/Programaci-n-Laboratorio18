#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int* puntero;
    int* otroPuntero;
    int* aux;
    int i;

    puntero= (int*)malloc(sizeof(int)*TAM);//apunta al primer bit... multiplico por la cantidad de elementos que quiero quet tenga el vector

    for(i=0; i<TAM; i++)
    {
        *(puntero+i)= i+1;
    }

    otroPuntero= (int*)malloc(sizeof(int)*TAM);

    printf("\nMuestro los 5 elementos iniciales\n");
    for(i=0; i<TAM; i++)
    {
        printf("%d\n", *(puntero+i));
    }

    printf("\nDir de memoria del puntero: %d", puntero);
    printf("\nDir de memoria del otro puntero: %d", otroPuntero);

    aux= (int*)realloc(puntero, sizeof(int)*(TAM*2));

    if(aux!=NULL)
    {
        puntero= aux;

        for(i=TAM; i<TAM*2; i++)
        {
            *(puntero+i)= i+1;
        }
        printf("\nMuestro los 10 elementos desp de pedir mas memoria\n");
        for(i=0; i<TAM*2; i++)
        {
            printf("%d\n", *(puntero+i));
        }
    }

    puntero= (int*)realloc(puntero, sizeof(int)*3);
    printf("\nMuestro los 10 elementos\n");
        for(i=0; i<TAM*2; i++)
        {
            printf("%d\n", *(puntero+i));
        }

    printf("\nDir de memoria del puntero: %d", puntero);
    printf("\nDir de memoria del otro puntero: %d", otroPuntero);


    return 0;
}
