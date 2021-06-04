#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"
#include "struct_operador.h"
#include "operadores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void destruir_int(BTNodo nodo)
{
    free((int*)(nodo.dato));
}





void btree_destruir_alt(BTree nodo) {
    if (nodo != NULL) {
        
        if(nodo->left == NULL && nodo->right == NULL) //Es un int
        {
            free((int*)(nodo->dato));
        }
        else
        {
            operador_destruir((Operador*)(nodo->dato));
        }
        
        btree_destruir_alt(nodo->left);
        btree_destruir_alt(nodo->right);
        
        free(nodo);
    }
}


void btree_destruir_int(void *dato)
{
    btree_destruir((BTree)dato, destruir_int);
}



void destruir_operador_o_int(BTNodo nodo)
{
    if(nodo.left == NULL && nodo.right == NULL)
    {
        free((int*)(nodo.dato));
    }
    else
    {
        operador_destruir((Operador*)(nodo.dato));
    }
}



void btree_destruir_operador_o_int(void *dato)
{
    btree_destruir((BTree)dato, destruir_operador_o_int);
}





void btree_recorrer_operador_o_int(BTree arbol, BTreeOrdenDeRecorrido orden) {
    
    if (!btree_empty(arbol)) {
        
        if (orden == BTREE_RECORRIDO_PRE)
        {
            if(arbol->left == NULL && arbol->right == NULL)
            {
                printf("%d ", *(int*)(arbol->dato));
            }
            else
            {
                printf("%s ", ((Operador*)(arbol->dato))->simbolo);
            }
        }

        btree_recorrer_operador_o_int(arbol->left, orden);

        if (orden == BTREE_RECORRIDO_IN)
        {
            if(arbol->left == NULL && arbol->right == NULL)
            {
                printf("%d ", *(int*)(arbol->dato));
            }
            else
            {
                printf("%s ", ((Operador*)(arbol->dato))->simbolo);
            }
        }

        btree_recorrer_operador_o_int(arbol->right, orden);

        if (orden == BTREE_RECORRIDO_POST)
        {
            if(arbol->left == NULL && arbol->right == NULL)
            {
                printf("%d ", *(int*)(arbol->dato));
            }
            else
            {
                printf("%s ", ((Operador*)(arbol->dato))->simbolo);
            }
        }
    }
}






int main() {
    
    TablaOps tabla = tablaOps_crear();


    char *sim = malloc(sizeof(char) * 2);

    sim[0] = '+';
    sim[1] = '\0';

    cargar_operador(&tabla, sim, 2, suma);


    sim[0] = '-';               //sim[1] = '\0';

    cargar_operador(&tabla, sim, 2, resta);

    free(sim);


    sim = malloc(sizeof(char) * 3);

    sim[0] = '-';
    sim[1] = '-';
    sim[2] = '\0';

    cargar_operador(&tabla, sim, 1, opuesto);

    free(sim);


    sim = malloc(sizeof(char) * 2);

    sim[0] = '*';
    sim[1] = '\0';

    cargar_operador(&tabla, sim, 2, producto);


    sim[0] = '/';               //sim[1] = '\0';

    cargar_operador(&tabla, sim, 2, division);


    sim[0] = '%';               //sim[1] = '\0';

    cargar_operador(&tabla, sim, 2, modulo);
    
    
    sim[0] = '^';               //sim[1] = '\0';
    
    cargar_operador(&tabla, sim, 2, potencia);
    

    free(sim);




    int *a = malloc(sizeof(int) * 2);

    a[0] = 19;
    a[1] = 6;

    TablaOps otra = tabla;

    while (!tablaOps_vacia(otra)) {
        printf("%d\n", ((Operador *) (otra->dato))->eval(a));

        otra = otra->sig;
    }
    
    char* expr = malloc(sizeof(char) * 200);
    
    //expr = strcpy(expr, "5 7 + 8 -");
    //arbol_operaciones_imprimir: 5 + 7 - 8
    //arbol_operaciones_evaluar = 4
    
    //expr = strcpy(expr, "4 8 + --");
    //arbol_operaciones_imprimir: --(4 + 8)
    //arbol_operaciones_evaluar = -12
    
    //expr = strcpy(expr, "4 8 + 5 + 6 + --");
    //arbol_operaciones_imprimir: --(4 + 8 + 5 + 6)
    //arbol_operaciones_evaluar = -23
    
    //expr = strcpy(expr, "4 8 + 5 + 6 + 9 +");
    //arbol_operaciones_imprimir: 4 + 8 + 5 + 6 + 9
    //arbol_operaciones_evaluar = 32
    
    //expr = strcpy(expr, "3 3 + 4 8 + 5 9 + 6 + * 2 - % --");
    //arbol_operaciones_imprimir: --(3 + 3) % ((4 + 8) * (5 + 9 + 6) - 2)
    //arbol_operaciones_evaluar = -6
    
    //expr = strcpy(expr, "2 3 + 4 5 + *");
    //arbol_operaciones_imprimir: (2 + 3) * (4 + 5)
    //arbol_operaciones_evaluar = 45
    
    //expr = strcpy(expr, "2 3 * 4 5 + ^");
    //arbol_operaciones_imprimir: (2 * 3) ^ (4 + 5)
    //arbol_operaciones_evaluar = 10077696
    
    //expr = strcpy(expr, "2 3 * 4 5 % /");
    //arbol_operaciones_imprimir: 2 * 3 / 4 % 5
    //arbol_operaciones_evaluar = 1              //Notemos que la división es entera, por lo que 6/4 = 1
    
    //expr = strcpy(expr, "12 9 %");
    //arbol_operaciones_imprimir: 12 % 9
    //arbol_operaciones_evaluar = 3
    
    //expr = strcpy(expr, "2 -- 5 +");
    //arbol_operaciones_imprimir: --2 + 5
    //arbol_operaciones_evaluar = 3
    
    //expr = strcpy(expr, "5");
    //arbol_operaciones_imprimir: 5
    //arbol_operaciones_evaluar = 5
    
    expr = strcpy(expr, "5 --");
    //arbol_operaciones_imprimir: --5
    //arbol_operaciones_evaluar = -5
    
    printf("%s\n", expr);
    
    
    
    
    
    
    Pila pila = crear_arbol_operaciones(tabla, expr);
    
    BTree arbol = (BTree)top(pila);
    
    
    Pila otraPila = pila;
    
    int i = 0;
    
    while(otraPila != NULL)
    {
        i ++;
        
        otraPila = otraPila->sig;
    }
    
    printf("Tiene tamaño %d\n", i);
    
    
    
    btree_recorrer_operador_o_int(arbol, BTREE_RECORRIDO_IN);
    printf("\n");
    
    
    arbol_operaciones_imprimir(arbol);
    printf("\n");
    
    
    int* args = malloc(sizeof(int) * 2);
    
    printf("El resultado es %d\n", arbol_operaciones_evaluar(arbol, args));
    
    free(args);
    
    
    
    pila_destruir(pila, btree_destruir_operador_o_int);
    
    
    
    
    
    
    
    
    
    /*
    
    Pila pila2 = crear_arbol_operaciones2(tabla, expr);
    
    BTree aux = (BTree)top(pila2);
    
    printf("((Operador*)(((BTree)top(pila2))->dato))->aridad vale %d\n", ((Operador*)(aux->dato))->aridad);
    
    printf("((Operador*)(((BTree)top(pila2))->dato))->simbolo vale %s\n", ((Operador*)(aux->dato))->simbolo);
    
    printf("*(int*)(((BTree)top(pila2))->left->dato) vale %d\n", *(int*)(aux->left->dato));
    
    printf("*(int*)(((BTree)top(pila2))->right->dato) vale %d\n", *(int*)(aux->right->dato));
    
    
    //operador_destruir((Operador*)aux->dato);
    
    //int* n = malloc(sizeof(int));
    
    //*n = 190;
    
    //aux->dato = n;
    
    pila_destruir(pila2, btree_destruir_operador_o_int);
    
    */
    
    
    
    
    
    free(a);

    tablaOps_destruir(tabla);
    
    free(expr);
    
    return 0;
}
