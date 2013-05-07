/**************************
*
* Fichero: Ejercicio1Main.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero verifico la validez de los metodos
* declarados para la clase VectorDinamico
*
*************************/


#include <iostream>
#include "datastructures.h"

using namespace std;

int main()
{
	///////////////////////////////////////////////////////////

	VectorDinamico v1(4,3);

	cout << endl << "Insertamos un valor en la primera posicion" << endl;

	v1.insertValue(2);

	v1. printArray();

	cout << endl << "Vamos a probar el operador []" << endl;

	cout << v1[3] << endl;

	//////////////////////////////////////////////////////////
	
	VectorDinamico v2(4,3);

	cout << endl << "Probamos la sobrecarga del operador ==" << endl;

	cout << "v1: " << endl;

	v1.printArray();

	cout << "v2: " << endl;

	v2.printArray();

	if(v1 == v2)
		cout << "Son iguales v1 y v2" << endl;
	else
		cout << "No son iguales v1 y v2" << endl;

	//////////////////////////////////////////////////////////
	
	VectorDinamico v3(5,3);

	cout << endl << "Probamos la sobrecarga del operador !=" << endl;
	
	cout << "v2: " << endl;

	v2.printArray();

	cout << "v3: " << endl;

	v3.printArray();

	if(v2 != v3)
		cout << "No son iguales v2 y v3" << endl;
	else
		cout << "Son iguales v2 y v3" << endl;

	///////////////////////////////////////////////////////////
	
	VectorDinamico v4(4);

	cout << "Vamos a probar la sobrecarga de << " << endl;
	
	cout << v4;

	cout << "Vamos a probar la sobrecarga de >> " << endl;

	cin >> v4;

	cout << "El VectorDinamico resultante es: " << endl;
	
	cout << v4;

}
