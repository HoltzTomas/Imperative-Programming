//Leer dos caracteres desde la entrada estándar e imprimir en la salida estándar el de mayor valor ASCII, 
//usando el operador condicional. Redireccionar la entrada de manera tal que getchar
//lea desde el archivo entrada.txt.  
//Dicho archivo será escrito con un editor de texto sin formato y deberá tener el siguiente contenido:

//a)   ABCD
// En este caso imprimira AB

//b) A
//   B
//   C
//   D

//En este caso imprime el caracter A y el caracter enter, por eso vemos solo a "A"

//b) A  B
//Por el mismo motivo que antes solo vemos la letra A

#include <stdio.h>

int main(void) {
    unsigned char a = getchar(), b = getchar();

    printf("Primer caracter: %c\n", a);
    // putchar(a);
    // putchar(b);
    printf("Segundo caracter: %c\n", b);
}
