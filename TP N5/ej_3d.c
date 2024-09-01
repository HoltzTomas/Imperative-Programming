#include <stdio.h>
#include "getnum.h"
#include <math.h>

int lugar(int num, int pos);

int main(void)
{
    int boleto, esCapicua = 1;
    int j;

    boleto = getint("Ingrese un número de 5 dígitos:");
    int longitud = calc_longitud(boleto);

    for (j = 1; j <= longitud / 2; j++)
        if (lugar(boleto, j) != lugar(boleto, longitud - j + 1))
        {
            esCapicua = 0;
            break;
        }
    printf("El boleto %ses capicúa", (esCapicua) ? "" : "no ");
    return esCapicua;
}

int lugar(int num, int pos)
{
    return (num / (int)pow(10, pos - 1)) % 10;
}

int calc_long(int num)
{
    int n;
    for (n = 0; num != 0; n++, num /= 10);
    return n;
}
