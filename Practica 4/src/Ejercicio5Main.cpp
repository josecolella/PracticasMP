/**********************
 * 
 * Ejercicio5Main.cpp
 * Autor: Jose Miguel Colella
 * Clase: Metodologia de Programacion
 * 
 * Considere una secuencia ordenada de datos almacenada en una lista.
 * a) Implemente una función para insertar un nuevo dato en su posición 
 * correcta.
 * b) Implemente una función para, dado un dato,
 * eliminar la celda que lo contiene.
***********************/ 

#include <iostream>
#include "list.h"

using namespace std;

int main(void)
{
	t_node *list = 0;
	double dato_a_eliminar;
	double dataToEnter;

	list = leer_insertar_organizado_valores();
	
	cout << endl;
	
	printList(list);

	cout << endl;

	cout << "Introduzca un valor y se insertara organizadamente en la lista (NO NEGATIVO): " << endl;
	do{
	    cin >> dataToEnter;	
	}while(dataToEnter < 0);
	
	list = organized_insert(list,dataToEnter);

	printList(list);

	cout << endl;
	cout << "Que valor quiere eliminar: ";
	cin >> dato_a_eliminar;

	list = delete_element(list,dato_a_eliminar);

	cout << endl;
	printList(list);

	list = deleteList(list);
}
