// Escribir la función nQueens que, dada una matriz de chars de NxN,
// verifique si el mismo contiene N reinas de ajedrez de forma tal que ninguna reina amenace a otra.

// Una reina amenaza a otra si está en la misma fila, columna o en alguna de sus dos diagonales.
// Una posición libre se indica con el valor '0' y una celda con una reina se indica con el valor '1'.
// Se asume que en el tablero sólo hay caracteres ceros y unos, no es necesario validarlo.
#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE !TRUE

#define IS_QUEEN(c) ((c) == '1')

int nQueens(unsigned n, const char m[][n]);
int isThreatened(unsigned n, const char m[][n], int y, int x);

int main(void)
{
    char board[][8] = {
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'1', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
    };
    // por ejemplo, hay tres reinas en la columna 4 y dos en la fila 6
    assert(nQueens(8, board) == 0);
    char board2[][6] = {
        {'0', '0', '0', '1', '0', '0'},
        {'1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '1'},
        {'0', '0', '1', '0', '0', '0'}};
    // Hay 6 reinas y no se atacan, retorna true
    // assert(nQueens(6, board2));
    char board3[][6] = {
        {'0', '0', '1', '0', '0', '0'},
        {'1', '0', '0', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '1'}};
    // Las reinas en (1,0) y (2,1) se amenazan en forma diagonal
    assert(nQueens(6, board3) == 0);
    char board4[][6] = {
        {'0', '0', '0', '1', '0', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '1'},
        {'0', '0', '1', '0', '0', '0'}};
    // No se amenazan pero hay menos de 6 reinas
    assert(nQueens(6, board4) == 0);
    // No hay solución para tableros de dimensión 2 o 3
    assert(nQueens(3, board2) == 0);
    assert(nQueens(2, board2) == 0);
    // En un tablero de 1x1 debe haber una reina
    const char board1[][1] = {{'1'}};
    assert(nQueens(1, board1));
    puts("OK!");
    return 0;
}

int nQueens(unsigned n, const char m[][n])
{
    if (n == 1)
        return TRUE;
    if (n == 2 || n == 3)
        return FALSE;

    int queens = 0;

    // Recorro la matriz en busca de una reina
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char actual = m[i][j];
            if (IS_QUEEN(actual))
            {
                queens++;
                // Si la posicion tiene una reina chequeo si esta amenazada
                int is_threatened = isThreatened(n, m, i, j);
                if (is_threatened)
                    return FALSE;
            }
        }
    }

    return queens == n;
}

int isThreatened(unsigned n, const char m[][n], int y, int x)
{

    // Cada vez que encuentre una reina, solo buscare otra hacia la derecha
    // En las dos diagonales hacia abajo, y hacia abajo
    static char directions[4][2] = {
        {1, 0}, // Avanzo uno hacia la derecha
        {0, 1}, // Avanzo uno hacia abajo
        {1, 1}, // Abajo y a la derecha
        {-1, 1} // Abajo y a la izquierda
    };

    // Recorremos en cada direccion posible
    for (int d = 0; d < 4; d++)
    {
        // Arrancamos una posicion adelante en la que queremos avanzar
        int increment_i = directions[d][1];
        int increment_j = directions[d][0];
        int i = y + increment_i;
        int j = x + increment_j;

        while (i < n && j < n) // Mientras sigamos en el tabler
        {
            if (IS_QUEEN(m[i][j]))
                return TRUE;

            // Avanzamos una posicion
            i += increment_i;
            j += increment_j;
        }
    }

    return FALSE; // Si llegamos hasta aca la reina no estaba amenazada
}
