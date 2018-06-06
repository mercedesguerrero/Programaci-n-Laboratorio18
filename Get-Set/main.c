#include <stdio.h>
#include <stdlib.h>

#include "Dato.h"


int main()
{
    eDato* d=NULL;
    eDato* e;

    d= new_eDato();

    e= new_eDato_Parametros(15000, "Luis");


    if(d!=NULL)
    {
        eDato_set_a(d,1600);
        eDato_set_b(d,"Pedro");

        printf("%d--%s", eDato_get_a(d), eDato_get_b(d));
    }

    //eDato_set_a(d,1800);

    if(e!=NULL)
    {
        printf("\n%d--%s", eDato_get_a(e), eDato_get_b(e));
    }


    return 0;
}
