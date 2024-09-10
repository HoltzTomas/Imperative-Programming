//	Escribir una función que ordene las filas de una matriz de cualquier tamaño, según el valor de una determinada columna.

//La función recibirá como parámetros la matriz, la cantidad de filas, la cantidad de columnas y el número de columna a tomar como clave de ordenación, 
//teniendo en cuenta que la primera columna es la columna 1 (uno).

//Para ordenar se puede usar el bubble sort ( https://www.geeksforgeeks.org/bubble-sort/ ) o selection sort (https://www.geeksforgeeks.org/selection-sort/ )

#define MAXCOL 10

void sortByColumn(unsigned char matrix[][MAXCOL], int dimRows, int dimCols, int colOrd);
