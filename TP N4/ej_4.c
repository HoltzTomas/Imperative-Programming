// Resolver el problema 4-14 del K&R.
// Utilizar la macro definida en un programa que realice intercambio de variables.
//(En no más de 5 líneas)
#include <assert.h>
#include <stdio.h>
#define SWAP(t, x, y) {\
    t aux = x;        \
    x = y;            \
    y = aux;}

int main(void)
{
    int a = 5, b = 3;

    SWAP(int, a, b);
    assert(a == 3 && b == 5);
    a = -1;
    SWAP(int, a, a);
    assert(a == -1);

    double x = 3.0, y = 8.0;
    SWAP(double, x, y);
    assert(x == 8.0 && y == 3.0);
    SWAP(double, x, y);
    assert(x == 3.0 && y == 8.0);

    puts("OK !");

    return 0;
}