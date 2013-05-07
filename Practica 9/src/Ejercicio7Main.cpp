#include <iostream>
#include "Conjunto.h"
#include "datastructures.h"

using namespace std;

int main()
{
	
	
	///////////////////////////////////////////////////////////////////7

	cout << endl << "Vamos a probar el constructor sin parametros" << endl;
	
	Conjunto c1;

	cout << endl << "Vamos a probar el metodo isEmpty()" << endl;
	
	if(c1.isEmpty() == false)
		cout << endl << "La cola no esta vacia" << endl;
	else
		cout  << endl << "La cola esta vacia" << endl;
	
	////////////////////////////////////////////////////////////////
	
	cout << "Vamos a probar el constructor con un parametro" << endl;

	Conjunto c2(5);

	c2.printSet();
	
	/////////////////////////////////////////////////////////////////

	cout << "Vamos a probar el constructor de copia" << endl;

	Conjunto *c3 = new Conjunto(c2);

	c3->printSet();

//////////////////////////////////////////////////////

	cout << endl << "Vamos a probar el operador de sobrecarga" << endl;

	Conjunto *c4 = new Conjunto();

	cout << endl << "Antes de la asignacion" << endl;

	c4 = c3;

	cout << endl << "Despues de la asignacion" << endl;
	c4->printSet();

	///////////////////////////////////////////////////////

	return 0;
	
}
