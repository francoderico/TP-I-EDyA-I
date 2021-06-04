#include "pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main() {
    
    int* a = malloc(sizeof(int));
    
    *a = 1;
    BTree ll = btree_unir((void*)a, btree_crear(), btree_crear());
    
    *a = 2;
    BTree l = btree_unir((void*)a, ll, btree_crear());
    
    *a = 3;
    BTree r = btree_unir((void*)a, btree_crear(), btree_crear());
    
    *a = 4;
    BTree raiz = btree_unir((void*)a, l, r);
    
    free(a);
    
    Pila pila = pila_crear();
    
    apilar(pila, raiz);
    
    destruir(pila);
    
    btree_destruir(raiz);
}








