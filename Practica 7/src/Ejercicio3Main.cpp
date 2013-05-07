/**************************
*
* Fichero: Ejercicio3Main.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero verifico la validez de los metodos
* declarados para la clase Matriz2D_2
*
*************************/

#include <iostream>
#include "datastructures.h"

using namespace std;

int main()
{
	Matriz2D_2 *m1;
	Matriz2D_2 *m2;
	Matriz2D_2 *m3;
	Matriz2D_2 *m4;

	///////////////////////////////////////////
	
	/////////////////////////////////////////////////

	cout << "Vamos a probar el constructor por defecto" << endl;

	m1 = new Matriz2D_2();

	cout << "Comprobamos que el matriz esta vacia" << endl;

	if(m1->isEmpty() == false)
		cout << endl <<"El matriz no esta vacia" << endl;
	else
		cout << endl << "El matriz esta vacia" << endl;
	

	////////////////////////////////////////////////

	cout << endl <<"Vamos a probar el constructor con un parametro de 3" << endl;

	m2 = new Matriz2D_2(3);

	cout << endl << "Vamos a probar a printMatrix()" << endl;

	m2->printMatrix();

	cout <<  endl <<"Vamos a probar el metodo PonValor()" << endl;

	m2->PonValor(1,1,3);

	cout <<  endl <<"Vamos a probar el metodo printMatrix()" << endl;

	m2->printMatrix();

	cout << endl << "Vamos a probar el metodo LeeValor()" << endl;

	cout << endl << m2->LeeValor(1,1) << endl;
	////////////////////////////////////////////////////

	cout << endl << "Vamos a probar el constructor con dos parametros. Fils = 2, Cols = 3" << endl;

	m3 = new Matriz2D_2(2,3);

	cout << endl << "Vamos a probar el metodo printMatrix()" << endl;

	m3->printMatrix();

	//////////////////////////////////////////////////

	cout << endl << "Vamos a probar el constructor con tres parametros. Fils = 2, Cols = 3, y valor por defecto 10" << endl;

	m4 = new Matriz2D_2(2,3,10);

	cout << endl << "Vamos a probar el metodo printMatrix()" << endl;

	m4->printMatrix();

	///////////////////////////////////////////////////////

}
