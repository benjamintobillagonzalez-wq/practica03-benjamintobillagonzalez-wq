#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

/* TODO
   Definir la estructura Nodo.
   Debe contener un entero llamado valor.
*/
struct Nodo
{
    int valor;
};


/* Crear un nodo dinámicamente */
Nodo* crearNodo(int valor)
{
    /* 1 Reservar memoria con malloc */
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));

    /* 2 Verificar que la memoria se haya asignado */
    if (nuevo_nodo != NULL)
    {
        /* 3 Inicializar el valor del nodo */
        nuevo_nodo->valor = valor;
    }

    /* 4 Regresar el nodo */
    return nuevo_nodo;
}


/* Obtener el valor almacenado */
int obtenerValor(Nodo* nodo)
{
    /* 1 Verificar que el nodo no sea NULL */
    if (nodo != NULL)
    {
        /* 2 Regresar el valor almacenado */
        return nodo->valor;
    }

    return 0;
}


/* Modificar el valor almacenado */
void asignarValor(Nodo* nodo, int valor)
{
    /* 1 Verificar que el nodo no sea NULL */
    if (nodo != NULL)
    {
        /* 2 Asignar el nuevo valor */
        nodo->valor = valor;
    }
}


/* Liberar memoria del nodo */
void destruirNodo(Nodo* nodo)
{
    /* Liberar la memoria usando free */
    if (nodo != NULL)
    {
        free(nodo);
    }
}
