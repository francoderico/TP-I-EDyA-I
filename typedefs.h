#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__

typedef void (*FuncionVisitante) (void *dato);

typedef void (*FuncionDestructora) (void *dato);

typedef void *(*FuncionCopia) (void *dato);

typedef int (*FuncionComparadora) (void *dato1, void *dato2);

typedef int (*Predicado) (void *dato);


#endif                          /* __TYPEDEFS_H__ */
