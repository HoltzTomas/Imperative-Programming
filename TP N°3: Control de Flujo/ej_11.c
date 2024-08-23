//Escribir un programa que utilice ciclos para imprimir la siguiente tabla de valores, para N  desde 1 hasta 20. (En no más de 6 líneas)
#include <stdio.h>

int main(void){

    int i;

    printf("N\tN*10\tN*100\tN*1000\n");
    for(i = 0; i<=20; i++){
        printf("%d\t%d\t%d\t%d\n", i, i*10, i*100, i*1000);
    }

    return 0;
}