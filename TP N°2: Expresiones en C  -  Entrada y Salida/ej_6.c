//  Indicar qué salida se obtiene en cada printf del siguiente programa:
#include <stdio.h>
#define palabra "ultima prueba"

int
main(void)
{
    int num1 = 53, num2 = 4;
    float num3 = 6.874;

    //El numero será impreso en una cadena de 10 caracteres alineado a la derecha
    printf("num1= %10d\n", num1);
    
    //Lo mismo que el anterior pero rellenado con ceros a la izquierda
    printf("num2= %010d\n", num2);

    //Lo mismo que el primero pero el "-" lo alinea a la izquierda
    printf("num1= %-10d\n", num1);

    //5 Caracteres, alineado a la derecha
    //Nota, la unica diferencia entre i y d es que d imprime un decimal y
    //i un entero en cualquier base (octal, hexa, decimal)
    printf("num1+num2= %5i\n", num1 + num2);

    //El compilador espera un float, recibe int, falla
    printf("num1+num2= %5f\n", num1 + num2);

    //Tres caracteres, dos decimales, alineado a la izquierda
    printf("num3= %-3.2f\n", num3);

    //num1= 53
    //num2=4
    //num3= 6.9 (redondea)
    printf("num1= %-4d\nnum2= %-4d\nnum3= %3.1f\n", num1,num2, num3);

    //Si tomamos la representacion binaria de num3 (punto flotante) y lo interpretamos como un int
    //termina en un numero gigante
    printf("num3(como entero)= %d\n", num3);

    //13
    printf("num1 / num2 = %d\n", num1 / num2);

    //0
    printf("num2 / num1 = %d\n", num2 / num1);
    
    //esta es la ultima prueba
    printf("esta es la %s\n", palabra);

    return 0;
}