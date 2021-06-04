#ifndef __ARBOLOPS_H_
#define __ARBOLOPS_H_


#include "struct_operador.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"

Pila crear_arbol_operaciones(TablaOps tabla, char *p);

Pila crear_arbol_operaciones2(TablaOps tabla, char *p);

int precedencia(char *operador);

void imprimir(BTree arbol);

int evaluar(BTree arbol, TablaOps tabla);

#endif /** __ARBOLOPS_H__ */
