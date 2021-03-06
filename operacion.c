#include "operacion.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "btree.h"


/*
 * Crea una nueva operación con los parámetros dados.
 * */


Operacion *operacion_crear(char *alias, char *expr, TablaOps tabla) {
    Operacion *nuevo = malloc(sizeof(Operacion));

    nuevo->alias = malloc(sizeof(char) * (strlen(alias) + 1));
    strcpy(nuevo->alias, alias);

    nuevo->pila = crear_arbol_operaciones(tabla, expr);

    return nuevo;
}


void operacion_destruir(Operacion * op) {
    free(op->alias);

    pila_destruir(op->pila, btree_destruir_operador_o_int);

    free(op);
}




/*
 * Dadas 2 operaciones, las compara según su alias, siguiendo el mismo
 * criterio que la función strcmp: devuelve
 * -1 si op1->alias < op2->alias,
 * 0 si op1->alias == op2->alias,
 * 1 si op1->alias > op2->alias.
 * */
int operacion_comparar(Operacion * op1, Operacion * op2) {
    return strcmp(op1->alias, op2->alias);
}
