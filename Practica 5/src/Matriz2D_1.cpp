/*********************************
*
* Fichero: Matriz2D_1.cpp
* Autor: Jose Miguel Colella
* Clase: Metodologia de Programacion
* Implementacion para matrices tipo Matriz2D_1
*
**********************************/


#include <iostream>
#include <iomanip> //Incluimos esta porque usaremos setw()
#include <string.h> //Incluimos esta para usar memcpy()
#include <cstdlib> //Incluimos para usar srand() y rand()
#include <time.h> //Incluimos para usar time
#include "Matriz2D_1.h"

using namespace std;

Matriz2D_1 CreaMatriz2D_1 (int fils, int cols)
{
	Matriz2D_1 matriz = new int * [fils]; // puntero local a un
	// vector de punteros
	for (int f=0; f<fils; f++) {
		matriz[f] = new int [cols]; // "matriz[f]" apunta a un
	}
	// vector dinamico de int
	return (matriz);
}

void LiberaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols)
{
	for (int f=0; f<fils; f++)
		delete [] matriz[f];
		// Libera una fila
	delete [] matriz;
	// Libera el vector de punteros
}

void PintaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols)
{
	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++)
			cout << setw(4) << matriz[f][c]; // acceso a un elemento
	cout << endl; // cada fila se muestra en una linea diferente
	}
}

//Construir un modulo que lea del teclado fils * cols valores y los copie en la matriz
Matriz2D_1 LeeMatriz2D_1 (int fils, int cols)
{
 	//Primero podemos usar la funcion CreaMatriz auxiliar para que nos cree la matriz
 	Matriz2D_1 matrixToReturn = CreaMatriz2D_1(fils,cols);

 	//Tenemos la matriz dinamica lista para que se rellene
 	cout << endl << "Rellenando matrices" << endl;

	for (int f=0; f<fils; f++)
		for (int c=0; c<cols; c++) 
			cin >> matrixToReturn[f][c];
	//La matriz esta rellena con los datos inseridos. Ahora devolvemos la matriz

	return (matrixToReturn);

}

Matriz2D_1 AleatorizaMatriz2D_1 (int fils, int cols, int MAX)
{
	time_t t;


	//Primero podemos usar la funcion CreaMatriz auxiliar para que nos cree la matriz
 	Matriz2D_1 matrixToReturn = CreaMatriz2D_1(fils,cols);

 	//Tenemos la matriz dinamica lista para que se rellene
 	cout << endl << "Rellenando matrices" << endl;

 	// Inicializa el generador con el reloj del sistema
	srand ((int) time(&t));

	for(int f=0;f<fils;f++)
		for(int c=0;c<cols;c++)
			matrixToReturn[f][c] = 1 + rand() % MAX; //Los valores son del 1 al MAX

	//Se regresa la matriz
	return (matrixToReturn);

}

Matriz2D_1 CopiaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols){

	//Primero creamos una matriz que tenga fils X cols bloques
	Matriz2D_1 matrixCopy = CreaMatriz2D_1(fils,cols);

	//Para copiar recoremos la matriz inicial
	for(int f=0;f<fils;f++)
			memcpy(matrixCopy[f],matriz[f],sizeof(int)*cols);

	return (matrixCopy);
}

Matriz2D_1 SubMatriz2D_1 (Matriz2D_1 matriz, int fil_init, int col_init, int fil_end, int col_end)
{
	if(fil_end >= fil_init && col_end >= col_init){
		
		int subFils = (fil_end - fil_init) + 1;
		int subCols = (col_end - col_init) + 1;

		//Creamos una Matriz de subFils X subCols
		Matriz2D_1 subMatrix =  CreaMatriz2D_1(subFils,subCols);

		for(int fsub=0, f=fil_init;fsub<=subFils && f<=fil_end;fsub++,f++)
			for(int csub=0, c=col_init;csub<=subCols && f<=col_end;csub++,c++)
				memcpy(&subMatrix[fsub][csub],&matriz[f][c],sizeof(int));

		return (subMatrix);
	}
	else
		return NULL;

}

Matriz2D_1 EliminaFilaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols, int fila)
{
	Matriz2D_1 reducida = CreaMatriz2D_1 (fils-1, cols);

	int fila_reducida = 0;
	for (int f=0; f<fila; f++, fila_reducida++) 
		memcpy (reducida[fila_reducida], matriz[f], cols*sizeof(int));
	for (int f=fila+1; f<fils; f++, fila_reducida++) 
		memcpy (reducida[fila_reducida], matriz[f], cols*sizeof(int));

	return (reducida);
}
 

Matriz2D_1 EliminaColumnaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols, int columna)
{
	//Tenemos que crear una matriz que tenga una columna de menos
	Matriz2D_1 reducida = CreaMatriz2D_1(fils,cols-1);

	for (int f=0,fReducida=0; f<fils && fReducida<fils; f++,fReducida++)
		for(int c=0,cReducida=0;c<cols && cReducida<cols-1;c++){
			if(c != columna){
				memcpy(&reducida[fReducida][cReducida],&matriz[f][c],sizeof(int));
				cReducida++;
			}
		}	
	
	return (reducida);
}


Matriz2D_1 TraspuestaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols)
{
	//La matriz transpuesta es cols X fils
	Matriz2D_1 transposeMatrix = CreaMatriz2D_1(cols,fils);

	for(int f=0;f<cols;f++)
		for(int c=0;c<fils;c++)
			memcpy(&transposeMatrix[f][c],&matriz[c][f],sizeof(int));


	return (transposeMatrix);
}


Matriz2D_1 InvierteMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols)
{
	Matriz2D_1 inverseMatrix = CreaMatriz2D_1(fils, cols);

	for(int i=fils-1,f=0;i>=0 && f<fils;i--,f++)
			memcpy(inverseMatrix[i],matriz[f],sizeof(int)*cols);

	return (inverseMatrix);
}
