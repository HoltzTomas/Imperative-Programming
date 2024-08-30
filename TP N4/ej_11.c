//Escribir una función que reciba tres parámetros de entrada de tipo entero y 
//que devuelva en su nombre el mayor de ellos. (En 2 líneas)

#include <stdio.h>

void mayor(int x, int y, int z);

int main(void){
    mayor(1,2,3);
    mayor(6,5,4);
    return 0;
}

void mayor(int x, int y, int z){
    int mayor = (x > y ? (x > z ? x : z) : (y > z ? y : z));
    printf("El mayor entre %d, %d y %d es %d\n", x, y, z, mayor);
    return;
}