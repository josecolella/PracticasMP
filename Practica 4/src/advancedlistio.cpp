#include <iostream>
#include "list.h"

using namespace std;

//implemente una fucntion para insertar un dato en su posicion correcta
t_node *organized_insert(t_node *list,TipoData newData)
{
	t_node *newNode,*tmp;
	
	newNode = new t_node;
	if(newNode != NULL)
	{
		newNode -> data = newData;
		newNode -> next = NULL;
	}
	else{
		cout << "No hay memoria para crear el nodo de la lista" << endl;
	}


	if(list==NULL || list->data > newData){
		newNode->next=list;
		list=newNode;
	}
	else{
		for(tmp=list; tmp->next!=NULL && tmp->next->data < newData; tmp=tmp->next);
			newNode->next=tmp->next;
			tmp->next=newNode;
    }
				
				

	return list;
}

t_node *leer_insertar_organizado_valores()
{
	t_node *list = NULL;
	TipoData dato;
	
	cout << "Introduzca valor double (valor negativo para terminar)): ";
		cin >> dato;

	while(dato >= 0.0)
	{
		list = organized_insert(list,dato);
		cout << "Introduzca valor double (valor negativo para terminar)): ";
		cin >> dato;
	}
	
	return list;
}
//Implemente una funcion para, dado un datom eliminar la cela que lo contiene
t_node *delete_element(t_node *list, TipoData element_to_delete)
{
	t_node *tmp, *nextNode;

	if(list ->data == element_to_delete){
		tmp = list;
		list = list -> next;
		delete tmp;
	}
	else{
		for(tmp = list, nextNode = list->next; nextNode!= NULL; tmp = tmp->next,nextNode = nextNode -> next)
			if(nextNode->data == element_to_delete){
				tmp->next = nextNode -> next;
				delete nextNode;
			}
	}

	return list;
}

