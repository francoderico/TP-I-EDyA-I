#ifndef __BTREE_H__
#define __BTREE_H__

//#include "pilas_generales.h"
#include "typedefs.h"


typedef enum {
    BTREE_RECORRIDO_IN,
    BTREE_RECORRIDO_PRE,
    BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;


typedef struct _BTNodo {
    void* dato;
    struct _BTNodo *left;
    struct _BTNodo *right;
} BTNodo;


typedef BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo, FuncionDestructora destruir);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(void *dato, BTree left, BTree right, FuncionCopia copia);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit);


void *copiar_nodo(void *nodo);

void btree_recorrer_pre_iterativo(BTree arbol, FuncionVisitante visit);

void *id(void *nodo);

void no_destruir(void *nodo);

void btree_recorrer_pre_iterativo2(BTree arbol, FuncionVisitante visit);



int btree_nnodos(BTree arbol);

int btree_buscar(void *dato, BTree arbol);

BTree btree_copiar(BTree arbol, FuncionCopia copia);

int btree_altura(BTree arbol);

int btree_nnodos_profundidad(int profundidad, BTree arbol);

int btree_profundidad(void *dato, BTree arbol, FuncionComparadora comp);

int btree_sumar(BTree arbol);







#endif                          /* __BTREE_H__ */
