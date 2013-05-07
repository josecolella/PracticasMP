/**************************
*
* Fichero: Ejercicio1Main.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero verifico la validez de los metodos
* declarados para la clase Queue
*
*************************/


#include <iostream>
#include "datastructures.h"

using namespace std;

int main()
{
	Queue *q = new Queue();

	q->enqueue(4);
	q->enqueue(4);
	q->enqueue(4);
	q->enqueue(4);
	q->enqueue(4);


	cout << "Probamos la sobrecarga de << " << endl;

	cout << *q;
	
	return 0;
	
}
