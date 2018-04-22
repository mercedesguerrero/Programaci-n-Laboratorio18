#include <stdio.h>
#include <stdlib.h>

void func (char* p, char q)
{
    *p= 'D';
    q= 'C';
}

int main()
{
    char letra1='A';
    char letra2='B';

    func(&letra1, letra2);

    printf("Letra 1: %c\nLetra 2: %c", letra1, letra2);
    return 0;
}
