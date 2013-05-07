/********************
 * 
 * Fichero: Node.h
 * Autor: Jose Miguel Colella
 * Descripcion: En este fichero declaro los prototipos para 
 * la clase Node. Este clase es un atributo de la clase Lista.
 * La clase Node no tiene sentido usarse sola porque 
 * representa in nodo de una lista, o de otras estructuras de datos
 *
 ********************/


typedef int TipoBase ; 

#ifndef _NODE_H_
#define _NODE_H_

class Node
{
	private:
		TipoBase data;
		Node *next; //Esto es el puntero que apunta al siguiente nodo
	public:
		//Cdonstructor
		Node();
		//Destructor
		~Node();
		void setData(TipoBase data);
		TipoBase getData() const;
		void setNext(Node *nextNode);
		Node *getNext() const;
};


#endif
