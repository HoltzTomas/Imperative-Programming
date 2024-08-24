//Escriba un programa que lea un entero no negativo ( cero o mayor ) y que calcule e imprima su factorial. 
//En caso de ingresar un valor inválido, imprimir un cartel aclarando cuáles son los valores válidos. (En no más de 10 líneas)

#include <stdio.h>
#include "../getnum.h"
#include <limits.h>

int main(void){

    int i, factorial = 1, num = getint("Ingresa un numero entero positivo o cero: ");
    int maxFactorial = 1, n = 1;

    // Iterar mientras el siguiente factorial no desborde el tipo int
    while (1) {
        // Verificar si multiplicar factorial por n desbordará el tipo int
        if (maxFactorial > INT_MAX / n) {
            break;  // Si el siguiente cálculo desborda, salir del bucle
        }

        maxFactorial *= n;
        n++;
    }
    // printf("El mayor número cuyo factorial no desborda en un int es %d.\n", n - 1);

    while (num < 0 || num > n) {
        printf("El numero debe ser positivo o cero y menor que %d", n);
        num = getint("Ingresa un numero entero positivo");
    }

    for(i=num; i > 0; i--){
        factorial *= i;
    }

    printf("El factorial de %d es %d\n", num, factorial);


    return 0;
}
