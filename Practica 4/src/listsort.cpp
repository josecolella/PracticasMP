#include <iostream>
#include "list.h"

bool isListOrdered(t_node *list)
{
	bool isOrdered;
	
	if(list == NULL)
		isOrdered = false;
	else if(list-> next == NULL)
		isOrdered = true;
	else{
		isOrdered = true;
		t_node *tmp,*nextNode;
		for(tmp = list; tmp->next != NULL && isOrdered;tmp = tmp -> next)
			if(tmp -> data > tmp->next-> data)
				isOrdered = false;
	}		
		return isOrdered;
}

void swap(TipoData *num1, TipoData *num2)
{
	TipoData aux = *num1;
	*num1 = *num2;
	*num2 = aux;
}



t_node *selection_sort(t_node *list)
{
	t_node *tmp, *minNode;

	if(list != NULL){
		for(tmp = list;tmp->next != NULL;tmp = tmp -> next){
			for(minNode = tmp -> next;minNode!= NULL;minNode = minNode->next)
				if(minNode ->data < tmp->data)
					swap(&tmp ->data, &minNode->data);
		}
	}
	return list;
}
