/**************************
*
* Fichero: Ejercicio3Main.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero verifico la validez de los metodos
* declarados para la clase Matriz2D_2
*
*************************/

#include <iostream>
#include "datastructures.h"

using namespace std;

int main()
{
	
	Matriz2D_2 m1(3);

	m1.PonValor(0,0,4);

	cout << endl << "Probamos la sobrecarga de <<" << endl;

	cout << m1 << endl;

	cout << endl << "Probamos la sobrecarga de ()" << endl;

	cout << "El valor tiene que ser 4" << endl;

	cout << "El valor es: " << m1(0,0) << endl;

	////////////////////////////////////////////////////
	
	Matriz2D_2 m2(3,3,4);
	cout << endl << "Probamos la sobrecarga de +" << endl;


	cout << "m1: " << endl;
	cout << m1 << endl; 

	cout << "m2: " << endl;
	cout  << m2 << endl;
	
	Matriz2D_2 m3 = m1 + m2;

	cout << "Matriz de suma resultante" << endl;

	cout << "m3: " << endl;
	cout << m3 << endl;

	/////////////////////////////////////////////////////
	
	cout << "Probamos la sobrecarga de -" << endl;

	Matriz2D_2 m4 = m2 - m1;

	cout << "Matriz resultante" << endl;

	cout << m4 << endl;

	//////////////////////////////////////////////////////
	
	cout << "Probamos la sobrecarga de ==" << endl;

	if(m4 == m3)
		cout << "Son iguales" << endl;
	else 
		cout << "No son iguales" << endl;

	cout << endl << "Probamos la sobrecarga de !=" << endl;

	Matriz2D_2 m5(m2);

	if(m5 != m2)
		cout << "No son iguales" << endl;
	else 
		cout << "Son iguales" << endl;

}
