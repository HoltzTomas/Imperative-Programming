//Leer un numero real indicando cuantos 5 tiene en su parte entera y cuantos en su parte decimal
//No mas de 25 lineas

//1. Tomar el double y truncarlo en una varibale auxiliar y con eso contas los 5
//2. Con esa aux, la cual es un int, en otra variable double guardar la parte decimal
#include <stdio.h>
#include "../getnum.h"

int main(void){

    double num = getdouble("Ingresar el numero en cuestion: ");
    int integerCounter = 0, decimalCounter = 0;
    int aux = num;

    //Print de chequeo
    printf("Ingresado: %g\n", num);
    printf("Entero Auxiliar: %d\n", aux);

    //Cuentos cuantos 5 hay en la parte entera
    //Recorro todos los digitos
    while (aux > 0) {
        if(aux % 10 == 5) {
            integerCounter++;
        }
        aux /= 10;
    }

    //num sigue teniendo el valor double, le restamos la parte entera y nos quedamos con la decimal
    num -= (int) num;
    printf("Double Auxiliar: %g\n", num);

    //Ahora recorro la parte decimal y cuento los 5
    while(num!=0){
        aux = num * 10; //Now aux is 1
        printf("Convierte %f a %d\n", num, aux);
        if(aux % 10 == 5) {
            decimalCounter++;
        }
        num *=10; // Now nomber is 1.1
        num -= aux; //Number is 0.1
        printf("Counter:  %d\n", decimalCounter);
    }

    printf("Final integer counter:  %d\n", integerCounter);
    printf("Final decimal counter:  %d\n", decimalCounter);

    return 0;
}
