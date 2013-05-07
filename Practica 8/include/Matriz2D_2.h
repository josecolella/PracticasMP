/**************************
*
* Fichero: Matriz2D_2.h
* Autor: Jose Miguel Colella
* Descripcion: En este fichero declaro los atributos y prototipos de la clase 
* Matriz2D_2. Esta clase consiste en un puntero a un array de punteros el primer
* puntero crea un array de fils * cols y cada puntero del array de puntero apunta 
* al comienzo de la fila de la matriz
*
*************************/

#ifndef _MATRIZ2D_2_H_
#define _MATRIZ2D_2_H_

typedef int TipoBase ;//Esto se puede cambiar
typedef TipoBase** Matrix2D2; //Hago esto para abstraer de lo que es una matriz

class Matriz2D_2
{

	private:
		Matrix2D2 matrix;
		int rows;
		int columns;
		void initializeMatrix(int fils, int cols, int value);
		void Copia(const Matriz2D_2 &otro);
		void LiberaMemoria(void);
	public:
		//Constructor
		Matriz2D_2();
		Matriz2D_2(int numFilsColsSquare); //inicia todas las casillas al valor nulo
		Matriz2D_2(int fils, int cols); //inicia todas las casillas al valor nulo 
		Matriz2D_2(int fils, int cols, int defaultValue); //inicia todas las casillas al valor defaultValue
		//Constructor de Copia
		Matriz2D_2(const Matriz2D_2 &otro);
		//Sobrecarga del operador de asignacion
		Matriz2D_2& operator= (const Matriz2D_2 & otro);
		Matriz2D_2& operator= (const TipoBase & otro);
		
		//Destructor
		~Matriz2D_2();
		//Metodos
		bool isEmpty() const;
		//Metodos para escribir/leer un valor
		void PonValor (int fila, int col, TipoBase val);
		TipoBase LeeValor (int fila, int col) const;
		void printMatrix() const;

};

#endif
