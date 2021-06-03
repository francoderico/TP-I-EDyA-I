#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"
#include "struct_operador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Crea un arbol de operaciones a partir de una expresión aritmética.

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
			aux = "";
		}
		else if(es_operador(tabla,aux)== 2){
		aux1 = pila->simbolo;
		desapilar(pila);
		aux2 = pila->simbolo;
		desapilar(pila);
		apilar(pila, btree_unir(aux, aux2, aux1));
		aux = "";
		}
		p++;
	}
BTree arbolOps = pila->simbolo;
destruir(pila);
return arbolOps;
}

//Determina la precedencia de un operador. 
//¿En donde entra el modulo? 

int precedencia(char *operador){
	int p;
	if (!strcmp(operador, "+") || !strcmp(operador, "-") ||  !strcmp(operador, "--")){
		p = 1;
	}
	else if (!strcmp(operador, "*") ||  !strcmp(operador, "/")){
		p = 2;
	}
	else if (!strcmp(operador, "^")){
		p = 3;
	}
	else {
		p =4;
	}
	return p;
}




//Imprime a partir de un arbol, la expresión aritmética en inorden.

void imprimir(BTree arbol){
	if (arbol != NULL){
		if(precedencia(arbol->dato) > precedencia (arbol->left->dato)){
			printf("(");
			imprimir(arbol->left);
			printf("%s\n", arbol->dato);
			if (precedencia(arbol->dato) > precedencia (arbol->right->dato)){
				printf("(");
				imprimir(arbol->right);
				printf(")");
			}
			else{
				imprimir(arbol->right);
			}
			printf(")");
		}
		else{
			imprimir(arbol->left);
			printf("%s\n", arbol->dato);
			if (precedencia(arbol->dato) > precedencia (arbol->right->dato)){
				printf("(");
				imprimir(arbol->right);
				printf(")");
			}
			else{
				imprimir(arbol->right);
			}
		}
	}
}




