#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.01

double raizNR(double valorAnterior, int iter, double x);

int main(void){

    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}

// Función recursiva para aproximar la raíz cuadrada
double raizNR(double valorAnterior, int iter, double x) {
    // Caso base: si no quedan más iteraciones, retornamos el valor actual
    if (iter == 0) {
        return valorAnterior;
    }
    
    // Aplicar la fórmula de Newton-Raphson
    double nuevoValor = (valorAnterior + x / valorAnterior) / 2;
    
    // Llamada recursiva con una iteración menos
    return raizNR(nuevoValor, iter - 1, x);
}