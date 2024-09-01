//Escribir una función real para calcular aproximadamente el valor de e^x  por medio de la serie  1 + x + x^2 / 2! + x^3 / 3! + ....... 
//Dicha función recibe como parámetros de entrada el valor de x. (En no más de 10 líneas)

#include <stdio.h>
#include <math.h>

#define PRECISION  0.2
#define E 2.718281828459045

double exp_approx(double x);
int factorial (int c);

int main(void) {
    printf("Aproximación de e^x: %lf\n", exp_approx(3));
    return 0;
}

double exp_approx(double x) {
    double termsSum = 1; //El primer termino vale 1
    double realValue = pow(E, x);

    for ( int i = 0; fabs(termsSum - realValue) > PRECISION ; i++ ) {
        termsSum += ( pow(x, i) / factorial(i) );
    }

    return termsSum;
}

int factorial (int c) {
    int fact = 1;

    for ( int i = c; i > 0; i-- ) {
        fact *= i;
    }

    return fact;
}
