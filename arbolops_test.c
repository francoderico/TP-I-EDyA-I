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

    free(sim);




    int *a = malloc(sizeof(int) * 2);

    a[0] = 19;
    a[1] = 6;

    TablaOps otra = tabla;

    while (!tablaOps_vacia(otra)) {
        printf("%d\n", ((Operador *) (otra->dato))->eval(a));

        otra = otra->sig;
    }
    
    char* expr = malloc(sizeof(char) * 10);
    
    //expr = strcpy(expr, "5 7 + 8 -"); //No da error de memoria ni de free
    
    expr = strcpy(expr, "4 8 + --"); //No da error de memoria ni de free
    
    //expr = strcpy(expr, "4 8 + 5 + 6 +"); //Sí da error de memoria ni de free
    
    //expr = strcpy(expr, "4 8 + 5 + 6 + 9 +"); //Sí da error de memoria ni de free
    
    printf("%s\n", expr);
    
    
    
    
    
    
    Pila pila = crear_arbol_operaciones(tabla, expr);
    
    BTree arbol = (BTree)top(pila);
    
    
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
