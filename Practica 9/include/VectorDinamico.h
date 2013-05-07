/**************************
*
* Fichero: VectorDinamico.h
* Autor: Jose Miguel Colella
* Descripcion: En este fichero defino la clase que representa el objeto de 
* vector dinamico. En este fichero declaro los prototipos que contiene la clase
*
*************************/



#include <iostream>

using namespace std;

#ifndef _VECTORDINAMICO_H_
#define _VECTORDINAMICO_H_



typedef int TipoBase;

class VectorDinamico{

private:
	int *dynamicVector;
	int size;
	int arrayIndex;
	void initializeVector();
	void initializeVector(int numToInitialize);
		//Codigo reutilizable
	void Copia(const VectorDinamico &otro);
	void PideMemoria (int n);
	void LiberaMemoria(void);

public:
		//Constructores
	VectorDinamico();
	VectorDinamico(int numCasillas);
	VectorDinamico(int numCasillas, TipoBase defaultValue);
		//Constructor de Copia
	VectorDinamico(const VectorDinamico & otro);
		//Sobrecarga del operador de asignacion
	VectorDinamico& operator= (const VectorDinamico & otro);	
		//Sobrecarga del operador de indices
	TipoBase& operator[](const int index);
		//Sobrecarga del == y !=
	bool operator==(const VectorDinamico &otro);
	bool operator!=(const VectorDinamico &otro);
		//Sobrecarga del >,<,>=, <=
	int operator >(const VectorDinamico &otro);
	int operator <(const VectorDinamico &otro);
	int operator<=(const VectorDinamico &otro);
	int operator>=(const VectorDinamico &otro);
		//Sobrecarga del >>,<<
	friend ostream & operator << (ostream &, const VectorDinamico &);
	friend istream & operator >> (istream &, VectorDinamico &);


		//Destructor
	~VectorDinamico();
		//Metodos
		//consulta si el vector dinamico esta vacio
	bool isEmpty() const;
		//Consultar el numero de casillas ocupadas
	int getOccupiedCells() const;
		//Metodos para consultar el numero de casillas ocupadas
	void insertValue(int value);
		//Metodo para escribir un valor
	int getValue(int index) const;
		//Funcion para obtener el size del array
	int getSize() const;
		//Metodo para escribir el contenido del vector dinamico -> Es como el printVector
	void printArray() const;
	void changeArraySize(int numCasillasNuevas);
	


};



#endif
