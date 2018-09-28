typedef struct
{
    int id;
    char descripcion[20];

}eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int isEmpty;
    int idSector;

}eEmpleado;


int menu();
void presionarContinuar();

int getInt(char* mensaje);

eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParametrizado(int legajo, char* nombre, char sexo, float sueldo, int isEmpty, int idSector);

void inicializarEmpleados(eEmpleado *listaEmpleados, int tam);
void hardcodearEmpleados(eEmpleado *listaEmpleados);
void hardcodearSectores(eSector *listaSectores, int tamSector);

int buscarEmpleado(ArrayList *listaEmpleados, int legajo);

void agregarEmpleado(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);

void listar_x_sector(eEmpleado *listaEmpleados, eSector *listaSectores, int tam, int tamSector);

void id_to_sector(int id, char sector[]);

void printEmpleado(eEmpleado unEmpleado, eSector listaSectores[], int tamSector);
void printEmpleadoPorReferencia(eEmpleado *unEmpleado, eSector listaSectores[], int tamSector);
void mostrarEmpleados(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector);

void eliminarEmpleado(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector);
void modificarEmpleado(eEmpleado *listaEmpleados, int tam, eSector listaSectores[], int tamSector);

void ordenarEmpleadosPorNombre(eEmpleado *listaEmpleados, int tam);

void parsearEmpleados(char* path, eEmpleado* listaEmpleados, int tam);

