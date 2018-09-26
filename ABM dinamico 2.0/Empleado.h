
/*
struct empleado
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
};
*/
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

void inicializarEmpleados(eEmpleado *listaEmpleados, int tam);
int buscarLibre(eEmpleado *listaEmpleados, int tam);

int buscarEmpleado(eEmpleado *listaEmpleados, int tam, int legajo);

void agregarEmpleado(eEmpleado *listaEmpleados, eSector listaSectores[], int tam);

void id_to_sector(int id, char sector[]);

void printEmpleado(eEmpleado unEmpleado);
void printEmpleadoPorReferencia(eEmpleado *unEmpleado);
void mostrarEmpleados(eEmpleado *listaEmpleados, int tam);

void eliminarEmpleado(eEmpleado *listaEmpleados, int tam);
void modificarEmpleado(eEmpleado *listaEmpleados, int tam);

void ordenarEmpleadosPorNombre(eEmpleado *listaEmpleados, int tam);
