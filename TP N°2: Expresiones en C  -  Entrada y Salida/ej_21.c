//Analizar el programa tp2_21.c
//a)Sin ejecutarlo decir qué va a imprimir. 
//b)Generar el ejecutable y verificar que se corresponda con el punto anterior
//c)Volver a generar el ejecutable pero agregando el flag -fsanitize=signed-integer-overflow. 
//¿El resultado es el mismo que en el punto anterior? De no ser así, analizar por qué


#include <stdio.h>
#include <limits.h>

int
main(void) {
   int c = INT_MAX;
   int d;
   d = c + c;
   int e = c + 1;

   printf("c=%d   d=%d   e=%d\n", c, d, e);
   return 0;
}
