/*********************
*
* Fichero: basiclistio.h
* Autor: Jose Miguel Colella 
* Descripcion: Este fichero represetna las funciones del ejercicio 1
* donde se leen y almacenan los datos, ademas mostrando el contenido 
* de la lista.
* 
* 
**********************/

#include "listnode.h"

#ifndef _BASICLISTIO_H_
#define _BASICLISTIO_H_

/**La funcion de insert sirve para la allocacion de memoria, y 
* la consecuente creacion del nuevo nodo para insertarlo en la lista 
* 
* @returns puntero a la cabecera de la nueva lista con el nuevo elemento al final	
*/
t_node *insert(t_node *, double);

/**La funcion de leer_insertar_valores usa la funcion de insert mas 
* controles sobre los datos de ingreso; por ejemplo, si el dato es negativo
* 
* @returns lista con valores no negativos
*/
t_node *leer_insertar_valores();

///La funcion de printList sirve para mostrar el contenido de la lista
void printList(t_node *);

///La funcion deleteList borra la lista y libera los recursos en la heap
t_node *deleteList(t_node *list);
#endif
