#include <stdio.h>
#include "pelicula.h"

int main()
{
    printf("Prueba del TAD Pelicula\n");

    /* 1 Crear una película */
    // Ejemplo: Inception, 2010, Ciencia Ficcion
    Pelicula* p = crearPelicula("Inception", 2010, "Ciencia Ficcion");


    /* 2 Agregar algunos directores */
    agregarDirector(p, "Christopher Nolan");
    // Probando que acepte más de uno
    agregarDirector(p, "Emma Thomas (Productora/Dir)");


    /* 3 Imprimir película */
    imprimir(p);


    printf("\nCambiar genero\n");

    /* 4 Cambiar genero */
    cambiarGenero(p, "Thriller Psicologico");


    /* 5 Imprimir nuevamente */
    imprimir(p);


    /* 6 Liberar memoria */
    destruir(p);

    return 0;
}
