// Escribir una función que reciba dos parámetros de entrada de tipo entero y devuelva en su nombre un número aleatorio entre ambos números. (En una línea)

#include <stdio.h>
#include "../getnum.h"
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

// Devuelve un real entre 0 y 1
double random_normalize(void);

// Devuelve un int aleatorio entre n1 y n2
int random_int(int n1, int n2);

int main(void) {
    double a = random_int(2, 5);
    assert( a >= 2 && a <= 5 );
    double b = random_int(5, 5);
    assert( b == 5 );
    double c = random_int(5, 2);
    assert( c >= 2 && c <= 5 );
    double d = random_int(-1, 1);
    assert( d >= -1 && d <= 1 );
    double e = random_int(0, 1000);
    assert( e >= 0 && e <= 1000 );
    puts("OK!");
}


double random_normalize(void)
{
    srand(time(NULL));
    rand(); // This step is only required on some MacOS environments
    return (rand() / ((double)RAND_MAX + 1));
}

int random_int(int n1, int n2)
{
    if(n1 > n2){
        int aux = n1;
        n1 = n2;
        n2 = aux;
    }

    return (random_normalize() * (n2 -n1 + 1) + n1);
}