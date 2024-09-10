//	Escribir una función que ordene las filas de una matriz de cualquier tamaño, según el valor de una determinada columna.

// La función recibirá como parámetros la matriz, la cantidad de filas, la cantidad de columnas y el número de columna a tomar como clave de ordenación,
// teniendo en cuenta que la primera columna es la columna 1 (uno).

// Para ordenar se puede usar el bubble sort ( https://www.geeksforgeeks.org/bubble-sort/ ) o selection sort (https://www.geeksforgeeks.org/selection-sort/ )

#define MAXCOL 10

void sortByColumn(unsigned char matrix[][MAXCOL], int dimRows, int dimCols, int colOrd);
void swapRows(unsigned char matrix[][MAXCOL], int dimCols, int row1, int row2);

void swapColumns(unsigned char matrix[][MAXCOL], int dimCols, int row1, int row2){
            // Quiero swapear las columnas
            unsigned char temp[dimCols];

            //Me guardo el vector de la fila 1
            for (int j = 0; j < dimCols; j++)
            {
                temp[j] = matrix[row1][j];
            }

            //Me guardo la fila 2 en fila 1
            for (int j = 0; j < dimCols; j++)
            {
                matrix[row1][j] = matrix[row2][j];
            }

            //Guardo aux en fila 2
            for (int j = 0; j < dimCols; j++)
            {
                matrix[row2][j] = temp[j];
            }
}

// Selection sort way
void sortByColumn(unsigned char matrix[][MAXCOL], int dimRows, int dimCols, int colOrd)
{
    int min_index;
    // The first step is to go through the entire vector and find the smallest value
    // We gonna do that dimCols - 1 times
    for (int i = 0; i < dimCols - 1; i++)
    {
        min_index = i;
        // Find the min
        for (int j = 1; j < dimCols; j++)
            if (matrix[j][colOrd] < matrix[min_index][colOrd])
                min_index = j;

        // Swap if i wasnt the min
        if (min_index != i)
            swapColumns(matrix, dimCols, i, min_index);
        
    }
}
