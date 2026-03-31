#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"


/* Definir la estructura Pelicula */
struct Pelicula
{
    char* titulo;
    int anio;
    char* genero;
    char* directores[MAX_DIRECTORES];
    int contador;
};


/* Función auxiliar para copiar cadenas usando malloc + strcpy */
char* copiarCadena(const char* texto)
{
    if (texto == NULL) return NULL;
    
    // Reservar tamaño del texto + 1 para el caracter nulo '\0'
    char* nuevo = (char*)malloc(strlen(texto) + 1);
    if (nuevo != NULL) {
        strcpy(nuevo, texto);
    }
    return nuevo;
}


/* Crear película */
Pelicula* crearPelicula(const char* titulo, int anio, const char* genero)
{
    /* 1 Reservar memoria para Pelicula */
    Pelicula* p = (Pelicula*)malloc(sizeof(Pelicula));
    
    if (p != NULL) {
        /* 2 Copiar titulo */
        p->titulo = copiarCadena(titulo);
        
        /* 3 Copiar genero */
        p->genero = copiarCadena(genero);
        
        /* 4 Inicializar anio */
        p->anio = anio;
        
        /* 5 Inicializar contador de directores en 0 */
        p->contador = 0;
        
        // Inicializar punteros de directores a NULL por seguridad
        for(int i = 0; i < MAX_DIRECTORES; i++) {
            p->directores[i] = NULL;
        }
    }

    /* 6 Regresar la película */
    return p;
}


/* Imprimir película */
void imprimir(Pelicula* p)
{
    if (p == NULL) return;

    printf("Titulo: %s\n", p->titulo);
    printf("Año: %d\n", p->anio);
    printf("Genero: %s\n", p->genero);
    printf("Directores:\n");
    
    if (p->contador == 0) {
        printf("  (Sin directores registrados)\n");
    } else {
        for (int i = 0; i < p->contador; i++) {
            printf("  - %s\n", p->directores[i]);
        }
    }
    printf("--------------------------\n");
}


/* Cambiar género */
void cambiarGenero(Pelicula* p, const char* nuevoGenero)
{
    if (p == NULL || nuevoGenero == NULL) return;

    /* 1 Liberar el genero anterior */
    free(p->genero);

    /* 2 Copiar nuevoGenero */
    p->genero = copiarCadena(nuevoGenero);
}


/* Agregar director */
void agregarDirector(Pelicula* p, const char* director)
{
    if (p == NULL || director == NULL) return;

    /* 1 Verificar que no exceda MAX_DIRECTORES */
    if (p->contador < MAX_DIRECTORES) {
        /* 2 Copiar el nombre del director */
        /* 3 Guardarlo en el arreglo */
        p->directores[p->contador] = copiarCadena(director);
        
        /* 4 Incrementar contador */
        p->contador++;
    } else {
        printf("Error: Maximo de directores alcanzado.\n");
    }
}


/* Liberar memoria */
void destruir(Pelicula* p)
{
    if (p == NULL) return;

    /* 1 Liberar titulo */
    free(p->titulo);

    /* 2 Liberar genero */
    free(p->genero);

    /* 3 Liberar cada director */
    for (int i = 0; i < p->contador; i++) {
        free(p->directores[i]);
    }

    /* 4 Liberar la estructura */
    free(p);
}
