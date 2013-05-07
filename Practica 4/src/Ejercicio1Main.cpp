/**********************
 * 
 * Ejercicio1Main.cpp
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
	t_node *list;
	
	list = leer_insertar_valores();
	printList(list);

	list = deleteList(list);

	
	return 0;



}
