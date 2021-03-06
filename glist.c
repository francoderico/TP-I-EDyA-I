#include "glist.h"
#include <stdlib.h>
#include <assert.h>


GList glist_crear() {
    return NULL;
}


void glist_destruir(GList lista, FuncionDestructora destruir) {
    while (lista) {
        GNodo *aux = lista->sig;

        destruir(lista->dato);

        free(lista);

        lista = aux;
    }
}


int glist_vacia(GList lista) {
    return !lista;
}


void glist_recorrer(GList lista, FuncionVisitante f) {
    GList copia = lista;

    while (copia) {
        f(copia->dato);

        copia = copia->sig;
    }
}


GList glist_agregar_final(GList lista, void *dato, FuncionCopia copia) {
    GNodo *nodoFinal = malloc(sizeof(GNodo));

    nodoFinal->dato = copia(dato);

    nodoFinal->sig = NULL;

    if (lista == NULL) {
        lista = nodoFinal;
    } else {
        GList otra = lista;

        while (otra->sig != NULL) {
            otra = otra->sig;
        }

        otra->sig = nodoFinal;
    }

    return lista;
}


GList glist_agregar_inicio(GList lista, void *dato, FuncionCopia copia) {
    GNodo *nodoInicio = malloc(sizeof(GNodo));

    nodoInicio->dato = copia(dato);

    nodoInicio->sig = lista;

    return nodoInicio;
}


int glist_buscar(GList lista, void *dato, FuncionComparadora comp) {
    GList otra = lista;

    int i;

    for (i = 0; otra != NULL && !comp(otra->dato, dato); i++) {
        otra = otra->sig;
    }

    if (otra == NULL) {
        i = -1;
    }

    return i;
}


GList glist_filtrar(GList lista, Predicado p, FuncionCopia copia) {
    GList otra = lista, nueva = glist_crear();

    while (otra) {
        if (p(otra->dato)) {
            nueva = glist_agregar_inicio(nueva, otra->dato, copia);
        }

        otra = otra->sig;
    }

    return nueva;
}
