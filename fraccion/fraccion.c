#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

/* Definir la estructura Fraccion */
struct Fraccion
{
    int numerador;
    int denominador;
};


/* Función auxiliar para calcular el máximo común divisor (MCD) */
int mcd(int a, int b)
{
    /* Algoritmo de Euclides */
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    while (b != 0) {
        int temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}


/* Crear fracción */
Fraccion* crearFraccion(int num, int den)
{
    /* 1 Verificar que el denominador no sea 0 */
    if (den == 0) {
        return NULL;
    }

    /* 2 Reservar memoria con malloc */
    Fraccion* f = (Fraccion*)malloc(sizeof(Fraccion));
    
    if (f != NULL) {
        /* 3 Asignar numerador y denominador */
        f->numerador = num;
        f->denominador = den;
        
        /* 4 Simplificar la fracción */
        simplificar(f);
    }

    /* 5 Regresar la fracción */
    return f;
}


/* Simplificar fracción */
void simplificar(Fraccion* f)
{
    if (f == NULL) return;

    /* 1 Calcular el MCD */
    int comun_divisor = mcd(f->numerador, f->denominador);

    /* 2 Dividir numerador y denominador entre el MCD */
    f->numerador /= comun_divisor;
    f->denominador /= comun_divisor;

    /* Ajuste extra: Que el signo siempre esté arriba si es negativa */
    if (f->denominador < 0) {
        f->numerador = -f->numerador;
        f->denominador = -f->denominador;
    }
}


/* Sumar fracciones */
Fraccion* sumar(Fraccion* a, Fraccion* b)
{
    if (a == NULL || b == NULL) return NULL;

    /* 1 Calcular numerador resultante: (a*d + b*c) / (b*d) */
    int num_res = (a->numerador * b->denominador) + (a->denominador * b->numerador);
    int den_res = a->denominador * b->denominador;

    /* 2 Crear nueva fracción (esto ya incluye la simplificación en tu lógica de crear) */
    Fraccion* resultado = crearFraccion(num_res, den_res);

    /* 3 Simplificar (aunque crearFraccion ya lo hace, lo mantenemos por tu flujo) */
    simplificar(resultado);

    /* 4 Regresar resultado */
    return resultado;
}


/* Imprimir fracción */
void imprimir(Fraccion* f)
{
    if (f != NULL) {
        /* Formato: numerador/denominador */
        printf("%d/%d", f->numerador, f->denominador);
    }
}


/* Liberar memoria */
void destruir(Fraccion* f)
{
    /* Liberar memoria con free */
    if (f != NULL) {
        free(f);
    }
}
