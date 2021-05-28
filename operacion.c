#include "operacion.h"
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







