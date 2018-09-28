#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Arraylist.h"
#include "Letra.h"


void mostrarMenu()
{
    system("cls");

    printf("\nLETRAS>>> Seleccione una opcion: \n\n");

    printf("1- ALTAS\n");
    printf("2- COMPLETAR\n");
    printf("3- COMPROBAR\n");
    printf("4- LISTAR\n");
    printf("5- SALIR\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}

eLetra* newLetras()//CONSTRUCTOR
{
    eLetra* returnAux = NULL;

    eLetra* p_Letra = (eLetra*)malloc(sizeof(eLetra));

    if(p_Letra!=NULL)
    {
       returnAux = p_Letra;
    }

    return returnAux;
}

int parseCargaDeDatos(ArrayList* lista, char filename[])
{
    FILE* fp;
    eLetra* l;
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
    int retorno=-1;

    fp = fopen(filename,"r");

    if(fp!=NULL && lista!=NULL)
    {
        fscanf(fp,"%[^,],%[^,],%[^,],%[^\n]\n", nombre, nombre, nombre, nombre);

        do
        {
            l= newLetras();
            fscanf(fp,"%c,%[^,],%d,%d\n", &letra, nombre, &vocal, &consonante);
            printf("%c--%s--%d--%d\n", letra, nombre, vocal, consonante);
            letras_setLetra(l, &letra);
            letras_setNombre(l, nombre);
            letras_setVocal(l, &vocal);
            letras_setConsonante(l, &consonante);

            lista->add(lista,l);
        }
        while(!feof(fp));
        printf("\n");
        retorno=0;
    }
    else
    {
        printf("Error\n");
    }
    fclose(fp);

    return retorno;
}
/*
void parseGuardarDatos(ArrayList* lista, char filename[])
{
    eAlumno* s;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                s=(eAlumno*) lista->get(lista,i);
                fprintf(fp,"%d,%d,%d,%d,%s,%s\n",emp_getId(s),emp_getEstado(s),emp_getLegajo(s),emp_getEdad(s),emp_getSexo(s),emp_getNombre(s));
            }
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo generar un archivo.");
    }
            fclose(fp);

}
*/
int letras_setLetra(eLetra* l, char* letra)
{
    if(l!=NULL)
    {
        l->letra= *letra;
    }
    return 0;
}

int letras_setNombre(eLetra* l, char* nombre)
{
    if(l!=NULL)
    {
        strcpy(l->nombre, nombre);
    }
    return 0;
}

int letras_setVocal(eLetra* l,int* vocal)
{
    if(l!=NULL)
    {
        l->vocal= *vocal;
    }
    return 0;
}

int letras_setConsonante(eLetra* l,int* consonante)
{
    if(l!=NULL)
    {
        l->consonante= *consonante;
    }
    return 0;
}

char letras_getLetra(void* Letra)
{
    eLetra* aux;

    aux= (eLetra*) Letra;

    return aux->letra;
}

int es_Vocal(char letra)
{// -1 si hay error, 0 consonante 1 vocal
    int retorno=-1;

    if(isalpha(letra))
    {
        retorno=0;
        letra=((char)tolower(letra));

        if(letra=='a' || letra=='e' || letra=='i' || letra=='o' || letra=='u')
        {
            retorno=1;
        }
    }
    return retorno;
}
/*
int es_vocal_o_consonante(eLetra* Letra)
{
    int retorno=-1;

    if(Letra!=NULL)
    {
        //  si es vocal (1) o consonante (0), devuelve (-1) si hay error
        if(es_Vocal(letras_getLetra(Letra))==1)
        {
            retorno= letras_setVocal(Letra, 1);
        }

        if(es_Vocal(letras_getLetra(Letra))==0)
        {
            retorno= letras_setConsonante(Letra, 1);
        }
    }

    return retorno;
}
*/
int completa_vocal_o_consonante(ArrayList* lista)
{
    int i;
    int retorno=-1;

    eLetra* l;

    if(lista!=NULL )
    {
        retorno=0;

        if(lista->isEmpty(lista)==0)
        {//No esta vacio
            for(i=0; i<lista->len(lista); i++)
            {
                l=al_get(lista, i);

                if(l)
            }
        }//if(lista->isEmpty(lista)==0)

    }//if(lista!=NULL && Titulo!=NULL)

/*
    for(i=0; i<lista->len(lista); i++)
    {
        printf("%c--%s--%d--%d\n", (lista->letra)+i, (lista->nombre+i), (lista->vocal+i), (lista->consonante+i));
    }
*/
    return retorno;
}

int muestraUno(eLetra* bloque)
{
    int retorno=-1;

    if(bloque!=NULL)
    {
        retorno=0;
        printf("Letra: %c \t", bloque->letra);
        printf("Nombre: %s\t\t", bloque->nombre);
        printf("vocal: %d\t", bloque->vocal);
        printf("consonante: %d\n", bloque->consonante);
    }

    return retorno;
}

