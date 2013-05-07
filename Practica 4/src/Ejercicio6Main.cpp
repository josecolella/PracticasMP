/**********************
 * 
 * Ejercicio6Main.cpp
 * Autor: Jose Miguel Colella
 * Clase: Metodologia de Programacion
 * 
 * Considere dos secuencias de datos ordenadas almacenadas 
 * en sendas listas. Implemente una función para
 * mezclar ordenadamente las dos secuencias en una nueva, 
 * de forma que las dos listas originales se queden
 * vacías tras realizar la mezcla y la lista resultante
 * contenga todos los datos.
***********************/ 

#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	t_node *list1 = NULL, *list2= NULL;
	t_node *mergedList;

	//Aqui estoy almacenando valores en las listas para probar si 
	//es correcta la funcion de juntar
	list1 = insert(list1, 1.0);
	list1 = insert(list1, 2.0);
	list1 = insert(list1, 4.0);
	list1 = insert(list1, 6.0);
	list1 = insert(list1, 8.0);

	cout << "Lista 1" << endl;
	printList(list1);
	cout << endl;

	list2 = insert(list2, 2.0);
	list2 = insert(list2, 3.0);
	list2 = insert(list2, 5.0);
	list2 = insert(list2, 7.0);
	list2 = insert(list2, 9.0);
	list2 = insert(list2, 10.0);

	cout << "Lista 2" << endl;
	printList(list2);
	cout << endl;


	mergedList = merge_sorted_lists(list1,list2);
	cout << "Lista fusionada" << endl;
	printList(mergedList);

	cout << endl;
	
	
	mergedList = deleteList(mergedList);

	
}	
