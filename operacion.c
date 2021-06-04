#include "operacion.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "btree.h"


/*
 * Crea una nueva operación con los parámetros dados.
 * */
Operacion *operacion_crear(char *alias, BTree arbol, int resultado, FuncionCopia copia) {
    Operacion *nuevo = malloc(sizeof(Operacion));

    nuevo->alias = malloc(sizeof(char) * (strlen(alias) + 1));
    strcpy(nuevo->alias, alias);

    nuevo->arbol = malloc(sizeof(BTree));
    nuevo->arbol = btree_copiar(arbol, copia);

    nuevo->resultado = resultado;

    return nuevo;
}


/*
 * Crea una copia física de la operación.
 */
Operacion *operacion_copiar(Operacion * op, FuncionCopia copia2) {
    Operacion *copia = operacion_crear(op->alias, op->arbol, op->resultado, copia2);

    return copia;
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



/*
 * Destruye la operación, liberando la memoria dinámica.
 * */
void operacion_destruir(Operacion * op, FuncionDestructora2 destruir) {
    free(op->alias);

    btree_destruir(op->arbol, destruir);

    free(op);
}
