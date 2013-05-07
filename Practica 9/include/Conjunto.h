#include "Lista.h"

#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_


typedef int TipoBase;

class Conjunto
{

	private:
		Lista *set;
		void Copia(const Conjunto & otro);
		void LiberaMemoria();
	public:
		//Constructor
		Conjunto();
		Conjunto(TipoBase data);
		//Constructor de Copia
		Conjunto(const Conjunto &otro);
		//Destructor
		~Conjunto();
		//metodos
		bool isEmpty() const;
		Conjunto & operator= (const Conjunto &otro);
		int getNumSetElements() const;
		bool isContained(TipoBase data) const;
		void printSet() const;


};




#endif