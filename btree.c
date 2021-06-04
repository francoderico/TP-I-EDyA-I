#include "btree.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() {
    return NULL;
}

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo, FuncionDestructora2 destruir) {
    if (nodo != NULL) {
        btree_destruir(nodo->left, destruir);
        btree_destruir(nodo->right, destruir);
        destruir(*nodo);
        free(nodo);
    }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) {
    return nodo == NULL;
}

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(void *dato, BTree left, BTree right, FuncionCopia copia) {
    BTree nuevoNodo = malloc(sizeof(BTNodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->left = left;
    nuevoNodo->right = right;
    return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit) {
    if (!btree_empty(arbol)) {
        if (orden == BTREE_RECORRIDO_PRE)
            visit(arbol->dato);

        btree_recorrer(arbol->left, orden, visit);

        if (orden == BTREE_RECORRIDO_IN)
            visit(arbol->dato);

        btree_recorrer(arbol->right, orden, visit);

        if (orden == BTREE_RECORRIDO_POST)
            visit(arbol->dato);
    }
}









int btree_nnodos(BTree arbol) {
    if (btree_empty(arbol)) {
        return 0;
    }

    int n = 1;

    n += btree_nnodos(arbol->left);

    n += btree_nnodos(arbol->right);

    return n;
}


int btree_buscar(void *dato, BTree arbol) {
    if (!btree_empty(arbol) && (dato == arbol->dato ||
                                btree_buscar(dato, arbol->left) ||
                                btree_buscar(dato, arbol->right))) {
        return 1;
    }

    return 0;
}


BTree btree_copiar(BTree arbol, FuncionCopia copia) {
    BTree ret = btree_crear();

    if (!btree_empty(arbol)) {
        ret =
            btree_unir(arbol->dato, btree_copiar(arbol->left, copia),
                       btree_copiar(arbol->right, copia), copia);
    }

    return ret;
}


int btree_altura(BTree arbol) {
    if (btree_empty(arbol)) {
        return -1;
    }

    int alturaL = btree_altura(arbol->left), alturaR =
        btree_altura(arbol->right);

    return alturaL > alturaR ? alturaL + 1 : alturaR + 1;
}


int btree_nnodos_profundidad(int profundidad, BTree arbol) {
    assert(profundidad >= 0);

    if (btree_empty(arbol)) {
        return 0;
    }

    if (profundidad == 0) {
        return 1;
    }

    return btree_nnodos_profundidad(profundidad - 1, arbol->left) +
        btree_nnodos_profundidad(profundidad - 1, arbol->right);
}


int btree_profundidad(void *dato, BTree arbol, FuncionComparadora comp) {
    if (btree_empty(arbol)) {
        return -1;
    }

    if (comp(dato, arbol->dato) == 0) {
        return 0;
    }

    int profundidadL = btree_profundidad(dato, arbol->left, comp),
        profundidadR = btree_profundidad(dato, arbol->right, comp);

    if (profundidadL != -1 && profundidadR == -1) {
        return profundidadL + 1;
    }

    if (profundidadL == -1 && profundidadR != -1) {
        return profundidadR + 1;
    }

    if (profundidadL == -1 && profundidadR == -1) {
        return -1;
    }

    return profundidadL < profundidadR ? profundidadL + 1 : profundidadR + 1;
}
