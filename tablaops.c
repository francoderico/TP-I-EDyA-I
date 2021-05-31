#include "tablaops.h"
#include "glist.h"
#include "struct_operador.h"
#include <stdlib.h>
#include <stdio.h>


TablaOps tablaOps_crear()
{
    return glist_crear();
}


/*
 * Función auxiliar para castear
 * */
void f_operador_destruir(void *op)
{
    operador_destruir((Operador*)op);
}

void tablaOps_destruir(TablaOps tabla)
{
    glist_destruir(tabla, f_operador_destruir);
}


int tablaOps_vacia(TablaOps tabla)
{
    return glist_vacia(tabla);
}


/*
 * Función auxiliar para castear
 * */
void* f_operador_copiar(void *op)
{
    return (void*)operador_copiar((Operador*)op);
}

TablaOps tablaOps_agregar_inicio(TablaOps tabla, Operador *data)
{
    return glist_agregar_inicio(tabla, (void*)data, f_operador_copiar);
}


/*
 * Función auxiliar para castear
 * */
int f_operador_comparar(void *op1, void *op2)
{
    return operador_comparar((Operador*)op1, (Operador*)op2);
}

int tablaOps_buscar(TablaOps tabla, Operador *data)
{
    return glist_buscar(tabla, (void*)data, f_operador_comparar);
}

void tablaOps_recorrer(TablaOps tabla, FuncionVisitante visitar)
{
    glist_recorrer(tabla, visitar);
}

void cargar_operador(TablaOps *tabla, char *simbolo, int aridad,
                     FuncionEvaluacion eval)
{
    Operador* nuevo = operador_crear(simbolo, aridad, eval);
    
    *tabla = tablaOps_agregar_inicio(*tabla, nuevo);
    
    operador_destruir(nuevo);
}

/*
 *Determina si un simbolo es un operador de una tabla de operadores.
 * Si le saco lo de simbolo compila. No se me ocurre como acceder a los datos del operador  cuando almacenamos datos con *void. 
 */

int es_operador(TablaOps tabla, char *simbolo)
{
	int ok = 0;
	char *buscar;
	TablaOps aux = tabla;
	buscar = simbolo;
	while (aux != NULL && aux->dato->simbolo!= buscar){
		aux = aux->sig;
		}
	if (aux->dato->simbolo == buscar ){
	ok=1;
	}
	return ok;
}










