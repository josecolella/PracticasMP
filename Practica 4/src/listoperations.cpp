#include <iostream>
#include "list.h"



int getNumLinkedNodes(t_node *list)
{
	t_node *tmp;
	int numLinkedNodes;
	
	if(list-> next == 0) //SI la lista no tiene mas nodos enlazados
		numLinkedNodes = 1;
	else{
		for(tmp = list->next,numLinkedNodes = 1;tmp!=NULL;tmp = tmp->next)
			numLinkedNodes++; //agregamos nodos linked
	}
		
	return numLinkedNodes;
}

double getMean(t_node *list)
{
	t_node *tmp;
	int counter;
	double mean;
	
	for(tmp = list,mean = 0.0;tmp!= NULL;tmp = tmp -> next)
		mean += tmp ->data;
	
	mean = mean / getNumLinkedNodes(list);
	
	return mean;
	
}

//varianza = 1/N summation (dato - media) ^2
double getVariance(t_node *list)
{
	t_node *tmp;
	double variance,difference;
	double mean = getMean(list);
	
	for(tmp = list,variance=0.0;tmp !=NULL;tmp = tmp-> next){
		difference = tmp-> data - mean;
		variance += pow(difference,2);
	}

	variance /= getNumLinkedNodes(list);

	return variance;
	
}
