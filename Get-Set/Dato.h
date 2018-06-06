typedef struct
{
    int a;
    char b[50];
}eDato;

eDato* new_eDato();//CREA UN NUEVO DATO
eDato* new_eDato_Parametros(int, char*);

int eDato_set_a(eDato*, int);
int eDato_set_b(eDato*, char*);

int eDato_get_a(eDato*);
char* eDato_get_b(eDato*);

