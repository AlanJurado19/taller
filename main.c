#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int numProductos, opcion, indice;
    char nombreBuscado[MAX_NOMBRE];

    printf("Cuantos productos desea ingresar (max %d): ", MAX_PRODUCTOS);
    scanf("%d", &numProductos);

    if (numProductos < 1 || numProductos > MAX_PRODUCTOS) {
        printf("Cantidad invalida.\n");
        return 0;
    }

    ingresarProductos(nombres, precios, numProductos);

    do {
        printf("\n====== MENU ======\n");
        printf("1. Mostrar productos\n");
        printf("2. Total del inventario\n");
        printf("3. Mas caro / mas barato\n");
        printf("4. Precio promedio\n");
        printf("5. Buscar producto\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            mostrarTodos(nombres, precios, numProductos);
        }
        else if (opcion == 2) {
            printf("Total: %.2f\n", calcularTotal(precios, numProductos));
        }
        else if (opcion == 3) {
            int caro = indiceMasCaro(precios, numProductos);
            int barato = indiceMasBarato(precios, numProductos);
            printf("\nMas caro:\n");
            mostrarProducto(nombres, precios, caro);
            printf("Mas barato:\n");
            mostrarProducto(nombres, precios, barato);
        }
        else if (opcion == 4) {
            printf("Promedio: %.2f\n", calcularPromedio(precios, numProductos));
        }
        else if (opcion == 5) {
            printf("Nombre a buscar: ");
            scanf("%s", nombreBuscado);
            indice = buscarProducto(nombres, numProductos, nombreBuscado);

            if (indice == -1) {
                printf("No encontrado.\n");
            } else {
                mostrarProducto(nombres, precios, indice);
            }
        }

    } while (opcion != 0);

    printf("Fin del programa.\n");
    return 0;
}
