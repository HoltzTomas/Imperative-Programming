#include <stdio.h>
#include "getnum.h"

int main(void){
    float number = getfloat("Ingresa el numero");
    int counter = 0;

    //Number aux gonna integer par of number
    int aux = (int) number;
    printf("Casteado %d\n", aux);

    //Now we have 0.[numberDecimalPart]
    number -= aux; //If number was 0.11, now it is 1.1

    while(number!=0){
        aux = number * 10; //Now aux is 1
        printf("Convierte %g a %d\n", number, aux);
        counter += aux; //Counter is 1
        number *=10; // Now nomber is 1.1
        number -= aux; //Number is 0.1
        printf("Counter:  %d\n", counter);
    }

    printf("La suma de los decimales el %d", counter);

}
