// Escribir un programa que ofrezca un menú con las siguientes opciones:

// Simplificar una fracción
// Sumar dos fracciones
// Terminar la ejecución

// Si se elige la primera opción se le solicitará numerador y denominador de la fracción y se imprimirá la fracción simplificada (algunos de ellos podrían ser negativos).

// Si se opta por la segunda, se le solicitará dos fracciones y se imprimirá la suma de las mismas, también simplificada.

// Obviamente con la tercera opción finaliza la ejecución del mismo. Escribir una función para cada item del menú.

//(No más de 20 líneas para main y no más de 10 líneas para las funciones del menú).

// Pista: Escribir y usar la función DivisorComunMaximo.

#include <stdio.h>
#include "../getnum.h"

/* Macro que pide un denominador distinto de cero */
#define LEER_DENOM_NO_CERO(denom)                              \
    {                                                          \
        do                                                     \
        {                                                      \
            denom = getint("");                                \
            if (denom == 0)                                    \
                printf("El denominador no puede ser cero.\n"); \
        }                                                      \
        \ 
 							while (denom == 0);                \
    }

int mcd(int x, int y);
void simplifyFraction(int num, int den);
void sumFractions(int num, int den, int num2, int den2);
int menu(void);

int main(void)
{
    int opcion;
    int num1, num2, den1, den2;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            num1 = getint("\nIngrese el numerador:");
            printf("\nIngrese el denominador:");
            LEER_DENOM_NO_CERO(den1)
            simplifyFraction(num1, den1);
            break;
        case 2:
            num1 = getint("\nIngrese el numerador de la 1ra. fracción:");
            printf("\nIngrese el denominador de la 1ra. fracción:");
            LEER_DENOM_NO_CERO(den1)
            num2 = getint("\nIngrese el numerador de la 2da. fracción:");
            printf("\nIngrese el denominador de la 2da. fracción:");
            LEER_DENOM_NO_CERO(den2)
            sumFractions(num1, den1, num2, den2);
            break;
        case 3:
            break;
        default:
            printf("\nOpción invalida");
            break;
        }
    } while (opcion != 3);

    return 0;
}

int menu(void)
{
    int opcion;

    printf("\n1 - Simplificar una fracción");
    printf("\n2 - Sumar dos fracciones");
    printf("\n3 - Terminar");

    opcion = getint("\nElija una opción:");

    return opcion;
}

void sumFractions(int num, int den, int num2, int den2)
{
    if (den == den2)
    {
        int numAux = num + num2;
        int mcdAux = mcd(den, numAux);
        printf("La suma de las fracciones es %d/%d\n", numAux / mcdAux, den / mcdAux);
    }
    else
    {
        int denAux = den * den2; // 50
        int numAux = (num * den2) + (num2 * den); //20
        int mcdAux = mcd(numAux, denAux);
        printf("La suma de las fracciones es %d/%d\n", numAux/mcdAux , denAux/mcdAux );
    }
}

void simplifyFraction(int num, int den)
{
    int mcdAux = mcd(den, num);

    printf("La fraccion simplificada de %d/%d es %d/%d\n", num, den, num / mcdAux, den / mcdAux);
    return;
}

int mcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
