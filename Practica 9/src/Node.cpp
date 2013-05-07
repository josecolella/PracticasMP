/**************************
*
* Fichero: Node.cpp
* Autor: Jose Miguel Colella
* Descripcion: Este fichero define los metodos para el objeto conocido como Node
* Basicamente tiene metodos get/set para los atributos privados
*
*************************/



#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node()
{
	data = 0;
	next = NULL;
}

Node :: ~Node()
{
	delete next;
	next = 0;
}

void Node :: setData(TipoBase data) 
{
	this->data = data;
}

TipoBase Node :: getData() const
{
	return this->data;
}

void Node :: setNext(Node *nextNode)
{
	next = nextNode;
}

Node * Node :: getNext() const
{

	return next;
}

