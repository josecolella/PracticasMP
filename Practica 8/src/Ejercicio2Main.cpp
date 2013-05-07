/**************************
*
* Fichero: Ejercicio2Main.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero verifico la validez de los metodos
* declarados para la clase Matriz2D_1
*
*************************/

#include <iostream>
#include "datastructures.h"

using namespace std;

int main()
{
	Matriz2D_1 *m1;
	Matriz2D_1 *m2;
	Matriz2D_1 *m3;
	Matriz2D_1 *m4;

	///////////////////////////////////////////
	
	/////////////////////////////////////////////////

	cout << "Vamos a probar el constructor por defecto" << endl;

	m1 = new Matriz2D_1();

	cout << "Comprobamos que el matriz esta vacia" << endl;

	if(m1->isEmpty() == false)
		cout << endl <<"El matriz no esta vacia" << endl;
	else
		cout << endl << "El matriz esta vacia" << endl;
	

	////////////////////////////////////////////////

	cout << endl <<"Vamos a probar el constructor con un parametro de 3" << endl;

	m2 = new Matriz2D_1(3);

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

	m3 = new Matriz2D_1(2,3);

	cout << endl << "Vamos a probar el metodo printMatrix()" << endl;

	m3->printMatrix();

	//////////////////////////////////////////////////

	cout << endl << "Vamos a probar el constructor con tres parametros. Fils = 2, Cols = 3, y valor por defecto 10" << endl;

	m4 = new Matriz2D_1(2,3,10);

	cout << endl << "Vamos a probar el metodo printMatrix()" << endl;

	m4->printMatrix();

	///////////////////////////////////////////////////////
	
	cout << endl << "Vamos a probar el constructor de copia de la ultima matriz" << endl;

	Matriz2D_1 *m5(m4);

	m5->printMatrix();

	///////////////////////////////////////////////////////

	cout << "Vamos a probar la primera sobrecarga del operador =" << endl;

	m3 = m5;

	m3->printMatrix();

	///////////////////////////////////////////////////////

	//Liberamos m1 y m2;

	delete m1;
	delete m2;


}
