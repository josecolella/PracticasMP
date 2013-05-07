/**********************
 * 
 * Ejercicio7MainA.cpp
 * Autor: Jose Miguel Colella
 * Clase: Metodologia de Programacion
 * 
 * El primero tomará los valores a insertar en el vector dinámico 
 * directamente del teclado.
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
	double dataToEnter;
	
	
	//El primero tomará los valores a insertar en el vector dinámico directamente del teclado.
	////////////////////////////////////////////////////////////////////
	cout << "Introduzca valor double (valor negativo para terminar)): ";
		cin >> dataToEnter;

	while(dataToEnter >= 0.0)
	{
		vectorInicial = insertKeyboardValue(vectorInicial,tam,currentIndex, dataToEnter);
		//Incrementamos el indice actual y el tamaño
		currentIndex++; tam++;
		cout << "Introduzca valor double (valor negativo para terminar)): ";
		cin >> dataToEnter;
	}
	
	printDVector(vectorInicial,tam);
		
	delete [] vectorInicial;
	////////////////////////////////////////////////////////////////////
	return 0;
}
