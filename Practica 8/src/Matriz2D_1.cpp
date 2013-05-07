/**************************
*
* Fichero: Matriz2D_1.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero creo los algoritmos de los prototipos
* para la clase Matriz2D_1.
*
*************************/



#include <iostream>
#include <iomanip> //Incluimos esta porque usaremos setw()
#include <string.h> //Incluimos esta para usar memcpy()
#include "Matriz2D_1.h"

using namespace std;

//Metodos privados
    void Matriz2D_1 :: initializeMatrix(int fils, int cols, int value)
    {
    if(this->matrix == NULL)
        this->matrix = new int * [fils]; 

    for (int f=0; f<fils; f++) {
        matrix[f] = new int [cols]; 
    }

    for(int f=0;f<fils;f++)
        for(int c=0;c<cols;c++)
            matrix[f][c] = value; 

        this->rows = fils;
        this->columns = cols;
    }


    void Matriz2D_1 :: Copia(const Matriz2D_1 &otro)
    {
        this->rows = otro.rows;
        this->columns = otro.columns;

        this->matrix = new int * [this->rows]; 

        for (int f=0; f<this->rows; f++) {
            matrix[f] = new int [this->columns]; 
        }

        for(int f=0;f<rows;f++)
            memcpy(matrix[f],otro.matrix[f],sizeof(TipoBase) * columns);



    }

    void Matriz2D_1 :: LiberaMemoria(void)
    {
        for (int f=0; f<rows; f++)
            delete [] matrix[f];
        // Libera una fila
        delete [] matrix;
        // Libera el vector de punteros

    }


//Constructores
    Matriz2D_1 :: Matriz2D_1()
    {
    //Tenemos una matriz vacia
        matrix = NULL;
        rows = 0;
        columns = 0;

    }

    Matriz2D_1 :: Matriz2D_1(int numFilsColsSquare)
    {
        initializeMatrix(numFilsColsSquare,numFilsColsSquare,0);
    }

    Matriz2D_1 :: Matriz2D_1(int fils, int cols)
    {

        initializeMatrix(fils,cols,0);
    }

    Matriz2D_1 :: Matriz2D_1(int fils, int cols, int defaultValue)
    {
        initializeMatrix(fils,cols,defaultValue);
    }

    Matriz2D_1 :: Matriz2D_1(const Matriz2D_1 & otro) 
    {
        Copia(otro);
    }


//Sobrecarga de operadores
    
    Matriz2D_1& Matriz2D_1 :: operator= (const Matriz2D_1 & otro)
    {
        if(this != &otro) //Evitar Autoasignacion
        {
            LiberaMemoria();    
            Copia(otro);
        }

        return (*this); //devuelve el objeto implicito
    }

//Sobrecarga del operador de asignaciona

    Matriz2D_1& Matriz2D_1 :: operator= (const TipoBase &otro)
    {

        for(int f=0;f<rows;f++)
            for(int c=0;c<columns;c++)
                this->matrix[f][c] = otro; 

        return (*this); //devuelve el objeto implicito

    }  

//Destructor
Matriz2D_1 :: ~Matriz2D_1(void)
{
    LiberaMemoria();
}

//Metodos
bool Matriz2D_1 :: isEmpty() const
{
    return matrix == NULL ? true : false;
}

void Matriz2D_1 :: PonValor (int fila, int col, TipoBase val)
{
    //Si la matriz actual esta vacia tenemos que crearla
    if(matrix == NULL)
    {
        initializeMatrix(fila,col,0);
    }
    matrix[fila][col] = val;
}

TipoBase Matriz2D_1 :: LeeValor(int fila, int col) const
{
    if(fila <= rows && col <= columns)
        return matrix[fila][col];
    else
        cerr << "Parametros Incorrectos" << endl;
}

void Matriz2D_1 :: printMatrix() const
{
    for (int f=0; f<rows; f++) {
        for (int c=0; c<columns; c++)
            cout << setw(4) << matrix[f][c]; // acceso a un elemento
        cout << endl; // cada fila se muestra en una linea diferente
    }
}
