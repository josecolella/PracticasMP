#include <iostream>
#include "list.h"
#include "dvectoroperations.h"
#define UNA_CASILLA 1;
#define DUPLICANDO 2;

using namespace std;


double *alloc_una_casilla(double *array, int size)
{
	double *newBlock;
	
	newBlock = new double[size];
	
	if(newBlock != NULL)
	{
		for(int i=0;i<size;i++)
		{
			*(newBlock +i) = *(array+i); 
		}
		
		delete [] array;
		
		array = new double[size+1];
		
		for(int i=0;i<size;i++)
		{
			*(array +i) = *(newBlock+i); 
		}
		
		delete [] newBlock;
	}
	else
		cout << "No se ha podido crear la casilla" << endl;
		
	
	return array;
	
}

double *alloc_n_casillas(double *array, int n, int size)
{
	double *newBlock;
	
	newBlock = new double[size];
	
	if(newBlock != NULL)
	{
		for(int i=0;i<size;i++)
		{
			*(newBlock +i) = *(array+i); 
		}
		
		delete [] array;
		
		array = new double[size+n];
		
		for(int i=0;i<size;i++)
		{
			*(array +i) = *(newBlock+i); 
		}
		
		delete [] newBlock;
	}
	else
		cout << "No se ha podido crear la casilla" << endl;
		
	
	return array;
	
	
}


double *alloc_double_size_casillas(double *array, int size)
{
	double *newBlock;
	
	newBlock = new double[size];
	
	if(newBlock != NULL)
	{
		for(int i=0;i<size;i++)
		{
			*(newBlock +i) = *(array+i); 
		}
		
		delete [] array;
		
		array = new double[size * 2];
		
		for(int i=0;i<size;i++)
		{
			*(array +i) = *(newBlock+i); 
		}
		
		delete [] newBlock;
	}
	else
		cout << "No se ha podido crear la casilla" << endl;
		
	
	return array;
	
}

double *insertKeyboardValue(double *array, int size, int currentIndex,double newValue)
{
	if(currentIndex < size)
		*(array + currentIndex) = newValue;
	else{
		array = alloc_una_casilla(array, size);
		*(array + currentIndex) = newValue;
	}
	
	return array;
}

double *insertFromList(double * array, int size, int currentIndex, t_node *list)
{
	t_node *ptrToList;
	int sizeList = getNumLinkedNodes(list);
	int sizeToAdd;
	
	
	if(sizeList >= size)
	{
		sizeToAdd = sizeList - size;
		array = alloc_n_casillas(array, sizeToAdd, size);
	}
	
	for(ptrToList = list;ptrToList != NULL; ptrToList = ptrToList -> next){
			*(array + currentIndex) = ptrToList -> data;
		}

	return array;
}

void printDVector(double *array, int size)
{

	for(int i=0;i<size;i++)
		cout << "Valor en "<<i << ": " << *(array+i) << endl;
}
