#ifndef LETRA_H_INCLUDED
#define LETRA_H_INCLUDED
#include "Letra.h"
#include "ArrayList.h"


typedef struct{

    char letra;
    char nombre[21];
    int vocal;
    int consonante;

}eLetra;

void mostrarMenu();
void pressContinue();

int getInt();

eLetra* newLetras();

int parseCargaDeDatos(ArrayList* lista, char filename[]);
void parseGuardarDatos(ArrayList* lista, char filename[]);

int letras_setLetra(eLetra* l, char* letra);
int letras_setNombre(eLetra* l, char* nombre);
int letras_setVocal(eLetra* l,int* vocal);
int letras_setConsonante(eLetra* l,int* consonante);

char letras_getLetra(void* bloque);

int es_Vocal(char letra);
int completa_vocal_o_consonante(ArrayList* lista, int(*pFunc)(void*));
int es_vocal_o_consonante(eLetra* Letra);

int muestraUno(eLetra* bloque);


#endif // LETRA_H_INCLUDED
