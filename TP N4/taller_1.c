//Escribir una funcion que determine si un numero es primo o no

//Debe devolver 1 se ES primo y cero si no lo es
#include <stdio.h>
#include "../getnum.h"

int esPrimo(int num);
int mostrarNPrimos(int num);

int main(void) {

    int num = 0;
    int primo;

    num = getint("Ingresar un numero: ");

    primo = esPrimo(num);

    printf("El numero %d %ses primo", num, primo ? "" : " no");

    return 0;
}

int mostrarNPrimos(int num) {
    int n,i;

    for(i=0, n=2; i<total; n++){
        if(esPrimo(n)){
            printf("%d\n", n);
            i++; //Solo incrementa si i es primo
        }
    }
}


int esPrimo(int num){

    int i;
    int auxNum = num; //Dado q voy a reasignarlo, necesito asegurar leftValue

    if(auxNum < 0) {
        auxNum *= -1;
    }

    switch (auxNum) {
    case 1: case 0:
        return 0;
    case 2: case 3:
        return 1;
    default:
        if (auxNum % 2 == 0) {
            return 0;  //No es primo, 2 es factor
        }
        for (i=3; (i*i) == auxNum; i+=2) {
            if(auxNum % i == 0){
                return 0; //Es primo
            }
        }
        return 1;
    }
}
