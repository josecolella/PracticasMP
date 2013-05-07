/**************************
*
* Fichero: VectorDinamico.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero especifico los algoritmos para la clase
* VectorDinamico
*************************/


#include <iostream>
#include <string.h> //Usamos para poder usar memcpy()
#include "VectorDinamico.h"

using namespace std;


//private method
/**
* El metodo initializeVector() es privado y es usado para inicializar los 
* elementos del vector a 0
*/
void VectorDinamico :: initializeVector()
{
	for(int i=0;i<size;i++)
		*(dynamicVector+i) = 0;
}

/**
* El metodo initializeVector() es privado y es usado para inicializar los 
* elementos del vector a numToInitialize
*/
void VectorDinamico :: initializeVector(int numToInitialize)
{
	for(int i=0;i<size;i++)
		*(dynamicVector+i) = numToInitialize;
}

void VectorDinamico :: Copia(const VectorDinamico &otro)
{
	this->size = otro.size;
	this->arrayIndex = otro.arrayIndex;

	//La memoria dinamica no se puede asignar con = debido a que apuntara a la memoria
	dynamicVector = new int[size];

	for(int i=0;i<size;i++)
		*(dynamicVector + i) = otro.dynamicVector[i];



}

void VectorDinamico :: PideMemoria (int n)
{
	dynamicVector = new int[n];
}

void VectorDinamico :: LiberaMemoria(void)
{
	delete[] dynamicVector;
	dynamicVector = NULL;
}


//Constructor por defecto
VectorDinamico :: VectorDinamico()
{
	dynamicVector = NULL;
	this->size = 0; 
	this->arrayIndex = 0;
}

VectorDinamico :: VectorDinamico(int numCasillas)
{
	PideMemoria(numCasillas);
	this->size = numCasillas;
	this->arrayIndex = 0;
	//inicializamos todas las casillas a cero
	initializeVector();
}

VectorDinamico :: VectorDinamico(int numCasillas, int defaultValue)
{
	PideMemoria(numCasillas);
	this->size = numCasillas;
	this->arrayIndex = numCasillas - 1;
	//inicializamos todas las casillas a defaultValue
}

//Constructor de Copia
VectorDinamico :: VectorDinamico(const VectorDinamico & otro) 
{
	Copia(otro);
}


//Sobrecarga de operadores
VectorDinamico& VectorDinamico :: operator= (const VectorDinamico & otro)
{
	if(this != &otro) //Evitar Autoasignacion
	{
		LiberaMemoria();	
		Copia(otro);
	}

	return (*this); //devuelve el objeto implicito
}
//Destructor
VectorDinamico :: ~VectorDinamico()
{
	delete [] dynamicVector;
	
	dynamicVector = 0;
}

//Metodos Publicos
bool VectorDinamico :: isEmpty() const
{
	return dynamicVector == NULL ? true: false;
}

int VectorDinamico :: getOccupiedCells() const
{
	return arrayIndex + 1;
}


void VectorDinamico :: insertValue(int value)
{
	if(arrayIndex >= size)
	{
		int *copyVector;

		if(dynamicVector != NULL){

			copyVector = new int[size];

			memcpy(copyVector, dynamicVector, sizeof(int) * size);

			delete [] dynamicVector;
		}

		this->size++;

		dynamicVector = new int[size];

		memcpy(dynamicVector,copyVector, sizeof(int) * size);

	}
	
	dynamicVector[arrayIndex] = value;
	this->arrayIndex++;

}


int VectorDinamico :: getValue(int index) const
{
	if(index < this->size)
		return *(dynamicVector + index);
	else 
		cerr << "El indice no esta dentro del tamagno del array" << endl;
}

int VectorDinamico :: getSize() const
{
	return this->size;
}
void VectorDinamico :: printArray() const
{
	for(int i=0;i<size;i++)
		cout << dynamicVector[i] << " ";
	cout << endl;

}

void VectorDinamico :: changeArraySize(int numCasillasNuevas)
{
	if(numCasillasNuevas > size){
		int *newVector = new int[size];

		memcpy(newVector,dynamicVector,sizeof(int) * size);

		delete[] dynamicVector;

		int oldSize = size;
		size = numCasillasNuevas; //El tamaño ha cambiado a numCasillasNuevas
		dynamicVector = new int[size];

		memcpy(dynamicVector,newVector,sizeof(int) *oldSize);

	}
	else 
		cerr << "El numero de casillas tiene que se mas grande que el tamagno original" << endl;

}
