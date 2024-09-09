// Escribir una función que reciba un vector desordenado de números enteros y su dimensión, y construya otro vector eliminando los valores repetidos.
// La función deberá retornar en su nombre la dimensión del nuevo vector (La función solicitada  no debe superar las 10 líneas).

// Receives a vector and creates a new one without repeated elements
// Returns the new vector dimension
int eliminateRepetitions(int vector[], int dim, int answerVector[]);
int belongs(const int v[], int dim, int elem);

#include <assert.h>
#include <stdio.h>

/* En este test asumimos que en caso de estar repetidos deja la primer aparición del elemento, no la última
** Si el vector es  { 3, 5, 1, 3, -3, 3, 5, 1};
** Deja en resultado  { 3, 5, 1, -3};
*/

int main(void)
{
    int v[] = {3, 5, 1, 3, -3, 3, 5, 1};
    int res[20];
    int dimRes;

    dimRes = eliminateRepetitions(v, 0, res);
    assert(dimRes == 0);

    dimRes = eliminateRepetitions(v, 1, res);
    assert(dimRes == 1);
    assert(res[0] == 3);

    dimRes = eliminateRepetitions(v, 2, res);
    assert(dimRes == 2);
    assert(res[0] == 3);
    assert(res[1] == 5);

    dimRes = eliminateRepetitions(v, 4, res);
    assert(dimRes == 3);
    assert(res[0] == 3);
    assert(res[1] == 5);
    assert(res[2] == 1);

    dimRes = eliminateRepetitions(v, 8, res);
    assert(dimRes == 4);
    assert(res[0] == 3);
    assert(res[1] == 5);
    assert(res[2] == 1);
    assert(res[3] == -3);

    for (int i = 0; i < 8; i++)
        v[i] = 10;
    dimRes = eliminateRepetitions(v, 8, res);
    assert(dimRes == 1);
    assert(res[0] == 10);

    for (int i = 0; i < 8; i++)
        v[i] = i;
    dimRes = eliminateRepetitions(v, 8, res);
    assert(dimRes == 8);
    for (int i = 0; i < 8; i++)
        assert(res[i] == i);

    puts("OK!");
    return 0;
}

int eliminateRepetitions(int vector[], int dim, int answerVector[])
{
    int dimResult = 0;

    for (int i = 0; i < dim; i++)
    {
        if (!belongs(answerVector, dimResult, vector[i]))
        {
            answerVector[dimResult++] = vector[i];
        }
    }

    return dimResult;
}

int belongs(const int v[], int dim, int elem)
{
    for (int i = 0; i < dim; i++)
        if (v[i] == elem)
            return 1;
    return 0;
}
