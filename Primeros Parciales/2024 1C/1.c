// Escribir la función firstN que recibe un vector de unsigned chars, su dimensión y un valor entero no negativo n.

// La función debe dejar en el vector las primeras n apariciones de cada valor

// y devolver en dos parámetros de salida:

// 1.la dimensión del nuevo vector

// 2.cuántos elementos eliminó

#include <assert.h>
#include <stdio.h>
#define MAX_CHAR 256

void firstN(unsigned char v[], unsigned int dim, unsigned int n, int *newDim, int *delElements);

int main(void)
{
    unsigned char v[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim, del;
    firstN(v, 8, 3, &dim, &del); // dim es 8, del es 0, v no cambia
    assert((dim) == 8);
    assert((del) == 0);
    firstN(v, 8, 8, &dim, &del); // dim es 8, del es 0, v no cambia
    assert((dim) == 8);
    assert((del) == 0);
    firstN(v, 8, 4, &dim, &del); // dim es 8, del es 0, v no cambia
    assert((dim) == 8);
    assert((del) == 0);
    firstN(v, 8, 1, &dim, &del); // dim=5, del=3, v = {1, 2, 3, 4, 5};
    assert((dim) == 5);
    assert((del) == 3);
    unsigned char w[] = {1, 2, 1, 3, 1, 4, 5, 2};
    firstN(w, 8, 0, &dim, &del); // dim=0, del=8, w = {}
    assert((dim) == 0);
    assert((del) == 8);
    unsigned char t[] = {1, 2, 1, 3, 1, 4, 5, 2};
    firstN(t, 8, 2, &dim, &del); // dim=7, del=1, t = {1, 2, 1, 3, 4, 5, 2}
    assert((dim) == 7);
    assert((del) == 1);
    puts("OK");
    return 0;
}

void firstN(unsigned char v[], unsigned int dim, unsigned int n, int *newDim, int *delElements)
{

    unsigned char appearences[MAX_CHAR] = {0};
    unsigned int writeIndex = 0;

    for (int i = 0; i < dim; i++)
    {
        unsigned char actual = v[i];

        //En este caso conservo el numero
        if(appearences[actual] < n){
            appearences[actual]++;
            v[i] = v[writeIndex++];
        }
    }

    *newDim = writeIndex;
    *delElements = dim - *newDim;

    return;
}
