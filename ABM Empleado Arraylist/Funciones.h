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


void hardcodearSectores(eSector *listaSectores, int tamSector);

void parsearEmpleados(char* path, ArrayList* listaEmpleados);
void guardarEmpleados(char* path, ArrayList* listaEmpleados);

int buscarEmpleado(ArrayList* listaEmpleados, int legajo);

void agregarEmpleado(ArrayList* listaEmpleados, eSector* listaSectores, int tamSector);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);

void listar_x_sector(ArrayList *listaEmpleados, eSector *listaSectores, int tamSector);

void id_to_sector(int id, char sector[]);

void printEmpleadoPorReferencia(eEmpleado* unEmpleado, eSector listaSectores[], int tamSector);
void mostrarEmpleados(ArrayList* listaEmpleados, eSector listaSectores[], int tamSector);

void eliminarEmpleado(ArrayList *listaEmpleados, eSector* listaSectores, int tamSector);
void modificarEmpleado(ArrayList* listaEmpleados, eSector listaSectores[], int tamSector);

int compararEmpleadosSueldo(void* x, void* y);
int compararEmpleadosNombre(void* x, void* y);
int compararEmpleadosLegajo(void* x, void* y);
int compararEmpleadosGenero(void* x, void* y);

void filtrarEmpleadosSistemas(ArrayList* listaEmpleados, eSector* sectores, int tamSector, ArrayList* lista2);

