//Para implementar la parte a) del intérprete
//Es un borrador

typedef struct _Operacion
{
    char *alias;
    char *expr; //Ver si es mejor guardar la string (5 -- 2 3 +) o el árbol
    int resultado;
} Operacion;


//Ver en qué archivo va y todo eso (contacto.h)
int comparar_operacion(void *a, void *b)
{
    return strcmp(a->alias, b->alias);
}


//Ver en qué archivo va y todo eso (contacto.h)
void* copiar_operacion(void *a)
{
    
}


while(palabra != salir)
{
    if(palabra == "imprimir")
    {
        scanf(ALIAS)
        
        Operacion *a = bstree_buscar(operaciones, ALIAS, comparar_op); //Está bien, porque comparo solo los ->alias
        
        //imprimo
    }
    else if(palabra == "evaluar")
    {
        scanf(ALIAS)
        
        Operacion *a = bstree_buscar(operaciones, ALIAS, comparar_op); //Está bien, porque comparo solo los ->alias
        
        //evalúo
    }
    else
    {
        //Si llegué acá, es porque la palabra es un ALIAS
        
        Operacion *a = op_crear(); //También puedo poner *Op en el typedef y hacer directamente a = op_crear()
        
        a->alias = palabra;
        
        scanf(=), scanf(EXPR);
        
        a->expr = EXPR;
        
        operaciones = bstree_insertar(operaciones, (void*)a, copiar_op, comparar_op);
        
        operacion_destruir(a);
        
        //listo
    }
    
}










