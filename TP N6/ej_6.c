// Dado un arreglo ordenado ascendentemente se pide escribir una función que reciba como parámetro de entrada/salida el arreglo y
// como parámetro de entrada su dimensión y que lo devuelva desordenado, simulando la mezcla de un mazo de cartas o de un bolillero
//(en no más de 10 líneas).

void shuffle(int arreglo[], unsigned int dim);

#include <stdio.h>
#include <assert.h>
#include "../random.h"
#define DIM 30

int main(void)
{
    int v[DIM];
    randomize();

    for (int i = 0; i < DIM; i++)
    {
        v[i] = -10 + i * 2;
    }
    shuffle(v, DIM);

    puts("Vamos a imprimir el vector, debería estar desordenado\n");
    for (int i = 0; i < DIM; i++)
    {
        printf("%03d\t", v[i]);
    }
    putchar('\n');

    int aux = v[0];
    puts("A continuación desordeamos un vector vacío, no debería fallar\n");
    shuffle(v, 0);
    assert(v[0] == aux);
    puts("Funcionó\n");

    return 0;
}

// Asumimos que el programa principal ejecutó randomize() o similar
void shuffle(int arreglo[], unsigned int dim)
{
    int j, aux;

    for (int i = 0; i < dim; i++)
    { // también se podría haber hecho hasta dim/2
        j = randInt(0, dim - 1);
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;

        printf("Se intercambio %d por %d\n", i + 1, j + 1);
    }
    return;
}