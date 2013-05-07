/*******************************
* Fichero: Matriz2D_2.h
* Autor: Jose Miguel Colella
* Descripcion: Este fichero cabecera contiene los prototipos para la
* estructura Matriz2D_2.
*
*******************************/

#ifndef _MATRIZ2D_2_H_
#define _MATRIZ2D_2_H_

typedef int ** Matriz2D_2;

Matriz2D_2 CreaMatriz2D_2(int fils, int cols);
void LiberaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
void PintaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
Matriz2D_2 LeeMatriz2D_2 (int fils, int cols); 
Matriz2D_2 AleatorizaMatriz2D_2 (int fils, int cols, int MAX);
Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz, int fil_init, int col_init, int fil_end, int col_end);
Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int fila);
Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columna);
Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);

#endif
