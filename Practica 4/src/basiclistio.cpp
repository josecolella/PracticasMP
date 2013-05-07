#include <iostream> //Inclusion para cout, cin, endl
#include "list.h"

using namespace std;

/* Funcion para insertar nuevos elementos en la lista
 * Si no hay elementos en la lista, lo creamos como elemento cabecera
 * en vez si hay elementos
 * Funcion auxiliar
 */
t_node *insert(t_node *list, TipoData newElement)
{
	t_node *newPositiveNode=0, *tmp;
	
	newPositiveNode = new t_node;
	if(newPositiveNode!= NULL)
	{
		newPositiveNode->data = newElement;
		newPositiveNode->next = NULL;
	}
	else{
		cout << "No hay memoria para crear el nodo" << endl;
	}
	
	if(list == NULL)
			list = newPositiveNode;
	else{
		for(tmp = list;tmp ->next != NULL;tmp = tmp -> next);
			tmp -> next = newPositiveNode;
	}
	
	return list;
}

//Funcion que incluye controles sobre los datos (si es negativo) e inserta los datos en una lista
//La funcion regresa un puntero a la lista creada
t_node *leer_insertar_valores()
{
	t_node *list = NULL;
	TipoData dato;
	
	cout << "Introduzca valor double (valor negativo para terminar)): ";
		cin >> dato;

	while(dato >= 0.0)
	{
		list = insert(list,dato);
		cout << "Introduzca valor double (valor negativo para terminar)): ";
		cin >> dato;
	}
	
	return list;
}

//Funcion para imprimir el contenido de la lista
void printList(t_node *list)
{
	t_node *tmp;
	int index;
	
	if(list!= NULL){
		for(tmp = list, index = 0;tmp!= NULL;tmp = tmp-> next, index++)
		cout << "Valor en "<<index<< ": " << tmp->data << endl;
	}
	else
		cout << "La lista esta vacia" << endl;
	
}

//Esta funcion borra la lista
t_node *deleteList(t_node *list)
{
	t_node *nodeToDelete; 

	while(list!=NULL)
	{
	   nodeToDelete = list;
	   list = list -> next;
	   delete nodeToDelete;	
	}
	  
	return list;
}
