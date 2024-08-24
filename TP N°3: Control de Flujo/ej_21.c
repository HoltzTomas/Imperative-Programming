//Escribir un programa que lea un número entero, y escriba por salida estándar  dicho número y un cartel
//indicando si es capicúa o no. (En no más de 10 líneas)
#include <stdio.h>
#include "../getnum.h"

int main(void){
    int n = getint("Dame un entero: ");
    int inverso = 0;
    
    for ( int i = n; i != 0; i /= 10 ) {
        inverso *= 10;
        inverso += (i % 10);
    }

    printf("Inverso: %i, N: %i\n", inverso, n);

    if ( n == inverso ) {
        printf("Es capicúa\n");
    }
    else {
        printf("No es capicúa\n");
    }

}