/******************************
 * 
 * Fichero: Queue.h
 * Autor: Jose Miguel Colella
 * Descripcion: En este fichero declaramos los prototipos
 * de la clase Queue. Una cola es una estructura de datos que emplea
 * un protocolo FIFO. Esto significa que emplea tres
 * metodos: enqueue, dequeue, y front. Enqueue empuja un elemento al final de la cola
 * Dequeue quita el primer elemento de la cola.
 * Front: devuelve el primer elemento de la cola
 *
 ********************************/

#include "Node.h"

#ifndef _QUEUE_H_
#define _QUEUE_H_

class Queue
{
	private:
		Node *queueHead;
		int size;
		Node *createNode(TipoBase data);
		void Copia(const Queue & otro);
		void LiberaMemoria();
	public:
		//Constructor
		Queue();
		//Constructor de Copia
		Queue(const Queue & otro);
		//Sobrecarga del operador de asignacion
		Queue& operator= (const Queue & otro);
		//Destructor
		~Queue();
		//Metodos
		bool isEmpty() const;
		void enqueue(TipoBase data);
		TipoBase dequeue();
		TipoBase front() const;
		void printQueue() const;
};


#endif
