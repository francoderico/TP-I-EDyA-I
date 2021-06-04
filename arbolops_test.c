#include "arbolops.h"
#include "tablaops.h"
#include "btree.h"
#include "pilas.h"
#include "struct_operador.h"
#include "operadores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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
    
    
    sim[0] = '^';               //sim[1] = '\0';
    
    cargar_operador(&tabla, sim, 2, potencia);
    

    free(sim);


    
    
    char* expr = malloc(sizeof(char) * 200);
    
    /*
     * A continuación, varios ejemplos con los que probamos el funcionamiento:
     * */
    
    expr = strcpy(expr, "5 7 + 8 -");
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
    
    //expr = strcpy(expr, "5 0 /");
    //arbol_operaciones_imprimir: 5 / 0
    //arbol_operaciones_evaluar = 2147483647
    
    //expr = strcpy(expr, "0 0 ^");
    //arbol_operaciones_imprimir: 0 ^ 0
    //arbol_operaciones_evaluar = 1
    
    //expr = strcpy(expr, "2 -- 5 +");
    //arbol_operaciones_imprimir: --2 + 5
    //arbol_operaciones_evaluar = 3
    
    //expr = strcpy(expr, "5");
    //arbol_operaciones_imprimir: 5
    //arbol_operaciones_evaluar = 5
    
    //expr = strcpy(expr, "5 --");
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
    
    printf("pila tiene iene tamaño %d\n", i);
    
    
    
    printf("En notación infija: ");
    arbol_operaciones_imprimir(arbol);
    printf("\n");
    
    
    int* args = malloc(sizeof(int) * 2);
    
    printf("El resultado es %d\n", arbol_operaciones_evaluar(arbol, args));
    
    free(args);
    
    
    
    pila_destruir(pila, btree_destruir_operador_o_int);
    
    
    
    
    
    

    tablaOps_destruir(tabla);
    
    free(expr);
    
    return 0;
}
