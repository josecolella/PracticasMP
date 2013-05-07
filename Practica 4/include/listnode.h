/*******************
*
* Fichero: listnode.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero es una abstracion de una celda enlazada
* que compone nuestra lista. La lista esta creada de celda que
* contienen un valor double y un puntero que apunta a la proxima
* celda de la lista
*
********************/


#ifndef _LISTNODE_H_
#define _LISTNODE_H_

/**Introduzco un typedef para el tipo double debido a que 
*si cambiamos el tipo double, ya se difunde el cambio por
*todas las funciones creadas. Abstraemos sobre el tipo para
*que los nodos puedan contener cualquier tipo*/
typedef double TipoData;

typedef struct node
{
	TipoData data;
	struct node *next;
	
}t_node;


#endif
