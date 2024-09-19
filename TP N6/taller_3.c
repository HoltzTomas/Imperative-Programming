// Hacer la función incrementoFCMinMax que recibe un arreglo con ángulos y
// un arreglo con las distancias que se pueden recorrer en cada dirección.

// La función deberá determinar el ángulo correspondiente a la mínima y a la
// máxima distancia que puede recorrer y obtener los incrementos en Fila y en Columna para esos ángulos

#include <stdio.h>
#include <assert.h>

#define ANGLE_INCREMENT 45

int incrementoFCMinMax(int angulos[], int distancias[], int dim, int *fMin, int *fMax, int *cMin, int *cMax);

int main(void)
{
    int angulos[] = {0, 45, 90, 135, 180, 225, 270, 315};
    int distancias[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int fMin, cMin, fMax, cMax;
    assert(incrementoFCMinMax(angulos, distancias, sizeof(angulos) / sizeof(angulos[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == 0 && cMin == 1 && fMax == 1 && cMax == 1);

    int angulos2[] = {0, 45, 90, 135, 180, 225, 270, 315};
    int distancias2[] = {8, 7, 6, 5, 4, 3, 2, 1};
    assert(incrementoFCMinMax(angulos2, distancias2, sizeof(angulos2) / sizeof(angulos2[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == 1 && cMin == 1 && fMax == 0 && cMax == 1);

    int angulos3[] = {45, 90, 135, 225, 180, 0};
    int distancias3[] = {12, 1, 4, 20, 7, 9};
    assert(incrementoFCMinMax(angulos3, distancias3, sizeof(angulos3) / sizeof(angulos3[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == -1 && cMin == 0 && fMax == 1 && cMax == -1);

    int angulos4[] = {90};
    int distancias4[] = {1};
    assert(incrementoFCMinMax(angulos4, distancias4, sizeof(angulos4) / sizeof(angulos4[0]), &fMin, &cMin, &fMax, &cMax) == 1);
    assert(fMin == -1 && cMin == 0 && fMax == -1 && cMax == 0);

    assert(incrementoFCMinMax(NULL, NULL, 0, &fMin, &cMin, &fMax, &cMax) == 0);
    assert(fMin == -1 && cMin == 0 && fMax == -1 && cMax == 0); // no debería modificar los valores

    puts("OK");
    return 0;
}

int incrementoFCMinMax(int angulos[], int distancias[], int dim, int *fMin, int *cMin, int *fMax, int *cMax)
{
    static int direcciones[8][2] = {
        {0, 1},   // 0 grados
        {-1, 1},  // 45 grados
        {-1, 0},  // 90 grados
        {-1, -1}, // 135 grados
        {0, -1},  // 180 grados
        {1, -1},  // 225 grados
        {1, 0},   // 270 grados
        {1, 1}    // 315 grados
    };

    if (dim == 0)
    {
        return 0;
    }

    int max_dist = distancias[0];
    int max_dist_idx = 0;
    int min_dist = distancias[0];
    int min_dist_idx = 0;

    // Encuentro la distancia máxima y mínima
    for (int i = 1; i < dim; i++)
    {
        if (distancias[i] > max_dist)
        {
            max_dist = distancias[i];
            max_dist_idx = i;
        }

        if (distancias[i] < min_dist)
        {
            min_dist = distancias[i];
            min_dist_idx = i;
        }
    }

    *fMin = direcciones[angulos[min_dist_idx] / ANGLE_INCREMENT][0];
    *cMin = direcciones[angulos[min_dist_idx] / ANGLE_INCREMENT][1];
    *fMax = direcciones[angulos[max_dist_idx] / ANGLE_INCREMENT][0];
    *cMax = direcciones[angulos[max_dist_idx] / ANGLE_INCREMENT][1];

    return 1;
}