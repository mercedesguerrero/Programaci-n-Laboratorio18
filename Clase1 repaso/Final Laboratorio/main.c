#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"
#include "Letra.h"

int main()
{
    char seguir='s';
    int opcion=0;

    ArrayList* letras= al_newArrayList();

    eLetra* pLetra;
    eLetra* aux;


    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                //ALTA
                parseCargaDeDatos(letras, "datos.csv");
                presionarContinuar();
                break;
            case 2:
                completa_vocal_o_consonante(letras, es_vocal_o_consonante(letras));
                presionarContinuar();
                break;
            case 3:

                presionarContinuar();
                break;
            case 4:
                //LISTAR

                presionarContinuar();
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');


    return 0;
}
