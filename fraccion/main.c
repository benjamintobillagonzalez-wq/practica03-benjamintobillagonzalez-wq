#include <stdio.h>
#include "fraccion.h"

int main()
{
    printf("Prueba del TAD Fraccion\n");

    /* 1 Crear dos fracciones
       ejemplo: 1/2 y 3/4
    */
    Fraccion* f1 = crearFraccion(1, 2);
    Fraccion* f2 = crearFraccion(3, 4);


    printf("Fraccion 1: ");
    /* imprimir */
    imprimir(f1);
    printf("\n");


    printf("Fraccion 2: ");
    /* imprimir */
    imprimir(f2);
    printf("\n");


    printf("\nSuma de fracciones:\n");

    /* 2 Sumar fracciones */
    Fraccion* resultado = sumar(f1, f2);


    /* 3 Imprimir resultado */
    imprimir(f1);
    printf(" + ");
    imprimir(f2);
    printf(" = ");
    imprimir(resultado);
    printf("\n");


    /* 4 Liberar memoria */
    destruir(f1);
    destruir(f2);
    destruir(resultado);

    return 0;
}
