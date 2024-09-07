

#include <stdio.h>
#include <assert.h>

#define FILAS 7
#define COLS 6

#define ERROR (-1)

int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y);

int main(void)
{
    char tablero[][COLS] = {
        {'0', '0', '0', '0', '1', '0'},
        {'X', 'X', '0', '0', '0', '0'},
        {'0', '0', '0', '0', 'X', 'X'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', 'X', '0', '0'},
        {'1', '0', '0', 'X', 'X', 'X'}};
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    assert(res == 0 || res == 45);

    assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
    assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
    assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
    assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);

    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
    assert(res == 0 || res == 45 || res == 90 || res == 270);

    // Jugador fuera del tablero
    assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);

    printf("OK!\n");
    return 0;
}

int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y)
{
    int maxSteps = 0;
    int max_dir = 0;
    int directions[][2] = {
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, -1}
    };

    for (int i = 0; i < 8; i++) // Este for se corre 8 veces, una vez por direccion
    {
        int x_increment = directions[i][0];
        int y_increment = directions[i][1];

        int actual_x = x + x_increment;
        int actual_y = y + y_increment;

        int counter_steps = 0;

        while (mat[actual_y][actual_x] != 'X' && actual_y >= 0 && actual_x >= 0 && actual_x < ancho && actual_y < alto)
        {
            actual_x+= x_increment;
            actual_y+= y_increment;
            counter_steps++;
        }

        printf("La cantidad de pasos para la direccion %d es %d\n", i, counter_steps);

        if (counter_steps > maxSteps)
        {
            maxSteps = counter_steps;
            max_dir = i;
        }
    }

    printf("Direction is %d\n", max_dir * 45);

    return max_dir * 45;
}
