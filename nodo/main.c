#include <stdio.h>
#include "nodo.h"

int main()
{
    printf("Prueba del TAD Nodo\n");

    /* 1 Crear un nodo con valor 10 */
    Nodo* n = crearNodo(10);


    /* 2 Mostrar el valor del nodo usando obtenerValor */
    if (n != NULL) {
        printf("Valor inicial del nodo: %d\n", obtenerValor(n));
    }


    /* 3 Cambiar el valor a 25 usando asignarValor */
    asignarValor(n, 25);
    printf("Cambiando valor a 25...\n");


    /* 4 Mostrar nuevamente el valor */
    if (n != NULL) {
        printf("Nuevo valor del nodo: %d\n", obtenerValor(n));
    }


    /* 5 Liberar el nodo con destruirNodo */
    destruirNodo(n);
    printf("Nodo destruido correctamente.\n");

    return 0;
}
