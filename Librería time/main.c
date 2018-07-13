#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Función aleatoria
 *
 * srand(time(NULL));
 * variable= limite_inferior + rand()%((limite_superior +1) - limite_inferior);
 */

void funcion_aleatoria();

int main()
{
    funcion_aleatoria();

    return 0;
}

void funcion_aleatoria()
{
    int numero;

    srand(time(NULL));
    numero= 1 + rand() % ((10+1) -1);

    printf("%d", numero);
}
