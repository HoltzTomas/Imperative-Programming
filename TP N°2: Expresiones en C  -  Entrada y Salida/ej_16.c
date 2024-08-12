// Leer dos caracteres seguidos de la entrada estándar e imprimir en la salida estándar si son iguales,
// si el primero es mayor o si el primero es menor, utilizando operadores condicionales:

#include <stdio.h>

int main(void) {
    char c1, c2;

    // Leer dos caracteres seguidos
    printf("Ingrese el primer carácter: ");
    c1 = getchar();
    getchar(); // Leer el salto de línea o espacio después del primer carácter

    printf("Ingrese el segundo carácter: ");
    c2 = getchar();

    // Comparación usando operador condicional
    (c1 == c2) ? printf("Los caracteres %c y %c son iguales.\n", c1, c2) :
    (c1 > c2) ? printf("El carácter %c es mayor que %c.\n", c1, c2) :
                printf("El carácter %c es menor que %c.\n", c1, c2);

    return 0;
}
