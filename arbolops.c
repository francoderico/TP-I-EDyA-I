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
        if(*p != ' ')
        {
            char* q = p;
            
            q ++;
            
            while(*q != '\0' && *q != ' ')
            {
                q ++;
            }
            
            char* coso = malloc(sizeof(char) * 15);
            
            int i = 0;
            
            while(p != q)
            {
                coso[i] = *p;
                
                p ++;
                
                i ++;
            }
            
            coso[i] = '\0';
            
            
            if(es_numero(coso))
            {
                int* n = malloc(sizeof(int));
        
                *n = num(coso);
                
                free(coso);
                
                BTree nuevoArbol = btree_unir((void*)n, btree_crear(), btree_crear(), no_copiar);
                        
                pila = push(pila, (void*)nuevoArbol, no_copiar);
            }
            else if(es_operador(tabla, coso))
            {
                //printf("ENTRÓ\n");
                
                Operador* op = operador_copiar(buscar_operador(tabla, coso));
    
                free(coso);
                
                
                BTree ult = (BTree)top(pila);
    
                pila = pop(pila, no_destruir);
                
                BTree penult;
                
                if(op->aridad == 2)
                {
                    penult = (BTree)top(pila);
                    
                    pila = pop(pila, no_destruir);
                }
                else
                {
                    penult = btree_crear();
                }
                
                BTree nuevoArbol = btree_unir((void*)op, penult, ult, no_copiar);
    
                pila = push(pila, (void*)nuevoArbol, no_copiar);
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



//Función que hice para testear

Pila crear_arbol_operaciones2(TablaOps tabla, char *p)
{
    Pila pila = pila_crear();
    
    int aux = 5;
    
    for(int i = 0; i < 2; i ++)
    {
        int* n = malloc(sizeof(int));
        
        *n = aux + 2*i;
        
        BTree nuevoArbol = btree_unir((void*)n, btree_crear(), btree_crear(), no_copiar);
                
        pila = push(pila, (void*)nuevoArbol, no_copiar);
    }
    
    BTree ult = (BTree)top(pila);
    
    pila = pop(pila, no_destruir);
    
    
    BTree penult;
    
    penult = (BTree)top(pila);
                    
    pila = pop(pila, no_destruir);
    
    
    
    char* mas = malloc(sizeof(char) * 2);
    
    mas = strcpy(mas, "+");
    
    Operador* op = operador_copiar(buscar_operador(tabla, mas));
    
    free(mas);
    
    
    
    //int* n = malloc(sizeof(int));
                
    //*n = aux + 2*2;
    
    BTree nuevoArbol = btree_unir((void*)op, penult, ult, no_copiar);
    
    pila = push(pila, (void*)nuevoArbol, no_copiar);
    
    
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
