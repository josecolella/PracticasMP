/***********************************
*
* Fichero: mergelist.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero cabecera representa la funcion 
* del ejercicio 6 que tomando dos listas como parametro 
* nos devuelve una lista fusionada con los datos de las dos listas
* puestas como parametro
*
***********************************/

#ifndef _MERGELIST_H_
#define _MERGELIST_H_

/**
* Esta funcion fusiona las dos listas que son parametros, y 
* las une en una lista ordenada
* 
* @returns puntero a lista fusionada
*/
t_node *merge_sorted_lists(t_node *list1, t_node *list2);

#endif