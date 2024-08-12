//Escribir un programa que lea dos enteros, e imprima si el segundo es múltiplo del primero.
//Usar el operador condicional.

#include <stdio.h>
#include "getnum.h"

int main(void) {
    char a = getint("Ingresa el primer numero"), b = getint("Ingresa el segundo numero");
    int isMultiple = b%a == 0;

    isMultiple ? printf("%d es multiplo de %d", b,a) : printf("%d no es multiplo de %d", b,a);

    return 0;
}
