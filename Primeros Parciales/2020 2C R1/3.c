// *Escribir una función que compruebe si una solución parcial dada a un Sudoku es correcta (retorna 1) o inválida (retorna cero)

#include <stdio.h>
#define TRUE 1
#define FALSE !TRUE

int verificarSudoku(int tablero[9][9]);
int verificarFilas(int tablero[9][9]);
int verificarColumnas(int tablero[9][9]);
int verificarSubcuadrados(int tablero[9][9]);

int main(void)
{
    int tablero[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    int resultado = verificarSudoku(tablero);

    if (resultado)
        printf("El tablero es válido.\n");
    else
        printf("El tablero es inválido.\n");

    return 0;
}

int verificarSudoku(int tablero[9][9])
{

    // Verificar filas
    int filasOk = verificarFilas(tablero);
    if (!filasOk)
        return FALSE;

    // Verificar columnas
    int columnasOk = verificarFilas(tablero);
    if (!columnasOk)
        return FALSE;

    // Verificar subcuadrados de 3x3
    int subcuadradosOk = verificarSubcuadrados(tablero);
    if (!subcuadradosOk)
        return FALSE;

    return TRUE;
}

int verificarSubcuadrados(int tablero[9][9])
{
    for (int boxFila = 0; boxFila < 3; boxFila++)
    {
        for (int boxColumna = 0; boxColumna < 3; boxColumna++)
        {
            int numeros[10] = {0}; // Índices 1-9 para los números
            for (int fila = 0; fila < 3; fila++)
            {
                for (int columna = 0; columna < 3; columna++)
                {
                    int num = tablero[boxFila * 3 + fila][boxColumna * 3 + columna];
                    if (num != 0)
                    {
                        if (numeros[num])
                            return FALSE; // Número duplicado en el subcuadrado
                        numeros[num] = 1;
                    }
                }
            }
        }
    }

    return TRUE;
}

int verificarColumnas(int tablero[9][9])
{
    for (int columna = 0; columna < 9; columna++)
    {
        int numeros[10] = {0}; // Índices 1-9 para los números
        for (int fila = 0; fila < 9; fila++)
        {
            int num = tablero[fila][columna];
            if (num != 0)
            {
                if (numeros[num])
                    return FALSE; // Número duplicado en la columna
                numeros[num] = 1;
            }
        }
    }

    return TRUE;
}

int verificarFilas(int tablero[9][9])
{

    // Verificar filas
    for (int fila = 0; fila < 9; fila++)
    {
        int numeros[10] = {0}; // Índices 1-9 para los números
        for (int columna = 0; columna < 9; columna++)
        {
            int num = tablero[fila][columna];
            if (num != 0)
            {
                if (numeros[num])
                    return FALSE; // Número duplicado en la fila
                numeros[num] = 1;
            }
        }
    }

    return TRUE;
}
