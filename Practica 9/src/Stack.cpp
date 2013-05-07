/*****************************
 * 
 * Fichero: Stack.cpp
 * Autor: Jose Miguel Colella
 * Descripcion: En este fichero defino los algoritmos para 
 * el constructor, destructor y metodos de la clase Stack
 * 
 ****************************/ 




#include "Stack.h"

using namespace std;


//Metodos Privados
//This auxiliary function creates a node
Node * Stack :: createNode(TipoBase data)
{
	Node *newNode = new Node();
	newNode->setData(data);
	newNode->setNext(NULL);

	return newNode;
}


void Stack :: Copia(const Stack & otro)
{
	
	Node *ptrToOtro = otro.stackHead;
	this->size = otro.size;

	while(ptrToOtro != NULL)
	{

		//Tenemos el nodo que se va a insertar
		Node *newStackNode = createNode(ptrToOtro->getData());

		if(this->stackHead == NULL)
			stackHead = newStackNode;
		else
		{
			Node *tmp = stackHead;
			newStackNode->setNext(tmp);
			stackHead = newStackNode;
		}
		this->size++;
		ptrToOtro = ptrToOtro->getNext();
	}
}

void Stack :: LiberaMemoria()
{
	
	Node *deleteNode;

	if(this->stackHead != NULL)
	{
		while(this->stackHead->getNext() != NULL)
		{
			deleteNode = stackHead;
			stackHead = stackHead ->getNext();
			delete deleteNode;
		}
	}
	
	stackHead = 0;
	
}

//Constructor
Stack :: Stack()
{
	this->stackHead = NULL;
	this->size = 0;
}

//Constructor de Copia
Stack :: Stack(const Stack & otro)
{
	Copia(otro);
}

//Sobrecarga de operador de asignacion
Stack& Stack :: operator= (const Stack & otro)
{
	if(this != &otro){
		LiberaMemoria();
		Copia(otro);
	}

	return (*this);

}

ostream & operator << (ostream &out, const Stack &otro)
{
	Node *tmp;
	int i;
	
	for(i=0,tmp = otro.getStackHead(); tmp != NULL; tmp = tmp -> getNext(),i++)
		out << "Valor en " << "[" << i+1 << "]: " << tmp->getData() << endl;

	return out;
}

//Destructor
Stack :: ~Stack()
{
	LiberaMemoria();	
}

bool Stack :: isEmpty() const
{
	return size == 0 ? true: false;
	
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

Node * Stack :: getStackHead() const
{
	return this->stackHead;
}
