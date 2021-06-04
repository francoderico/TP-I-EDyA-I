#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"
#include "struct_operador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* copiar_char(void* dato)
{
    char* nuevo = malloc(sizeof(char) * 100);
    
    strcpy(nuevo, (char*)dato);
    
    return nuevo;
}


//Crea un arbol de operaciones a partir de una expresión aritmética.

//BTree crear_arbol_operaciones(TablaOps tabla, char *expresion) {
    //Pila pila = pila_crear();
    //char* p = expresion;
    //char* aux = malloc(sizeof(char) * 100);
    //char* auxptr = aux;
    //BTree aux1;
    //BTree aux2;
    
    //while (*p != '\0') {
        //if (*p != ' ') {
            //*auxptr = *p;
            //auxptr++;
        //}
        //else if (!es_operador(tabla, aux)) {
            //pila = apilar(pila, btree_unir(aux, NULL, NULL, copiar_char));
        //}
        //else if (es_operador(tabla, aux) == 1) {
            //aux1 = pila->simbolo;
            //pila = desapilar(pila);
            //pila = apilar(pila, btree_unir(aux, aux1, NULL, copiar_char));
            //aux = "";
        //}
        //else if (es_operador(tabla, aux) == 2) {
            //aux1 = pila->simbolo;
            //pila = desapilar(pila);
            //aux2 = pila->simbolo;
            //pila = desapilar(pila);
            //pila = apilar(pila, btree_unir(aux, aux2, aux1, copiar_char));
            //aux = "";
        //}
        //p++;
    //}
    //BTree arbolOps = pila->simbolo;
    //destruir(pila);
    //return arbolOps;
//}


/*
 * Dada una string coso, devuelve 1 si es un número, y 0
 * en caso contrario.
 * */
int es_numero(char *coso)
{
    while(*coso != '\0')
    {
        if(*coso < '0' || *coso > '9')
            return 0;
        
        coso ++;
    }
    
    return 1;
}


/*
 * Dada una string coso que representa un número, devuelve el int
 * que representa.
 * */

int num(char *coso)
{
    int ret = 0;
    
    while(*coso != '\0')
    {
        ret = 10*ret + (*coso - '0');
        
        coso ++;
    }
    
    return ret;
}


//Para trabajar con los originales en vez de las copias
void* no_copiar(void *dato)
{
    return dato;
}
//Para trabajar con los originales en vez de las copias
void no_destruir(void *dato)
{
    return;
}



Pila crear_arbol_operaciones(TablaOps tabla, char *p)
{
    //char* p = expresion;
    
    int flag = 0;
    
    Pila pila = pila_crear();
    
    while(*p != '\0')
    {
        //printf("*p vale %c\n", *p);
        
        if(*p != ' ')
        {
            char* q = p;
            
            q ++;
            
            //printf("*q vale %c\n", *q);
            
            while(*q != '\0' && *q != ' ')
            {
                q ++;
                
                //printf("*q vale %c\n", *q);
            }
            
            char* coso = malloc(sizeof(char) * 15);
            
            int i = 0;
            
            while(p != q)
            {
                coso[i] = *p;
                
                p ++;
                
                //printf("*p vale %c\n", *p);
                
                i ++;
            }
            
            coso[i] = '\0';
            
            //printf("coso = %s\n", coso);
            
            //coso = realloc(coso, i+1);
            
            //printf("es_numero(coso) = %d\n", es_numero(coso));
            
            if(es_numero(coso))
            {
                int* n = malloc(sizeof(int));
                
                *n = num(coso);
                
                printf("*n = num(coso) = %d\n", *n);
                
                //BTree* nuevoArbol = malloc(sizeof(BTree));
                
                BTree nuevoArbol = btree_unir((void*)n, btree_crear(), btree_crear(), no_copiar);
                
                pila = push(pila, (void*)nuevoArbol, no_copiar);
            }
            else if(es_operador(tabla, coso))
            {
                printf("ENTRÓ\n");
                
                //Operador op = buscar_operador(tabla, coso);
                
                Operador* opPtr = malloc(sizeof(Operador));
                
                opPtr = operador_copiar(buscar_operador(tabla, coso));
                
                //if(is_empty(pila))
                //{
                    //printf("11111111111111111111111111111111\n");
                //}
                
                printf("bandera 1\n");
                
                BTree ult = (BTree)top(pila);
                
                printf("bandera 2\n");
                
                pila = pop(pila, no_destruir);
                
                printf("bandera 3\n");
                
                BTree penult;
                
                if(opPtr->aridad == 2)
                {
                    //if(is_empty(pila))
                    //{
                        //printf("2222222222222222222222222222222\n");
                    //}
                    
                    printf("bandera 4\n");
                    
                    penult = (BTree)top(pila);
                    
                    printf("bandera 5\n");
                    
                    pila = pop(pila, no_destruir);
                    
                    printf("bandera 6\n");
                }
                else if(opPtr->aridad == 1)
                {
                    penult = btree_crear();
                }
                
                //Operador* opPtr = malloc(sizeof(Operador));
                
                //*opPtr = op;
                
                //BTree* nuevoArbol = malloc(sizeof(BTree));
                
                printf("penult apunta a %p\n", penult);
                
                printf("ult apunta a %p\n", ult );
                
                int* n = malloc(sizeof(int));
                
                *n = opPtr->aridad;
                
                //BTree nuevoArbol = btree_unir((void*)opPtr, penult, ult, no_copiar);
                
                BTree nuevoArbol = btree_unir((void*)n, penult, ult, no_copiar);
                
                operador_destruir(opPtr);
                
                
                printf("bandera 7\n");
                
                pila = push(pila, (void*)nuevoArbol, no_copiar);
                
                printf("bandera 8\n");
            }
            //else
            //{
                //printf("La expresión ingresada no es correcta.\n");
                
                //flag = 1;
                
                //break;
            //}
            
            //free(coso);
        }
        else
            p++;
    }
    
    return pila;
}












//Determina la precedencia de un operador. 
//¿En donde entra el modulo? 

int precedencia(char *operador) {
    int p;
    if (!strcmp(operador, "+") || !strcmp(operador, "-")
        || !strcmp(operador, "--")) {
        p = 1;
    } else if (!strcmp(operador, "*") || !strcmp(operador, "/") || !strcmp(operador, "%")) {
        p = 2;
    } else if (!strcmp(operador, "^")) {
        p = 3;
    } else {
        p = 4;
    }
    return p;
}




//Imprime a partir de un arbol, la expresión aritmética en inorden.

void imprimir(BTree arbol) {
    if (arbol != NULL) {
        if (precedencia(arbol->dato) > precedencia(arbol->left->dato)) {
            printf("(");
            imprimir(arbol->left);
            printf("%s\n", (char*)(arbol->dato));
            if (precedencia(arbol->dato) > precedencia(arbol->right->dato)) {
                printf("(");
                imprimir(arbol->right);
                printf(")");
            } else {
                imprimir(arbol->right);
            }
            printf(")");
        } else {
            imprimir(arbol->left);
            printf("%s\n", (char*)arbol->dato);
            if (precedencia(arbol->dato) > precedencia(arbol->right->dato)) {
                printf("(");
                imprimir(arbol->right);
                printf(")");
            } else {
                imprimir(arbol->right);
            }
        }
    }
}

//Funcion que devuelve la evaluacion de un arbol de operaciones.

/*
int evaluar(BTree arbol, TablaOps tabla) {
    int resultado;
    if (es_operador(tabla, arbol->dato) > 0) {
        FuncionEvaluacion funcion = buscar_operador(tabla, arbol->dato);
        int operandos[2];
        operandos[0] = evaluar(arbol->left, tabla);
        if (arbol->right) {
            operandos[1] = evaluar(arbol->right, tabla);
        }
        resultado = funcion(operandos);
    } else {
        resultado = atoi(arbol->dato);
    }
    return resultado;           // Lo retorna, no lo imprime. Despues habra que hacer un printf aparte sino se enquilombaba todo con la recursion.
}
*/
