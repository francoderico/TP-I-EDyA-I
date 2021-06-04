#ifndef __PILAS_H__
#define __PILAS_H__

#include "glist.h"


typedef GList Pila;


Pila pila_crear();

void pila_destruir(Pila pila, FuncionDestructora destruir);

int is_empty(Pila pila);

void* top(Pila pila);

Pila push(Pila pila, void *dato, FuncionCopia copia);

Pila pop(Pila pila, FuncionDestructora destruir);




#endif /* __PILAS_H__ */
