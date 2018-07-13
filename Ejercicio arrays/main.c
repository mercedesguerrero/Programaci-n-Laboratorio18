#include <stdio.h>
#include <stdlib.h>

void copiaArrays(int a[], int b[], int tamanio);

int main()
{
    int array1[5]= {2,5,4,3,7};
    int array2[5];

    printf("Copiando arrays\n");

    copiaArrays(array1, array2, 5);

    return 0;
}

void copiaArrays(int a[], int b[], int tamanio)
{
    int i;

    for(i=0; i<tamanio; i++)
    {
        b[i]= a[i];//array2 = array1
    }

    for(i=0; i<tamanio; i++)
    {
        printf("%d", b[i]);
    }
}
