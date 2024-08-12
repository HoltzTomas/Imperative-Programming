//	Dada la siguiente declaración de variable:
//  char c = 't';
//  armar un programa que imprima en la salida estándar dicha variable, con los siguientes formatos:  
//  %c,  %d,  %f.  
//  Indicar qué valores imprime y de dónde obtiene dichos valores.

#include <stdio.h>

int main(void) {
    //Esta variable almacena el valor ASCII de 't' (116)
    //Tanto signed como unsigned lo soportan asi que todo ok.
    // El binario es 0111 0100
    char c = 't';

    //Imprimira el valor ASCII de 116 ('t')
    printf("Caracter: %c\n", c);

    //Imprimira el valor decimal de 116 (116)
    printf("Decimal: %d\n", c);

    //Dado que los tipos no coinciden el comportamiento es indefinido
    printf("Float: %f\n", c);

    //Distitno es si
    printf("Float: %f\n", (float)c);


    return 0;
}
