/*************************************
*
* Fichero: poligonoperations.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero cabecera define
* el prototipo de las operationes que se pueden
* efectuar sobre el tipo Poligono
*
**************************************/


#include "polygon.h"

#ifndef _POLIGONOPERATIONS_H_
#define _POLIGONOPERATIONS_H_

//Función auxiliar para insertar los puntos en el Poligono
Poligono insert(Poligono polygon,Punto2D puntoToInsert);
///////////////////////////////////////////////////
Poligono CrearPoligono(Punto2D arrayDatos[], int numPuntos);
//He creado una funcion que nos imprima los puntos del poligono
void PrintPolygon(Poligono polygon);
void LiberarPoligono(Poligono polygon);
int GetNumLados(Poligono polygon);
void PintaRecta(Punto2D p1, Punto2D p2);
void PintarPoligono(Poligono polygon); 
//Funciones auxiliares
bool isPuntoInPolygon(Punto2D point);
Poligono getSmallestNode(Poligono polygon);
Poligono getLargestNode(Poligono polygon);
///////////////////////
Poligono * GetTwoTriangles(Poligono squarePolygon);
Poligono GetSubTriangle(Poligono trianglePolygon);
Poligono CrearPoligonoNLados(Punto2D center,int nLados, double radius);


#endif
