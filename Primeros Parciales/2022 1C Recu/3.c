/*
RECUPERATORIO 1, 2022, PRIMER CUATRIMESTRE, EJERCICIO 3

Escribir una función esMagica que reciba como único parámetro una matriz de enteros de N filas y N columnas y determine si es
un “cuadrado mágico”.

Una matriz es cuadrado mágico cuando:
* es cuadrada (NxN) (donde N es una constante simbólica)
* tiene todos los números del 1 al N2
* la suma de los elementos de cualquier fila es igual a la suma de los elementos de cualquier columna
*/

#include <stdio.h>
#include <assert.h>

#define N 4
#define N_CUADRADO N *N
#define TRUE 1
#define FALSE !TRUE

int isMagical(const int m[N][N]);

// Chequeamos la primer fila
int isMagical(const int m[N][N])
{

    int appearences[N * N] = {0}; // Vector auxiliar de apariciones
    int sumCols[N] = {0};         // Vector auxiliar de apariciones
    int counter, sumRow;
    // Idea, recorrer toda la matriz una vez realizando las sumas por columna y fila
    // Tmb llenar el vector appearences, si en ninguna iteracion ya estaba la posicion llena...

    for (int i = 0; i < N; i++)
    {
        counter = 0;
        for (int j = 0; j < N; j++)
        {
            int actual = m[i][j];

            if (actual > N_CUADRADO || actual < 1)
                return FALSE;

            appearences[actual - 1]++;
            if (appearences[actual - 1] > 1)
            {
                return FALSE;
            }

            counter += actual;
            sumCols[j] += actual;
        }

        if (i == 0)
        {
            sumRow = counter;
        }
        else if (counter != sumRow)
        {
            return FALSE;
        }
    }

    /* Chequear que la suma de las columnas haya dado lo mismo que la de las filas */
    for (int i = 0; i < N; i++)
    {
        if (sumCols[i] != sumRow)
        {
            return FALSE;
        }
    }

    return TRUE;
}

int main(void)
{
    const int m1[N][N] = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 6, 7, 12},
        {4, 15, 14, 1}};
    assert(isMagical(m1) == 1);

    const int m2[N][N] = {
        {16, 4, 5, 10},
        {11, 2, 3, 6},
        {12, 9, 13, 15},
        {7, 8, 1, 14}};
    assert(isMagical(m2) == 0);

    const int m3[N][N] = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 15, 7, 12},
        {4, 6, 14, 1}};
    assert(isMagical(m3) == 0);

    const int m4[N][N] = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 7, 6, 12},
        {4, 15, 14, 1}};
    assert(isMagical(m4) == 0);

    puts("OK!");

    return 0;
}
