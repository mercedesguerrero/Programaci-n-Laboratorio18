#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=5;
    int *p= &x;

    printf("x vale %d\n", *p);

    *p= 10;

    printf("x vale %d\n", x);


    return 0;
}
