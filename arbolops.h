#ifndef __ARBOLOPS_H_
#define __ARBOLOPS_H_


#include "struct_operador.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"

Pila crear_arbol_operaciones(TablaOps tabla, char *p);

int precedencia(BTree arbol);

void arbol_operaciones_imprimir(BTree arbol);

int arbol_operaciones_evaluar(BTree arbol, int *args);

void destruir_operador_o_int(BTNodo nodo);

void btree_destruir_operador_o_int(void *dato);

#endif /** __ARBOLOPS_H__ */
