/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2011-2012
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
/*********************************************************************/

#include <iostream>
using namespace std;

int suma (int, int);
int resta (int, int);
int multiplica (int, int);
int divide (int, int);


int main (void)
{
   int num1, num2; 

   cout << "Introduce un numero: "; 
   cin >> num1; 
   cout << "Introduce otro numero: "; 
   cin >> num2; 

   cout << "La suma es = " << suma (num1, num2) << "\n"; 
   cout << "La resta es = " << resta (num1, num2) << "\n"; 
   cout << "La multiplicaci�n es = " << multiplica (num1, num2) << "\n"; 
   cout << "La divisi�n es = " << divide (num1, num2) << "\n"; 

   return (0);
}



int suma (int a, int b)
{
   return (a+b); 
}

int resta (int a, int b)
{
   return (a-b); 
}

int multiplica (int a, int b)
{
   return (a*b); 
}

int divide (int a, int b)
{
   return (a/b); 
}
 
                
 
