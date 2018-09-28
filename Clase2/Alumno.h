
typedef struct
{
    int numero;
    char texto[30];
    int isEmpty;
}sOpcion;

typedef struct
{
    char titulo[15];
    sOpcion listadoDeOpciones[5];
}sMenu;

typedef struct
{
    float promedio;
    int legajo;
    char nombre[35];
    int edad;

} sAlumno;

/** \brief
 *
 * \param sAlumno
 * \return void
 *
 */
void mostrarUnAlumno(sAlumno);
sAlumno pedirAlumno();

sOpcion RetornarOpcion(sOpcion listadoOpciones[], int cantidad);

void cargarListadoDeAlumnos(sAlumno[], int);
void mostrarListadoDeAlumnos(sAlumno[], int);
void ordenarListadoDeAlumnosPorNombre(sAlumno[], int);

void presionarContinuar();

sOpcion AltaOpcion();
void mostrarOpcion(sOpcion opcionParametro);
void mostrarListadoOpciones(sOpcion listado[], int cantidad);

void mostrarMenu(sMenu unMenu);
sMenu inicializarMenu(sMenu unMenu);
sMenu cargaDeMenu(sMenu unMenu);
sMenu eliminaUnaOpcion(sMenu unMenu);
