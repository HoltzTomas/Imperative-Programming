//Escriba un programa que lea de entrada estándar un número entero positivo y 
//calcule la cantidad de bits en ‘1’ que contiene.

#include <stdio.h>
#include "../getnum.h"

int main(void){
    int num, bitsCounter = 0, potencia = 1;

    do {
       num = getint("Ingresa un entero positivo: ");
    } while (num < 0);
    
    /* veo la maxima potencia que tendrá */
    while ( num > potencia ) {
        potencia *= 2;
    }

    while ( potencia != 0 ) {
        if ( num / potencia == 1 ) {
            bitsCounter++;
            num -= potencia;
        }

        potencia /= 2;
    }
    
    printf("Cantidad de 1s: %i\n", bitsCounter);

    return 0;
}
