/***************************
*
* Fichero: listsort.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero contiene la funcion del ejercicio3.
* Determina si una lista esta ordenada. 
* Ademas tenemos las funciones que son parte del ejercicio 4 donde
* tenemos que hacer la ordenacion por selection sort.

*
**************************/

#include "listnode.h"

#ifndef _LISTSORT_H_
#define _LISTSORT_H_

//Esta funcion regresa si la lista puesta como parametro esta ordenada
bool isListOrdered(t_node *list);
//Esta funcion es una funcion auxiliar que se usa en la fucnion selection_sort
void swap(double *num1, double *num2);
/** 
* La funcion selection_sort ordena la lista que se usa como parametro
* usando el criterio de selection_sort que consigue el elemento minimo y
* lo intercambia con el indice actual. Este algoritmo tiene eficiencia O(n^2)
*
* @returns puntero a la lista ordenada
*/
t_node *selection_sort(t_node *list);

#endif