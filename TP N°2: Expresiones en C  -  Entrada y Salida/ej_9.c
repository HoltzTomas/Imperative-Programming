//Leer un número entero positivo y escribir en la salida estándar 
//el valor de dicho número dividido 2, usando decalaje.
#include <stdio.h>
#include "getnum.h"

int main(void) {
    int integer = getint("Ingrese un numero entero ");
    //integer >> 1 divide por dos
    printf("La mitad de ese numero es %f", integer >> 1);
    return 0;
}
