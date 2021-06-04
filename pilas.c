#include "pilas.h"
#include <stdlib.h>
#include <assert.h>


Pila pila_crear()
{
    Pila pila = glist_crear();
    
    return pila;
}


void pila_destruir(Pila pila, FuncionDestructora destruir)
{
    glist_destruir(pila, destruir);
}


int is_empty(Pila pila)
{
    if(pila)
        return 0;
    
    return 1;
}


void* top(Pila pila)
{
    return pila->dato;
}


Pila push(Pila pila, void *dato, FuncionCopia copia)
{
    return glist_agregar_inicio(pila, dato, copia);
}


void push_void(Pila *pila, void *dato, FuncionCopia copia)
{
    *pila = glist_agregar_inicio(*pila, dato, copia);
}


Pila pop(Pila pila, FuncionDestructora destruir)
{
    assert(pila);
    
    Pila aux = pila->sig;
    
    destruir(pila->dato);
    
    free(pila);
    
    pila = aux;
    
    return pila;
}


void pop_void(Pila *pila, FuncionDestructora destruir)
{
    assert(*pila);
    
    Pila aux = (*pila)->sig;
    
    destruir((*pila)->dato);
    
    free(*pila);
    
    *pila = aux;
}


GList glist_revertir(GList lista, FuncionCopia copia, FuncionDestructora destruir)
{
    Pila pila = pila_crear();
    
    GList otra = lista;
    
    while(otra)
    {
        pila = push(pila, otra->dato, copia);
        
        otra = otra->sig;
    }
    
    glist_destruir(lista, destruir);
    
    return pila;
}


void glist_revertir_void(GList *lista, FuncionCopia copia, FuncionDestructora destruir)
{
    Pila pila = pila_crear();
    
    GList otra = *lista;
    
    while(otra)
    {
        pila = push(pila, otra->dato, copia);
        
        otra = otra->sig;
    }
    
    glist_destruir(*lista, destruir);
    
    *lista = pila;
}





