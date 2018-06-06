#ifndef ESTRUCTURAPROPIETARIO_H_INCLUDED
#define ESTRUCTURAPROPIETARIO_H_INCLUDED

#define OCUPADO 1
#define LIBRE 0

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

typedef struct
{
    int idPropietario;
    char nombre[50];
    char direccion[50];
    char numTarjetaCred[30];
    int estado;
}ePropietario;

typedef struct
{
    char patente[10];
    int marca;
	int idAuto;
    int idPropietario;
    int estado;
}eAuto;

int ePropietario_init(ePropietario[],int limite);
void inicializarPropietariosHardCode(ePropietario[]);

int eAuto_init(eAuto[], int limite);
void inicializarAutosHardCode(eAuto[]);

int ePropietario_buscarPorId(ePropietario[] ,int limite, int id);
int ePropietario_siguienteId(ePropietario[], int limite);
int ePropietario_buscarLugarLibre(ePropietario[],int limite);

int eAuto_siguienteId(eAuto[], int limite);

void getString(char mensaje[], char input[]);

/** \brief VALIDA QUE UN STRING DE CARACTERES NO SE EXCEDA DEL L�MITE
 *
 * \param mensaje a ser mostrado
 * \param mensaje de error
 * \param input Array donde se cargar� el texto ingresado
 * \param limite de caracteres
 */
void getValidString(char mensaje[], char error[], char input[], int limite);

int pedirNumEntero(char mensaje[]);

void marca_a_cadena(int constanteMarca, char caracteresMarca[]);
int get_int_Rango(char mensaje[],int desde,int hasta);
int get_marca();

void mostrarUnPropietario(ePropietario propietario);
int mostrarListadoPropietarios(ePropietario[], int limite);
int mostrarListadoPropietariosConBorrados(ePropietario[] ,int limite);

int mostrarListadoAutos(eAuto[], int limite);

int eAuto_alta(eAuto[], int limite, int idPropietario);

int ePropietario_alta(ePropietario[], int limite);
int ePropietario_modificacion(ePropietario[] ,int limite, int posId);
int ePropietario_baja(ePropietario[], int limite, int posId);

int ePropietario_ordenar(ePropietario[] ,int limite, int orden);

void mostrarMenu();
void presionarContinuar();


#endif // ESTRUCTURAPROPIETARIO_H_INCLUDED
