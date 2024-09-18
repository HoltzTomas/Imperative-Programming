//* Dada una matriz cuadrada de dimension M
// (Donde M es un constante simbolica par mayor a cero previamente definida

// #define M 4

//*Se desea calcular la suma de cada uno de sus bordes
// Se considera como un borde a un contorno de la matriz

// El primer borde estaria conformado por la primer y ultima fila junto a la primer y ultima columna
// El segundo border por la segunda y anteultima fila junto a la segunda y anteultima columna, y
// continuando asi hasta llegar al centro de la matriz

//* Escriba la funcion border que reciba
/**
 *  @param mat matriz de enteros de dimension M (No se debe validar que M sea par positivo)
 *
 *  @param sumas vector de enteros no inicializado con al menos M/2 posiciones reservadas
 *
 * *La funcion debe dejar en sumas[i] la suma del borde i para todo i en [0, M/2)
 */

#include <stdio.h>
#include <assert.h>
#define M 6

void bordes(const int mat[][M], int sumas[M / 2]);

int main(void)
{
    int mat[][M] = {{1, 1, 1, 1, 1, 1},
                    {1, 2, 2, 2, 2, 1},
                    {1, 2, 3, 3, 2, 1},
                    {1, 2, 3, 3, 2, 1},
                    {1, 2, 2, 2, 2, 1},
                    {1, 1, 1, 1, 1, 1}};
    int sumas[M / 2];
    bordes(mat, sumas);

    int res[M / 2] = {20, 24, 12};

    for (int i = 0; i < M / 2; i++)
    {
        assert(sumas[i] == res[i]);
    }

    printf("OK!\n");

    return 0;
}

void bordes(const int m[M][M], int sumas[M / 2])
{

    for (int i = 0; i < M / 2; i++)
    {
        int suma = m[i][i] + m[M - i - 1][M - i - 1] + m[i][M - i - 1] + m[M - i - 1][i];

        //Podria extraer a funcion externa
        for (int j = i + 1; j < M - i - 1; j++)
        {
            suma += m[i][j];        
            suma += m[j][i];        
            suma += m[M - i - 1][j];
            suma += m[j][M -i -1]; 
        }
        printf("Suma: %d\n", suma);
        sumas[i] = suma;
    }
}