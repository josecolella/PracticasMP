/****************************************
*
* Fichero: dvectoroperations.h
* Autor: Jose Miguel 
* Descripcion: Las funciones declaradas en este fichero corresponden
* a las funciones necesarias para completar el ejercicio 7.
* Se han declarador tres funciones alloc auxiliares para insertar 
* en nuestro vector dinamico desde un teclado, y con una lista como
* parametro
*
*****************************************/


#include "listnode.h"

#ifndef _DVECTOROPERATIONS_H_
#define _DVECTOROPERATIONS_H_

///Esta funcion amplia por una casilla el vector dinamico
double *alloc_una_casilla(double *array, int size);
///Esta funcion amplia por n casillas el vector dinamico
double *alloc_n_casillas(double *array, int n, int size);
///Esta funcion duplica el tamaño de nuestro vector
double *alloc_double_size_casillas(double *array, int size);
/*Esta funcion inserta un valor nuevo en nuestro array dinamico.
* Si nuestro indice actual es igual al tamagno del vector, se amplia
* el vector 
*/
double *insertKeyboardValue(double *array, int size, int currentIndex,double newValue);
/* Tomando una lista como parametro, insertamos en nuestro array
* los valores de la lista en el array
*/
double *insertFromList(double * array, int size, int currentIndex, t_node *list);

//Funcion para imprimir los valores del vector
void printDVector(double *array, int size);
#endif
