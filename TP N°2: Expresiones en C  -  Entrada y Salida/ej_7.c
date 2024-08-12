//	Dada la siguiente definición de variables

// imprimir en la salida estándar:
// a)  la variable edad, encolumnada a izquierda, en un ancho de campo de 5 espacios.
// b)  la variable edad, encolumnada a derecha, en un ancho de campo de 10 espacios.
// c) la variable longitud, encolumnada a la izquierda en un ancho de campo de 10 espacios, con 2 dígitos decimales.
// d)  la variable letra, como número entero, en un ancho de campo de 8 espacios.


#include <stdio.h>

int main(void) {
    int edad = 25;
    float longitud =185.654;
    char letra = 'Z';

    //a)
    printf("Edad encolumnada a izquierda, en un ancho de campo de 5 espacios: %-5d\n", edad);

    //b)
    printf("Edad encolumnada a derecha, en un ancho de campo de 10 espacios: %10d\n", edad);

    //c)
    printf("Longitud, encolumnada a la izquierda en un ancho de campo de 10 espacios, con 2 dígitos decimales: %-10.2f\n", longitud);

    //d
    printf("Letra, como numero entero, en un ancho de campo de 8 espacios: %8d\n", letra);
}
