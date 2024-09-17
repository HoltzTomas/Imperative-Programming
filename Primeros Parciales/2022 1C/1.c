// Dados dos conjuntos A y B, su diferencia simétrica, A Δ B, es un conjunto que contiene los elementos de A y los de B,
// excepto los que son comunes a ambos:

// *Para este ejercicio se debe asumir que los conjuntos contienen únicamente números positivos
// *sin repetir y ordenados ascendentemente, con el valor -1 como marca de final.

// Como trabajaremos con varios conjuntos, los mismos se almacenan en una "matriz".

// *Se pide: escribir la función difSim que reciba:
// tres matrices enteras m1, m2 y m3 de COLS columnas (COLS es una constante simbólica previamente definida).
// Cada fila i de m1 y m2 contendrá un conjunto de enteros mayor o igual a cero, ordenados ascendentemente y sin repetir, con el valor -1 como marca de final

// un valor entero filas que representa la cantidad de conjuntos en cada matriz

// La función deberá dejar en cada fila i de m3 la diferencia simétrica entre las filas idem1 y dem2, coni ∈ [0, filas)

#include <stdio.h>
#include <assert.h>

#define COLS 5

void difSim(int m1[][COLS], int m2[][COLS], int m3[][COLS], int filas);

int main(void)
{
    int filas = 6; // Número de conjuntos en cada matriz
    int m1[][COLS] = {
        {1, 2, 3, 4, -1},
        {3, 4, 5, -1},
        {10, 15, 20, -1},
        {-1},
        {-1},
        {5, 6, 7, -1},
    };
    int m2[][COLS] = {
        {3, 4, 5, 6, -1},
        {3, 4, 5, -1},
        {10, 20, -1},
        {1, 2, 3, 4, -1},
        {-1},
        {1, 2, 7, -1},
    };
    int m3[6][COLS];

    // Llamar a la función difSim
    difSim(m1, m2, m3, filas);

    // Definir los resultados esperados
    int expected_m3[][COLS] = {
        {1, 2, 5, 6, -1},
        {-1},
        {15, -1},
        {1, 2, 3, 4, -1},
        {-1},
        {1, 2, 5, 6, -1}};

    // Utilizar asserts para verificar los resultados
    for (int i = 0; i < filas; i++)
    {
        int j = 0;
        while (expected_m3[i][j] != -1)
        {
            assert(m3[i][j] == expected_m3[i][j]);
            j++;
        }
        // Verificar que la longitud de los conjuntos es la misma
        assert(m3[i][j] == -1); // Verificar marca de final
    }

    printf("Todas las pruebas pasaron exitosamente.\n");

    return 0;
}

void difSim(int m1[][COLS], int m2[][COLS], int m3[][COLS], int rows)
{

    // Hacemos por cada fila una comparacion
    for (int i = 0; i < rows; i++)
    {
        int idx1 = 0, idx2 = 0, idx3 = 0;

        // Mientras el valor q estamos evaluando de cada fila sea != -1 seguimos
        while (m1[i][idx1] != -1 || m2[i][idx2] != -1)
        {
            int m1_actual = m1[i][idx1];
            int m2_actual = m2[i][idx2];

            // Si son igual incremento ambos y no los agrego a la diffSimetrica
            if (m1_actual == m2_actual)
            {
                idx1++;
                idx2++;
            }
            else if ((m1_actual < m2_actual && m1_actual != -1) || m2_actual == -1)
            {
                // Valor unico de m1
                m3[i][idx3++] = m1[i][idx1++];
            }
            else
            {
                // Valor unico de m2
                m3[i][idx3++] = m2[i][idx2++];
            }
        }

        // Indice final
        m3[i][idx3] = -1;
    }
}