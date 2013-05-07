/**********************
 * 
 * Ejercicio7MainB.cpp
 * Autor: Jose Miguel Colella
 * Clase: Metodologia de Programacion
 * 
 * El segundo tomará los valores a insertar desde una lista.
***********************/
#include <iostream>
#include "list.h"
#include "dvectoroperations.h"
#define INITIAL_SIZE 5

using namespace std;


int main(void)
{
	int tam = INITIAL_SIZE, currentIndex = 0;
	double *vectorInicial = new double[INITIAL_SIZE];
	t_node *list = 0; //inicialmente no apunta a nada

	list = leer_insertar_valores();
	
	//El segundo tomará los valores a insertar desde una lista
	////////////////////////////////////////////////////////////////////
	cout << "\nLa lista contiene los siguientes valores " << endl;
	printList(list);
	cout << endl << endl;
	
	cout << "El array dinamico contiene los siguientes valores" << endl;
	vectorInicial = insertFromList(vectorInicial,tam,currentIndex,list);
	//Incrementamos el indice actual y el tamaño
	currentIndex++; tam++;
	printDVector(vectorInicial,tam);
		
	delete [] vectorInicial;
	list = deleteList(list);
	////////////////////////////////////////////////////////////////////
	return 0;
}
