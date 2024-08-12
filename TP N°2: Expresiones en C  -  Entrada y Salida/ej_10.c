// Escribir un programa que lea una variable entera que representa un intervalo de tiempo expresado en segundos. 
// Realizar la conversión para imprimir en la salida estándar el equivalente en horas, minutos y segundos. 
// No utilizar variables auxiliares.

#include <stdio.h>
#include "getnum.h"

int main(void) {
    int timeInSeconds = getint("Ingresa el tiempo en segundos: ");
    printf("Time in hours %f\n", (double) timeInSeconds / 3600);
    printf("Time in minutes %f\n", (double) timeInSeconds / 60);
    printf("Time in seconds %d\n", timeInSeconds);
    return 0;
}
