// Reescribir el ejercicio 10 de la práctica 5 de forma tal que quede separado correctamente el front-end del back-end

// Para la opción de simplificar una fracción, la obtención del nUMerador y DENominador pertenece al front-end.
// Luego se invoca a una función de back-end que recibe esos parámetros y los modifica.
// ¿Cómo se puede hacer para que la función de back-end reciba ambos y los pueda modificar?

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../getnum.h"

#define SIMPLIFICAR 1
#define SUMAR 2
#define SALIR 3

typedef int Fraction[2];
#define NUM(f) f[0]
#define DEN(f) f[1]

// Calcular el MCD de la fraccion
int mcd(int x, int y);
// Lee un fraccion de entrada estandar y la guarda en la dir recibida
void readFraction(Fraction fraction);
// Toma una fraccion y la simplifica
void simplifyFraction(Fraction fraction);
// Toma dos fracciones y las sumas, las guarda en la tercera
void sumFractions(Fraction fraction1, Fraction fraction2, Fraction fraction3);
// Show a Menu where u can select the function u need
int menu(void);
/* Imprime una fracción */
void printFraction(const Fraction fraction);

int main(void)
{
    int opcion;
    Fraction f1, f2, f3;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case SIMPLIFICAR:
            printf("Ingrese fraccion a simplificar\n");
            readFraction(f1);
            simplifyFraction(f2);
            printf("Fraccion simplificada: ");
            printFraction(f1);
            break;
        case SUMAR:
            printf("Ingrese la primera fraccion\n");
            readFraction(f1);
            printf("Ingrese la segunda fraccion\n");
            readFraction(f2);
            sumFractions(f1, f2, f3);
            printf("Resultado: ");
            printFraction(f3);
            break;
        case SALIR:
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

void readFraction(Fraction fraction)
{

    NUM(fraction) = getint("Ingrese el numerador: ");

    while ((DEN(fraction) = getint("Ingrese el denominador: ")) == 0)
        printf("El DENominador no puede ser cero.\n");

    return;
}

void sumFractions(Fraction f1, Fraction f2, Fraction f3)
{
    /* Calcula la suma */
    DEN(f3) = DEN(f1) * DEN(f2);
    NUM(f3) = DEN(f3) / DEN(f1) * NUM(f1) + DEN(f3) / DEN(f2) * NUM(f2);

    simplifyFraction(f3);

    return;
}

void simplifyFraction(Fraction fraction)
{
    int mcdAux = mcd(DEN(fraction), NUM(fraction));

    // Divide DEN and NUM by MCD only if MCD != 1 (In that case it is already simplified)
    DEN(fraction) /= mcdAux;
    NUM(fraction) /= mcdAux;

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

void printFraction(const Fraction f)
{

    printf("%s%d", (NUM(f) * DEN(f) >= 0) ? "" : "-", abs(NUM(f)));
    if (abs(DEN(f)) != 1)
        printf("/%d", abs(DEN(f)));
    putchar('\n');
}