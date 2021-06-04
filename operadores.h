#ifndef __OPERADORES_H__
#define __OPERADORES_H__

typedef int (*FuncionEvaluacion) (int *args);  //Esta definido esto? no lo encontré por ningun lado. 

int suma(int *args);

int resta(int *args);

int opuesto(int *args);

int producto(int *args);

int division(int *args);

int modulo(int *args);

int potencia(int *args);


#endif /** __OPERADORES_H__ */
