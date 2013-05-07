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
	Queue *q1;
	
	cout << endl << "Vamos a probar el constructor sin parametros" << endl;
	
	q1 = new Queue();
	
	cout << endl << "Vamos a probar el metodo isEmpty()" << endl;
	
	if(q1->isEmpty() == false)
		cout << endl <<"La cola no esta vacia" << endl;
	else
		cout  << endl << "La cola esta vacia" << endl;
	
	cout << endl << "Vamos a probar el metodo enqueue(5)" << endl;
	
	q1->enqueue(5);
	
	cout << endl << "Vamos a probar el metodo printQueue()" << endl;
	
	q1->printQueue();
	
	cout << endl << "Vamos a probar el metodo enqueue(7)" << endl;
	
	q1->enqueue(7);
	
	q1->printQueue();
	cout << endl << "Vamos a probar el metodo enqueue(8)" << endl;
	
	q1->enqueue(8);
	
	q1->printQueue();
	
	cout << endl << "Vamos a probar el metodo dequeue()" << endl;
	
	q1->dequeue();
	
	q1->printQueue();
	
	cout << endl << "Vamos a probar el metodo dequeue()" << endl;
	
	q1->dequeue();
	
	q1->printQueue();
	
	cout << endl << "Vamos a probar el metodo front()" << endl;
	
	cout << endl << "El elemento en frente de la cola es: (" << q1->front() << ")" << endl;
	
	///////////////////////////////////////////////
	
	cout << endl << "Vamos a probar el constructor de copia" << endl;

	Queue *q2(q1);

	q2->printQueue();

	////////////////////////////////////////////////

	cout << endl << "Vamos a probar la sobrecarga del operador de asignacion" << endl;

	Queue *q3 = new Queue();

	cout << endl << "Antes de la asignacion" << endl;

	q3->printQueue();

	cout << "Despues de la asignacion" << endl;

	q3 = q2;

	q3->printQueue();

	//////////////////////////////////////////	


	delete q1;

	return 0;
	
}
