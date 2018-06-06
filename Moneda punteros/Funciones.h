#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define OCUPADO 1
#define LIBRE 0
#define CANTIDAD 20


typedef struct
{
    char pais[10];
    int id;
    char nombre[10];
}eMoneda;

void mostrarMenu();
void presionarContinuar();

void altaDeMoneda(eMoneda*, int limite);

void cargaFILE(eMoneda*, int limite);

void bajaDeMoneda(eMoneda*, int limite);

void muestra_FILE(eMoneda*, int limite);

void moneda_mostrarListado(eMoneda*, int limite);



#endif // FUNCIONES_H_INCLUDED
