#include "operadores.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Devuelve la suma entre 2 números.
 * */
int suma(int *args) {
    return args[0] + args[1];
}


/*
 * Devuelve la resta entre 2 números.
 * */
int resta(int *args) {
    return args[0] - args[1];
}


/*
 * Devuelve el opuesto de un número.
 * */
int opuesto(int *args) {
    return -args[0];
}


/*
 * Devuelve el producto entre 2 números.
 * */
int producto(int *args) {
    return args[0] * args[1];
}


/*
 * Devuelve la división entera entre 2 números.
 * */
int division(int *args) {
    
    if(args[1] == 0)
    {
        printf("¡Usted está dividiendo por 0! Esto es matemáticamente incorrecto.\n");
        
        return 2147483647;  //2^31 - 1, el mayor int posible
    }
    
    return args[0] / args[1];
}


/*
 * Devuelve el resto de un número en la división por el segundo.
 * */
int modulo(int *args) {
    return args[0] % args[1];
}


/*
 * Devuelve el resultado de elevar un número al segundo.
 * */
int potencia(int *args)
{
    int ret = 1;
    
    for(int i = 0; i < args[1]; i ++)
    {
        ret *= args[0];
    }
    
    if(args[0] == 0 && args[1] == 0)
    {
        printf("¡Usted está elevando 0 a la 0! Esto es matemáticamente incorrecto.\n");
    }
    
    return ret;
}
