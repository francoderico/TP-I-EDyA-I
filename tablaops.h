#ifndef __TABLAOPS_H__
#define __TABLAOPS_H__

#include "glist.h"
#include "struct_operador.h"

/*
 * Almacenaremos la tabla de operadores como una lista de Operador
 * */
typedef GList TablaOps;


TablaOps tablaOps_crear();

void tablaOps_destruir(TablaOps tabla);

int tablaOps_vacia(TablaOps tabla);

TablaOps tablaOps_agregar_inicio(TablaOps tabla, Operador *data);

int tablaOps_buscar(TablaOps tabla, Operador *data);

void tablaOps_recorrer(TablaOps tabla, FuncionVisitante visitar);

void cargar_operador(TablaOps *tabla, char *simbolo, int aridad,
                     FuncionEvaluacion eval);

int es_operador(TablaOps tabla, char *simbolo);




#endif /** __TABLAOPS_H__ */
