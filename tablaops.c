#include "tablaops.h"
#include "glist.h"
#include "struct_operador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


TablaOps tablaOps_crear() {
    return glist_crear();
}


/*
 * Función auxiliar para castear
 * */
void f_operador_destruir(void *op) {
    operador_destruir((Operador *) op);
}

void tablaOps_destruir(TablaOps tabla) {
    glist_destruir(tabla, f_operador_destruir);
}


int tablaOps_vacia(TablaOps tabla) {
    return glist_vacia(tabla);
}


/*
 * Función auxiliar para castear
 * */
void *f_operador_copiar(void *op) {
    return (void *) operador_copiar((Operador *) op);
}

TablaOps tablaOps_agregar_inicio(TablaOps tabla, Operador * data) {
    return glist_agregar_inicio(tabla, (void *) data, f_operador_copiar);
}


/*
 * Función auxiliar para castear
 * */
int f_operador_comparar(void *op1, void *op2) {
    return operador_comparar((Operador *) op1, (Operador *) op2);
}

int tablaOps_buscar(TablaOps tabla, Operador * data) {
    return glist_buscar(tabla, (void *) data, f_operador_comparar);
}

void tablaOps_recorrer(TablaOps tabla, FuncionVisitante visitar) {
    glist_recorrer(tabla, visitar);
}


//Carga un operador en una tabla de operadores.

void cargar_operador(TablaOps * tabla, char *simbolo, int aridad,
                     FuncionEvaluacion eval) {
    Operador *nuevo = operador_crear(simbolo, aridad, eval);

    *tabla = tablaOps_agregar_inicio(*tabla, nuevo);

    operador_destruir(nuevo);
}



//Determina si un símbolo es operador o no.

int es_operador(TablaOps tabla, char *simbolo)
{
    if(tabla == NULL)
    {
        return 0;
    }
    
    if(strcmp(((Operador*)(tabla->dato))->simbolo, simbolo) == 0)
    {
        return 1;
    }
    
    return es_operador(tabla->sig, simbolo);
}



//Busca un operador en una tabla de operadores, y lo devuelve.

Operador* buscar_operador(TablaOps tabla, char *simbolo)
{
    if(strcmp(((Operador*)(tabla->dato))->simbolo, simbolo) == 0)
    {
        return (Operador*)(tabla->dato);
    }
    
    return buscar_operador(tabla->sig, simbolo);
}
