/*******************************
*
* Fichero: polygonoperations.cpp
* Autor: Jose Miguel Colella
* Descripcion: Este fichero representa 
* las implementaciones de los prototipos
* definidos para funciones sobre Poligonos
*
*******************************/

#include <iostream>
#include <math.h>
#include "polygonoperations.h"
#define CIRCUMFERENCE 360

using namespace std;

//Funcion auxiliar que la usamos para insertar punto en el Poligono
Poligono insert(Poligono polygon,Punto2D puntoToInsert)
{
	t_node *nodeToInsert=0,*tmp;

	//Creamos un nuevo nodo que se insertara en nuestro Poligono
	nodeToInsert = new t_node; 

	if(nodeToInsert != NULL)
	{
		nodeToInsert->punto.x = puntoToInsert.x;
		nodeToInsert->punto.y = puntoToInsert.y;
		nodeToInsert->next = NULL;
		
		//Si nuestro poligono esta vacio le asignamos el nodo creado
		if(polygon == NULL)
			polygon = nodeToInsert;
		else //Si no esta vacio la agregamos
		{
			for(tmp = polygon; tmp -> next != NULL; tmp = tmp -> next);
				tmp -> next = nodeToInsert;
		}		
	}
	else 
		cout << "No se ha podido crear el nodo" << endl;
		
	return (polygon);
}


Poligono CrearPoligono(Punto2D arrayDatos[], int numPuntos)
{
	Poligono polygon = NULL; //Tenemos un poligono vacio
	t_node *tmp;

	for(int i=0; i< numPuntos;i++)
		polygon = insert(polygon,arrayDatos[i]); 

	//for(tmp=polygon; tmp -> next != NULL; tmp = tmp -> next);
	//	tmp -> next = polygon; //La estructura tiene que ser circular 
 	
	return (polygon);
}

void PrintPolygon(Poligono polygon)
{
	t_node *tmp;

	for(tmp = polygon;tmp != NULL;tmp = tmp -> next)
		cout << "[x][y]: " << tmp->punto.x << " " << tmp->punto.y << endl;

}

void LiberarPoligono(Poligono polygon)
{
	t_node *tmp;
	
	while(polygon != NULL){	
		tmp = polygon;
		polygon = polygon -> next;
		delete tmp;
			
	}	

}

int GetNumLados(Poligono polygon)
{
	t_node *tmpPtr;
	int numLados;
	
	for(tmpPtr = polygon, numLados = 0;tmpPtr!=NULL;tmpPtr = tmpPtr-> next, numLados++);

		return numLados;
}

void PintaRecta(Punto2D p1, Punto2D p2)
{
	//Funcion que pinta una recta entre los dos puntos que se le pasan como argumentos
}
void PintarPoligono(Poligono polygon)
{
	//Tenemos por suponido que la funcion PintaRecta(Punto2D p1, Punto2D p2); esta implementada

	t_node *tmp;

	for(tmp=polygon;tmp->next!=NULL;tmp = tmp -> next)
		PintaRecta(tmp->punto,tmp->next->punto);
}

bool isPuntoInPolygon(Poligono polygon,Punto2D point)
{
	bool isPuntoInPolygon = false;
	t_node *tmp;

	for(tmp = polygon;tmp!=NULL && !isPuntoInPolygon;tmp = tmp -> next)
		if(tmp->punto.x == point.x && tmp->punto.y == point.y)
			isPuntoInPolygon = true;

	return isPuntoInPolygon;
}

Poligono getSmallestNode(Poligono polygon)
{
	t_node *tmp, *smallest;

	for(smallest = polygon,tmp = polygon->next;tmp!= NULL;tmp= tmp->next)
		if(smallest->punto.x > tmp->punto.x && smallest->punto.y > tmp->punto.y)
			smallest = tmp;

	return smallest;
}

Poligono getLargestNode(Poligono polygon)
{
	t_node *tmp, *largest;

	for(largest = polygon,tmp = polygon->next;tmp!= NULL;tmp= tmp->next)
		if(largest->punto.x < tmp->punto.x && largest->punto.y < tmp->punto.y)
			largest = tmp;

	return largest;
}
//Esta funcion toma como parametro un Poligono y devuelve un array con dos punteros que apuntan a tres puntos que representan
//los triangulos
Poligono * GetTwoTriangles(Poligono squarePolygon)
{
	Poligono *twoTrianglesArray = new Poligono[2];
	t_node *smallestCoordinateNode,*largestCoordinateNode;
	int counter = 0;
	//Primero tenemos que conseguir las coordenadas [x][y] mas pequenas y las 
	//coordenadas [x][y] mas grandes que representan la esquina inferior 
	//izquierda del cuadrado con su esquina superior derecha

	smallestCoordinateNode = getSmallestNode(squarePolygon);
	largestCoordinateNode = getLargestNode(squarePolygon);
	

	for(int i=0;i<2;i++){
		twoTrianglesArray[i] = insert(twoTrianglesArray[i],smallestCoordinateNode->punto);
		twoTrianglesArray[i] = insert(twoTrianglesArray[i],largestCoordinateNode->punto);
	}
	

	for(t_node *tmp = squarePolygon;tmp != NULL;tmp = tmp->next)
		if(twoTrianglesArray[0]->punto.x == tmp->punto.x && twoTrianglesArray[0]->punto.y != tmp->punto.y)
			twoTrianglesArray[0] = insert(twoTrianglesArray[0],tmp->punto);
		else if(!isPuntoInPolygon(twoTrianglesArray[0],tmp->punto))
			twoTrianglesArray[1] = insert(twoTrianglesArray[1],tmp->punto);
		
	return (twoTrianglesArray);
}

Poligono GetSubTriangle(Poligono trianglePolygon)
{
	Punto2D subTriangleCoordinates[3];
	t_node *tmp;
	Poligono subTriangle;

	tmp = trianglePolygon;
	subTriangleCoordinates[0].x = (tmp->punto.x + tmp->next->punto.x)/2;
	subTriangleCoordinates[0].y = (tmp->punto.y + tmp->next->punto.y)/2;
	subTriangleCoordinates[1].x = (tmp->next->punto.x + tmp->next->next->punto.x)/2;
	subTriangleCoordinates[1].y = (tmp->next->punto.y + tmp->next->next->punto.y)/2;
	subTriangleCoordinates[2].x = (tmp->punto.x + tmp->next->next->punto.x)/2;
	subTriangleCoordinates[2].y = (tmp->punto.y + tmp->next->next->punto.y)/2;
	
	subTriangle = CrearPoligono(subTriangleCoordinates, 3);

	return (subTriangle);
}

Poligono CrearPoligonoNLados(Punto2D center,int nLados, double radius)
{
 	Poligono polygon;
 	Punto2D point;
	t_node *tmp;

 	double angulos = CIRCUMFERENCE / nLados;	

 	for(int i=0;i<nLados;i++){
 		point.x = cos(angulos*i) * radius + center.x;
 		point.y = sin(angulos*i) * radius + center.y;
 		polygon = insert(polygon,point);
 	}

 	for(tmp = polygon;tmp->next!=NULL;tmp = tmp -> next);
 		tmp -> next = polygon;

 	return (polygon);
}

