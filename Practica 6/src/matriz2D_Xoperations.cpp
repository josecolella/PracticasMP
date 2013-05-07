/************************************
*
* Fichero: matriz2D_Xoperations.cpp
* Autor: Jose Miguel Colella
* Descripcion: Implementa los prototipos para 
* que se pueda crear una Matriz2D_1 de una Matriz2D_2,
* y vice-versa creando una Matriz2D_2 de una Matriz2D_1
*
************************************/

#include "matriz2D_Xoperations.h"
#include <string.h> //Incluimos para usar memcpy()

Matriz2D_2 CrearMatriz2D_2de2D_1(Matriz2D_1 matriz2D_1, int fils, int cols)
{
	//Primero creamos la matriz2D_2 que se devuelve al usuario
	Matriz2D_2 matrixtoReturn = CreaMatriz2D_2 (fils, cols);

	for(int f=0;f<fils;f++)
			memcpy(matrixtoReturn[f],matriz2D_1[f],sizeof(int)*cols);

	return (matrixtoReturn);
}


Matriz2D_1 CrearMatriz2D_1de2D_2(Matriz2D_2 matriz2D_2, int fils, int cols)
{
	//Creamos la Matriz2D_1 que se devuelve al usuario
	Matriz2D_1 matrixtoReturn = CreaMatriz2D_1(fils,cols);

	int columnsMatrix2D_1;

	for(int f=0,filMatrix2D_1=0;f<fils;f++,filMatrix2D_1++)
		memcpy(matrixtoReturn[f],matriz2D_2[f],sizeof(int)*cols);
		

	return (matrixtoReturn);
}