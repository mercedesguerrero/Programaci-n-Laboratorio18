#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Propietario.h"


void mostrarMenu()
{
    system("cls");

    printf("\nESTACIONAMIENTO>>> Seleccione una opcion: \n");

    printf("\n1- Registrar Propietario \n");
    printf("\n2- Ingresar auto \n");
    printf("\n3- Modificar datos de propietario\n");
    printf("\n4- Dar de baja propietario\n");
    printf("\n5- Listar propietarios\n");
    printf("\n6- Listar autos\n");
    printf("\n7- Salir\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

/**< INICIALIZA ESTADO EN LIBRE Y ID DE USUARIO EN 0 */
int ePropietario_init (ePropietario propietarios[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && propietarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            propietarios[i].estado= LIBRE;
            propietarios[i].idPropietario= 0;
        }
    }
    return retorno;
}

/**< INICIALIZA ESTADO EN LIBRE Y ID DE AUTO EN 0 */
int eAuto_init (eAuto ListAutos[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && ListAutos != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            ListAutos[i].estado= LIBRE;
            ListAutos[i].idAuto= 0;
        }
    }
    return retorno;
}

/**< HARDCODEAR DATOS */
void inicializarPropietariosHardCode(ePropietario propietarios[])
{


    int idPropietario[4] = {1,2,3,4};
    char nombre[4][30]= {"Juan","Luis","Maria","Jose"};
    char direccion[4][30]= {"Mitre","Urquiza","Belgrano","Alsina"};
    char numTarjetaCred[4][20]= {"111-111","222-222","333-333","444-444"};

    int i;

    for(i=0; i<4; i++)
    {
        propietarios[i].idPropietario= idPropietario[i];
        propietarios[i].estado = OCUPADO;
        strcpy(propietarios[i].nombre, nombre[i]);
        strcpy(propietarios[i].direccion, direccion[i]);
        strcpy(propietarios[i].numTarjetaCred, numTarjetaCred[i]);

    }
}

/**< HARDCODEAR DATOS */
void inicializarAutosHardCode(eAuto ListAutos[])
{
    int idAuto[10]= {1,2,3,4,5,6,7,8,9,10};
    char patente[10][10]= {"A-AA","C-CC","D-DD","B-BB","Z-ZZ","I-II","H-HH","E-EE","F-FF","G-GG"};
    int marca[10]= {ALPHA_ROMEO,AUDI,AUDI,FERRARI,FERRARI,AUDI,AUDI,OTROS,AUDI,ALPHA_ROMEO};
    int propietario[10]= {2,1,2,1,3,3,4,1,4,3};

    int i;

    for(i=0; i<10; i++)
    {
        ListAutos[i].idAuto= idAuto[i];
        ListAutos[i].estado = OCUPADO;
        strcpy(ListAutos[i].patente, patente[i]);
        ListAutos[i].marca= marca[i];
        ListAutos[i].idPropietario= propietario[i];

    }
}

/**< BUSCA UN LUGAR LIBRE EN EL ARRAY */
int ePropietario_buscarLugarLibre(ePropietario propietarios[], int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(propietarios[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }

    if(retorno<0)
    {
        printf("No hay lugar libre\n");
    }

    return retorno;
}

/**< SIGUIENTE ID PROPIETARIO*/
int ePropietario_siguienteId(ePropietario propietarios[],int limite)
{
    int retorno = 0;

    if(limite > 0 && propietarios != NULL)
    {
        for(int i=0; i<limite; i++)
        {
            if(propietarios[i].estado==OCUPADO)
            {
                    if(propietarios[i].idPropietario > retorno)
                    {
                         retorno= propietarios[i].idPropietario;
                    }
            }
        }
    }
    return retorno+1;
}

/**< SIGUIENTE ID AUTO*/
int eAuto_siguienteId(eAuto ListAutos[],int limite)
{
    int retorno = 0;

    if(limite > 0 && ListAutos != NULL)
    {
        for(int i=0; i<limite; i++)
        {
            if(ListAutos[i].estado==OCUPADO)
            {
                    if(ListAutos[i].idAuto> retorno)
                    {
                         retorno= ListAutos[i].idAuto;
                    }
            }
        }
    }
    return retorno+1;
}

/**< PIDE UN STRING DE CARACTERES */
void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
}

/**< VALIDA TAMAÑO DE STRING */
void getValidString(char mensaje[], char error[], char input[], int limite)
{
    int j;
    char auxString[limite+200]; //por si se pasa

    getString(mensaje, input);

    j= strlen(input);

    while (j>= limite)
    {
        printf("Ha ingresado %d caracteres\n %s", j, error);
        getString(mensaje, input);

        j= strlen(input);

    }

    strcpy(auxString, input);
}

int pedirNumEntero(char mensaje[])
{
    int numeroEntero;

    printf("%s", mensaje);
    scanf("%d", &numeroEntero);

    return numeroEntero;
}

/**< BUSCA POR ID Y SI LO ENCUENTRA DEVUELVE EL ÍNDICE */
int ePropietario_buscarPorId(ePropietario propietarios[] ,int limite, int id)
{
    int retorno = -1;

    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        for(int i=0; i<limite; i++)
        {
            if(propietarios[i].estado == OCUPADO && propietarios[i].idPropietario == id)
            {
                printf("\nSe encontro el id %d", id);
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**< DA DE ALTA USUARIOS */
int ePropietario_alta(ePropietario propietarios[], int limite)
{
    int retorno = -1;
    char nombre[50];
    int idPropietario;
    char direccion[50];
    char tarjeta[50];
    int indice;

    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        indice = ePropietario_buscarLugarLibre(propietarios, limite);

        if(indice>= 0)//HAY LUGAR LIBRE EN EL VECTOR
        {
            getValidString("Ingrese nombre: \n", "Ha superado el maximo. ", nombre, 50);
            strcpy(propietarios[indice].nombre, nombre);
            idPropietario= ePropietario_siguienteId(propietarios, limite);
            propietarios[indice].idPropietario = idPropietario;
            getValidString("Ingrese direccion: \n", "Ha superado el maximo. ", direccion, 50);
            strcpy(propietarios[indice].direccion, direccion);
            getValidString("Ingrese numero de tarjeta: \n", "Ha superado el maximo. ", tarjeta, 50);
            strcpy(propietarios[indice].numTarjetaCred, tarjeta);
            propietarios[indice].estado = OCUPADO;
            retorno = 0;
        }
        else
        {
            printf("\n No hay lugar para cargar propietarios");
        }
    }
    return retorno;
}

/**< INGRESAR AUTO ALTA ESTACIONADOS*/
int eAuto_alta(eAuto ListAutos[], int limite, int idPropietario)
{
    int retorno = -1;
    int indice;
    int idPropietario;


    if(limite > 0 && ListAutos != NULL)
    {
        retorno = -2;
        indice = ePropietario_buscarLugarLibre(propietarios, limite);

        if(indice>= 0)//HAY LUGAR LIBRE EN EL VECTOR
        {
            getValidString("Ingrese patente: \n", "Ha superado el maximo. ", ListAutos[indice].patente, 10);
            ListAutos[indice].marca= get_marca();
            ListAutos[indice].idPropietario = idPropietario;
            ListAutos[indice].idAuto= eAuto_siguienteId(ListAutos, limite);
            ListAutos[indice].estado = OCUPADO;
            retorno = 0;
        }
        else
        {
            printf("\n No hay lugar para cargar autos");
        }
    }
    return retorno;
}

/**< CONSTANTE MARCA A CADENA DE CARACTERES */
void marca_a_cadena(int constanteMarca, char caracteresMarca[])
{
    switch(constanteMarca)
    {
        case ALPHA_ROMEO:
            strcpy(caracteresMarca,"ALPHA ROMEO");
            break;
        case FERRARI:
            strcpy(caracteresMarca,"FERRARI");
            break;
        case AUDI:
            strcpy(caracteresMarca, "AUDI");
            break;
        case OTROS:
            strcpy(caracteresMarca, "OTRA MARCA");
            break;
    }
}

int get_int_Rango(char mensaje[30],int desde,int hasta)
{
    int aux;
    int flag=0;
    do
    {
        if(flag==1)
        {
            printf("\n Valor fuera de Rango Debe ser: (%d< X <%d)  \n",desde-1,hasta+1);
            system("pause");
            system("cls");
        }
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%d",&aux);
        flag=1;
    }while( (aux<desde) || (aux>hasta) );

    return aux;
}

/**< CONSTANTE MARCA A CADENA DE CARACTERES */
int get_marca()
{
    int marca;

    printf("1. ALPHA_ROMEO\n");
    printf("2. FERRARI\n");
    printf("3. AUDI\n");
    printf("4. OTROS\n");

    marca= get_int_Rango("Seleccione una marca\n",1,4);

    return marca;
}

/**< MUESTRA UN USUARIO */
void mostrarUnPropietario(ePropietario propietario)
{
     printf("\n %s - %d - %s - %s - %d", propietario.nombre, propietario.idPropietario, propietario.direccion, propietario.numTarjetaCred, propietario.estado);
}

/**< LISTA CON BORRADOS */
int mostrarListadoPropietariosConBorrados(ePropietario propietarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(propietarios[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            mostrarUnPropietario(propietarios[i]);
        }
    }
    return retorno;
}

/**< MODIFICA TARJETA PROPIETARIO */
int ePropietario_modificacion(ePropietario propietarios[], int limite, int posId)
{
    int retorno= -2;
    char tarjeta[30];

    if(limite > 0 && propietarios != NULL)
    {
        retorno -1;

        if(posId>=0)
        {
            retorno= 0;
            getValidString("\nIngrese Tarjeta: ","\nNumero muy largo", tarjeta, 30);
            strcpy(propietarios[posId].numTarjetaCred, tarjeta);
            propietarios[posId].estado= OCUPADO;

            printf("\nSe modifico tarjeta");

        }
        else
        {
            retorno= -3;
            printf("\nNo se encontro el id ingresado");
        }
    }

    return retorno;

}

/**< BAJA DE USUARIOS */
int ePropietario_baja(ePropietario propietarios[], int limite, int posId)
{
    int retorno= -2;

    if(limite > 0 && propietarios != NULL)
    {
        retorno -1;

        if(posId>=0)
        {
            retorno= 0;
            propietarios[posId].idPropietario= 0;
            propietarios[posId].estado= LIBRE;

            printf("\nSe dio de baja el propietario");

        }
        else
        {
            retorno= -3;
            printf("\nNo se encontro el id ingresado");
        }
    }

    return retorno;
}

/**< MUESTRA LISTA DE USUARIOS */
int mostrarListadoPropietarios(ePropietario propietarios[], int limite)
{
    int retorno = -2;
    int i;

    printf("%s\t %s\t\t %s\t %s\n","\nID","Nombre", "Direccion", "Numero de tarjeta");


    if(limite > 0 && propietarios != NULL)
    {
        for(i=0; i<limite; i++)
        {
            retorno = -1;
            if(propietarios[i].estado==OCUPADO)
            {
                retorno= 0;
                printf("%d\t %s\t\t %s\t\t %s\n", propietarios[i].idPropietario, propietarios[i].nombre, propietarios[i].direccion, propietarios[i].numTarjetaCred);
            }
        }
    }
    return retorno;
}

/**< MUESTRA LISTA DE AUTOS */
int mostrarListadoAutos(eAuto ListAutos[], int limite)
{
    int retorno = -2;
    int i;

    printf("%s\t %s\t %s\t %s\n","\nID Auto","Patente", "Marca", "ID Propietario");


    if(limite > 0 && ListAutos != NULL)
    {
        for(i=0; i<limite; i++)
        {
            retorno = -1;
            if(ListAutos[i].estado==OCUPADO)
            {
                retorno= 0;
                printf("   %d\t   %s\t\t   %d\t\t %d\n", ListAutos[i].idAuto, ListAutos[i].patente, ListAutos[i].marca, ListAutos[i].idPropietario);
            }
        }
    }
    return retorno;
}

