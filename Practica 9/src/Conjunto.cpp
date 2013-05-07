#include <iostream>
#include "Conjunto.h"

using namespace std;


void Conjunto :: Copia(const Conjunto & otro)
{
	//Creamos el mismo set
	set = otro.set;

}

void Conjunto :: LiberaMemoria()
{
	delete set;
}

//Constructor
Conjunto :: Conjunto()
{
	set = NULL;
}

Conjunto :: Conjunto(TipoBase data)
{
	//Creamos un conjunto
	set = new Lista(1,data);
}
		//Constructor de Copia
Conjunto :: Conjunto(const Conjunto &otro)
{
	Copia(otro);
	
}


		//Destructor
Conjunto :: ~Conjunto()
{

	LiberaMemoria();

}

//metodos
bool Conjunto :: isEmpty() const
{
	return set == NULL ? true : false;
}

Conjunto& Conjunto   :: operator= (const Conjunto &otro)
{
	if(this != &otro) //Evitar Autoasignacion
	{
		LiberaMemoria();	
		Copia(otro);
	}

	return (*this); //devuelve el objeto implicito

}

int Conjunto :: getNumSetElements() const
{
	return this->set->getNumNodes();
}

bool Conjunto ::  isContained(TipoBase data) const
{
	
	return this->set->isContained(data);

}

void Conjunto :: printSet() const
{

	this->set->printList();
}