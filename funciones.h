#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 20

void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int numProductos);

float calcularTotal(float precios[], int numProductos);
float calcularPromedio(float precios[], int numProductos);
int indiceMasCaro(float precios[], int numProductos);
int indiceMasBarato(float precios[], int numProductos);

int buscarProducto(char nombres[][MAX_NOMBRE], int numProductos, char nombreBuscado[]);

void mostrarProducto(char nombres[][MAX_NOMBRE], float precios[], int indice);
void mostrarTodos(char nombres[][MAX_NOMBRE], float precios[], int numProductos);

#endif
    
