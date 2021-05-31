#include "glist.h"
//#include "operacion.h"
#include "operadores.h"
#include "struct_operador.h"
#include "tablaops.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){
    
    TablaOps tabla = tablaOps_crear();
    
    
    char* sim = malloc(sizeof(char) * 2);
    
    sim[0] = '+'; sim[1] = '\0';
    
    cargar_operador(&tabla, sim, 2, suma);
    
    
    sim[0] = '-'; //sim[1] = '\0';
    
    cargar_operador(&tabla, sim, 2, resta);
    
    free(sim);
    
    
    sim = malloc(sizeof(char) * 3);
    
    sim[0] = '-'; sim[1] = '-'; sim[2] = '\0';
    
    cargar_operador(&tabla, sim, 1, opuesto);
    
    free(sim);
    
    
    sim = malloc(sizeof(char) * 2);
    
    sim[0] = '*'; sim[1] = '\0';
    
    cargar_operador(&tabla, sim, 2, producto);
    
    
    sim[0] = '/'; //sim[1] = '\0';
    
    cargar_operador(&tabla, sim, 2, division);
    
    
    sim[0] = '%'; //sim[1] = '\0';
    
    cargar_operador(&tabla, sim, 2, modulo);
    
    free(sim);
    
    
    
    
    int* a = malloc(sizeof(int) * 2);
    
    a[0] = 19; a[1] = 6;
    
    TablaOps otra = tabla;
    
    while(! tablaOps_vacia(otra))
    {
        printf("%d\n", ((Operador*)(otra->dato))->eval(a));
        
        otra = otra->sig;
    }
    
    
    free(a);
    
    tablaOps_destruir(tabla);
    
    return 0;
}





