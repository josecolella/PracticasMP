/**********************************8
 * Fichero: Ejercicio9Main.cpp
 * Autor: Jose Miguel Colella
 * Descripcion: Este fichero verifica la validez de las funciones creadas
 * para las matrices 
 * Este fichero se enfoca en verficar las matrices tipo Matriz2D_2
 *
 *************************************************/

#include <iostream>
#include "matrix.h"
#define MAX 10
using namespace std;

int main()
{
	Matriz2D_2 matriz1;
	Matriz2D_2 matrizAleatoria;
	Matriz2D_2 matrizCopia;
	Matriz2D_2 subMatriz;
	int filas, columns;
	
	
	/////////////////////////////////////////////////////////////
	cout << "Probando LeeMatriz2D_2" << endl;
	
	cout << "Numero de Filas: ";
	cin >> filas;
	cout << "Numero de Columnas: ";
	cin >> columns;
	
	matriz1 = LeeMatriz2D_2(filas,columns);
	
	cout << endl << "Matriz creada despues de LeeMatriz2D_2" << endl;
	
	PintaMatriz2D_2(matriz1,filas,columns);

	///////////////////////////////////////////////////////////////
	cout << endl << "Probando AleatorizaMatriz2D_2" << endl;
	
	matrizAleatoria = AleatorizaMatriz2D_2(filas,columns,MAX);

	cout << endl << "Matriz creada despues de AleatorizaMatriz2D_2" << endl;
	
	PintaMatriz2D_2(matrizAleatoria,filas,columns);
	
	///////////////////////////////////////////////////////////////////////
	cout << endl << "Probando CopiaMatriz2D_2" << endl;
	
	matrizCopia = CopiaMatriz2D_2(matrizAleatoria,filas,columns);

	cout << endl << "Matriz creada despues de CopiaMatriz2D_2" << endl;
	
	PintaMatriz2D_2(matrizCopia,filas,columns);
	
	///////////////////////////////////////////////////////////////////////
	
	cout << endl << "Probando SubMatriz2D_2 sobre Matriz Aleatoria" << endl;
	
	subMatriz = SubMatriz2D_2(matrizAleatoria,0,0,1,1);

	cout << endl << "Matriz creada despues de SubMatriz2D_2" << endl;
	
	PintaMatriz2D_2(subMatriz,filas-1,columns-1);
	
	///////////////////////////////////////////////////////////////////
	
	cout << endl << "Probando EliminaFilaMatriz2D_2 sobre Matriz Aleatoria" << endl;
	
	cout << "Matriz antes de eliminar fila 1" << endl;
	
	PintaMatriz2D_2(matrizAleatoria,filas,columns);
	
	matrizAleatoria = EliminaFilaMatriz2D_2(matrizAleatoria,filas,columns,1);
	
	cout << "Matriz despues de eliminar fila 1" << endl;
	
	PintaMatriz2D_2(matrizAleatoria,filas-1,columns);

	/////////////////////////////////////////////////////////////////////
	
	int newFilas = filas -1;
	
	cout << endl << "Probando EliminaColumnaMatriz2D_2 sobre Matriz Aleatoria" << endl;
	
	cout << "Matriz antes de eliminar columna 0" << endl;
	
	PintaMatriz2D_2(matrizAleatoria,newFilas,columns);
	
	matrizAleatoria = EliminaColumnaMatriz2D_2(matrizAleatoria,newFilas,columns,0);
	
	cout << "Matriz despues de eliminar columna 0" << endl;
	
	int newColumns = columns -1;
	
	PintaMatriz2D_2(matrizAleatoria,newFilas,newColumns);
	
	////////////////////////////////////////////////////////////////////
	
	cout << endl << "Probando TraspuestaMatriz2D_2 sobre matriz1" << endl;
	
	cout << "Matriz antes de la traspuesta" << endl;
	
	PintaMatriz2D_2(matriz1,filas,columns);
	
	matriz1 = TraspuestaMatriz2D_2(matriz1,filas,columns);
	
	cout << "Matriz despues de la traspuesta" << endl;
	
	PintaMatriz2D_2(matriz1,columns,filas);

	////////////////////////////////////////////////////////////////////

	
	cout << endl << "Probando InvierteMatriz2D_2 sobre Matriz Copia" << endl;
	
	cout << "Matriz antes de invertirla" << endl;
	
	PintaMatriz2D_2(matrizCopia,filas,columns);
	
	matrizCopia= InvierteMatriz2D_2(matrizCopia,filas,columns);
	
	cout << "Matriz despues de invertir la matriz" << endl;
	
	PintaMatriz2D_2(matrizCopia,filas,columns);


	////////////////////////////////////////////////////////////////////

	//Para concluir tenemos que liberar las matrices creadas
	LiberaMatriz2D_2(matriz1,filas,columns);
	LiberaMatriz2D_2(matrizAleatoria,newFilas,newColumns);
	LiberaMatriz2D_2(matrizCopia,columns,filas);
	LiberaMatriz2D_2(subMatriz,newFilas,newColumns);


}
	
