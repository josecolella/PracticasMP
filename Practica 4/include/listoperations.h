/*****************
*
* Fichero: listoperations.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero repreenta las funciones
* del ejercicio 2, y lo he denominado  listoperations.h debido a 
* que todas las funciones declaradas son operaciones que se pueden
* efectuar sobre las listas.
*
*****************/

#include "listnode.h"
#include "math.h"

#ifndef _LISTOPERATIONS_H_
#define _LISTOPERATIONS_H_

///La funcion getNumLinkedNodes nos devuelve el numeero de celda enlazadas
int getNumLinkedNodes(t_node *);
///La funcion de getMean calcula la media de los datos almacenados
double getMean(t_node *);
/**La funcion getVariance devuelve la varianza de los datos almacenados
* Esta funcion usa la funcion power para poder calcular la varianza de los datos
* La formula para el calculo de la varianza es 1/N summation (x - mean) ^2
*/
double getVariance(t_node *);

#endif
