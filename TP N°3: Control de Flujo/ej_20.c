//Escribir un programa (en no más de 10 líneas) que calcule el valor de la constante matemática e utilizando la fórmula 
//e = 1 + 1/1!  + 1/2! + 1/3! +...
//e imprima una tabla que indique cantidad de términos de la serie y el resultado parcial, con el siguiente formato:
#include <stdio.h>

#define EPS 0.0000001

int main(void){

    double e = 1, prev = 0; // Inicializo en 1 para ahorrarme el primer paso del polionomio que es 0!

    printf("%-10s %-10s\n", "N", "e");
    for(int n = 1; e - prev > EPS; n++){
        prev = e;
        printf("%-10d %-10.7f\n", n, e);
        int factorial = 1;
        for (int i = 2; i <= n; i++) {
            factorial *= i;
        }

        e += 1.0/factorial;
    }



    return 0;
}