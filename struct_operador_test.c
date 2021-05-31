//#include "glist.h"
//#include "operacion.h"
//#include "operadores.h"
#include "struct_operador.h"
//#include "tablaops.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int suma(int *args)
{
    return args[0] + args[1];
}



int main(){
    
    char* sim = malloc(sizeof(char) * 2);
    
    sim[0] = '+'; sim[1] = '\0';
    
    Operador* nuevo = operador_crear(sim, 2, suma);
    
    free(sim);
    
    int* a = malloc(sizeof(int) * 2);
    
    a[0] = 5; a[1] = 10;
    
    printf("%d\n", nuevo->eval(a));
    
    free(a);
        
    operador_destruir(nuevo);
    
    return 0;
}





