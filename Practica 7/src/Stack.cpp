/*****************************
 * 
 * Fichero: Stack.cpp
 * Autor: Jose Miguel Colella
 * Descripcion: En este fichero defino los algoritmos para 
 * el constructor, destructor y metodos de la clase Stack
 * 
 ****************************/ 



#include <iostream>
#include "Stack.h"

using namespace std;


//Constructor
Stack :: Stack()
{
	this->stackHead = NULL;
	this->size = 0;
}

//Destructor
Stack :: ~Stack()
{
	Node *deleteNode;

	if(stackHead != NULL)
	{
		while(stackHead->getNext() != NULL)
		{
			deleteNode = stackHead;
			stackHead = stackHead ->getNext();
			deleteNode->~Node();
		}
	}
	
	stackHead = 0;
	
}

bool Stack :: isEmpty() const
{
	return stackHead == NULL ? true: false;
	
}

//El elemento va a final de la pila
void Stack :: push(TipoBase data)
{
	Node *newStackNode;
	
	newStackNode = new Node();
	
	newStackNode->setData(data);
	
	if(stackHead == NULL)
		stackHead = newStackNode;
	else
	{
		Node *tmp = stackHead;
		newStackNode->setNext(tmp);
		stackHead = newStackNode;
	}
	this->size++;
	
}

//El ultimo elemento insertado se elimina y obtenemos el elemento extraido
TipoBase Stack :: pop()
{
	if(size > 0)
	{
		Node *tmp;
		TipoBase entityDestroy;
		entityDestroy = stackHead->getData();
		
		if(stackHead->getNext() == NULL) //Si tienemos que eliminar el primer elemento
		{
			tmp = stackHead;
			stackHead = stackHead -> getNext();
		}
		else{
			for(tmp = stackHead;tmp->getNext()->getNext() != NULL;tmp = tmp->getNext());
				tmp->getNext()->~Node();
				tmp->setNext(NULL);
		
		}
			
		this->size--;
		return entityDestroy;
	}
	else
		cerr << "Stack underflow: No hay mas elementos" << endl;
	
	
}

TipoBase Stack :: top() const
{
	return stackHead->getData();
}

void Stack :: printStack() const
{
	Node *tmp;
	int i;
	
	for(i=0,tmp = stackHead; tmp != NULL; tmp = tmp -> getNext(),i++)
		cout << "Valor en " << "[" << i+1 << "]: " << tmp->getData() << endl;
}
