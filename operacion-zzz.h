#ifndef __OPERACION_H__
#define __OPERACION_H__

/*Archivo cabecera de la estructura operación y sus funciones.*/


#include "arbolops.h"


/*
 * Vamos a almacenar las operaciones según su alias y su expresión
 * (dadas por el usuario a través de la entrada estándar), y su
 * resultado, que será calculado en el momento en el que leemos la
 * expresión.
 * */
typedef struct _Operacion {
    char *alias;
    char *expr;                 //Ver si es mejor guardar la string (5 -- 2 3 +) o el árbol. Me inclino para el àrbol, va a estar màs simple asì para la operacion imprimir.
    int resultado;
} Operacion;

/*
 * Crea una nueva operación con los parámetros dados.
 * */
Operacion *operacion_crear(char *alias, char *expr, int resultado);

/*
 * Crea una copia física de la operación.
 * */
Operacion *operacion_copiar(Operacion * op);

/*
 * Evalúa la expresión de la operación.
 * */
int operacion_evaluar(Operacion * op);

/*
 * Dadas 2 operaciones, las compara según su alias, siguiendo el mismo
 * criterio que la función strcmp: devuelve
 * -1 si op1->alias < op2->alias, 
 * 0 si op1->alias == op2->alias,
 * 1 si op1->alias > op2->alias.
 * */
int operacion_comparar(Operacion * op1, Operacion * op2);


/*
 * Imprime la expresión de la operación, con notación infija.
 * */
void operacion_imprimir(Operacion * op);

/*
 * Destruye la operación, liberando la memoria dinámica.
 * */
void operacion_destruir(Operacion * op);





#endif /** __OPERACION_H__ */
