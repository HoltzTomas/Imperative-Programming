#include <stdio.h>
#include <assert.h>

#define MAX 10

void reemplazo(int matriz[][MAX], int dim, int fil, int col);
void procesarDiagonalPrincipal(int matriz[][MAX], int dim, int fil, int col, int step);
void procesarDiagonalSecundaria(int matriz[][MAX], int dim, int fil, int col, int step);

int main(void)
{
    int m[5][MAX] = {{1, 0, 1, 0, 1},
                     {0, 1, 1, 1, 1},
                     {1, 0, 0, 1, 0},
                     {1, 1, 1, 0, 1},
                     {0, 0, 0, 0, 0}};
                     
    reemplazo(m, 5, 1, 2);

    int m2[5][MAX] = {{1, 1, 1, 1, 1},
                      {0, 1, 0, 1, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                      {0, 0, 0, 0, 0}};
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            assert(m[i][j] == m2[i][j]);

    printf("OK!\n");
    return 0;
}

// Función auxiliar para negar el valor en la matriz
void negarElemento(int matriz[][MAX], int fil, int col)
{
    matriz[fil][col] = !matriz[fil][col];
}

// Función recursiva para procesar la diagonal principal
void procesarDiagonalPrincipal(int matriz[][MAX], int dim, int fil, int col, int step)
{
    // Caso base: si estamos fuera de la matriz, detener la recursión
    if (fil < 0 || fil >= dim || col < 0 || col >= dim)
    {
        return;
    }

    // Negar el valor actual
    negarElemento(matriz, fil, col);

    // Llamada recursiva en ambas direcciones de la diagonal principal
    procesarDiagonalPrincipal(matriz, dim, fil + step, col + step, step);
}

// Función recursiva para procesar la diagonal secundaria
void procesarDiagonalSecundaria(int matriz[][MAX], int dim, int fil, int col, int step)
{
    // Caso base: si estamos fuera de la matriz, detener la recursión
    if (fil < 0 || fil >= dim || col < 0 || col >= dim)
    {
        return;
    }

    // Negar el valor actual
    negarElemento(matriz, fil, col);

    // Llamada recursiva en ambas direcciones de la diagonal secundaria
    procesarDiagonalSecundaria(matriz, dim, fil + step, col - step, step);
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col)
{
    // Negar el valor en la posición inicial
    negarElemento(matriz, fil, col);

    // Procesar la diagonal principal (desde la posición actual hacia arriba y hacia abajo)
    procesarDiagonalPrincipal(matriz, dim, fil - 1, col - 1, -1);
    procesarDiagonalPrincipal(matriz, dim, fil + 1, col + 1, 1);

    // Procesar la diagonal secundaria (desde la posición actual hacia arriba y hacia abajo)
    procesarDiagonalSecundaria(matriz, dim, fil - 1, col + 1, -1);
    procesarDiagonalSecundaria(matriz, dim, fil + 1, col - 1, 1);
}
