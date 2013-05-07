/**********************************8
 * Fichero: Ejercicio9Main.cpp
 * Autor: Jose Miguel Colella
 * Descripcion: Este fichero verifica la validez de las funciones implementadas
 * para los apartados b y c del Ejercicio 9
 *
 * Primero vamos a rellenar una Matriz2D_1 y despues llamaremos a 
 * la funcion CrearMatriz2D_2de2D_1 y pintaremos la Matriz2D_2 
 * para verificar su validez. Despues rellenamos una Matriz2D_2
 * y llamaremos la funcion CrearMatriz2D_1de2D_2 y pintaremos la Matriz2D_1
 * para verificar su validez
 *************************************************/

#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	Matriz2D_1 matriz1; 
	Matriz2D_2 matriz2; 
	

	Matriz2D_1 matriz2To1;
	Matriz2D_2 matriz1To2;
	int filas1,filas2, columns1,columns2;
	
	
	/////////////////////////////////////////////////////////////
	cout << "Primero rellenamos una Matriz2D_1" << endl;
	
	cout << "Numero de Filas: ";
	cin >> filas1;
	cout << "Numero de Columnas: ";
	cin >> columns1;
	
	matriz1 = LeeMatriz2D_1(filas1,columns1);
	
	cout << endl << "Matriz creada despues de LeeMatriz2D_1" << endl;
	
	PintaMatriz2D_1(matriz1,filas1,columns1);

	////////////////////////////////////////////////////////////////////

	cout << "Ahora llamamos a CrearMatriz2D_2de2D_1" << endl;

	matriz1To2 = CrearMatriz2D_2de2D_1(matriz1,filas1,columns1);

	cout << endl << "Matriz2D_2 creada despues de llamar CrearMatriz2D_2de2D_1" << endl;

	PintaMatriz2D_2(matriz1To2,filas1,columns1);

	/////////////////////////////////////////////////////////////////////

	cout << "Ahora rellenamos una Matriz2D_2" << endl;
	
	cout << "Numero de Filas: ";
	cin >> filas2;
	cout << "Numero de Columnas: ";
	cin >> columns2;
	
	matriz2 = LeeMatriz2D_2(filas2,columns2);
	
	cout << endl << "Matriz creada despues de LeeMatriz2D_2" << endl;
	
	PintaMatriz2D_2(matriz2,filas2,columns2);

	////////////////////////////////////////////////////////////////////

	cout << endl <<"Ahora llamamos a CrearMatriz2D_1de2D_2" << endl;

	matriz2To1 = CrearMatriz2D_1de2D_2(matriz2,filas2,columns2);

	cout << endl << "Matriz2D_2 creada despues de llamar CrearMatriz2D_1de2D_2" << endl;

	PintaMatriz2D_1(matriz2To1,filas2,columns2);

	////////////////////////////////////////////////////////////////////
	
	//Para concluir tenemos que liberar las matrices creadas
	LiberaMatriz2D_1(matriz1,filas1,columns1);
	LiberaMatriz2D_2(matriz2,filas2,columns2);
	LiberaMatriz2D_1(matriz2To1,filas1,columns1);
	LiberaMatriz2D_2(matriz1To2,filas2,columns2);
	
}
	
