/**********************
 * 
 * Ejercicio2Main.cpp
 * Autor: Jose Miguel Colella
 * Clase: Metodologia de Programacion
 * 
 * Escriba un programa para que lea una secuencia con un número 
 * indefinido de valores double hasta que se
 * introduzca un valor negativo. Estos valores
 * (excepto el último, el negativo) los almacenará en una estructura
 * de celdas enlazadas (una lista) y después mostará los valores almacenados.
***********************/ 

#include <iostream>
#include "list.h"

using namespace std;


int main(void)
{
	t_node *list = 0;
	double mean;
	
	list = leer_insertar_valores();
	printList(list);
	
	cout << "El numero de celdas enlazadas: " << getNumLinkedNodes(list) << endl;
	cout << "La media de los datos almacenados: " << getMean(list) << endl;
	cout << "La varianca de los datos almacenados: " << getVariance(list) << endl;
	 
	 
	list = deleteList(list);



}
