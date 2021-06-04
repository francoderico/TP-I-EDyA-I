#ifndef __PILAS_H_
#define __PILAS_H_


#include <stdio.h>   
#include <stdlib.h> 
#include "glist.h"
#include "btree.h"

typedef struct _Simbolo {
  BTree simbolo;
  struct _Simbolo *sig;
} Simbolo;

typedef Simbolo *Pila;

//Crear pila
Pila pila_crear();

//Operacion Push
void apilar(Pila pila, BTree simbolo);

//Operacion Pop
void desapilar(Pila pila);

//Destruye la pila
void destruir(Pila pila);


#endif /** _PILAS_H__ */
