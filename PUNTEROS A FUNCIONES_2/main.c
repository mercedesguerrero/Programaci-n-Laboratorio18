#include <stdio.h>
#include <stdlib.h>

int saludar(char*);
int despedir(char*);

void funcionDelegado(int (*F1)(char*), char*);

int main()
{

    funcionDelegado(saludar, "Mercedes");
    funcionDelegado(despedir, "Cecilia");

    /*
    int(*F1)(char*); //F1= puntero a la funcion
    int algo;

    F1=saludar;



    F1= despedir;

    printf("Retorno %d", algo);
    */

    return 0;
}

int saludar(char* txt)
{
    printf("Holo %s\n", txt);
    return 0;
}

int despedir(char* txt)
{
    printf("\nChau %s\n", txt);
    return 5;
}

void funcionDelegado(int (*F1)(char*), char* nombre)
{
    int algo;

    algo= F1(nombre);

    printf("Retorno %d\n", algo);

}
