#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTS 10

int ingresarDatos(char nombres[MAX_PRODUCTS][30], float precios[MAX_PRODUCTS], int maxProductos);
float calcularPrecioTotal(float precios[], int numProductos);
const char* productoMasCaro(char nombres[MAX_PRODUCTS][30], float precios[], int numProductos);
const char* productoMasBarato(char nombres[MAX_PRODUCTS][30], float precios[], int numProductos);
float calcularPromedio(float precios[], int numProductos);
void buscarProducto(char nombres[MAX_PRODUCTS][30], float precios[], int numProductos, char nombreBuscado[]);
int esNombreValido(const char nombre[]);

#endif