// Escribir un programa que lea una variable tipo float representando una velocidad en m/s, 
//e imprima en la salida estándar el equivalente en km/h. Utilizar una única variable
#include "getnum.h"
#include <stdio.h>

int main(void) {
    float speed = getfloat("Ingresa la velocidad en m/s ");

    printf("Velocidad en km/h %f", speed * 3.6);
}
