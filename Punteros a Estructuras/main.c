#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    int b;
}dato;

int main()
{
    dato datito = {1, 'c'};

    dato* p;

    p= &datito;

    printf("%d\n%c\n", p->a, p->b);

    //printf("%d\n%c\n", (*p).a, (*p).b); //OTRA MANERA par�ntesis prioriad de ejecuci�n
    //printf("%d\n", datito.b);
    //printf("%d", &datito);

    return 0;
}
