// Implementar la función anterior para vectores ordenados.
#include <assert.h>
#include <stdio.h>

int eliminateRepetitions(int vector[], int dim, int answerVector[]);
// int belongs(const int v[], int dim, int elem);

int main(void)
{
    int v[] = {-3, -3, -1, 0, 1, 2, 2, 2, 3, 3, 3};
    int res[20];
    int dimRes;

    dimRes = eliminateRepetitions(v, 0, res);
    assert(dimRes == 0);

    dimRes = eliminateRepetitions(v, 1, res);
    assert(dimRes == 1);
    assert(res[0] == -3);

    dimRes = eliminateRepetitions(v, 2, res);
    assert(dimRes == 1);
    assert(res[0] == -3);

    dimRes = eliminateRepetitions(v, 11, res);
    assert(dimRes == 6);
    assert(res[0] == -3);
    assert(res[1] == -1);
    assert(res[2] == 0);
    assert(res[3] == 1);
    assert(res[4] == 2);
    assert(res[5] == 3);

    int n = 80000;
    int v2[n];
    int res2[n];
    for (int i = 0; i < n; i++)
        v2[i] = 100;
    dimRes = eliminateRepetitions(v2, n, res2);
    assert(dimRes == 1);
    assert(res2[0] == 100);

    for (int i = 0; i < n; i++)
        v2[i] = i;
    dimRes = eliminateRepetitions(v2, n, res2);
    assert(dimRes == n);
    for (int i = 0; i < n; i++)
        assert(res2[i] == i);

    puts("OK!");
    return 0;
}

int eliminateRepetitions(int vector[], int dim, int answerVector[])
{

    if (dim == 0)
    {
        return 0;
    }
    int dimAnswer = 1;
    answerVector[0] = vector[0];

    // Si estan repetidos, el repetido sera igual al anterior
    for (int i = 1; i < dim; i++)
    {
        // Si es distinto del anterior, lo agregamos
        if (vector[i] != vector[i - 1])
        {
            answerVector[dimAnswer] = vector[i];
            dimAnswer++;
        }
    }

    return dimAnswer;
}
