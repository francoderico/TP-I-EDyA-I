//Para implementar la parte a) del intérprete
//Es un borrador

typedef struct _Op
{
    char *alias;
    char *expr; //Ver si es mejor guardar la string (5 -- 2 3 +) o el árbol
} Op;


//Ver en qué archivo va y todo eso (contacto.h)
int comparar_op(void *a, void *b)
{
    return strcmp(a->alias, b->alias);
}


//Ver en qué archivo va y todo eso (contacto.h)
void* copiar_op(void *a)
{
    
}


while(palabra != salir)
{
    if(palabra == "imprimir")
    {
        scanf(ALIAS)
        
        Op *a = bstree_buscar(operaciones, ALIAS, comparar_op); //Está bien, porque comparo solo los ->alias
        
        //imprimo
    }
    else if(palabra == "evaluar")
    {
        scanf(ALIAS)
        
        Op *a = bstree_buscar(operaciones, ALIAS, comparar_op); //Está bien, porque comparo solo los ->alias
        
        //evalúo
    }
    else
    {
        //Si llegué acá, es porque la palabra es un ALIAS
        
        Op *a = op_crear(); //También puedo poner *Op en el typedef y hacer directamente a = op_crear()
        
        a->alias = palabra;
        
        scanf(=), scanf(EXPR);
        
        a->expr = EXPR;
        
        operaciones = bstree_insertar(operaciones, (void*)a, copiar_op, comparar_op);
        
        op_destruir(a);
        
        //listo
    }
    
}










