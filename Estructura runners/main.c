#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct
{
    char nombre[20];
    int edad;
    char sexo[20];
    char club[20];
    char categoria[20];
}runner;

int main()
{
    runner runners[TAM];

    int i;

    for(i=0; i<TAM; i++)
    {
        system("cls");
        printf("\nIngrese nombre: ");
        gets(runners[i].nombre);
        printf("\nIngrese edad: ");
        scanf("%d", &runners[i].edad);
        fflush(stdin);
        printf("\nIngrese sexo: ");
        gets(runners[i].sexo);
        printf("\nIngrese club: ");
        gets(runners[i].club);
        printf("\n");

    }
    //ASIGNAR CATEGORIA
    for(i=0; i<TAM; i++)
    {
        if((runners[i].edad) <=18)
        {
            strcpy(runners[i].categoria, "Juvenil");
        }
        else if((runners[i].edad)>18 && (runners[i].edad)<=40)
        {
            strcpy(runners[i].categoria, "Adultos");
        }
        else
        {
            strcpy(runners[i].categoria, "Veterano");
        }
    }

    for(i=0; i<TAM; i++)
    {
        printf("Nombre: %s\n", runners[i].nombre);
        printf("Edad: %d\n", runners[i].edad);
        printf("Categoria: %s\n", runners[i].categoria);
        printf("Sexo: %s\n", runners[i].sexo);
        printf("Club: %s\n", runners[i].club);
        printf("\n");
    }

    return 0;
}
