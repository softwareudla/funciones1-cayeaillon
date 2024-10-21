#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTS 10

int main() {
    char nombres[MAX_PRODUCTS][30];
    float precios[MAX_PRODUCTS];
    int numProductos;
    char continuar;

    do {
        numProductos = ingresarDatos(nombres, precios, MAX_PRODUCTS);

        printf("Precio total del inventario: %.2f\n", calcularPrecioTotal(precios, numProductos));
        printf("Producto mas caro: %s\n", productoMasCaro(nombres, precios, numProductos));
        printf("Producto mas barato: %s\n", productoMasBarato(nombres, precios, numProductos));
        printf("Precio promedio de los productos: %.2f\n", calcularPromedio(precios, numProductos));

        char nombreBuscado[30];
        printf("Ingresa el nombre del producto que deseas buscar: ");
        getchar();  
        fgets(nombreBuscado, sizeof(nombreBuscado), stdin);
        nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

        buscarProducto(nombres, precios, numProductos, nombreBuscado);
  printf("Deseas ejecutar el programa nuevamente (s/n): ");
        scanf(" %c", &continuar);
        getchar();  
    } while (continuar == 's' || continuar == 'S');
    return 0;
}