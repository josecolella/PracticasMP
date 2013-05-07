/**************************
*
* Fichero: Matriz2D_2.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero termino de definir lo que hacen los prototipos
* para el objeto Matriz2D_2. Recordamos que este objeto es diferente que Matriz2D_1, y
* esto se hace claro cuando se crean los algoritmos
*
*************************/

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Matriz2D_2.h"

using namespace std;

//Metodos privados
void Matriz2D_2 :: initializeMatrix(int fils, int cols, int value)
{
	this->matrix = new int * [fils]; 

	matrix[0] = new int [fils*cols]; 

	for(int f=1; f<fils ; f++)
		matrix[f] = matrix[f-1] + cols; 

	for(int f=0;f<fils*cols;f++)
		matrix[0][f] = value;

	this->rows = fils;
	this->columns = cols;
}

void Matriz2D_2 :: Copia(const Matriz2D_2 &otro)
{
	this->rows = otro.rows;
	this->columns = otro.columns;

	this->matrix = new int * [this->rows]; 

	for (int f=0; f<this->rows; f++) {
		matrix[f] = new int [this->columns]; 
	}

	for(int f=0;f<rows;f++)
		memcpy(matrix[f],otro.matrix[f],sizeof(TipoBase) * columns);



}

void Matriz2D_2 :: LiberaMemoria(void)
{
	delete [] matrix[0]; 
	delete [] matrix;
}

//Constructores
Matriz2D_2 :: Matriz2D_2()
{
	//Tenemos una matriz vacia
	matrix = NULL;
	rows = 0;
	columns = 0;

}

Matriz2D_2 :: Matriz2D_2(int numFilsColsSquare)
{
	initializeMatrix(numFilsColsSquare,numFilsColsSquare,0);
}

Matriz2D_2 :: Matriz2D_2(int fils, int cols)
{
	initializeMatrix(fils,cols,0);
}

Matriz2D_2 :: Matriz2D_2(int fils, int cols, int defaultValue)
{
	initializeMatrix(fils,cols,defaultValue);
}


//Constructor de Copia
Matriz2D_2 :: Matriz2D_2(const Matriz2D_2 &otro)
{
	Copia(otro);

}


	Matriz2D_2& Matriz2D_2 :: operator= (const Matriz2D_2 & otro)
	{
		if(this != &otro) //Evitar Autoasignacion
		{
			LiberaMemoria();    
			Copia(otro);
		}

	        return (*this); //devuelve el objeto implicito
    }		

    Matriz2D_2&  Matriz2D_2 :: operator= (const TipoBase & otro)
    {
    	for(int f=0;f<rows*columns;f++)
    		this->matrix[0][f] = otro; 

        return (*this); //devuelve el objeto implicito

    }
//Destructor
    Matriz2D_2 :: ~Matriz2D_2()
    {

    }

//Metodos
    bool Matriz2D_2 :: isEmpty() const
    {
    	return matrix == NULL ? true : false;
    }

    void Matriz2D_2 :: PonValor (int fila, int col, TipoBase val)
    {
	//Si la matriz actual esta vacia tenemos que crearla
    	if(matrix == NULL)
    	{
    		initializeMatrix(fila,col,0);
    	}
    	matrix[fila][col] = val;
    }

    TipoBase Matriz2D_2 :: LeeValor(int fila, int col) const
    {
    	if(fila <= rows && col <= columns)
    		return matrix[fila][col];
    	else
    		cerr << "Parametros Incorrectos" << endl;
    }

    void Matriz2D_2 :: printMatrix() const
    {
    	for (int f=0; f<rows; f++) {
    		for (int c=0; c<columns; c++)
			cout << setw(4) << matrix[f][c]; // acceso a un elemento
		cout << endl; // cada fila se muestra en una linea diferente
	}
}
