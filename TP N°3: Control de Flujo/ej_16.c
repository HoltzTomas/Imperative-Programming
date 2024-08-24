// Dado un número entero positivo, imprimir por salida estándar  el equivalente en base binaria.
// El rango de números a considerar puede estar acotado. (En no más de 15 líneas).

#include <stdio.h>
#include "../getnum.h"

int main(void) {
    //Tomaremos somo el enteros de 1 byte = 8 bits = 0 a 255 (Positivo)

    int i, num = getint("Ingresa un numero entero entre 0 y 255: ");

    while (num > 255 || num < 0) {
        printf("El numero debe estar entre 0 y 255\n");
        num = getint("Ingresa un numero entero entre 0 y 255: ");
    }

    for (i=7; i>=0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
     printf("\n");

    return 0;
}
