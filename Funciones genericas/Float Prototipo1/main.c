#include <stdio.h>
#include <stdlib.h>

/** \brief Pide al usuario un float y lo valida
 *
 * \param El texto del mensaje a mostrar
 * \param El valor minimo del intervalo de validación
 * \param El valor máximo del intervalo de validación
 * \return Un número float validado
 *
 */

float pedirPrecio(char[], float, float);

float validarNumero(float, float, float);

int main()
{
    float precioA;
    float precioB;

    precioA = pedirPrecio("Ingrese precio\n", 1, 1000);
    precioB = pedirPrecio("Ingrese precio con aumento \n", 1, 1500);

    printf("El precio es: %.2f\n", precioA);
    printf("El precio con aumento es: %.2f\n", precioB);
    return 0;
}


float pedirPrecio(char mensaje[], float min, float max)
{
    float numero;

    printf("%s", mensaje);
    scanf("%f", &numero);

    numero = validarNumero(numero, min, max);

    return numero;

}

float validarNumero(float dato, float min, float max)
{
    while(dato < min || dato >max)
    {
        printf("Error: Ingrese entre %.2f y %.2f", min, max);
        scanf("%f", &dato);
    }
    return dato;
}
