#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "typedefs.h"

typedef void (*FuncionVisitanteExtra)(void *dato, void *extra);

typedef enum {
  BTREE_RECORRIDO_IN_BS,  /** Inorden */
  BTREE_RECORRIDO_PRE_BS, /** Preorden */
  BTREE_RECORRIDO_POST_BS /** Postorden */
} BSTreeRecorrido;

typedef struct _BST_Nodo *BSTree;

/**
 * Retorna un arbol de busqueda binaria vacio.
 */
BSTree bstree_crear();

/**
 * Destruye el arbol y sus datos.
 */
void bstree_destruir(BSTree, FuncionDestructora);

/**
 * Retorna 1 si el dato se encuentra y 0 en caso contrario.
 */
void* bstree_buscar(BSTree, void *, FuncionComparadora);

/**
 * Inserta un dato no repetido en el arbol, manteniendo la propiedad del arbol
 * de busqueda binaria.
 */
BSTree bstree_insertar(BSTree, void *, FuncionCopia, FuncionComparadora);

/**
 * Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree, BSTreeRecorrido, FuncionVisitanteExtra,
                     void *extra);

#endif //__BSTREE_H__
