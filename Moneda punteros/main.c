#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAM_MONEDA 6

int main(int argc, char **argv)
{


    eMoneda lista[TAM_MONEDA]= {{"Argentina",1,"Peso"},{"Brasil",2,"Real"}, {"EEUU",3,"Dolar"}};


    //altaDeMoneda(lista, TAM_MONEDA);

    cargaFILE(lista, TAM_MONEDA);

    moneda_mostrarListado(lista, TAM_MONEDA);




    return 0;
}


