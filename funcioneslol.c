#include <stdio.h>
#include "funcioneslol.h"
#include <string.h>

void ingresarProductos(char NProducto[][30],
                       float cantidadPrecio[][2], 
                       int n){
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del producto %d: ", i+1);
        scanf("%s", &NProducto[i]);
        printf("Ingrese la cantidad del producto %d: ", i+1);
        scanf("%f", &cantidadPrecio[i][0]);
        printf("Ingrese el precio del producto %d: ", i+1);
        scanf("%f", &cantidadPrecio[i][1]);
    }   
}

void imprimirProductos(char NProducto[][30],
                       float cantidadPrecio[][2], 
                       int n){
    printf("N.producto\tCantidad\tPrecio\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%.2f\t\t%.2f\n", NProducto[i], cantidadPrecio[i][0], cantidadPrecio[i][1]);
    }
}

int buscarProductoXNom(char NProducto[][30],
                       char productoABus[], 
                       int n){
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(NProducto[i], productoABus)==0){
            index=i;
            break;
        }
    }
    return index;
}

void imprimirProductoXIndex(char productoABus[],
                            char Nproducto[][30],
                            float cantidadPrecio[][2],
                            int index){
    if (index!=-1)
    {
        printf("los datos del producto %s son: \n",Nproducto[index]);
        printf("Cantidad: %.2f\n", cantidadPrecio[index][0]);
        printf("Precio: %.2f\n", cantidadPrecio[index][1]);
    }else
    {
        printf("No se encontro el producto %s\n", productoABus);
    }
}

void editarProducto(char Nproducto[][30],
                    float cantidadPrecio[][2], 
                    int n){
    char productoABus[30];
    float nuevaCant, nuevoPrecio;
    printf("Ingrese el nombre del producto que desea editar: ");
    fflush(stdin);
    scanf("%s", productoABus);
    int index = buscarProductoXNom(Nproducto, productoABus, n);
    if (index!=-1)
    {
        printf("Ingrese la nueva cantidad: ");
        fflush(stdin);
        scanf("%f", &nuevaCant);
        printf("Ingrese el nuevo precio: ");
        fflush(stdin);
        scanf("%f", &nuevoPrecio);
        cantidadPrecio[index][0] = nuevaCant;
        cantidadPrecio[index][1] = nuevoPrecio;
    }else
    {
        printf("El producto ingresado no existe");
    }

}

void eliminarProducto(char Nproducto[][30], float cantidadPrecio[][2], int n) {
    char productoABus[30];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    fflush(stdin);
    scanf("%s", productoABus);
    int index = buscarProductoXNom(Nproducto, productoABus, n);
    if (index!= -1) {
        for (int i = index; i < n - 1; i++) {
            strcpy(Nproducto[i], Nproducto[i + 1]); // Copia el nombre del producto en la posición i+1 al nombre del producto en la posición i
            memcpy(&cantidadPrecio[i], &cantidadPrecio[i + 1], 2 * sizeof(float)); // Copia la cantidad y el precio del producto en la posición i+1 al producto en la posición i
        }
        (n)--; // Disminuye el número de productos en uno
    } else {
        printf("El producto ingresado no existe\n");
    }
}