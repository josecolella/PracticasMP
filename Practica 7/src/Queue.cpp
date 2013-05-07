/*****************************
 * 
 * Fichero: Queue.cpp
 * Autor: Jose Miguel Colella
 * Descripcion: En este fichero defino los algoritmos para 
 * el constructor, destructor y metodos de la clase Queue
 * 
 ****************************/ 



#include <iostream>
#include "Queue.h"

using namespace std;


//Constructor
Queue :: Queue()
{
	this->queueHead = NULL;
	this->size = 0;
}

//Destructor
Queue :: ~Queue()
{
	Node *deleteNode;

	if(queueHead != NULL)
	{
		while(queueHead->getNext() != NULL)
		{
			deleteNode = queueHead;
			queueHead = queueHead ->getNext();
			deleteNode->~Node();
		}
	}
	
	queueHead = 0;
	
}

bool Queue :: isEmpty() const
{
	return queueHead == NULL ? true: false;
	
}

//El elemento se coloca al final de la cola
void Queue :: enqueue(TipoBase data)
{
	Node *newQueueNode,*tmp;
	
	newQueueNode = new Node();
	
	newQueueNode->setData(data);
	
	if(queueHead == NULL)
		queueHead = newQueueNode;
	else
	{
		for(tmp = queueHead;tmp->getNext() != NULL;tmp = tmp->getNext());	
			tmp->setNext(newQueueNode);
	}
	this->size++;
	
}

//El primer elemento de la cola se elimina, y obtenemos el elemento extraido 
TipoBase Queue :: dequeue()
{
	if(size > 0)
	{
		TipoBase entityDestroy;
		entityDestroy = queueHead->getData();
		
		queueHead = queueHead->getNext();
		//Se elimina el ultimo elemento insertado
		
		this->size--;
		return entityDestroy;
		
	}
	else
		cerr << "Stack underflow: No hay mas elementos" << endl;
	
	
}

TipoBase Queue :: front() const
{
	return queueHead->getData();
}

void Queue :: printQueue() const
{
	Node *tmp;
	int i;
	
	for(i=0,tmp = queueHead; tmp != NULL; tmp = tmp -> getNext(),i++)
		cout << "Valor en " << "[" << i+1 << "]: " << tmp->getData() << endl;
}
