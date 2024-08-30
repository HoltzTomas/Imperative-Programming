//Escribir la macro MAXIMO3 para determinar el mayor de 3 valores, 
//usando la macro definida en el ejercicio anterior. (En no más de 10 líneas).
//Verificar su funcionamiento invocándola desde un programa.

//Escribir una macro MAXIMO2 que r
//ecibiendo tres parámetros, asigne al tercer parámetro el mayor de los dos primeros. 
//Utilizarla en un programa para verificar su correcto funcionamiento. (En no más de 5 líneas)

#include <stdio.h>
#include <assert.h>

#define MAXIMO2(a, b, c)  (c) =  (a) > (b) ? (a) : (b) ;
#define MAXIMO3(w, x, y, z)  MAXIMO2(w, x, z); \
                             MAXIMO2(z, y, z);

int main(void){
    int z;

    MAXIMO3(1,4,7,z);
    assert(z==7);

    MAXIMO3(1,4,-7,z);
    assert(z==4);

    MAXIMO3(1,-4,-7,z);
    assert(z==1);

    puts("OK!");

    return 0;
}
