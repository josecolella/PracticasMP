#include <iostream>
#include "list.h"


t_node *merge_sorted_lists(t_node *list1, t_node *list2)
{
	t_node *mergedList = NULL;
	t_node **ptrToList1 = &list1,**ptrToList2 = &list2;

	while(*ptrToList1 != NULL && *ptrToList2 != NULL){
		if((*ptrToList1) -> data < (*ptrToList2)->data){
			mergedList = insert(mergedList,(*ptrToList1)->data);
			ptrToList1 = &(*ptrToList1) -> next;
		}
		else if((*ptrToList1) -> data >= (*ptrToList2)->data){
			mergedList = insert(mergedList,(*ptrToList2)->data);
			ptrToList2 = &(*ptrToList2) -> next;
		}
		
	}

	while(*ptrToList1!= NULL)
	{
		mergedList = insert(mergedList,(*ptrToList2)->data);
		ptrToList1 = &(*ptrToList1) -> next;
	}

	while(*ptrToList2!=NULL)
	{
		mergedList = insert(mergedList,(*ptrToList2)->data);
		ptrToList2 = &(*ptrToList2) -> next;
	}

	//You can't delete 
	//list1 = deleteList(list1);
	//list2 = deleteList(list2);
		
	return mergedList;
}

