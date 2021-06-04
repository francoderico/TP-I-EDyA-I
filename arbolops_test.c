#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"
#include "struct_operador.h"
#include "operadores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void destruir_int(void *dato)
{
    free((int*)dato);
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
    
    expr = strcpy(expr, "5 7 +");
    
    printf("%s\n", expr);
    
    Pila pila = crear_arbol_operaciones(tabla, expr);
    
    BTree arbol = (BTree)top(pila);
    
    //if((*arbol)->left == NULL)
    //{
        //printf("Es NULL\n");
    //}
    
    printf("*(int*)(arbol->left->dato) es %d\n", *(int*)(arbol->left->dato));
    
    printf("arbol->left->left es %p\n", arbol->left->left);
    
    printf("arbol->left->right es %p\n", arbol->left->right);
    
    printf("*(int*)(arbol->right->dato) es %d\n", *(int*)(arbol->right->dato));
    
    printf("arbol->right->left es %p\n", arbol->right->left);
    
    printf("arbol->right->right es %p\n", arbol->right->right);
    
    //printf("((Operador*)(arbol->dato))->simbolo es %s\n", ((Operador*)(arbol->dato))->simbolo);
    
    //printf("((Operador*)(arbol->dato))->aridad es %d\n", ((Operador*)(arbol->dato))->aridad);
    
    //printf("((Operador*)(arbol->dato))->eval(a) es %d\n", ((Operador*)(arbol->dato))->eval(a));
    
    printf("*(int*)(arbol->dato) es %d\n", *(int*)(arbol->dato));
    
    //imprimir(arbol);
    
    //printf("El resultado es %d\n", evaluar(arbol, tabla));
    
    //btree_destruir(arbol, free);
    //btree_destruir((*arbol)->left, free);
    
    //btree_destruir((*arbol)->right, free);
    
    //free((*arbol)->left->dato);
    
    //free((*arbol)->left);
    
    //free((*arbol)->right->dato);
    
    //free((*arbol)->right);
    
    

    free(a);

    tablaOps_destruir(tabla);
    
    //btree_destruir_alt(arbol);
    
    //btree_destruir(arbol, destruir_int);
    
    btree_destruir((BTree)top(pila), destruir_int);
    
    pila_destruir(pila, no_destruir);
    
    free(arbol);
    
    free(expr);
    
    
    return 0;
}
