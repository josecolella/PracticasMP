/********************************
*
* Fichero: polygon.h
* Autor: Jose Miguel Colella
* Descripcion: fichero que describe las estructuras Punto2D
* que contiene dos TipoDeData que son coodenadas x e y
* Tambien se ha definido el Nodo que contiene los dos puntos 
* y un puntero que representa un enlace al proximo punto
*
********************************/

#ifndef _POLYGON_H_
#define _POLYGON_H_


typedef double TipoDeData;

struct Punto2D
{
	TipoDeData x;
	TipoDeData y;
};

typedef struct Nodo
{
	Punto2D punto;
	struct Nodo *next;
}t_node;

typedef t_node * Poligono;
#endif
