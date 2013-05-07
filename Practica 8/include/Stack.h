/**************************
 * 
 * Fichero: Stack.h
 * Autor: Jose Miguel Colella
 * Descripcion: Este fichero contiene los prototipos
 * de la estructura de datos conocida como la Pila.
 * "La pila es una estructura de datos que permite la gestion de problemas
 * en los que la gestion se realiza empleando un protocolo LIFO. La pila tiene tres operaciones: push, pop, peek. El metodo push agrega una entidad 
 * a la pila. Pop elimina la ultima entidad insertada en la Pila. 
 * Top es un metodo que deja ver que elemento esta 
 * encima de la pila
 **********************************/

#include "Node.h"

#ifndef _STACK_H_
#define _STACK_H_

	class Stack{
		
		private:
			Node *stackHead;
			int size;
			Node *createNode(TipoBase data);
			void Copia(const Stack & otro);
			void LiberaMemoria();
		public:
			//Constructor
			Stack();
			//Constructor de Copia
			Stack(const Stack & otro);
			//Sobrecarga de operadores
			Stack& operator=(const Stack & otro);
			//Destructor
			~Stack();
			//Metodo
			bool isEmpty() const;
			void push(TipoBase data);
			TipoBase pop();
			TipoBase top() const;
			void printStack() const;

	};


#endif
