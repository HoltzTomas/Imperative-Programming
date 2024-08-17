//Escribir un programa que lea un numero entero y obtenga la suma de las cifras

#include <stdio.h>
#include "getnum.h"

int main(void) {
    int number = getint("Ingresa el numero");
    int suma = 0;
    
    if(number<0){
        number*=-1; //Lo vuelvo positivo
    }

     // Sumamos las cifras
    while (number > 0) {
        suma += number % 10;  // Tomamos el último dígito
        number /= 10;         // Eliminamos el último dígito
    }

    printf("La suma de los digitos es %d", suma);

    return 0;
}
