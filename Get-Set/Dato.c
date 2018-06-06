#include <stdio.h>

#include "Dato.h"

eDato* new_eDato()
{
    eDato* retorno;

    retorno=(eDato*) malloc(sizeof(eDato));

    return retorno;
}

eDato* new_eDato_Parametros(int a, char* b)
{
    eDato* retorno;

    retorno= new_eDato(); //si consiguio espacio en memoria

    if (retorno!=NULL)
    {
        eDato_set_a(retorno, a);
        eDato_set_b(retorno, b);
    }

    return retorno;
}

int eDato_set_a(eDato* dato, int valor)
{
    int ret = 0;
    if(dato!=NULL && valor>1500)
    {
        dato->a = valor;
        ret = 1;
    }

    return ret;
}

int eDato_set_b(eDato* dato, char* valor)
{
    int ret = 0;
    if(dato!=NULL && valor!=NULL)
    {
        strcpy(dato->b , valor);
        ret = 1;
    }

    return ret;
}

int eDato_get_a(eDato* dato)
{
    int valor = -1;

    if(dato!=NULL)
    {
        valor = dato->a;
    }

    return valor;
}

char* eDato_get_b(eDato* dato)
{
    char* valor;
    if(dato!=NULL)
    {
       valor=dato->b;
    }

    return valor;
}
