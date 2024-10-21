#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define MAX_PRODUCTS 100 

int ingresarDatos(char nombres[MAX_PRODUCTS][30], float precios[MAX_PRODUCTS], int maxProductos) {
    int numProductos;
    printf("Cuantos productos deseas ingresar (maximo %d): ", maxProductos);
    scanf("%d", &numProductos);
    getchar();  

    for (int i = 0; i < numProductos; i++) {
        do {
            printf("Ingresa el nombre del producto %d: ", i + 1);
            fgets(nombres[i], sizeof(nombres[i]), stdin);
            nombres[i][strcspn(nombres[i], "\n")] = '\0';  
        } while (!esNombreValido(nombres[i]));

        do {
            printf("Ingresa el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("Error: No se pueden ingresar precios negativos.\n");
            }
        } while (precios[i] < 0);
        getchar();  
    }
    return numProductos;
}

float calcularPrecioTotal(float precios[], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
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

float calcularPromedio(float precios[], int numProductos) {
    if (numProductos == 0) return 0;
    return calcularPrecioTotal(precios, numProductos) / numProductos;
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
