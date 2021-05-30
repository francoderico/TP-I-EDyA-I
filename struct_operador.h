#ifndef __OPERADOR_H__
#define __OPERADOR_H__

typedef int (*FuncionEvaluacion)(int *args);

typedef struct _Operador {
  char *simbolo;
  int aridad;
  FuncionEvaluacion eval;
} Operador;

/*
 * Crea una nueva operación con los parámetros dados.
 * */
Operador* operador_crear(char *simbolo, int aridad, FuncionEvaluacion eval);

/*
 * Crea una copia física de la operación.
 * */
Operador* operador_copiar(Operador *op);

/*
 * Dadas 2 operaciones, las compara según su alias, siguiendo el mismo
 * criterio que la función strcmp: devuelve
 * -1 si op1->alias < op2->alias, 
 * 0 si op1->alias == op2->alias,
 * 1 si op1->alias > op2->alias.
 * */
int operador_comparar(Operador *op1, Operador *op2);

/*
 * Destruye la operación, liberando la memoria dinámica.
 * */
void operador_destruir(Operador *op);




#endif /** __OPERADOR_H__ */
