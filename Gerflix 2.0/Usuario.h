

typedef struct
{
    int idUsuario;
    char nombre[50];
    int serie;
    int estado;
}eUsuario;

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);

