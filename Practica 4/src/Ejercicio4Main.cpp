/**********************
 * 
 * Ejercicio4Main.cpp
 * Autor: Jose Miguel Colella
 * Clase: Metodologia de Programacion
 * 
 * Considere una secuencia de datos almacenada en una lista. 
 * Implemente una función para ordenar la secuencia empleando 
 * el método de ordenación por selección.
 *
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
	
	cout << endl;
	
	cout << "Efectuamos el selection sort sobre los datos" << endl;
	 
	list = selection_sort(list);

	printList(list);

	isOrdered = isListOrdered(list);
	if(isOrdered == true)
			cout << "La lista esta ordenada" << endl;
	else if(isOrdered == false) 
			cout << "La lista no esta ordenada" << endl;

	list = deleteList(list);



}
