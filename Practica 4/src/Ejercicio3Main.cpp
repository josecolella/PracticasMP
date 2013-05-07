/**********************
 * 
 * Ejercicio3Main.cpp
 * Autor: Jose Miguel Colella
 * Clase: Metodologia de Programacion
 * 
 * Utilizando como base el problema 1, escribir un programa que 
 * lea una secuencia de valores y los almacene en
 * una lista. Escribir una función que determine si 
 * la secuencia está ordenada.
***********************/ 

#include <iostream>
#include "list.h"

using namespace std;


int main(void)
{
	t_node *list = 0;
	bool isOrdered;

	list = leer_insertar_valores();
	printList(list);
	
	isOrdered = isListOrdered(list);
	if(isOrdered == true)
			cout << "La lista esta ordenada" << endl;
	else if(isOrdered == false) 
			cout << "La lista no esta ordenada" << endl;

	list = deleteList(list);



}
