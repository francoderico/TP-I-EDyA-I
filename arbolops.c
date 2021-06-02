#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"
#include "struct_operador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BTree crear_arbol_operaciones(TablaOps tabla, char *expresion)
{
	Pila pila = pila_crear();
	char *p;
	char *aux;
	BTree aux1;
	BTree aux2;
	p = expresion;
	while (*p != '\0'){
		if(*p != " "){
			aux = strcat(aux, *p);
		}
		else if(!es_operador(tabla, aux)){
			apilar(pila, btree_unir(aux, NULL, NULL));
		}
		else if (es_operador(tabla, aux) == 1){
			aux1 = pila->simbolo;
			desapilar(pila);
			apilar(pila, btree_unir(aux, aux1, NULL));	
		}
		else if(es_operador(tabla,aux)== 2){
		aux1 = pila->simbolo;
		desapilar(pila);
		aux2 = pila->simbolo;
		desapilar(pila);
		apilar(pila, btree_unir(aux, aux2, aux1));
		}
		p++;
	}
BTree arbolOps = pila->simbolo;
return arbolOps;
}








