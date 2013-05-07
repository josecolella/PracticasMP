/***********************
*
* Fichero: Lista.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero especifico los algoritmos de los
* prototipos declarados para la clase Lista.
*
************************/



#include "Lista.h"
#include <iostream>

using namespace std;

//Metodos privados
void Lista :: insertNodes(TipoBase dataToInsert, int pos)
{
	Node *newNode,*tmp;
	int i;
	
	newNode = new Node();

	if(newNode != NULL)
	{
		newNode->setData(dataToInsert) ;
		newNode->setNext(NULL);

		//Dos condiciones: Si la lista esta vacia, o insertar al final
		if(listHead == NULL)
			listHead = newNode;
		else if(pos == 1)
		{
			newNode ->setNext(listHead);
			listHead = newNode;
		}
		else if(pos < size)
		{
			for(i=0,tmp = listHead;i != pos -2 && tmp->getNext()!= NULL;tmp = tmp->getNext(), i++);
				Node *aux = tmp->getNext();
			tmp->setNext(newNode);
			newNode->setNext(aux);
		}
		else //Que se inserte al final
			for(tmp = listHead;tmp->getNext()!= NULL;tmp = tmp->getNext());
				tmp -> setNext(newNode);
			this->size++;
		}


	}

	void Lista :: Copia(const Lista & otro)
	{
		Node *ptr = otro.listHead;
		this->size = otro.size;

		for(int i=0;i<this->size && ptr!= NULL;i++, ptr = ptr -> getNext())
			insertNodes(ptr->getData(),this->size);
	}

	void Lista :: LiberaMemoria(void)
	{
		Node *deleteNode;

		if(listHead != NULL)
		{
			while(listHead->getNext() != NULL)
			{
				deleteNode = listHead;
				listHead = listHead ->getNext();
				delete deleteNode;
			}
		}

		listHead = 0;
	}

	Lista :: Lista() 
	{
	//Crea una lista vacia
		listHead = NULL;
		this->size = 0;
	}

	Lista :: Lista(int numNodes)
	{
		size = 0;

		for(int i=0;i<numNodes;i++)
			insertNodes(0,numNodes);
		this->size = numNodes;
	}

	Lista :: Lista(int numNodes, TipoBase defaultValue)
	{
		size = 0;

		for(int i=0;i<numNodes;i++)
			insertNodes(defaultValue,numNodes);
		this->size = numNodes;
	}


//Constructor de Copia
	Lista :: Lista(const Lista & otro)
	{
		Copia(otro);
	}



	Lista& Lista :: operator= (const Lista & otro)
	{
	if(this != &otro) //Evitar Autoasignacion
	{
		LiberaMemoria();	
		Copia(otro);
	}

	return (*this); //devuelve el objeto implicito
}


//Destructor
Lista :: ~Lista()
{
	LiberaMemoria();
}

//Metodos
bool Lista :: isEmpty() const
{
	return listHead == NULL ? true : false;
}

int Lista :: getNumNodes() const
{
	return size;
}

void Lista :: Insertar(TipoBase val, int pos)
{
	insertNodes(val,pos);
}

void Lista :: Borrar(int pos)
{
	if(pos < size)
	{
		Node *tmp,*deleteNode;
		int i;
		
		if(listHead->getNext() == NULL) //Si tienemos que eliminar el primer elemento
		{
			tmp = listHead;
			listHead = listHead -> getNext();
		}
		else{
			for(i=0,tmp = listHead, deleteNode = listHead->getNext(); deleteNode!= NULL; tmp = tmp->getNext(),deleteNode = deleteNode -> getNext(),i++)
				if(i == pos - 2)
					tmp->setNext(deleteNode -> getNext());
			}	
			this->size--;
		}
		else
			cerr << "El parametro es invalido" << endl;

	}

	TipoBase Lista :: ObtenerValor(int pos) const
	{
		int i;
		Node *tmp;

		if(pos < size){
			for(i=0, tmp = listHead;i != pos - 1 && tmp != NULL;i++,tmp = tmp ->getNext());
				return tmp->getData();
		}
		else
			cerr << "El parametro es invalido" << endl;
	}

	void Lista :: PonerValor(int pos, TipoBase val)
	{
		insertNodes(val,pos);
	}

	bool Lista :: isContained(TipoBase data)
	{
		Node *tmp;
		bool isContained;

		for(tmp = listHead, isContained = false;tmp != NULL && !isContained; tmp = tmp ->getNext())
			if(tmp->getData() == data)
				isContained = true;

			return isContained;

	}
	void Lista :: printList() const
	{
		Node *tmp;
		int i;

		for(i=0,tmp = listHead; tmp != NULL; tmp = tmp -> getNext(),i++)
			cout << "Valor en " << "[" << i+1 << "]: " << tmp->getData() << endl;
	}

Node * Lista :: getListHead() const
{

	return this->listHead;
}