#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vectorA[5] = {10,5,-1,11,4};
    int vectorB[5] = {9,3,9,12,6};
    int C[5];
    int i;

    /*
    for(i=0; i<5; i++)
    {
        if(vectorA[i]> vectorB[i])
        {
            C[i]=vectorA[i];
        }
        else
        {
            C[i]=vectorB[i];
        }
    }

    for(i=0; i<5; i++)
    {
        printf("El valor mas alto es: %d\n", C[i]);
    }

    */

    for (i=0; i<5; i++)
    {
        if(vectorA[i]%2==0 && vectorB[i]%2==0)
        {
            //los dos son pares
            if(vectorA[i] > vectorB[i])
            {
                C[i]=vectorA[i];
            }
            else
            {
                C[i]=vectorB[i];
            }
        }
        else
        {
            if(vectorA[i]%2==0)
            {
                C[i]=vectorA[i];
            }
            else
            {
                C[i]=vectorB[i];
            }
        }
    }

    for(i=0; i<5; i++)
    {
        printf("\nPosicion: %d", i);

    }
    return 0;
}
