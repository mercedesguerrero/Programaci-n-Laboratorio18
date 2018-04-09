#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5];


    /* ACCEDER A UN ELEMENTO DEL VECTOR
    vector[2] = 20;
    printf("%d", vector[2]);

    PARA INICIALIZAR TODOS LOS ELEMNTOS DEL VECTOR EN 0:

    int vector[5]={0};

    PARA INICIALIZAR POR EXTENSION:

    int vector[5]={5,55,365,214,489};

    PARA MOSTRAR LA POSICION DE UN VALOR:

    for(int i=0; i<5; i++)
    {
        if(vector[i]==365)
        {
            printf ("\nPosicion: %d",i);
        }
    }

    */

    printf("Direccion de memoria de vector: %p", vector);

    for(int i=0; i<5; i++) //CUIDADO NO DESBORDAR EL VECTOR
    {
        printf("\n Ingrese un numero: ");
        scanf("%d", &vector[i]);
    }


    for(int i=0; i<5; i++)
    {
        printf("%d\n", &vector[i]);
    }


    return 0;
}
