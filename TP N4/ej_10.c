// La siguiente función intenta ser una instrumentación del algoritmo de Euclides para calcular el MCD de dos números,
// pero no siempre da el resultado correcto.
// Indicar errores y corregirlos para que funcione correctamente.
#include <stdio.h>

// Función para calcular el MCD usando el algoritmo de Euclides
int mcd(int a, int b);

int main(void) {
    int a = 56, b = 98;
    printf("El MCD de %d y %d es: %d\n", a, b, mcd(a, b));
    return 0;
}

int mcd(int a, int b) {
    int auxi;

    while (b != 0) {
        auxi = a % b;
        a = b;
        b = auxi;
    }

    return a;
}
