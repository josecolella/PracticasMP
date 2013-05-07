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
	VectorDinamico *v1;
	VectorDinamico *v2;
	VectorDinamico *v3;

	/////////////////////////////////////////////////

	cout << "Vamos a probar el constructor por defecto" << endl;

	v1 = new VectorDinamico();

	cout << "Comprobamos que el vector esta vacio" << endl;

	if(v1->isEmpty() == false)
		cout << endl <<"El vector no esta vacio" << endl;
	else
		cout << endl << "El vector esta vacio" << endl;
		
	cout << endl << "Vamos a probar insertValue()" << endl;
	
	v1->insertValue(3);
	
	cout << endl << "Vamos a probar a printArray()" << endl;
	
	v1->printArray();

	////////////////////////////////////////////////

	cout << endl <<"Vamos a probar el constructor con un parametro de 5" << endl;

	v2 = new VectorDinamico(5);

	cout <<  endl <<"Vamos a probar el metodo insertValue()" << endl;

	v2->insertValue(6);

	cout <<  endl <<"Vamos a probar el metodo printArray()" << endl;

	v2->printArray();

	cout << "Vamos a probar el metodo insertValue() mas veces" << endl;

	v2->insertValue(6);
	v2->insertValue(5);
	v2->insertValue(7);
	v2->insertValue(8);
	v2->insertValue(10);

	cout << "Vamos a probar el metodo printArray()" << endl;

	v2->printArray();

	////////////////////////////////////////////////////

	cout << endl << "Vamos a probar el constructor con dos parametros de 7, y valor defecto 10" << endl;

	v3 = new VectorDinamico(7,10);

	cout << endl << "Vamos a probar el metodo printArray()" << endl;

	v3->printArray();

	cout << endl << "Vamos a probar getValue(int index)" << endl;

	cout << endl <<"El segundo elemento es: " << v3->getValue(1) << endl;

	//////////////////////////////////////////////////

	cout << endl << "Vamos a probar el metodo changeArraySize()" << endl;

	v3->changeArraySize(8);
	
	cout << endl << "Vamos a probar el metodo getSize()" << endl;
	
	cout << endl << "El tamano es: " << v3->getSize() << endl;

	cout << endl << "Vamos a robar el metodo getOccupiedCells()"  << endl;

	cout << "El numero de celdas ocupadas es: " << v3->getOccupiedCells() << endl;

	///////////////////////////////////////////////////////


	return 0;
}
