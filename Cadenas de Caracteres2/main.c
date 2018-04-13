#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena[10]="hola";
    char cadena2[150]="chau";
    //int len;
    //int comp;


    //printf("Ingrese una palabra: \n");
    //gets(cadena);

    /**< PASAR EL CONTENIDO DE UNA CADENA A OTRA, EL DESTINO TIENE QUE SER DEL MISMO TAMAÑO QUE EL ORIGEN O MAYOR */

    //cadena=cadena2 NO SE PUEDE
    //strcpy(cadena2, cadena);

    /**< PARA COMPARAR DOS CADENAS */

    //comp = strcmp(cadena, cadena2);

    //printf("Resultado de la comparacion: %d\n", comp);

    //len= strlen(cadena);

    /**< PARA CONCATENAR */

    //strcat(cadena2, cadena);

    /**< PARA PASAR TODO A MAYÚSCULA O A MINÚSCULA */

    strupr(cadena);
    strlwr(cadena2);

    puts(cadena);
    puts(cadena2);
    //printf("La palabra ingresada es: %s\n y tiene %d caracteres\n", cadena, len);


    return 0;
}
