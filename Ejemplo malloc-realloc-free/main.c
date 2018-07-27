#include <stdio.h>
#include <stdlib.h>

#define TAM 3
int main()
{
    int *vector;
    int *vector_aux;
    int i;

    vector=(int *)malloc(sizeof(int)*TAM);

    vector[0]=10;
    vector[1]=20;
    vector[2]=30;

    for(i=0;i<TAM;i++)
    {
        printf("%d\n", vector[i]);
    }

    printf("\n\n");

    vector_aux= (int *)realloc(vector, sizeof(int)*(TAM*2));

    if(vector_aux!= NULL)
    {
        vector= vector_aux;

        vector[3]= 40;
        vector[4]= 50;
        vector[5]= 60;

        for(i=0;i<TAM*2;i++)
        {
            printf("%d\n", vector[i]);
        }
    }

    free(vector);

    return 0;
}
