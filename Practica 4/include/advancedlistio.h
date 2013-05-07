/***************************
*
* Fichero: advancedlistio.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero contiene funciones relevante al ejercicio 5.
* Contiene la funcion para una insercion organizada en la lista y para 
* la eliminacion de un elemento de la lista
*
****************************/

#include "listnode.h"

#ifndef _ADVANCEDLISTIO_H_
#define _ADVANCEDLISTIO_H_

/**
* La funcion organized_insert inserta los elementos dentro de la lista 
* en manera organizada
* 
* @returns puntero a la cabeza de la nueva lista que incluye el valor inserta en manera organizada
*/
t_node *organized_insert(t_node *, double);

/** La funcion leer_insertar_organizado_valores usa controles sobre los valores insertados.
* Por ejemplo, si el valor es negativo, se para de insertar. Esta funcion usa la funcion organized_insert para insertar 
* los valores
* 
* @returns lista organizada 
*/
t_node *leer_insertar_organizado_valores();

/**La funcion delete_element elimina el elemneto double indicado 
* como parametro.
* 
* @returns lista organizada sin el valor double indicado
*/
t_node *delete_element(t_node *, double);


#endif