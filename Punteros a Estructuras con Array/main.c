#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    int b;
}dato;

int main()
{
    dato lista[2] = {{1, 'c'}, {2, 'a'}};

    dato* p;

    p= lista;

    int i;

    for(i=0; i<2; i++)
    {
        //printf("%d\n%c\n", (*(p+i)).a, (*(p+i)).b); //OTRA MANERA
        printf("%d\n%c\n", (p+i)->a, (p+i)->b);

    }

    return 0;
}
