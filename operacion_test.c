#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "bstree.h"
#include "pilas.h"
#include "struct_operador.h"
#include "operadores.h"
#include "operacion.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void cargar(TablaOps *tabla)
{
    char* sim = malloc(sizeof(char) * 3);

    sim[0] = '-';
    sim[1] = '-';
    sim[2] = '\0';

    cargar_operador(tabla, sim, 1, opuesto);

    free(sim);
    

    sim = malloc(sizeof(char) * 2);

    sim[0] = '+';
    sim[1] = '\0';

    cargar_operador(tabla, sim, 2, suma);


    sim[0] = '-';
    //sim[1] = '\0';

    cargar_operador(tabla, sim, 2, resta);


    sim[0] = '*';
    //sim[1] = '\0';

    cargar_operador(tabla, sim, 2, producto);


    sim[0] = '/';
    //sim[1] = '\0';

    cargar_operador(tabla, sim, 2, division);


    sim[0] = '%';
    //sim[1] = '\0';

    cargar_operador(tabla, sim, 2, modulo);
    
    
    sim[0] = '^';
    //sim[1] = '\0';
    
    cargar_operador(tabla, sim, 2, potencia);
    

    free(sim);
}


int comparar_string_operacion(void *s, void *op)
{
    return strcmp((char*)s, ((Operacion*)op)->alias);
}


void* NO_copiar(void *dato)
{
    return dato;
}


int main()
{
    TablaOps tabla = tablaOps_crear();

    cargar(&tabla);
    
    
    char* expr = malloc(sizeof(char) * 200);
    
    //expr = strcpy(expr, "5 7 + 8 -");
    
    expr = strcpy(expr, "3 3 + 4 8 + 5 9 + 6 + * 2 - % --");
    
    printf("%s\n", expr);
    
    
    Operacion* op = operacion_crear("hola", expr, tabla);
    
    free(expr);
    
    
    int* args = malloc(sizeof(int) * 2);
    
    //printf("El resultado es %d\n", arbol_operaciones_evaluar((BTree)top(op->pila), args));
    
    op->resultado = arbol_operaciones_evaluar((BTree)top(op->pila), args);
    
    printf("El resultado es %d\n", op->resultado);
    
    free(args);
    
    
    
    BSTree arbolExp = bstree_crear();
    
    arbolExp = bstree_insertar(arbolExp, (void*)op, NO_copiar, comparar_string_operacion);
    
    
    
    
    char *alias;
            
    scanf("%s", alias);
    
    Operacion* otra = bstree_buscar(arbolExp, alias, comparar_string_operacion);
    
    arbol_operaciones_imprimir((BTree)top(otra->pila));
    printf("\n");
    
    
    
    
    
    operacion_destruir(op);
    
    tablaOps_destruir(tabla);
    
    
    return 0;
}

