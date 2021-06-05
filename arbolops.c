#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"
#include "struct_operador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
 * Dada una string fragmento, devuelve 1 si es un número, y 0
 * en caso contrario.
 * */
int es_numero(char *fragmento) {
    while (*fragmento != '\0') {
        if (*fragmento < '0' || *fragmento > '9')
            return 0;

        fragmento++;
    }

    return 1;
}


/*
 * Dada una string fragmento que representa un número, devuelve el int
 * que representa.
 * */

int num(char *fragmento) {
    int ret = 0;

    while (*fragmento != '\0') {
        ret = 10 * ret + (*fragmento - '0');

        fragmento++;
    }

    return ret;
}


//Para trabajar con los originales en vez de las copias
void *no_copiar(void *dato) {
    return dato;
}

//Para trabajar con los originales en vez de las copias
void no_destruir(void *dato) {
    return;
}

//Crea un arbol de operaciones a partir de una expresión.

Pila crear_arbol_operaciones(TablaOps tabla, char *p) {
    int flag = 0;

    Pila pila = pila_crear();

    while (*p != '\0') {
        if (*p != ' ') {
            char *q = p;

            q++;

            while (*q != '\0' && *q != ' ') {
                q++;
            }

            char *fragmento = malloc(sizeof(char) * 15);

            int i = 0;

            while (p != q) {
                fragmento[i] = *p;

                p++;

                i++;
            }

            fragmento[i] = '\0';


            if (es_numero(fragmento)) {
                int *n = malloc(sizeof(int));

                *n = num(fragmento);

                free(fragmento);

                BTree nuevoArbol =
                    btree_unir((void *) n, btree_crear(), btree_crear(),
                               no_copiar);

                pila = push(pila, (void *) nuevoArbol, no_copiar);
            } else if (es_operador(tabla, fragmento)) {
                Operador *op =
                    operador_copiar(buscar_operador(tabla, fragmento));

                free(fragmento);


                BTree ult = (BTree) top(pila);

                pila = pop(pila, no_destruir);

                BTree penult;

                if (op->aridad == 2) {
                    penult = (BTree) top(pila);

                    pila = pop(pila, no_destruir);
                } else {
                    penult = btree_crear();
                }

                BTree nuevoArbol =
                    btree_unir((void *) op, penult, ult, no_copiar);

                pila = push(pila, (void *) nuevoArbol, no_copiar);
            }
        } else {
            p++;
        }
    }

    return pila;
}



//Define la precedencia de un operador (u operando).


int precedencia(BTree arbol) {
    int p;

    if (arbol == NULL || (arbol->left == NULL && arbol->right == NULL)) {
        p = 5;
    } else {
        char *simbolo = ((Operador *) (arbol->dato))->simbolo;

        if (strcmp(simbolo, "+") == 0 || strcmp(simbolo, "-") == 0) {
            p = 0;
        } else if (strcmp(simbolo, "--") == 0) {
            p = 1;
        } else if (strcmp(simbolo, "*") == 0 || strcmp(simbolo, "/") == 0
                   || strcmp(simbolo, "%") == 0) {
            p = 2;
        } else if (strcmp(simbolo, "^") == 0) {
            p = 3;
        } else {
            p = 4;
        }
    }

    return p;
}


//Imprime un arbol de operaciones en notación infija.

void arbol_operaciones_imprimir(BTree arbol) {

    if (arbol == NULL) {
        printf("La operación es vacía.");
    } else {
        if (arbol->left == NULL && arbol->right == NULL) {
            printf("%d", *(int *) (arbol->dato));
        } else {
            if (((Operador *) (arbol->dato))->aridad == 2) {
                if (precedencia(arbol) > precedencia(arbol->left)) {
                    printf("(");
                    arbol_operaciones_imprimir(arbol->left);
                    printf(")");
                } else {
                    arbol_operaciones_imprimir(arbol->left);
                }

                printf(" %s ", ((Operador *) (arbol->dato))->simbolo);
            } else {
                printf("%s", ((Operador *) (arbol->dato))->simbolo);
            }

            if (precedencia(arbol) > precedencia(arbol->right)) {
                printf("(");
                arbol_operaciones_imprimir(arbol->right);
                printf(")");
            } else {
                arbol_operaciones_imprimir(arbol->right);
            }
        }
    }
}


//Devuelve el resultado de evaluar un árbol de operaciones.

int arbol_operaciones_evaluar(BTree arbol, int *args) {

    if (arbol == NULL) {
        return 0;
    } else {
        if (arbol->left == NULL && arbol->right == NULL) {
            return *(int *) (arbol->dato);
        } else {
            if (((Operador *) (arbol->dato))->aridad == 2) {
                int auxLeft =
                    arbol_operaciones_evaluar(arbol->left, args), auxRight =
                    arbol_operaciones_evaluar(arbol->right, args);

                args[0] = auxLeft;

                args[1] = auxRight;

                return ((Operador *) (arbol->dato))->eval(args);
            } else {
                args[0] = arbol_operaciones_evaluar(arbol->right, args);

                return ((Operador *) (arbol->dato))->eval(args);
            }
        }
    }
}




void destruir_operador_o_int(BTNodo nodo) {
    if (nodo.left == NULL && nodo.right == NULL) {
        free((int *) (nodo.dato));
    } else {
        operador_destruir((Operador *) (nodo.dato));
    }
}



void btree_destruir_operador_o_int(void *dato) {
    btree_destruir((BTree) dato, destruir_operador_o_int);
}
