// Escribir una función potencia, que reciba en dos parámetros de entrada, la base (de tipo double) y el exponente (entero),
// y devuelva el valor de dicha potencia (En no más de 10 líneas).
// Por ejemplo, potencia(2,-4) debe devolver 0.0625. En caso de no poder calcularse el resultado debe devolver –1.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

// Dado que el exponente es entero no pasa nada con las raices cuadradas
#define EPSILON 0.00001

double potencia(double base, int exponente);

int main(void)
{

    assert(potencia(0, 0) == -1);

    for (int i = -10, j = 1; i < 10; i++, (i % 2 == 0 ? j++ : 0))
    {
        assert(fabs(potencia(i, j) - pow(i, j)) <= EPSILON);
    }
    assert(fabs(potencia(-2, -4) - pow(-2, -4)) <= EPSILON);

    puts("OK!");
    return 0;
}
double potencia(double base, int exponent)
{
    if( base == 0 ){
        return exponent == 0 ? -1 : 0;
    }

    double counter = 1.0;
    int absExponent = abs(exponent);

    for (int i = 1; i <= absExponent; i++)
    {
        counter *= base;
    }

    return exponent > 0 ? counter : 1.0 / counter;
}
