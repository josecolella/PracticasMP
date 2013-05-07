/**************************
*
* Fichero: Matriz2D_1.h
* Autor: Jose Miguel Colella
* Descripcion: En este fichero declaro los atributos y prototipos de la clase 
* Matriz2D_1. Esta clase consiste en un puntero a un array de punteros donde se crean
* vectores.
*
*************************/


typedef int TipoBase;//Esto se puede cambiar
typedef int ** Matriz2D1; //Abstraccion de lo que es una matriz

#ifndef _MATRIZ2D_1_H_
#define _MATRIZ2D_1_H_


class Matriz2D_1
{

	private:
		Matriz2D1 matrix;
		int rows;
		int columns;
		void initializeMatrix(int fils, int cols, int value);
		//Codigo Reutilizable
		void Copia(const Matriz2D_1 &otro);
		void LiberaMemoria(void);
	public:
		//Constructor
		Matriz2D_1();
		Matriz2D_1(int numFilsColsSquare); //inicia todas las casillas al valor nulo
		Matriz2D_1(int fils, int cols); //inicia todas las casillas al valor nulo 
		Matriz2D_1(int fils, int cols, int defaultValue); //inicia todas las casillas al valor defaultValue
		//Constructor de Copia
		Matriz2D_1(const Matriz2D_1 &otro);
		//Sobrecarga del operador de asignacion
		Matriz2D_1& operator= (const Matriz2D_1 & otro);
		Matriz2D_1& operator= (const TipoBase & otro);
		//Destructor
		~Matriz2D_1(void);
		//Metodos
		bool isEmpty() const;
		//Metodos para escribir/leer un valor
		void PonValor (int fila, int col, TipoBase val);
		TipoBase LeeValor (int fila, int col) const;
		void printMatrix() const;

};

#endif
