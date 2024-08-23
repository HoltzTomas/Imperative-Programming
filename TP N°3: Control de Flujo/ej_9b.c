#include <stdio.h>

//Cada palabra la imprime en una linea distinta

int main(void) {
    int c;
    
    // Leer caracteres hasta que llegue el final del archivo (EOF)
    while ((c = getchar()) != EOF) {
        // Si es un espacio, tabulación o salto de línea, imprimimos un salto de línea
        if (c == ' ' || c == '\t' || c == '\n') {
            putchar('\n');
        } else {
            // Si no es un separador, imprimimos el carácter tal cual
            putchar(c);
        }
    }

    return 0;
}
