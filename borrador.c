//Para implementar la parte a) del intérprete
//Es un borrador


//Ver en qué archivo va y todo eso (contacto.h)
int f_operacion_comparar(void *op1, void *op2)
{
    return operacion_comparar((Operacion*)op1, (Operacion*)op2);
}


//Ver en qué archivo va y todo eso (contacto.h)
void* f_operacion_copiar(void *op)
{
    return operacion_copiar((Operacion*)op);
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










