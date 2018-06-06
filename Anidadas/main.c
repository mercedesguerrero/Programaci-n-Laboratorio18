#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char calle[50];
    int numero;
    int cp;


}eDomicilio direccion;

typedef struct
{
    int legajo;
    char nombre[50];
    eDomicilio direccion;

}eAlumno;

int main()
{
    eAlumno a;
    a.direccion.cp=1948;


    return 0;
}
