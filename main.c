#include "glist.h"
#include "operacion.h"
#include "operadores.h"
#include "struct_operador.h"
#include "tablaops.h"
#include "arbolops.h"
#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int comparar_string_operacion(void *s, void *op)
{
    return strcmp((char*)s, ((Operacion*)op)->alias);
}


int f_operacion_comparar(void *op1, void *op2)
{
    return operacion_comparar((Operacion*)op1, (Operacion*)op2);
}

//void* f_operacion_copiar(void *op)
//{
    //return operacion_copiar((Operacion*)op);
//}

void* operacion_identidad(void *op)
{
    return op;
}

void f_operacion_destruir(void *op)
{
    operacion_destruir((Operacion*)op);
}




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

void interpretar(TablaOps *tabla)
{
    char* palabra = malloc(sizeof(char) * 200);
    
    BSTree arbolExp = bstree_crear();
    
    printf("¡Hola! Ingrese un comando: ");
    
    char C;
    int i = 0;
    
    while((C = getchar()) != '\n')
    {
        palabra[i] = C;
        
        i ++;
    }
    
    palabra[i] = '\0';
    
    while(strcmp(palabra, "salir") != 0)
    {
        char* nueva = malloc(sizeof(char) * 200);
        
        for(i = 0; palabra[i] != '\0' && palabra[i] != ' '; i ++)
        {
            nueva[i] = palabra[i];
        }
        
        nueva[i] = '\0';
        
        if(strcmp(nueva, "imprimir") == 0)
        {
            char* alias = malloc(sizeof(char) * 200);
            
            int j = i+1;
            
            for(; palabra[j] != '\0' && palabra[j] != ' '; j ++)
            {
                alias[j-(i+1)] = palabra[j];
            }
            
            alias[j-(i+1)] = '\0';
            
            Operacion* op = (Operacion*)bstree_buscar(arbolExp, (void*)alias, comparar_string_operacion);
            
            BTree arbol = (BTree)top(op->pila);
            
            arbol_operaciones_imprimir(arbol);
            
            free(alias);
            
            operacion_destruir(op);
            
            free(nueva);
        }
        if(strcmp(nueva, "evaluar") == 0)
        {
            char* alias = malloc(sizeof(char) * 200);
            
            int j = i+1;
            
            for(; palabra[j] != '\0' && palabra[j] != ' '; j ++)
            {
                alias[j-(i+1)] = palabra[j];
            }
            
            alias[j-(i+1)] = '\0';
            
            Operacion* op = (Operacion*)bstree_buscar(arbolExp, (void*)alias, comparar_string_operacion);
            
            printf("%d\n", op->resultado);
            
            free(alias);
            
            operacion_destruir(op);
            
            free(nueva);
        }
        else
        {
            char* alias = nueva;
            
            //if(bstree_buscar(arbolExp, (void*)alias, comparar_string_operacion) != NULL)
            //{
                
            //}
            
            char* expr = malloc(sizeof(char) * 200);
            
            int j = i+1;
            
            for(; palabra[j] != '\0'; j ++)
            {
                expr[j-(i+1)] = palabra[j];
            }
            
            expr[j-(i+1)] = '\0';
            
            Operacion* op = operacion_crear(alias, expr, *tabla);
            
            arbolExp = bstree_insertar(arbolExp, (void*)op, operacion_identidad, f_operacion_comparar);
            
            
            free(alias);
            
            //operacion_destruir(op);
            
            free(expr);
        }
        
        printf("Ingrese un nuevo comando: ");
        
        char CC;
        int ii = 0;
        
        while((CC = getchar()) != '\n')
        {
            palabra[ii] = CC;
            
            ii ++;
        }
        
        palabra[ii] = '\0';
    }
    
    free(palabra);
    
    bstree_destruir(arbolExp, f_operacion_destruir);
}


int main() {
    
    TablaOps tabla = tablaOps_crear();

    cargar(&tabla);
    
    interpretar(&tabla);
    
    
    return 0;
}
