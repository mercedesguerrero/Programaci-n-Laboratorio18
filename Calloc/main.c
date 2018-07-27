#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**< PUNTERO =  calloc(numero de elementos, tamaño de cada elemento);  */

int main()
{
    int* puntero;
    int* puntero2;
    char* p_palabra;
    char palabra[50];
    int i;

    /**< PARA 1 ELEMENTO */
    puntero= (int*)calloc(1, sizeof(int));

    /**< PARA 5 ELEMENTOS */
    puntero2= (int*)calloc(5, sizeof(int));

    *puntero=15;
    printf("%i\n", *puntero);

    for(i=0; i<5; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &puntero2[i]);
    }

    for(i=0; i<5; i++)
   {
       printf("\nNumero ingresado: %d", *(puntero2+i));//ARITMETICA DE PUNTEROS
   }

   /**< PARA UN ARRAY */

   printf("\n\nIngrese una palabra: ");
   fflush(stdin);
   gets(palabra);

   //palabra\0 -> palabra+1
   p_palabra= (char*)calloc(strlen(palabra)+1, sizeof(char));

   strcpy(p_palabra, palabra);

   printf("\nPalabra: %s", p_palabra);

   free(p_palabra);

    return 0;
}
