#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[3]; //={5,9,1};
    int i;
    int* pEntero= NULL;
    //int* otroPuntero;
    //int miEntero=7; //VARIABLE ASOCIADA DEL MISMO TIPO DE MANERA ESTÁTICA, SE LE PUEDE ASIGNAR UN VALOR ACÁ

    //pEntero= &miEntero; //SIEMPRE INICIALIZAR: ASIGNA UNA DIRECCIÓN DE MEMORIA

    //*pEntero= 5; //OTRA MANERA: ACCEDER AL VALOR AL QUE APUNTA

    //otroPuntero = pEntero;

    pEntero = vec; //APUNTA A LA DIRECCION DE MEMORIA DEL PRIMER ELEMENTO DEL VECTOR

    for(i=0; i<3; i++)
    {
        printf("Ingrese valor a cargar");
        scanf("%d", pEntero+i);//no se pone * porq quiere acceder a la pos de memoria
    }


    for(i=0; i<3; i++)
    {
        printf("%d\n", *(pEntero+i));//accede al valor
    }

    /*
    if(pEntero!=NULL)
    {
        printf("El valor es: %d\n", *pEntero);
    }
    */

    /**< SUMANDO O RESTANDO VALORES ME PUEDO IR MOVIENDO EN MEMORIA */
    /*
    printf("El valor es: %d\n", pEntero);
    printf("El valor es: %d\n", pEntero+0);
    printf("El valor es: %d\n", pEntero+1);
    printf("El valor es: %d\n", pEntero+2); //SE MUEVE 1 ENETERO, SE VA DESPLAZANDO EL SIZE OF DEL TIPO DE DATO

    pEntero = pEntero+1;

    printf("\nEl valor es: %d\n", pEntero);
    /*

    /*
    printf("El valor es: %d\n", *pEntero);
    printf("El valor es: %d\n", miEntero);
    printf("El valor es: %d\n", pEntero);
    printf("El valor es: %d\n", &miEntero);
    printf("El valor es: %d\n", &pEntero);
    //printf("El valor es: %d\n", otroPuntero);
    //printf("El valor es: %d\n", &otroPuntero);

    */

    return 0;
}
