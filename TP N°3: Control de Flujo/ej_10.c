// Identificar y corregir el error en cada uno de los segmentos de código
#include <stdio.h>

int main(void)
{
    // a
    float x = 1 / 3;  // Esto da cero
    while (x != 0.52) // no hay representacion exacta, el ciclo se ejecuta infinitamente probablemente
    {
        x += .01;
        putchar(x);
        putchar('\n');
    }

    // Justamente el compilador da un warning
    // ej_10.c:8:14: warning: floating-point comparison is always true; constant cannot be represented exactly in type 'float' [-Wliteral-range]

    // b
    float y;
    for (y = .1; y != 1.0; y += .1) // Cero punto uno no tiene representacion exacta, sumarlo 10 veces no dara exactamente uno
        printf("%f\n", y);          // El ciclo corre infinitamente

    // c
    int n = 3;

    switch (n)
    {
    case 1:
        printf("El número es 1\n"); // Falta break aca, va a dar esta orden y la que sigue
    case 2:
        printf("El número es 2\n");
        break;
    default:
        printf("El número no es ni 1 ni 2\n");
        break;
    }

    // d
    int c, mayor;
    mayor = 0;
    while (c = getchar() != EOF) //Falta parentesis en c = getchar()
    {
        if (c > mayor)
            mayor = c;
    }
    printf("El mayor es %c\n", mayor);

    return 0;
}