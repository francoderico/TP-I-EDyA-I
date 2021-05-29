#ifndef __OPERADORES_H__
#define __OPERADORES_H__





typedef int (*FuncionEvaluacion)(int *args);

int suma(int *args);

int resta(int *args);

int opuesto(int *args);

int producto(int *args);

int division(int *args);

int modulo(int *args);

int potencia(int *args);


typedef struct Operador {
  char *simbolo;
  int aridad;
  FuncionEvaluacion eval;
  struct Operador *sig;
} Operador;

typedef Operador *TablaOps;

TablaOps tablaOps_crear();

void  cargaroperador (TablaOps *tabla, char *simbolo, int aridad , FuncionEvaluacion  eval );

#endif /** __OPERADORES_H__ */
