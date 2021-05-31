#include "struct_operador.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
 * Crea un nuevo operador con los parámetros dados.
 * */
Operador* operador_crear(char *simbolo, int aridad, FuncionEvaluacion eval)
{
    Operador* nuevo = malloc(sizeof(Operador));

    nuevo->simbolo = malloc(sizeof(char) * (strlen(simbolo) + 1));
    strcpy(nuevo->simbolo, simbolo);

    nuevo->aridad = aridad;
    
    nuevo->eval = eval;

    return nuevo;
}


/*
 * Crea una copia física del operador.
 * */
Operador* operador_copiar(Operador *op);
{
    Operador* copia = operador_crear(op->simbolo, op->aridad, op->eval);
    
    return copia;
}


/*
 * Dados 2 operadores, los compara según su símbolo, siguiendo el mismo
 * criterio que la función strcmp: devuelve
 * -1 si op1->simbolo < op2->simbolo, 
 * 0 si op1->simbolo == op2->simbolo,
 * 1 si op1->simbolo > op2->simbolo.
 * */
int operador_comparar(Operador *op1, Operador *op2);
{
    return strcmp(op1->simbolo, op2->simbolo);
}


/*
 * Destruye el operador, liberando la memoria dinámica.
 * */
void operador_destruir(Operador *op)
{
    free(op->simbolo);
    
    free(op);
}

