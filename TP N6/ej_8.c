// Repetir el ejercicio anterior, teniendo en cuenta que los arreglos de entrada pueden tener elementos repetidos
// Pero el de salida NO debe tener repeticiones.

// Dado que estan ordenados, puedo hacer lo mismo pero salteando elementos que sean iguales a su predecesor

#include <stdio.h>
#include <assert.h>

#define MAXIMO 20
#define V_FINAL -1

enum
{
    EQUAL,
    LOWER,
    BIGGER
};
int compare(int clave1, int clave2);
int unionOfIntegerSets(const int vector1[], const int vector2[], int answerVector[]);
void check(const int v1[], const int v2[])
{
    int i;
    for (i = 0; v1[i] != -1; i++)
        assert(v1[i] == v2[i]);
    assert(v1[i] == -1);
    assert(v2[i] == -1);
}

int main(void)
{
    int v1[] = {1, 5, 15, 30, 35, 45, 55, -1};
    int v2[] = {-1};
    int v3[] = {1, -1};
    int v4[] = {2, 3, 15, 16, 33, 35, 45, 65, -1};
    int res[30];

    unionOfIntegerSets(v1, v2, res);
    check(v1, res);

    unionOfIntegerSets(v2, v2, res);
    check(v2, res);

    unionOfIntegerSets(v1, v1, res);
    check(v1, res);

    unionOfIntegerSets(v1, v3, res);
    check(v1, res);

    int expected[] = {1, 2, 3, 5, 15, 16, 30, 33, 35, 45, 55, 65, -1};
    unionOfIntegerSets(v1, v4, res);
    check(expected, res);

    printf("OK!\n");
    return 0;
}
int unionOfIntegerSets(const int ar1[], const int ar2[], int resultado[])
{
    int i = 0, j = 0; /* índices del primer y segundo arreglo */
    int k = 0;        /* índice de la unión ( arreglo resultado ) */

    while ((ar1[i] != V_FINAL || ar2[j] != V_FINAL) && k < MAXIMO - 1)
    {

        /* Saltear elementos repetidos en arreglo1 */
        if (ar1[i] != V_FINAL)
            while (ar1[i] == ar1[i + 1])
                i++;

        /* Saltear elementos repetidos en arreglo2 */
        if (ar2[j] != V_FINAL)
            while (ar2[j] == ar2[j + 1])
                j++;


        switch (compare(ar1[i], ar2[j]))
        {
        case EQUAL:
            resultado[k] = ar1[i++];
            j++;
            break;
        case LOWER:
            resultado[k] = ar1[i++];
            break;
        case BIGGER:
            resultado[k] = ar2[j++];
        }
        k++;
    }
    resultado[k] = V_FINAL;
    return k;
}

int compare(int clave1, int clave2)
{
    if (clave1 == clave2)
        return EQUAL;
    if (clave1 == V_FINAL)
        return BIGGER;
    if (clave2 == V_FINAL)
        return LOWER;
    if (clave1 > clave2)
        return BIGGER;
    return LOWER;
}
