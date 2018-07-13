#include <stdio.h>
#include <stdlib.h>

void ordenar(int vec[], int tamanio);

int main()
{
    int vec[10]={7,2,5,4,3,6,1,10,9,8};
    int i=0;
    int flag=0;
    int elemento_a_buscar;


    printf("Ingrese el numero a buscar ");
    scanf("%d", &elemento_a_buscar);

    while((flag==0) && (i<10))
    {
        if(vec[i]==elemento_a_buscar)
        {
            flag=1;
            printf("\nSe encontro el numero en la posicion %d\n", i);
        }
        i++;
    }

    if(flag==0)
    {
        printf("\nNo se encontro\n");
    }

    return 0;
}
