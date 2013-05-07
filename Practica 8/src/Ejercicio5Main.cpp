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
	Stack *s1;
	
	////////////////////////////////////////////////////
	
	cout << endl << "Vamos a probar el constructor sin parametros" << endl;
	
	s1 = new Stack();
	
	cout << endl << "Vamos a probar el metodo isEmpty()" << endl;
	
	if(s1->isEmpty() == false)
		cout << endl <<"La lista no esta vacia" << endl;
	else
		cout << endl << "La lista esta vacia" << endl;
	
	cout << endl << "Vamos a probar el metodo push(6)" << endl;
	
	s1->push(6);
	
	cout << endl << "Vamos a probar el metodo printStack()" << endl;
	
	s1->printStack();
	
	cout << endl << "Vamos a probar el metodo push(5)" << endl;
	
	s1->push(5);
	
	cout << endl << "Vamos a probar el metodo push(5)" << endl;
	
	s1->push(5);
	
	cout << endl << "Vamos a probar el metodo top()" << endl;
	
	cout << "El elemento encima de la pila es: (" << s1->top() << ")" <<endl;
	
	cout << endl << "Vamos a probar el metodo printStack()" << endl;
	
	s1->printStack();
	
	cout << endl << "Vamos a probar el metodo pop()" << endl;
	
	s1->pop();
	
	s1->printStack();
	
	cout << endl << "Vamos a probar el metodo pop()" << endl;
	
	s1->pop();
	
	s1->printStack();
	
	cout << endl << "Vamos a probar el metodo pop()" << endl;
	
	s1->pop();
	
	s1->printStack();
	
	if(s1->isEmpty() == false)
		cout << endl <<"La lista no esta vacia" << endl;
	else
		cout << endl << "La lista esta vacia" << endl;
	

	cout << endl << "Vamos a probar el metodo push(5)" << endl;
	
	s1->push(5);
	
	s1->printStack();
	////////////////////////////////////////////////////////
	
	cout << endl << "Vamos a probar el constructor de copia" << endl;

	Stack *s2(s1);

	s2->printStack();

	//////////////////////////////////////////////////////

	cout << endl << "Vamos a probar la sobrecarga del operador de asignacion" << endl;

	Stack *s3 = new Stack();

	cout << "Antes de la asignacion" << endl;

	s3->printStack();
	
	cout <<endl << "Despues de la asignacion:\nLa pila s3 tiene los siguientes valores" << endl;

	s3 = s2;

	s3->printStack();

	////////////////////////////////////////////////////////

	delete s1;


	return 0;
}
