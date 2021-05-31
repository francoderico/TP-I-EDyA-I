#ifndef __OPERADOR_H__
#define __OPERADOR_H__

typedef int (*FuncionEvaluacion)(int *args);

typedef struct _Operador {
  char *simbolo;
  int aridad;
  FuncionEvaluacion eval;
} Operador;

/*
 * Crea un nuevo operador con los parámetros dados.
 * */
Operador* operador_crear(char *simbolo, int aridad, FuncionEvaluacion eval);

/*
 * Crea una copia física del operador.
 * */
Operador* operador_copiar(Operador *op);

/*
 * Dados 2 operadores, los compara según su símbolo, siguiendo el mismo
 * criterio que la función strcmp: devuelve
 * -1 si op1->simbolo < op2->simbolo, 
 * 0 si op1->simbolo == op2->simbolo,
 * 1 si op1->simbolo > op2->simbolo.
 * */
int operador_comparar(Operador *op1, Operador *op2);

/*
 * Destruye el operador, liberando la memoria dinámica.
 * */
void operador_destruir(Operador *op);




#endif /** __OPERADOR_H__ */
