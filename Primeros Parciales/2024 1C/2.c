// Escribir la función nQueens que, dada una matriz de chars de NxN,
// verifique si el mismo contiene N reinas de ajedrez de forma tal que ninguna reina amenace a otra.

// Una reina amenaza a otra si está en la misma fila, columna o en alguna de sus dos diagonales.
// Una posición libre se indica con el valor '0' y una celda con una reina se indica con el valor '1'.
// Se asume que en el tablero sólo hay caracteres ceros y unos, no es necesario validarlo.
#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE !TRUE
#define N 6

int isQueenThreatened(unsigned int n, const char m[][n], unsigned int y, unsigned int x);
int nQueens2(unsigned int n, const char m[][n]);
int nQueens(unsigned int n, const char m[N][N]);

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
    assert(nQueens2(8, board) == 0);
    char board2[][6] = {
        {'0', '0', '0', '1', '0', '0'},
        {'1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '1'},
        {'0', '0', '1', '0', '0', '0'}};
    // Hay 6 reinas y no se atacan, retorna true
    // assert(nQueens2(6, board2));
    char board3[][6] = {
        {'0', '0', '1', '0', '0', '0'},
        {'1', '0', '0', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '1'}};
    // Las reinas en (1,0) y (2,1) se amenazan en forma diagonal
    // assert(nQueens2(6, board3) == 0);
    char board4[][6] = {
        {'0', '0', '0', '1', '0', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0'},
        {'0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '1'},
        {'0', '0', '1', '0', '0', '0'}};
    // No se amenazan pero hay menos de 6 reinas
    assert(nQueens2(6, board4) == 0);
    // No hay solución para tableros de dimensión 2 o 3
    assert(nQueens2(3, board2) == 0);
    assert(nQueens2(2, board2) == 0);
    // En un tablero de 1x1 debe haber una reina char board1[][1] = {{'1'}}; assert(nQueens(1, board1));
    puts("OK!");
    return 0;
}

int nQueens2(unsigned int n, const char m[][n])
{

    if (n == 1)
        return TRUE;
    if (n == 2 || n == 3)
        return FALSE;

    int reinas = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char actual = m[i][j];

            if (actual == '1')
            {
                reinas++;
                if (isQueenThreatened(n, m, i, j))
                {
                    return FALSE;
                }
            }
        }
    }

    return reinas == n;
}

int isQueenThreatened(unsigned int n, const char m[][n], unsigned int y, unsigned int x)
{
    // Tomo la posicion actual, y avanzo en cada una de las direcciones hasta encontrar un '1'

    //  Al encontrar una reina, escaneamos en las siguientes direcciones en busca de otra,
    //  las demas estan escaneadas previamente
    const int directions[][2] = {{1, 0}, {0, -1}, {-1, -1}, {1, -1}};

    // Para cada una de las direcciones
    for (int d = 0; d < 4; d++)
    {
        int dirx = directions[d][0];
        int diry = directions[d][1];
        unsigned int i = y + diry;
        unsigned int j = x + dirx;

        while (i < n && j < n)
        {
            if (m[i][j] == '1')
                return TRUE;

            i += diry;
            j += dirx;
        }
    }

    return FALSE;
}

int nQueens(unsigned int n, const char m[][n])
{

    if (n == 1)
        return TRUE;
    if (n == 2 || n == 3)
        return FALSE;

    int reinas = 0;
    int prinDiagonal[2 * N - 1] = {0}; //-(N-1) hasta (N-1)
    int secDiagonal[2 * N - 1] = {0};  // De 0 a 2(N-1)
    char rows[n];
    char cols[n];

    // Inicializo Vectores apariciones col y rows
    for (int i = 0; i < n; i++)
    {
        rows[i] = 0;
        cols[i] = 0;
    }
    // Lo mismo pero para las diagonales
    for (int i = 0; i < 2 * n; i++)
    {
        prinDiagonal[i] = 0;
        secDiagonal[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == '1')
            {
                if (rows[i] || cols[i] || prinDiagonal[i - j + N - 1] || secDiagonal[i + j]) // i - j + N - 1 para no tener indices negativos
                {
                    return FALSE;
                }

                rows[i] = cols[i] = prinDiagonal[i - j + N - 1] = secDiagonal[i + j] = 1;
            }
        }
    }

    return reinas == n;
}
