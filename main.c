#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTS][30];
    float precios[MAX_PRODUCTS];
    int cantidades[MAX_PRODUCTS];
    int numProductos;

    do {
        numProductos = ingresarDatos(nombres, precios, cantidades, MAX_PRODUCTS);

        printf("Precio total del inventario: %.2f\n", calcularPrecioTotal(precios, cantidades, numProductos));
        printf("Producto mas caro: %s\n", nombres[productoMasCaro(precios, numProductos)]);
        printf("Producto mas barato: %s\n", nombres[productoMasBarato(precios, numProductos)]);
        printf("Promedio de precios: %.2f\n", calcularPromedio(precios, cantidades, numProductos));

        char nombreBuscado[30];
        printf("Ingresa el nombre del producto a buscar: ");
        getchar();  
        fgets(nombreBuscado, sizeof(nombreBuscado), stdin);
        nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';
        buscarProducto(nombres, precios, numProductos, nombreBuscado);

    } while (deseaContinuar());  

    printf("Gracias por usar el programa de gestión de inventario.\n");

    return 0;
}
