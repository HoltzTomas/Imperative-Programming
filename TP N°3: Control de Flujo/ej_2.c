//Leer dos caracteres desde la entrada estándar  e imprimir por salida estándar  si son iguales, 
//si el primero es mayor o si el primero es menor, teniendo en cuenta su valor ASCII. 
//(En no más de 15 líneas).

#include <stdio.h>

int main(void) {
    int c1 = getchar(), c2 = getchar();

    if (c1 == c2) {
        printf("'%c' es igual que '%c'\n", c1, c2);
    } else if (c1 > c2) {
        printf("'%c' es mayor que '%c'\n", c1, c2);
    } else {
        printf("'%c' es menor que '%c'\n", c1, c2);
    }
    return 0;
}
