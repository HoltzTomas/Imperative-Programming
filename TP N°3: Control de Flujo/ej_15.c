// Dado un entero que representa un número binario positivo (todos sus dígitos son cero o uno),
// imprimir por salida estándar el equivalente decimal. (En no más de 10 líneas)

#include <stdio.h>
#include "../getnum.h"
#define TRUE 1
#define FALSE !TRUE

int main(void)
{
    // Debere recorrer los digitos del entero y segun la posesion multiplicar por 2^n
    // Necesito un auxiliar donde ir guardando el binario y dividiendolo por 10
    // Necesito un iterador que me diga en q digito estoy para saber la potencia

    int num = getint("Ingresar el binario:");
    int n, i, j, auxBit, auxPotencia, esBinario = TRUE;
    int sumaPolinomio = 0;

    if (num < 0)
    {
        num *= -1;
    }

    for (i = num, n = 0; i > 0; i /= 10, n++)
    {

        // Primero necesito saber el valor de ese bit
        auxBit = i % 10;

        if (auxBit != 0 && auxBit != 1)
        {
            esBinario = FALSE;
            printf("El numero no es binario");
            break;
        }

        // La potencia inicial es 2^0 = 1, la inicializo  y si es mayor iteramos
        auxPotencia = 1;
        for (j = 1; j <= n; j++)
        {
            auxPotencia *= 2; // Multiplico por 2 n veces para encontrar el valor de la potencia
        }

        // Multiplicamos el valor del bit por el valor de la potencia y la sumamos al polinomio
        sumaPolinomio += auxBit * auxPotencia;
    }

    if (esBinario)
    {
        printf("La representacion decimal de %d es %d", num, sumaPolinomio);
    }

    return 0;
}
