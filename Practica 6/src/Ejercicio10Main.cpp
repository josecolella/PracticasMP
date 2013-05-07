/**********************************************
*
* Fichero: Ejercicio10Main
* Autor: Jose Miguel Colella
* Descripcion: Este fichero comprueba las funciones creadas para gestionar poligonos
* Las dos funciones que no fueron comprobadas fueron PintarPoligono, debido a que llama
* a la funcion PintaRecta que "supuestamente" tiene que esta ya implemetada
*
**********************************************/


#include <iostream>
#include "polygons.h"
#define TRIANGLE_SIDES 3
#define SQUARE_SIDES 4
#define TWO_TRIANGLES 2

using namespace std;

int main()
{

	int numLados;
	double radius;
	
	Punto2D trianglePoints[TRIANGLE_SIDES];
	Punto2D squarePoints[SQUARE_SIDES];
	Punto2D center;
	

	Poligono polygon;
	Poligono subTrianglePolygon;
	Poligono fourSidedPolygon;
	Poligono *twoTriangles;
	Poligono nSidedPolygon;

	//////////////////////////////////////////
	cout << "Primero hay que inserir los puntos del triangulo" << endl;

	for(int i=0;i<TRIANGLE_SIDES;i++){
		cout << i << "-> [x][y]: ";
		cin >> trianglePoints[i].x >> trianglePoints[i].y;
	}

	cout << endl << "Ahora vamos a probar CrearPoligono" << endl;

	polygon = CrearPoligono(trianglePoints,TRIANGLE_SIDES);

	cout << endl << "El poligono creado tienes los proximos valores" << endl;

	PrintPolygon(polygon);

	//////////////////////////////////////////

	cout << "El poligono creado tiene " << GetNumLados(polygon) << " lados" <<endl;

	/////////////////////////////////////////

	cout << endl << "Ahora vamos a probar GetsubTrianglePolygon sobre el poligono de tres Punto2D" << endl;

	subTrianglePolygon = GetSubTriangle(polygon);

	cout << endl << "Ahora vamos a probar CrearPoligono" << endl;

	PrintPolygon(subTrianglePolygon); 


	////////////////////////////////////////////////

	cout << endl << "Ahora tenemos que probar a insertar puntos en un poligono de cuatro puntos" << endl;

	for(int i=0;i<SQUARE_SIDES;i++){
		cout << i << "-> [x][y]: ";
		cin >> squarePoints[i].x >> squarePoints[i].y;
	}

	cout << endl << "Ahora vamos a probar CrearPoligono" << endl;

	fourSidedPolygon = CrearPoligono(squarePoints,SQUARE_SIDES);

	cout << endl << "El poligono creado tienes los proximos valores" << endl;

	PrintPolygon(fourSidedPolygon);

	cout << "El poligono creado tiene " << GetNumLados(fourSidedPolygon) << " lados" <<endl;

	///////////////////////////////////////////////////////////////

	cout << endl << "Ahora comprobamos la funcion GetTwoTriangles que nos tiene que devolver dos triangulos" << endl;

	twoTriangles = GetTwoTriangles(fourSidedPolygon);

	cout << endl << "El primer triangulo tiene " << GetNumLados(twoTriangles[0]) << " lados" <<endl;

	PrintPolygon(twoTriangles[0]);

	cout << endl;

	cout << endl << "El segundo triangulo tiene " << GetNumLados(twoTriangles[1]) << " lados" <<endl;

	PrintPolygon(twoTriangles[1]);

	cout << endl;


	/////////////////////////////////////////////////////////////

	cout << endl << "Ahora vamos a comprobar la funcion CrearPoligonoNLados" << endl;

	cout << endl << "Hay que introducir un centro, numero de lados, y radio" << endl;

	
	cout << endl << "Introducir la x del centro" << endl;

	cin >> center.x;

	cout << endl << "Introducir la x del centro" << endl;
	
	cin >> center.y;

	cout << endl << "Introducir el numero de lados" << endl;
	
	cin >> numLados;

	cout << endl << "Introducir el radio" << endl;
	
	cin >> radius;

	nSidedPolygon = CrearPoligonoNLados(center,numLados,radius);

	PrintPolygon(nSidedPolygon);

	cout << endl;

	/////////////////////////////////////////////////////////////
	//Al concluir tenemos que liberar los polinomios creados
	LiberarPoligono(polygon);
	LiberarPoligono(subTrianglePolygon);
	LiberarPoligono(fourSidedPolygon);
	LiberarPoligono(twoTriangles[0]);
	LiberarPoligono(twoTriangles[1]);
	LiberarPoligono(nSidedPolygon);
}
