/**************************
*
* Fichero: Ejercicio5Main.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero verifico la validez de los metodos
* declarados para la clase Stack
*
*************************/



#include <iostream>
#include "datastructures.h"

using namespace std;

int main()
{
	
	Stack *s = new Stack();

	s->push(3);
	s->push(4);
	s->push(5);
	s->push(6);
	
	cout << "Probamos la sobrecarga de << " << endl;

	cout << *s; 

	delete s;
	return 0;
}
