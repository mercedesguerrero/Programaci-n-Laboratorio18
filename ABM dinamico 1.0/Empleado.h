
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
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int isEmpty;
    int idSector;

}eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

int menu();
void presionarContinuar();

int printUnEmpleado(eEmpleado employee);

void inicializarEmpleados(eEmpleado *listaEmpleados, int tam);
int buscarLibre(eEmpleado *listaEmpleados, int tam);

int buscarEmpleado(eEmpleado *listaEmpleados, int tam, int legajo);

void printEmpleado(eEmpleado unEmpleado);
void printEmpleadoPorReferencia(eEmpleado *unEmpleado);
void mostrarEmpleados(eEmpleado *listaEmpleados, int tam);

void eliminarEmpleado(eEmpleado *listaEmpleados, int tam);
void modificarEmpleado(eEmpleado *listaEmpleados, int tam);
