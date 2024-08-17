//Escribir un programa que oermita al usuario ingresar los coeficientes de una ecuación
//cuadtratica y luego imprima la solución

//Si la ecuacion no es cuadtrática, deberia indicarle un error al usuario.
//Si la ecuacion es cuadratica pero tiene raíces complejas, mostrar un mensaje dando información al usuario

#include <math.h>
#include <stdio.h>
#include "getnum.h"

int main(void){

    double a = getdouble("Ingresa el termino cuadratico");
    double b = getdouble("Ingresa el termino lineal");
    double c = getdouble("Ingresa el termino independiente");
    double discriminante = b*b-4*a*c;
    double raizDiscriminante = sqrt(b*b-4*a*c);
    double raiz_1, raiz_2;

    if (a == 0) {
        printf("ERROR: El polinomio no es de grado 2");
        return 1;
    }

    if (discriminante < 0) {
        printf("ERROR: El polinomio tiene raices complejas");
        return 2;
    }

    
    raiz_1 = (-b + raizDiscriminante)/2*a;
    raiz_2 = (-b - raizDiscriminante)/2*a;
    printf("La raices son %-3.2f y %-3.2f", raiz_1, raiz_2);

    return 0;
}
