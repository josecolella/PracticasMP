/**************************
*
* Fichero: Matriz2D_1.cpp
* Autor: Jose Miguel Colella
* Descripcion: En este fichero creo los algoritmos de los prototipos
* para la clase Matriz2D_1.
*
*************************/


#include <iomanip> //Incluimos esta porque usaremos setw()
#include <string.h> //Incluimos esta para usar memcpy()
#include "Matriz2D_1.h"

using namespace std;

//Metodos privados
void Matriz2D_1 :: initializeMatrix(int fils, int cols, int value)
{
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

    //Sobrecarga del operador ()
    TipoBase& Matriz2D_1 :: operator() (const int nFils, const int nCols)
    {
        if((nFils < this->rows && nFils >= 0) && (nCols < this->columns && nCols>=0))
            return this->matrix[nFils][nCols];
        else
            cerr << "Indices equivocado" << endl;
    }


    Matriz2D_1 Matriz2D_1 ::  operator+ (const Matriz2D_1 &otro)
    {
        if(this->rows == otro.rows && this->columns == otro.columns)
        {
            Matriz2D_1 tmp(this->rows);

            for(int f=0;f<this->rows;f++)
                for(int c=0;c<this->columns;c++)
                    tmp.matrix[f][c] = this->matrix[f][c] + otro.matrix[f][c]; 

                return (tmp);

            }
            else
                cerr << "El parametro tiene que tener el mismo numero de filas y columnas" << endl;

        }



        Matriz2D_1 Matriz2D_1 :: operator- (const Matriz2D_1 &otro)
        {
            if(this->rows == otro.rows && this->columns == otro.columns)
            {
                Matriz2D_1 tmp(this->rows);

                for(int f=0;f<this->rows;f++)
                    for(int c=0;c<this->columns;c++)
                        tmp.matrix[f][c] = this->matrix[f][c] - otro.matrix[f][c]; 

                    return (tmp);

                }
                else
                    cerr << "El parametro tiene que tener el mismo numero de filas y columnas" << endl;

            }

            bool Matriz2D_1 :: operator== (const Matriz2D_1 &otro)
            {
                bool isSameSize;
                bool isSameContent = true;

                if(this->rows == otro.rows && this->columns == otro.columns)
                    isSameSize = true;
                else 
                    isSameSize = false;

                if(isSameSize)
                {
                    for(int f=0;f<this->rows && isSameContent;f++)
                        for(int c=0;c<this->columns;c++)
                            if(this->matrix[f][c] != otro.matrix[f][c])
                                isSameContent = false;

                            return isSameContent;
                        }
                        else
                            return false;
            }

            bool Matriz2D_1 :: operator!= (const Matriz2D_1 &otro)
            {
                bool isSameSize;
                bool isNotSameContent = true;

                if(this->rows == otro.rows && this->columns == otro.columns)
                    isSameSize = false;
                else 
                    isSameSize = true;

                if(!isSameSize)
                {
                    for(int f=0;f<this->rows && isNotSameContent;f++)
                        for(int c=0;c<this->columns;c++)
                            if(this->matrix[f][c] == otro.matrix[f][c])
                                isNotSameContent = false;

                        return isNotSameContent;
                }
                else
                            return true;
            }


            ostream & operator << (ostream & out, const Matriz2D_1 & otro)
            {
                       for (int f=0; f<otro.rows; f++) {
                        for (int c=0; c<otro.columns; c++)
            out << setw(4) << otro.matrix[f][c]; // acceso a un elemento
                 out << "\n"; // cada fila se muestra en una linea diferente
             }

             return (out);
         }

//Destructor
         Matriz2D_1 :: ~Matriz2D_1(void)
         {
            LiberaMemoria();
        }

//Metodos
        bool Matriz2D_1 :: isEmpty() const
        {
            return rows == 0 ? true : false;
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
