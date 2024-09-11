#include <stdio.h>
#include <assert.h>

#define COLS 4

int sonAmigas(const int(m1[])[COLS], unsigned int fils1, const int(m2[])[COLS], unsigned int fils2);

int main(void)
{
    int m1[][COLS] = {{0, 1, 2, 3}, {4, 4, 5, 6}, {7, 8, 8, 9}};
    int m2[][COLS] = {{0, 1, 2, 3}, {-3, 7, 8, 9}, {-1, 3, 4, 7}, {4, 5, 6, 8}};
    int m3[][COLS] = {{2, 3, 3, 7}};
    assert(sonAmigas(m1, 3, m2, 4) == 1);
    assert(sonAmigas(m1, 1, m2, 4) == 1);
    assert(sonAmigas(m1, 2, m2, 4) == 1);
    assert(sonAmigas(m1, 2, m2, 2) == 0);
    assert(sonAmigas(m2, 4, m1, 3) == 2);
    assert(sonAmigas(m1, 3, m3, 1) == 0);
    assert(sonAmigas(m3, 1, m1, 3) == 0);
    int res = sonAmigas(m1, 3, m1, 3);
    assert(res == 1 || res == 2);

    printf("OK !\n");

    return 0;
}

static int contieneOrden(const int v1[], const int v2[], unsigned int dim)
{
    int i, j;
    for (i = 0, j = 0; i < dim && j < dim;)
    {
        if (v1[i] < v2[j]) // Si es menor, no va a estar despues
            return 0;
        if (v1[i] == v2[j])
        {
            i++; // no incrementamos j, porque puede haber elementos repetidos en v1
        }
        else // v1[i] > v2[j]  -> puede estar mas adelante
            j++;
    }
    // Si llegue al final, quiere decir que todos los elementos estaban
    return i == dim;
}

static int vecEnMatriz(const int v[], const int(m[])[COLS], unsigned int fils)
{
    // Debemos ver si v esta contenido dentro de alguna de las filas de m
    // Apenas encontramos que v "pertenece" a m retornamos 1. El razonamiento es
    // muy parecido al de buscar un elemento en un vector
    for (int i = 0; i < fils; i++)
    {
        if (contieneOrden(v, m[i], COLS))
            return 1;
    }
    return 0;
}

static int esAmiga(const int(m1[])[COLS], unsigned int fils1, const int(m2[])[COLS], unsigned int fils2)
{
    // Verificar que todas las filas de m1 esten en m2
    for (int i = 0; i < fils1; i++)
    {
        if (!vecEnMatriz(m1[i], m2, fils2))
            return 0;
    }
    return 1;
}

int sonAmigas(const int(m1[])[COLS], unsigned int fils1, const int(m2[])[COLS], unsigned int fils2)
{

    // Como hay que verificar m1 contra m2 y luego m2 contra m1, realizamos una funcion auxiliar que haga todo el trabajo, y la llamamos primero para m1.
    if (esAmiga(m1, fils1, m2, fils2))
        return 1; // Si esAmiga no hace falta hacer nada mas
    if (esAmiga(m2, fils2, m1, fils1))
        return 2;
    return 0;
}