/**************************
*
* Fichero: VectorDinamico.h
* Autor: Jose Miguel Colella
* Descripcion: En este fichero defino la clase que representa el objeto de 
* vector dinamico. En este fichero declaro los prototipos que contiene la clase
*
*************************/


#ifndef _VECTORDINAMICO_H_
#define _VECTORDINAMICO_H_


class VectorDinamico{

	private:
		int *dynamicVector;
		int size;
		int arrayIndex;
		void initializeVector();
		void initializeVector(int numToInitialize);

	public:
		//Constructores
		VectorDinamico();
		VectorDinamico(int numCasillas);
		VectorDinamico(int numCasillas, int defaultValue);
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
