//Escribir una macro MAXIMO2 que r
//ecibiendo tres parámetros, asigne al tercer parámetro el mayor de los dos primeros. 
//Utilizarla en un programa para verificar su correcto funcionamiento. (En no más de 5 líneas)

#include <stdio.h>
#include <assert.h>

#define MAXIMO2(a, b, c)  (c) =  (a) > (b) ? (a) : (b) ;

int main(void){
    int z;

    MAXIMO2(1,4,z);
    assert(z==4);

    MAXIMO2(1,-4,z);
    assert(z==1);

    MAXIMO2(-10,-4,z);
    assert(z==-4);

    puts("OK!");

    return 0;
}
