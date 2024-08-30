//Escribir la macro DIVISOR que reciba dos números enteros (no necesariamente positivos)
// y retorne 1 si el segundo es divisor del primero y cero si no es divisor. 
//No usar funciones auxiliares.
#include <stdio.h>
#include <assert.h>
#define DIVISOR(x,y) ((y) == 0) ? 0 : ((x) % (y) == 0)

int main (void) {
    int b = 10, c=3;
    
    int a;

    a = DIVISOR(b, 0);
    assert(a==0);

    a = DIVISOR(b, c);
    assert(a==0);

    a = DIVISOR(b, c-1);
    assert(a==1);

    a = DIVISOR(b, b == 0 ? 3 : 2);
    assert(a==1);
    
    a = DIVISOR(-10, 2);
    assert(a==1);

    a = DIVISOR(-10, -2);
    assert(a==1);

    a = DIVISOR(10, -2);
    assert(a==1);
    
    a = DIVISOR(10, -3);
    assert(a==0);

    puts("OK!");
}
