#include <stdio.h>
#include "../getnum.h"

#define DIM 50

int readArray(float array[], unsigned dim);

int main(void)
{
    float v[DIM];

    // Invocamos la funcion read array
    int numberOfElements = readArray(v, DIM);

    printf("LA cantidad de elementos es %d\n", numberOfElements);

    // Imprimimos los elementos
    for(int i=0 ; i < numberOfElements; i++){
        printf("El elemento %d es %g\n", i, v[i]);
    }

    return 0;
}

int readArray(float array[], unsigned int maxDim)
{
    int dim = 0;
    float nbr;

    while (dim < maxDim && (nbr = getfloat("Ingresa un numero: ")) > 0)
    {
        array[dim++] = nbr;
    }
    

    return dim;
}