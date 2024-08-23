//Dada una variable entera que indica el lado de un cuadrado, imprimir por salida estándar  dicho cuadrado en forma de asteriscos.

#include <stdio.h>
#include "../getnum.h"

int main(void){

    int a = getint("Ingrese el largo de un lado: "), i, j;

    //a) Uso dos for anidados
    for(i=1; i<=a; i++){
        for(j=1; j<=a; j++){
            printf("*");
        }
        printf("\n");
    }

    //b) solo un for
    for(i=1; i<=a*a; i++){
        if(i%a == 0)
            printf("*\n");
        else
            printf("*");  
    }

    return 0;
}