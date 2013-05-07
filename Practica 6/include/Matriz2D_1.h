/*********************************************************************/
//
// Fichero de cabecera asociado al tipo Matriz2D_1
//
// Matriz 2D dinamica de datos "int" en la que cada fila es un 
// vector dinamico independiente. 
//
// Usado en: Ejercicio-02-08
//
/*********************************************************************/

#ifndef _MATRIZ2D_1_H_
#define _MATRIZ2D_1_H_

typedef int ** Matriz2D_1;

Matriz2D_1 CreaMatriz2D_1 (int fils, int cols);
void       LiberaMatriz2D_1 (Matriz2D_1 matriz,int fils,int cols);

void	   PintaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols); 

Matriz2D_1 LeeMatriz2D_1 (int fils, int cols); 
Matriz2D_1 AleatorizaMatriz2D_1 (int fils, int cols, int MAX); 
Matriz2D_1 CopiaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols); 
Matriz2D_1 SubMatriz2D_1 (Matriz2D_1 matriz, int fil_init, int col_init, int fil_end, int col_end); 
Matriz2D_1 EliminaFilaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols, int fila);
Matriz2D_1 EliminaColumnaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols, int columna);
Matriz2D_1 TraspuestaMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols); 
Matriz2D_1 InvierteMatriz2D_1 (Matriz2D_1 matriz, int fils, int cols); 

#endif 
                
 
