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
	Lista l1(4,3);

	cout << endl << "Probamos la sobrecarga de <<" << endl;

	cout << l1;

	cout << endl << "Probamos la sobrecarga del operador []" << endl;

	l1.Insertar(1,1);

	cout << l1; 

	cout << endl;
	
	cout << "El valor en primera posicion es: " << l1[1]; 

	cout << endl;


	/////////////////////////////////////////////////////////////
	
	
	cout << "Probamos la sobrecarga de >>" << endl;

	cin >> l1;

	cout << l1;



}