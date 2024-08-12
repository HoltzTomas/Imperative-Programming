//Escribir un programa que lea dos enteros y a continuación imprima el promedio,
//la suma, el menor y el mayor de ellos (o indicar que son iguales).
//Usar el operador condicional.

#include <stdio.h>
#include "getnum.h"

int main(void) {
    int a = getint("Ingresa el primer numero"), b=getint("Ingresa el segundo numero");
    float average = (a + b) / 2.0;
    int sum = a+b;
    int areEqual = a == b;

    printf("El promedio es %.1f\n", average);
    printf("La suma es %d\n", sum);

    areEqual ? printf("%d y %d son iguales\n", a,b) : printf("%d es mayor que %d\n", a>b ? a:b, a<b ? a:b);
    
    return 0;
}
