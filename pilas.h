#ifndef __PILAS_H__
#define __PILAS_H__

#include "glist.h"


typedef GList Pila;


Pila pila_crear();

void pila_destruir(Pila pila, FuncionDestructora destruir);

int is_empty(Pila pila);

void* top(Pila pila);

Pila push(Pila pila, void *dato, FuncionCopia copia);

void push_void(Pila *pila, void *dato, FuncionCopia copia);

Pila pop(Pila pila, FuncionDestructora destruir);

void pop_void(Pila *pila, FuncionDestructora destruir);

void pila_imprimir(Pila pila);

GList glist_revertir(GList lista, FuncionCopia copia, FuncionDestructora destruir);

void glist_revertir_void(GList *lista, FuncionCopia copia, FuncionDestructora destruir);






#endif /* __PILAS_H__ */
