#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTS][30];
    float precios[MAX_PRODUCTS];
    int cantidades[MAX_PRODUCTS];
    int numProductos;
    char continuar;

    do {
        
        numProductos = ingresarDatos(nombres, precios, cantidades, MAX_PRODUCTS);

       
        printf("Precio total del inventario: %.2f\n", calcularPrecioTotal(precios, cantidades, numProductos));
        
        int indiceMasCaro = productoMasCaro(precios, numProductos);
        printf("Producto mas caro: %s\n", nombres[indiceMasCaro]);
        
        int indiceMasBarato = productoMasBarato(precios, numProductos);
        printf("Producto mas barato: %s\n", nombres[indiceMasBarato]);
        
        printf("Precio promedio de los productos (por unidad): %.2f\n", calcularPromedio(precios, cantidades, numProductos));

        char nombreBuscado[30];
        printf("Ingresa el nombre del producto que deseas buscar: ");
        fgets(nombreBuscado, sizeof(nombreBuscado), stdin);
        nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

        buscarProducto(nombres, precios, numProductos, nombreBuscado);

        printf("¿Deseas ejecutar el programa nuevamente? (s/n): ");
        scanf(" %c", &continuar);
        getchar();  

    } while (continuar == 's' || continuar == 'S');
    
    return 0;
}
