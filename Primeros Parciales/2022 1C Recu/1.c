// Los teléfonos (incluyendo los celulares) poseen grabado en sus teclas no sólo
// el número sino un conjunto de letras

// esto quiere decir que a cada dígito (excepto el 0 y el 1) le corresponden 3 posibles letras.

// A continuación,

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../../random.h"

static int
randInt(int from, int to) {
    return rand() % (to - from + 1) + from;
}


void convertirATexto(unsigned long number, char s[]);

int main(void)
{
    char s[10];
    srand(time(NULL));
    randomize();
    convertirATexto(0, s);
    assert(strcmp(s, "0") == 0); // Única posible solución
    convertirATexto(1, s);
    assert(strcmp(s, "1") == 0);
    convertirATexto(101, s);
    assert(strcmp(s, "101") == 0);
    convertirATexto(10000, s);
    assert(strcmp(s, "10000") == 0);
    convertirATexto(23721, s);
    assert(strlen(s) == 5);
    assert(s[0] == 'A' || s[0] == 'B' || s[0] == 'C');
    assert(s[1] == 'D' || s[1] == 'E' || s[1] == 'F');
    assert(s[2] == 'P' || s[2] == 'Q' || s[2] == 'R' || s[2] == 'S');
    assert(s[3] == 'A' || s[3] == 'B' || s[3] == 'C');
    assert(s[4] == '1');
    puts("OK");
    return 0;
}

void convertirATexto(unsigned long number, char resultado[])
{

    if (number == 0)
    {
        resultado[0] = '0';
        resultado[1] = '\0';
        return;
    }

    int index = 0;

    // Lista con las equivalencias de cada caracter
    const char *teclado[] = {"0",
                             "1",
                             "ABC",
                             "DEF",
                             "GHI",
                             "JKL",
                             "MNO",
                             "PQRS",
                             "TUV",
                             "WXYZ"};

    while (number > 0)
    {

        int digit = number % 10;

        if (digit == 0 || digit == 1)
        {
            resultado[index] = '0' + digit;
        }
        else
        {
            int numLetras = 0;
            while (teclado[digit][numLetras] != '\0')
            {
                numLetras++; // Contar cuántas letras tiene el dígito
            }
            int indexLetra = rand() % numLetras;

            resultado[index] = teclado[digit][indexLetra];
        }

        // Eliminar el último dígito procesado
        number /= 10;
        index++;
    }

    resultado[index] = '\0';

    int len = index;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = resultado[i];
        resultado[i] = resultado[len - i - 1];
        resultado[len - i - 1] = temp;
    }
}
