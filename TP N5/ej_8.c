// La función floor puede ser utilizada para redondear un número a una cantidad específica de lugares decimales.
// Por ejemplo,  floor( x * 100 + .5 ) / 100  redondea x a la posición de los centésimos.

#include <stdio.h>
#include "../getnum.h"
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define EPSILON 0.000000001

double redondeo(double n, int user_input);
int menu(void);

int equals(double x, double y)
{
    return fabs(x - y) < EPSILON;
}

int main(void)
{

    double x = 1.0;

    for (int i = 0; i < 10; i++)
        assert(redondeo(x, i) == x);

    x = 1.11111;
    assert(equals(redondeo(x, 0), 1.0));
    assert(equals(redondeo(x, 1), 1.1));
    assert(equals(redondeo(x, 2), 1.11));
    assert(equals(redondeo(x, 3), 1.111));
    assert(equals(redondeo(x, 4), 1.1111));
    assert(equals(redondeo(x, 5), 1.11111));
    assert(equals(redondeo(x, 6), 1.11111));
    assert(equals(redondeo(x, 7), 1.11111));

    x = 1.15555;
    assert(equals(redondeo(x, 0), 1.0));
    assert(equals(redondeo(x, 1), 1.2));
    assert(equals(redondeo(x, 2), 1.16));
    assert(equals(redondeo(x, 3), 1.156));

    puts("OK !");
    return 0;
}

double redondeo(double n, int user_input)
{
    int aux = 1;

    while (user_input >= 1)
    {
        aux *= 10;
        user_input--;
    }

    printf("Fixed: %f\n", floor(n * aux + 0.5) / aux);

    return (floor(n * aux + 0.5) / aux);
}
