#include <stdio.h>
#include <stdlib.h>
#define TAM 30

/**< ARRIBA DEL MAIN Y DE LOS PROTOTIPOS SE DECLARA LA ESTRUCT O AL .h */

typedef struct
    {
        /**< CAMPOS O ATRIBUTOS DE LA ESTRUCTURA: */
        int codigo;
        char descripcion[TAM];
        int stock;
        float precioCosto;

    }eProducto; //alias de la estructura: e de estructura

eProducto crearProducto();
void mostrarProducto(eProducto producto);

int main()
{
        eProducto unProducto;
        unProducto.codigo=3;
        strcpy(unProducto.descripcion, "Panuelitos de hojaldre\n");
        unProducto.precioCosto=25.39;
        unProducto.stock=10;

        eProducto dosProducto;
        dosProducto= unProducto;

        /**< CARGA SECUENCIAL */
        eProducto inventario[10];

        eProducto producto;

        crearProducto();

        int i;

        for(i=0; i<10; i++)
        {
            //scanf("%d", &inventario[i].codigo); //dirección de memoria de un producto en particular
            inventario[i]= crearProducto();
        }


        mostrarProducto(producto); //llamo la func

        printf("Producto\nCodigo: %d\nDescripcion: %sCantidad en stock: %d\nPrecio de costo: %.2f\n", unProducto.codigo, unProducto.descripcion, unProducto.stock, unProducto.precioCosto);
        printf("\nProducto\nCodigo: %d\nDescripcion: %sCantidad en stock: %d\nPrecio de costo: %.2f\n", dosProducto.codigo, dosProducto.descripcion, dosProducto.stock, dosProducto.precioCosto);

      return 0;
}

void mostrarProducto(eProducto producto)
{
        printf("\n Codigo: %d\nDescripcion: %s", producto.codigo, producto.descripcion);
        printf("Inventario: %s\n", inventario);
}

eProducto crearProducto()
{
        eProducto producto;

        printf("Ingrese codigo: ");
        fflush(stdin);
        scanf("%d", &producto.codigo);
        printf("\nIngrese descripcion: ");
        gets(producto.descripcion);

    return producto;
}
