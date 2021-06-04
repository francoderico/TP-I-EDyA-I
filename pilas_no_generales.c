#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

Pila pila_crear() {
    return NULL;
}

Pila apilar(Pila pila, BTree simbolo) {
    Simbolo *nuevoSimbolo = malloc(sizeof(Simbolo));
    nuevoSimbolo->simbolo = simbolo;
    nuevoSimbolo->sig = pila;
    return nuevoSimbolo;
}

Pila desapilar(Pila pila) {
    Simbolo *temp = pila;
    pila->simbolo = pila->sig->simbolo;
    pila->sig = pila->sig->sig;
    free(temp);
    return pila;
}

void destruir(Pila pila) {
    Simbolo *nodoAEliminar;
    while (pila != NULL) {
        nodoAEliminar = pila;
        pila = pila->sig;
        free(nodoAEliminar);
    }
}
