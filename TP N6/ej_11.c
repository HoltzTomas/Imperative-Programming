//	Escribir una función que ordene las filas de una matriz de cualquier tamaño, según el valor de una determinada columna.

// La función recibirá como parámetros la matriz, la cantidad de filas, la cantidad de columnas y el número de columna a tomar como clave de ordenación,
// teniendo en cuenta que la primera columna es la columna 1 (uno).

// Para ordenar se puede usar el bubble sort ( https://www.geeksforgeeks.org/bubble-sort/ ) o selection sort (https://www.geeksforgeeks.org/selection-sort/ )

#include <assert.h>
#include <stdio.h>

#define MAXCOL 10

void sortByColumn(int matrix[][MAXCOL], int dimRows, int dimCols, int colOrd);
void swapRows(int matrix[][MAXCOL], int dimCols, int row1, int row2);

int checkVector(const int v1[], const int v2[], int dim)
{
    for (int i = 0; i < dim; i++)
        if (v1[i] != v2[i])
            return 0;
    return 1;
}

int main(void)
{
    int m[][MAXCOL] = {{1, 2, 3, 4, 5},
                       {6, 2, 8, 9, 10},
                       {3, 5, 8, 2, 1},
                       {8, 7, 3, 6, 7}};

    int m2[][MAXCOL] = {{1, 2, 3, 4, 5},
                        {6, 2, 8, 9, 10},
                        {3, 5, 8, 2, 1},
                        {8, 7, 3, 6, 7}};

    // La matriz no cambia
    sortByColumn(m, 4, 5, 2);

    for (int i = 0; i < 4; i++)
        assert(checkVector(m[i], m2[i], 5));

    sortByColumn(m, 4, 5, 1);
    assert(checkVector(m[0], m2[0], 5));
    assert(checkVector(m[1], m2[2], 5));
    assert(checkVector(m[2], m2[1], 5));
    assert(checkVector(m[3], m2[3], 5));

    sortByColumn(m, 4, 5, 3);
    assert(checkVector(m[0], m2[0], 5) || checkVector(m[0], m2[3], 5));
    assert(checkVector(m[1], m2[0], 5) || checkVector(m[1], m2[3], 5));
    assert(checkVector(m[2], m2[1], 5) || checkVector(m[2], m2[2], 5));
    assert(checkVector(m[3], m2[1], 5) || checkVector(m[3], m2[2], 5));

    printf("OK!\n");
    return 0;
}

void swapRows(int matrix[][MAXCOL], int dimCols, int row1, int row2)
{
    // Quiero swapear las filas
    int temp[MAXCOL];  // Usa int para las filas en lugar de unsigned char.

    // Me guardo el vector de la fila 1
    for (int j = 0; j < dimCols; j++)
    {
        temp[j] = matrix[row1][j];
    }

    // Me guardo la fila 2 en fila 1
    for (int j = 0; j < dimCols; j++)
    {
        matrix[row1][j] = matrix[row2][j];
    }

    // Guardo temp en fila 2
    for (int j = 0; j < dimCols; j++)
    {
        matrix[row2][j] = temp[j];
    }
}

// Selection sort para ordenar las filas basadas en una columna específica
void sortByColumn(int matrix[][MAXCOL], int dimRows, int dimCols, int colOrd)
{
    int min_index;
    colOrd--;  // Ajustar colOrd para que sea 0-indexado.
    
    for (int i = 0; i < dimRows - 1; i++)
    {
        min_index = i;
        
        // Encontrar el índice de la fila con el valor mínimo en la columna colOrd
        for (int j = i + 1; j < dimRows; j++)
        {
            if (matrix[j][colOrd] < matrix[min_index][colOrd])
            {
                min_index = j;
            }
        }

        // Swap si la fila mínima no es la actual
        if (min_index != i)
        {
            swapRows(matrix, dimCols, i, min_index);
        }
    }
}
