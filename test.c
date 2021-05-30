#include "glist.h"
#include "operacion.h"
#include "operadores.h"
#include "struct_operador.h"
#include "tablaops.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main(){
    
    
    TablaOps tabla = tablaOps_crear();
    
    cargar_operador(&tabla, '+', 2, suma);
    
    
    tablaOps_destruir(tabla);
    
    return 0;
}





