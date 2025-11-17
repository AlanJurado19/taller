#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int numProductos) {
    int i;

    for (i = 0; i < numProductos; i++) {
        printf("\nProducto %d\n", i + 1);
        
        printf("Nombre (una sola palabra): ");
        scanf("%s", nombres[i]);

        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[], int numProductos) {
    int i;
    float total = 0;

    for (i = 0; i < numProductos; i++) {
        total = total + precios[i];
    }

    return total;
}

float calcularPromedio(float precios[], int numProductos) {
    float total;
    float promedio;

    if (numProductos == 0) {
        return 0;
    }

    total = calcularTotal(precios, numProductos);
    promedio = total / numProductos;

    return promedio;
}

int indiceMasCaro(float precios[], int numProductos) {
    int i;
    int indiceMayor = 0;

    for (i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceMayor]) {
            indiceMayor = i;
        }
    }

    return indiceMayor;
}

int indiceMasBarato(float precios[], int numProductos) {
    int i;
    int indiceMenor = 0;

    for (i = 1; i < numProductos; i++) {
        if (precios[i] < precios[indiceMenor]) {
            indiceMenor = i;
        }
    }

    return indiceMenor;
}

int buscarProducto(char nombres[][MAX_NOMBRE], int numProductos, char nombreBuscado[]) {
    int i;

    for (i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            return i;
        }
    }

    return -1; // no lo encontró
}

void mostrarProducto(char nombres[][MAX_NOMBRE], float precios[], int indice) {
    printf("Nombre: %s - Precio: %.2f\n", nombres[indice], precios[indice]);
}

void mostrarTodos(char nombres[][MAX_NOMBRE], float precios[], int numProductos) {
    int i;

    printf("\n--- LISTA DE PRODUCTOS ---\n");

    for (i = 0; i < numProductos; i++) {
        printf("%d) ", i + 1);
        mostrarProducto(nombres, precios, i);
    }
}
