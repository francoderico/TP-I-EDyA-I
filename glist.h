#ifndef __GLIST_H__
#define __GLIST_H__

#include <stddef.h>
#include "typedefs.h"


typedef struct _GNodo {
    void *dato;
    struct _GNodo *sig;
} GNodo;

typedef GNodo *GList;



GList glist_crear();

void glist_destruir(GList lista, FuncionDestructora destruir);

int glist_vacia(GList lista);

void glist_recorrer(GList lista, FuncionVisitante f);

GList glist_agregar_final(GList lista, void *dato, FuncionCopia copia);

GList glist_agregar_inicio(GList lista, void *dato, FuncionCopia copia);

int glist_buscar(GList lista, void *dato, FuncionComparadora comp);

GList glist_filtrar(GList lista, Predicado p, FuncionCopia copia);









#endif                          /* __GLIST_H__ */
