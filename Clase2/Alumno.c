#include <stdio.h>
#include <string.h>
#include "Alumno.h"

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

sAlumno pedirAlumno()
{
    sAlumno alumnito;

    system("cls");
    printf("Ingrese legajo: ");
    scanf("%d", &alumnito.legajo);
    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets(alumnito.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &alumnito.promedio);
    printf("Ingrese edad: ");
    scanf("%d", &alumnito.edad);

    return alumnito;
}

void mostrarUnAlumno(sAlumno miAlumno)
{
    printf("%d--%s--%.2f--%d\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio, miAlumno.edad);
}

void cargarListadoDeAlumnos(sAlumno listado[], int tam)
{
    int i;
     for(i=0; i<tam; i++)
    {
       listado[i]= pedirAlumno();
    }
}

void mostrarListadoDeAlumnos(sAlumno listado[], int tam)
{
    int i;

     for(i=0; i<tam; i++)
    {
        mostrarUnAlumno(listado[i]);
    }
}

void ordenarListadoDeAlumnosPorNombre(sAlumno listado[], int tam)
{
    sAlumno auxAlumno;
    int i;
    int j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
        }
    }
}

sOpcion RetornarOpcion(sOpcion listadoOpciones[], int cantidad)
{
    int i;
    int opcion;
    sOpcion opcionStruct;

    mostrarListadoOpciones(listadoOpciones, cantidad);

    printf("\n\n\t Ingrese su opcion: ");
    scanf("%d", &opcion);

    opcionStruct.numero= opcion;
    strcpy(opcionStruct.texto, listadoOpciones[opcion-1].texto);

    return opcionStruct;
}

sOpcion AltaOpcion()
{
    sOpcion retornoOpcion;

    printf("\nIngrese el numero de opcion: ");
    scanf("%d", &retornoOpcion.numero);
    printf("Ingrese el texto: ");
    fflush(stdin);
    gets(retornoOpcion.texto);
    retornoOpcion.isEmpty= 1;

    return retornoOpcion;
}

void mostrarOpcion(sOpcion opcionParametro)
{
    printf("\t%d-\t %s\n", opcionParametro.numero, opcionParametro.texto);
}

void mostrarListadoOpciones(sOpcion listado[], int cantidad)
{
    for(int i=0; i<cantidad; i++)
    {
        if(listado[i].isEmpty == 1)
        {
            mostrarOpcion(listado[i]);
        }
    }
}

void mostrarMenu(sMenu unMenu)
{
    printf("\n\t\t%s\n\n", unMenu.titulo);
    mostrarListadoOpciones(unMenu.listadoDeOpciones, 5);
}

sMenu inicializarMenu(sMenu unMenu)
{
    for(int i=0; i<5; i++)
    {
        unMenu.listadoDeOpciones[i].isEmpty=0;
    }

    return unMenu;
}

int buscarLugarLibre(sMenu unMenu)
{
    int posicionLibre= -1;

    for(int i=0; i<5; i++)
    {
        if(unMenu.listadoDeOpciones[i].isEmpty == 0)
        {
            posicionLibre= i;
            break;
        }
    }

    if(posicionLibre<0)
    {
        printf("\nNo hay mas lugar para cargar opciones");
    }

    return posicionLibre;
}

sMenu cargaDeMenu(sMenu unMenu)
{
    int index;
    char respuesta;

    printf("\nIngrese un titulo para el menu: ");
    gets(unMenu.titulo);

    do
    {
        index= buscarLugarLibre(unMenu);
        unMenu.listadoDeOpciones[index]= AltaOpcion();

        printf("\nDesea ingresar otra opcion para el menu? s/n");
        fflush(stdin);
        respuesta= getchar();

    }while(respuesta== 's');

    return unMenu;
}

sMenu eliminaUnaOpcion(sMenu unMenu)
{
    int numero;

    printf("\nQue numero desea eliminar? ");
    scanf("%d", &numero);

    for(int i=0; i<5; i++)
    {
        if(unMenu.listadoDeOpciones[i].numero == numero)
        {
            unMenu.listadoDeOpciones[i].isEmpty= 0;
        }
    }

    return unMenu;
}
