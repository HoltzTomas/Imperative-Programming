// escribir una función que reciba un vector de enteros y un número y devuelva si el número aparece en el vector.
// Implementarla usando notación de vectores y notación de punteros.

#include <assert.h>
#include <stdio.h>

#define TRUE 1
#define FALSE !TRUE

int belongsVectorNotation(int vector[], int dim, int num);
int belongsPointerNotation(int vector[], int dim, int num);

int main(void)
{

    int numberVector[4] = {0, 1, 2, 3};

    // Testing vector notation function
    assert(belongsVectorNotation(numberVector, 4, 2) == TRUE);  // El dos pertenece
    assert(belongsVectorNotation(numberVector, 4, 5) == FALSE); // El 5 no pertenece

    // Testing pointer notation function
    assert(belongsPointerNotation(numberVector, 4, 2) == TRUE);  // El dos pertenece
    assert(belongsPointerNotation(numberVector, 4, 5) == FALSE); // El 5 no pertenece

    puts("OK!");

        return 0;
}

int belongsVectorNotation(int vector[], int dim, int num)
{
    for (int i = 0; i < dim; i++)
    {
        if (vector[i] == num)
            return TRUE;
    }

    return FALSE;
}

int belongsPointerNotation(int vector[], int dim, int num)
{
    int exist = FALSE, *end = vector + dim;
    while (vector < end && !exist)
    {
        exist = *vector == num;
        vector++;
    }
    return exist;
}
