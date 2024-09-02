//Escribir una función real para calcular aproximadamente el valor de e^x  por medio de la serie  1 + x + x^2 / 2! + x^3 / 3! + ....... 
//Dicha función recibe como parámetros de entrada el valor de x. (En no más de 10 líneas)

#include <stdio.h>
#include <math.h>

#define PRECISION  0.05
#define E 2.718281828459045

double exp_approx(double x);

int main(void) {
    printf("Aproximación de e^x: %lf\n", exp_approx(3));
    return 0;
}

double exp_approx(double x) {
    int factorial = 1;
    int exp = 1;
    double termsSum = 1; //El primer termino vale 1
    double prevValue = 0;

    for ( int i = 1; fabs(termsSum - prevValue) > PRECISION ; i++) {
        prevValue = termsSum;
        exp*=x;
        factorial*=i;
        termsSum += ( (double) exp / factorial);
    }

    return termsSum;
}
