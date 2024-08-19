//Leer un caracter desde la entrada estándar e imprimir por salida estándar si el caracter es una letra o no y, 
//en caso de ser una letra, indicar si es letra mayúscula o minúscula, sin tener en cuenta el caracter ‘ñ’.
//(En no más de 15 líneas).

#include <stdio.h>

int main(void){
    int c = getchar();
    const int isUpperCase = (c >= 'A' && c <= 'Z');
    const int isLowerCase =  (c >= 'a' && c <= 'z');

    // Esto es lo que haria pero como en el enunciado piden no usar condicionales...
    // if(isUpperCase || isLowerCase){
    //     printf("Es una letra %s\n", isLowerCase ? "minuscula" : "mayuscula");
    // } else {
    //     printf("No es una letra");
    // }

    if(isUpperCase){
        printf("Es una letra mayuscula");
    } else if (isLowerCase) {
        printf("Es una letra minuscula");
    } else {
        printf("No es una letra");
    }

    return 0;
}
