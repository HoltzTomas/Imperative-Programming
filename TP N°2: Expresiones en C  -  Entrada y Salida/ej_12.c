//Leer un carácter desde la entrada estándar e imprimir en la salida estándar si el mismo es una letra o no.
//Considerar que el conjunto de caracteres es el del lenguaje inglés, o sea ignorar la ñ  y vocales acentuadas.
//Usar el operador condicional.

#include <stdio.h>

int main(void) {
    //Deberia utilizar un int para manejar un EOF?
    unsigned char letra = getchar();
    int isLetra = (letra >= 'A' && letra <='Z') || (letra >= 'a' && letra <='z');

    //Esto no es un operador condicional pero es una forma mas linda de hacerlo
    if(isLetra) {
        printf("El caracter %c es una letra\n", letra);
    }

    if(!isLetra){
        printf("El caracter %c no es una letra\n", letra);
    }

    //Con opeardores condicionales se veria así
    isLetra ?  printf("El caracter %c es una letra\n", letra) : printf("El caracter %c no es una letra\n", letra);

}
