#include <stdio.h>
#include <stdlib.h>

void saludar(void);

int main()
{
    void(*F1)(void); //F1= puntero a la funcion

    F1=saludar;

    F1(); //LLAMA A LA FUNCION A TRAVÉS DE F1

    return 0;
}

void saludar()
{
    printf("Holo a todos!\n");
}
