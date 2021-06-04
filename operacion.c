#include "operacion.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*
 * Crea una nueva operación con los parámetros dados.
 * */
Operacion* operacion_crear(char *alias, char *expr, int resultado)
{
    Operacion* nuevo = malloc(sizeof(Operacion));

    nuevo->alias = malloc(sizeof(char) * (strlen(alias) + 1));
    strcpy(nuevo->alias, alias);

    nuevo->expr = malloc(sizeof(char) * (strlen(expr) + 1));
    strcpy(nuevo->expr, expr);

    nuevo->resultado = resultado;

    return nuevo;
}


/*
 * Crea una copia física de la operación.
 * */
Operacion* operacion_copiar(Operacion *op)
{
    Operacion* copia = operacion_crear(op->alias, op->expr, op->resultado);
    
    return copia;
}


//Sin hacer
/*
 * Evalúa la expresión de la operación.
 * */
int operacion_evaluar(Operacion *op)
{
    
}


/*
 * Dadas 2 operaciones, las compara según su alias, siguiendo el mismo
 * criterio que la función strcmp: devuelve
 * -1 si op1->alias < op2->alias,
 * 0 si op1->alias == op2->alias,
 * 1 si op1->alias > op2->alias.
 * */
int operacion_comparar(Operacion *op1, Operacion *op2)
{
    return strcmp(op1->alias, op2->alias);
}


//Sin hacer
/*
 * Imprime la expresión de la operación, con notación infija.
 * */
void operacion_imprimir(Operacion *op)
{
    
}


/*
 * Destruye la operación, liberando la memoria dinámica.
 * */
void operacion_destruir(Operacion *op)
{
    free(op->alias);
    
    free(op->expr);
    
    free(op);
}






