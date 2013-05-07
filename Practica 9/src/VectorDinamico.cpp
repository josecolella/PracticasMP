/**************************
*
* Fichero: VectorDinamico.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero especifico los algoritmos para la clase
* VectorDinamico
*************************/

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
	initializeVector(defaultValue);
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

//Sobrecarga del operador []
TipoBase & VectorDinamico :: operator[] (const int index)
{
	if(index < 0 || index>= this->size){
		cerr << "Error: indice incorrecto" << endl;
	}
	return *(dynamicVector+index);

}


/**En esta sobrecarga hacemos dos comprobaciones
 *
 * 1. Si el tamaño es igual
 * 2. Si el contenido es igual
 *
 * Se tiene que hacer estas dos comprobaciones antes de devolver
 * que son iguales
 */
 bool VectorDinamico :: operator == (const VectorDinamico &otro)
 {
 	bool isEqualSize; 
 	bool isContentEqual = true;
 	int *ptr1,*ptr2;

 	if(this->size == otro.size)
 		isEqualSize= true;
 	else
 		isEqualSize=false;

 	if(isEqualSize== true){
 		for(ptr1=dynamicVector,ptr2=otro.dynamicVector;ptr1!=dynamicVector+this->size && isContentEqual;ptr1++,ptr2++)
 			if(*ptr1 != *ptr2)
 				isContentEqual = false;
 		}
 		else
 			isContentEqual = false;

 		return isContentEqual;



 	}

 	/**
 	 * 
 	 */
 	 bool VectorDinamico :: operator != (const VectorDinamico &otro)
 	 {
 	 	bool isNotEqualSize; 
 	 	bool isNotContentEqual = true;
 	 	int *ptr1,*ptr2;

 	 	if(this->size != otro.size)
 	 		isNotEqualSize= true;
 	 	else
 	 		isNotEqualSize=false;

 	 	if(!isNotEqualSize){
 	 		for(ptr1=dynamicVector,ptr2=otro.dynamicVector;ptr1!=dynamicVector+this->size  && ptr2!=otro.dynamicVector+otro.size && isNotContentEqual;ptr1++,ptr2++)
 	 			if(*ptr1 == *ptr2)
 	 				isNotContentEqual = false;
 	 	}
 	 	else
 	 			isNotContentEqual = true;

 	 		return isNotContentEqual;

 	 	}

 	 	int VectorDinamico :: operator >(const VectorDinamico &otro)
 	 	{
 	 		int isGreater;
 	 		int *ptr1;
 	 		int *ptr2;

 	 		
 	 		for(ptr1=this->dynamicVector,ptr2=otro.dynamicVector,isGreater=0;ptr1 != this->dynamicVector+size && ptr2 != otro.dynamicVector+otro.size && isGreater == 0;ptr1++,ptr2++)
 	 				if(*ptr1 > *ptr2)
 	 					isGreater = 1;
 	 				else if(*ptr1 < *ptr2)
 	 					isGreater = -1;
 	 			

 	 			return isGreater;
 	 	}

 	 	int VectorDinamico :: operator <(const VectorDinamico &otro)
 	 	{
 	 		int isLess;
 	 		int *ptr1;
 	 		int *ptr2;

 	 		
 	 		for(ptr1=this->dynamicVector,ptr2=otro.dynamicVector,isLess=0;ptr1 != this->dynamicVector+size && ptr2 != otro.dynamicVector+otro.size && isLess == 0;ptr1++,ptr2++)
 	 				if(*ptr1 > *ptr2)
 	 					isLess = 1;
 	 				else if(*ptr1 < *ptr2)
 	 					isLess = -1;
 	 			

 	 			return isLess;
 	 	}

 	 	int VectorDinamico :: operator<=(const VectorDinamico &otro)
 	 	{
 	 		int isLessEqual;
 	 		int *ptr1;
 	 		int *ptr2;

 	 		
 	 		for(ptr1=this->dynamicVector,ptr2=otro.dynamicVector,isLessEqual=-1;ptr1 != this->dynamicVector+size && ptr2 != otro.dynamicVector+otro.size && isLessEqual == -1;ptr1++,ptr2++)
 	 				if(*ptr1 > *ptr2)
 	 					isLessEqual = 1;
 	 				else if(*ptr1 <= *ptr2)
 	 					isLessEqual = -1;
 	 			

 	 			return isLessEqual;

 	 	}


		int VectorDinamico :: operator >=(const VectorDinamico &otro)
		{
			int isGreaterEqual;
 	 		int *ptr1;
 	 		int *ptr2;

 	 		
 	 		for(ptr1=this->dynamicVector,ptr2=otro.dynamicVector,isGreaterEqual=1;ptr1 != this->dynamicVector+size && ptr2 != otro.dynamicVector+otro.size && isGreaterEqual == 1;ptr1++,ptr2++)
 	 				if(*ptr1 >= *ptr2)
 	 					isGreaterEqual = 1;
 	 				else if(*ptr1 < *ptr2)
 	 					isGreaterEqual = -1;
 	 			

 	 			return isGreaterEqual;
		}


		ostream & operator << (ostream & out, const VectorDinamico &otro)
		{
			for(int i=0;i<otro.size;i++)
 	 			out << otro.dynamicVector[i] << " ";
 	 		out << endl;
		}
		
		istream & operator >> (istream &in, VectorDinamico &v)
		{
			int currentIndex = v.arrayIndex;
			TipoBase value;

			while(currentIndex < v.size)
			{
				in >> value;
				v.insertValue(value);
				currentIndex++;
			}

			return (in); //devuelve la referencia al objeto istream
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
