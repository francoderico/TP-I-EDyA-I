#include "bstree.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol leftuierdo (left),
 * y un puntero al nodo raiz del subarbol rightecho (right).
 */


/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstree_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->left, destr);
    bstree_destruir(raiz->right, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna el elemento que busco si el dato se encuentra,
 * y NULL en caso contrario
 */
void* bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return NULL;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return raiz->dato;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->left, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->right, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopia copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    BTNodo *nuevoNodo = malloc(sizeof(BTNodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->left = nuevoNodo->right = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->left = bstree_insertar(raiz->left, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->right = bstree_insertar(raiz->right, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE_BS)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->left, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN_BS)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->right, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST_BS)
      visita(raiz->dato, extra);
  }
}
