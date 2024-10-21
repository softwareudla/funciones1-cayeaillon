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
        // Llamada a la función para ingresar los datos
        numProductos = ingresarDatos(nombres, precios, cantidades, MAX_PRODUCTS);

        // Llamadas a las diferentes funciones
        printf("Precio total del inventario: %.2f\n", calcularPrecioTotal(precios, cantidades, numProductos));
        printf("Producto más caro: %s\n", productoMasCaro(nombres, precios, numProductos));
        printf("Producto más barato: %s\n", productoMasBarato(nombres, precios, numProductos));
        printf("Precio promedio de los productos: %.2f\n", calcularPromedio(precios, cantidades, numProductos));

        // Buscar un producto por nombre
        char nombreBuscado[30];
        printf("Ingresa el nombre del producto que deseas buscar: ");
        fgets(nombreBuscado, sizeof(nombreBuscado), stdin);  
        nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0'; 

        buscarProducto(nombres, precios, numProductos, nombreBuscado);

        // Preguntar si se quiere continuar
        printf("¿Deseas ejecutar el programa nuevamente? (s/n): ");
        scanf(" %c", &continuar); 
        getchar();  

    } while (continuar == 's' || continuar == 'S');
    return 0;
}
