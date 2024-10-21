#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int ingresarDatos(char nombres[MAX_PRODUCTS][30], float precios[MAX_PRODUCTS], int cantidades[MAX_PRODUCTS], int maxProductos) {
    int numProductos;
    printf("Cuantos productos deseas ingresar (maximo %d) ", maxProductos);
    scanf("%d", &numProductos);
    getchar();  

    for (int i = 0; i < numProductos; i++) {
        do {
            printf("Ingresa el nombre del producto %d: ", i + 1);
            fgets(nombres[i], sizeof(nombres[i]), stdin);  
            nombres[i][strcspn(nombres[i], "\n")] = '\0';  

            if (!esNombreValido(nombres[i])) {
                printf("Error: El nombre del producto solo debe contener letras. Intenta nuevamente.\n");
            }
        } while (!esNombreValido(nombres[i]));  

        printf("Ingresa la cantidad del producto %d: ", i + 1);
        scanf("%d", &cantidades[i]);

        do {
            printf("Ingresa el precio unitario del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("Error: No se pueden ingresar precios negativos. Por favor, intenta nuevamente.\n");
            }
        } while (precios[i] < 0);
        getchar();  
    }

    return numProductos;
}

float calcularPrecioTotal(float precios[], int cantidades[], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i] * cantidades[i];
    }
    return total;
}

const char* productoMasCaro(char nombres[MAX_PRODUCTS][30], float precios[], int numProductos) {
    int indiceMasCaro = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i;
        }
    }
    return nombres[indiceMasCaro];
}

const char* productoMasBarato(char nombres[MAX_PRODUCTS][30], float precios[], int numProductos) {
    int indiceMasBarato = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;
        }
    }
    return nombres[indiceMasBarato];
}

float calcularPromedio(float precios[], int cantidades[], int numProductos) {
    float totalPrecio = 0;
    int totalProductos = 0;
    for (int i = 0; i < numProductos; i++) {
        totalPrecio += precios[i] * cantidades[i];
        totalProductos += cantidades[i];
    }
    if (numProductos == 0) return 0;
    return totalPrecio / numProductos;  // Dividir por el número de productos (no por las unidades)
}

void buscarProducto(char nombres[MAX_PRODUCTS][30], float precios[], int numProductos, char nombreBuscado[]) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("Producto encontrado: %s con precio %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

int esNombreValido(const char nombre[]) {
    for (int i = 0; i < strlen(nombre); i++) {
        if (!isalpha(nombre[i]) && nombre[i] != ' ') {
            return 0;
        }
    }
    return 1;
}
