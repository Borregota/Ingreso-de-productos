#include <stdio.h>
#include "funcioneslol.h"

int main(int argc, char const *argv[])
{
    int a;
    char productoABus[30];
    int opcion1, opcion2;

    printf ("Ingrese la cantidad de productos que se van a ingresar: \n");
    scanf ("%d", &a);

    char Nproducto[a][30];
    float cantidadPrecio[a][2];
    do
    {
        printf("Seleccione una opcion: \n1. Ingresar Productos\n2. Imprimir productos\n3. Buscar Producto\n4. Editar Producto\n5. Eliminar Producto\n6. Ingresar otra cantidad\n>>");
        scanf("%d", &opcion1);
        switch (opcion1)
        {
        case 1:
            ingresarProductos(Nproducto,cantidadPrecio,a);
            break;
        case 2:
            imprimirProductos(Nproducto,cantidadPrecio,a);
            break;
        case 3:
        printf("Ingrese el nombre del producto a buscar: \n>>");
        fflush(stdin);
        scanf("%s", &productoABus);
        int index = buscarProductoXNom(Nproducto, productoABus, a);
        imprimirProductoXIndex(productoABus, Nproducto, cantidadPrecio, index);
            break;
        case 4:
        editarProducto(Nproducto, cantidadPrecio, a);
            break;
        case 5:
        eliminarProducto(Nproducto, cantidadPrecio, a);
        a--; // Disminuye el número de productos en uno
            break;
        case 6:
            printf("Ingrese la nueva cantidad de productos que se van a ingresar: \n");
            scanf ("%d", &a);
        default:
            break;
        }
        printf("Desea elegir una nueva opcion: 1.si / 2.No\n>>");
        scanf("%d",&opcion2);
    } while (opcion2 == 1);
    return 0;
}