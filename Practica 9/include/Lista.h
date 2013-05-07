/******************************
*
* Fichero: Lista.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero representa los prototipos para
* la estructura de datos Lista. Este lista esta compuesta de
* nodos enlazados
*
*
*******************************/

#include "Node.h"
#include <iostream>

using namespace std;

#ifndef _LISTA_H_
#define _LISTA_H_

typedef int TipoBase; //Esto abstrae del dato del nodo

class Lista
{
private:	
	Node *listHead;
	int size;
	void insertNodes(TipoBase dataToInsert, int pos);
	void Copia(const Lista & otro);
	void LiberaMemoria(void);
public:
		//Constructor
	Lista();
		Lista(int numNodes); ///Inicia con el valor nulo
		Lista(int numNodes, TipoBase defaultValue); //Inicia al parametro defaultValue
		//Constructor de copia
		Lista(const Lista & otro);
		//Sobrecarga de operadores
		Lista & operator=(const Lista & otro);
		//Sobrecarga del operador[]
		TipoBase operator[](const int index);
		//Sobrecarga de los operadores >> y << 
		friend ostream & operator << (ostream &, const Lista &);
		//Para la implementeacion del operador >> leera una secuencia 
		//indefinida de valores, hasta que se introduzca el valor *.
		//Los valores se leeran en una cadena de caracteres, y solo se
		//convertiran al tipo TipoBase cuando se verifique que son validos para 
		//su almacenamiento(no se ha introducido el terminador(*))
		friend istream & operator >> (istream &, Lista &);

		//Destructor
		~Lista();
		//Metodos
		bool isEmpty() const;
		int getNumNodes() const;
		void Insertar (TipoBase val, int pos);
		void Borrar (int pos);
		TipoBase ObtenerValor (int pos) const;
		void PonerValor (int pos, TipoBase val); //Usa borrar e insertar
		bool isContained(TipoBase data);
		void printList() const;
		Node *getListHead() const;
	};



#endif
