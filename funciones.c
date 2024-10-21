#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int ingresarDatos(char nombres[MAX_PRODUCTS][30], float precios[MAX_PRODUCTS], int cantidades[MAX_PRODUCTS], int maxProductos) {
    int numProductos;
    do {
        printf("Cuantos productos deseas ingresar (maximo %d): ", maxProductos);
        scanf("%d", &numProductos);

        if (numProductos < 0) {
            printf("Error: No se pueden ingresar valores negativos. Por favor, intenta nuevamente.\n");
        } else if (numProductos > maxProductos) {
            printf("Error: No puedes ingresar más de %d productos.\n", maxProductos);
        }
    } while (numProductos < 0 || numProductos > maxProductos);

    for (int i = 0; i < numProductos; i++) {
        do {
            printf("Ingresa el nombre del producto %d: ", i + 1);
            getchar();  
            fgets(nombres[i], sizeof(nombres[i]), stdin);
            nombres[i][strcspn(nombres[i], "\n")] = '\0';  

            if (!esNombreValido(nombres[i])) {
                printf("Error: El nombre del producto solo debe contener letras. Intenta nuevamente.\n");
            }
        } while (!esNombreValido(nombres[i]));

        do {
            printf("Ingresa la cantidad del producto %d: ", i + 1);
            scanf("%d", &cantidades[i]);
            if (cantidades[i] < 0) {
                printf("Error: No se pueden ingresar cantidades negativas. Por favor, intenta nuevamente.\n");
            }
        } while (cantidades[i] < 0);

        do {
            printf("Ingresa el precio unitario del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("Error: No se pueden ingresar precios negativos. Por favor, intenta nuevamente.\n");
            }
        } while (precios[i] < 0);
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

int productoMasCaro(float precios[], int numProductos) {
    int indiceMasCaro = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i;
        }
    }
    return indiceMasCaro;
}

int productoMasBarato(float precios[], int numProductos) {
    int indiceMasBarato = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;
        }
    }
    return indiceMasBarato;
}

float calcularPromedio(float precios[], int cantidades[], int numProductos) {
    float totalPrecio = 0;
    int totalUnidades = 0;

    for (int i = 0; i < numProductos; i++) {
        totalPrecio += precios[i] * cantidades[i];
        totalUnidades += cantidades[i];
    }

    if (totalUnidades == 0) return 0;
    return totalPrecio / totalUnidades;
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

// Nueva función que permite continuar o no el programa
int deseaContinuar() {
    char respuesta;
    do {
        printf("¿Deseas continuar con otro conjunto de productos? (s/n): ");
        scanf(" %c", &respuesta);
        respuesta = tolower(respuesta);  // Convertir a minúscula para que 'S' o 's' funcionen igual
        if (respuesta != 's' && respuesta != 'n') {
            printf("Error: Respuesta no valida. Por favor, ingresa 's' para sí o 'n' para no.\n");
        }
    } while (respuesta != 's' && respuesta != 'n');  // Repetir hasta que la respuesta sea válida

    return respuesta == 's';  // Retorna 1 si es 's' (quiere continuar), 0 si es 'n' (no quiere continuar)
}
