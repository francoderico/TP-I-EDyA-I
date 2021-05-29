#include "operadores.h"
#include <stdlib.h>
#include <math.h>


/* No me funciona una cosita que ya estoy viendo pero lo voy subiendo*/


/*
 * Devuelve la suma entre 2 números.
 * */
int suma(int *args)
{
    return args[0] + args[1];
}


/*
 * Devuelve la resta entre 2 números.
 * */
int resta(int *args)
{
    return args[0] - args[1];
}


/*
 * Devuelve el opuesto de un número.
 * */
int opuesto(int *args)
{
    return -args[0];
}


/*
 * Devuelve el producto entre 2 números.
 * */
int producto(int *args)
{
    return args[0] * args[1];
}


/*
 * Devuelve la división entera entre 2 números.
 * */
int division(int *args)
{
    return args[0] / args[1];
}


/*
 * Devuelve el resto de un número en la división por el segundo.
 * */
int modulo(int *args)
{
    return args[0] % args[1];
}


/*
 * Devuelve el resultado de elevar un número al segundo.
 * */
int potencia(int *args)
{
    return pow(args[0], args[1]);   //Chequear esto con los casts y eso.
}

/*
 * Crea una tabla de operadores vacìa.
*/

TablaOps tablaOps_crear() {
  return NULL;
}

/*
 * Carga un operador a la Tabla de Operadores.
*/
void  cargaroperador (TablaOps ∗tabla, char ∗simbolo, int aridad , FuncionEvaluacion  eval )
{
	Operador *nuevoOperador = malloc(sizeof(Operador));
	nuevoOperador->simbolo = simbolo;
	nuevoOperador->aridad = aridad;
	nuevoOperador->eval = eval;
	nuevoOperador->sig = tabla;
}



