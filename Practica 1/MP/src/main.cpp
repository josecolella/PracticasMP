#include <stdio.h>
#include "swap.h"

using namespace std;

int main()
{
   int a=5;
   int b=6;
   //int *ptrA = &a;
   //int *ptrB = &b;

   printf("Direccion de a: %x\n", &a);
   printf("Direccion de b: %x\n", &b);
   printf("Valor de a: %d\n", a);
   printf("Valor de b: %d\n", b);
   
   printf("Hacemos el swap\n");


   swap(&a, &b);

   printf("Direccion de a: %x\n", &a);
   printf("Direccion de b: %x\n", &b);
   printf("Valor de a: %d\n", a);
   printf("Valor de b: %d\n", b);



}
