
typedef struct
{
    int idSerie;
    char nombre[50];
    char genero[50];
    int cantidadTemporadas;
    int estado;
}eSerie;

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);
void mostrarListadoDeSeries(eSerie[], int);


