/*********************************
 * Fichero: Matriz2D_2.cpp
 * Autor: Jose Miguel Colella
 * Descripcion: La implementacion de las funciones para matrices tipo
 * Matriz2D_2
 * En todas las funciones se ha tomado ventaja 
 * de la estructura de la matriz para implementar funciones mas eficientes
 * En vez de recorrer la matriz usando dos for, en muchas de las funciones 
 * se ha usando solo un for, esto significa menos accesos
 **************************************************/


#include <iostream>
#include <iomanip> //La incluimos para usar setw()
#include <time.h>
#include <cstdlib>
#include <string.h> //La incluimos para usar memcpy
#include "Matriz2D_2.h"
using namespace std;

Matriz2D_2 CreaMatriz2D_2 (int fils, int cols)
{
	Matriz2D_2 matriz = new int * [fils]; // puntero local a un
	// vector de punteros
	matriz[0] = new int [fils*cols]; // vector de datos: todos
	// estan en una sola fila
	for(int f=1; f<fils ; f++)
		matriz[f] = matriz[f-1] + cols; // apuntar con "matriz[f]"
	// al inicio de la fila "f"
	return (matriz);
}

void LiberaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols)
{
	delete [] matriz[0]; // Libera el vector de datos
	delete [] matriz;
	// Libera el vector de punteros
}

void PintaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols)
{
	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++)
			cout << setw(4) << matriz[f][c]; // acceso a un elemento
	cout << endl; // cada fila se muestra en una linea diferente
	}
}


Matriz2D_2 LeeMatriz2D_2 (int fils, int cols)
{
	//Tenemos que crear una matriz2D_2 usando la funcion creada a priori
	Matriz2D_2 matrixToReturn = CreaMatriz2D_2(fils,cols);

	//Tenemos la matriz dinamica lista para que se rellene
 	cout << endl << "Rellenando matrices" << endl;

	for (int i=0; i<fils*cols; i++)
			cin >> matrixToReturn[0][i];
	//La matriz esta rellena con los datos inseridos. Ahora devolvemos la matriz

	return (matrixToReturn);

}

Matriz2D_2 AleatorizaMatriz2D_2 (int fils, int cols, int MAX)
{
	time_t t;

	//Primero podemos usar la funcion CreaMatriz auxiliar para que nos cree la matriz
 	Matriz2D_2 matrixToReturn = CreaMatriz2D_2(fils,cols);

 	//Tenemos la matriz dinamica lista para que se rellene
 	cout << endl << "Rellenando matrices" << endl;

 	// Inicializa el generador con el reloj del sistema
	srand ((int) time(&t));


	for(int i=0;i<fils*cols;i++)
		matrixToReturn[0][i] = 1 + rand() % MAX; //Los valores son del 1 al MAX

	//Se regresa la matriz
	return (matrixToReturn);
}

Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols)
{
	//Primero creamos una matriz que tenga fils X cols bloques
	Matriz2D_2 matrixCopy = CreaMatriz2D_2(fils,cols);

	//Para copiar recoremos la matriz inicial
	for(int i=0;i<fils*cols;i++)
			memcpy(&matrixCopy[0][i],&matriz[0][i],sizeof(int));

	return (matrixCopy);
}

Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz, int fil_init, int col_init, int fil_end, int col_end)
{
	if(fil_end >= fil_init && col_end >= col_init){
		
		int subFils = (fil_end - fil_init) + 1;
		int subCols = (col_end - col_init) + 1;

		//Creamos una Matriz de subFils X subCols
		Matriz2D_2 subMatrix =  CreaMatriz2D_2(subFils,subCols);

		for(int fsub=0, f=fil_init;fsub<=subFils && f<=fil_end;fsub++,f++)
			for(int csub=0, c=col_init;csub<=subCols && f<=col_end;csub++,c++)
				memcpy(&subMatrix[fsub][csub],&matriz[f][c],sizeof(int));

		return (subMatrix);
	}
	else
		return NULL;
}

Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int fila)
{
	Matriz2D_2 reducida = CreaMatriz2D_2 (fils-1, cols);

	//Vamos recorriendo la matriz y solo copiamos los valores que no son de 
	//fila
	for(int i=0, k=0;i<fils*cols && k<(fils-1)*cols;i++)
		if(i< fila*cols || i >= fila*cols + cols){
			memcpy(&reducida[0][k],&matriz[0][i],sizeof(int));
			k++;
		}

	return (reducida);
}

Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columna)
{
	//Tenemos que crear una matriz que tenga una columna de menos
	Matriz2D_2 reducida = CreaMatriz2D_2(fils,cols-1);

	//Este variable nos servira para conseguir indices que no tenemos que copiar 
	int multiplesColumn = columna; 

	for(int i=0,k=0;i<fils*cols && k<fils*(cols-1);i++)
		if(i != multiplesColumn){
			memcpy(&reducida[0][k],&matriz[0][i],sizeof(int));
			k++;
		}
		else{ //Sumamos cols asi tenemos el indices del proximo elemento a no copia
			multiplesColumn+=cols;
		}


	return (reducida); //Return la matriz sin la columna
}

Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols)
{
	//La matriz transpuesta es cols X fils
	Matriz2D_2 transposeMatrix = CreaMatriz2D_2(cols,fils);

	int transFilas = 0;

	for(int f=0,k=0;f<fils*cols;f++,transFilas++){
		transFilas = transFilas % fils; //Usamos modulo para las filas
		memcpy(&transposeMatrix[transFilas][k],&matriz[0][f],sizeof(int));
		if(transFilas==fils-1)
			k++;
	}

	return (transposeMatrix);

}

Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols)
{
	Matriz2D_2 inverseMatrix = CreaMatriz2D_2(fils, cols);

	for(int i=fils-1,f=0;i>=0 && f<fils;i--,f++)
		memcpy(inverseMatrix[i],matriz[f],sizeof(int)*cols);

	return (inverseMatrix);
}
