/*****************************
 * 
 * Fichero: Ejercicio4Main.cpp
 * Autor: Jose Miguel Colella
 * Descripcion: Este fichero se usa para verificar la validez de 
 * la clase Lista
 * 
 ***************************/ 
 
#include <iostream>
#include "datastructures.h"

using namespace std;

int main()
{
	Lista *l1;
	Lista *l2;
	Lista *l3;
	
	////////////////////////////////////////
	
	cout << endl << "Vamos a probar el constructor con ningun parametro" << endl;
	
	l1 = new Lista();
	
	cout << endl << "Vamos a probar isEmpty()" << endl; 
	
	if(l1->isEmpty() == false)
		cout << endl <<"La lista no esta vacia" << endl;
	else
		cout << endl << "La lista esta vacia" << endl;
	
	cout << "Vamos a probar PonerValor(1,3)" << endl;

	l1->PonerValor(1,3);

	cout << endl << "Vamos a probar printList()" << endl;

	l1->printList(); 
	//////////////////////////////////////////

	cout << endl << "Vamos a probar el constructor con un parametro de 5" << endl;

	l2 = new Lista(5);

	cout << endl << "Vamos a probar printList()" << endl;

	l2->printList();

	cout << endl << "Vamos a probar Insertar(10,6)" << endl;

	l2->Insertar(10,6);

	l2->printList();
	cout << endl << "Vamos a probar Insertar(5,1)" << endl;

	l2->Insertar(5,1);

	l2->printList();

	////////////////////////////////////////////////

	cout << endl << "Vamos a probar el constructor con dos parametro de 8, 9" << endl;

	l3 = new Lista(8,9);

	l3->printList();
	
	cout << endl << "Vamos a probar getNumNodes()" << endl;

	cout << "El numero de nodos es: " << l3->getNumNodes() << endl;

	cout << endl << "Vamos a probar Insertar(6,4)" << endl;

	l3->Insertar(6,4);

	l3->printList();

	cout << endl << "Vamos a probar ObtenerValor(4)" << endl;

	cout << "El valor en el indice 4 es: " << l3->ObtenerValor(4) << endl;

	cout << endl << "Vamos a probar Borrar(4)" << endl;

	l3->Borrar(4);

	l3->printList();
/*
	cout << endl << "Vamos a probar Borrar(1)" << endl;

	l3->Borrar(3);

	l3->printList();
	
	cout << endl << "Vamos a probar Borrar(1)" << endl;
	
	l3->Borrar(4);
	
	l3->printList();
	
	cout << endl << "Vamos a probar Borrar(1)" << endl;
	
	l3->Borrar(5);
	
	l3->printList();
*/
	cout << "El numero de nodos es: " << l3->getNumNodes() << endl;
	///////////////////////////////////////////////////////
	return 0;
}
