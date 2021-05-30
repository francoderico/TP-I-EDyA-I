#include "tablaops.h"
#include "glist.h"
#include "struct_operador.h"
#include <stdlib.h>
#include <stdio.h>


TablaOps tablaOps_crear()
{
    return glist_crear();
}

void tablaOps_destruir(TablaOps tabla)
{
    glist_destruir(tabla, operador_destruir);
}

int tablaOps_vacia(TablaOps tabla)
{
    return glist_vacia(tabla);
}

TablaOps tablaOps_agregar_inicio(TablaOps tabla, Operador *data)
{
    return glist_agregar_inicio(tabla, (void*)data, operador_copiar);
}

int tablaOps_buscar(TablaOps tabla, Operador *data)
{
    return glist_buscar(tabla, (void*)data, operador_comparar);
}

void tablaOps_recorrer(TablaOps tabla, FuncionVisitante visitar)
{
    glist_recorrer(tabla, visitar);
}

void cargar_operador(TablaOps *tabla, char *simbolo, int aridad,
                     FuncionEvaluacion eval)
{
    Operador nuevo = operador_crear(simbolo, evaluacion, eval);
    
    *tabla = tablaOps_agregar_inicio(*tabla, nuevo);
    
    operador_destruir(nuevo);
}












