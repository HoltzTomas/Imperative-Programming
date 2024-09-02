//Escribir un programa (en no más de 15 líneas) para encontrar raíces de funciones en un intervalo dado. 
//Se deberá recorrer el intervalo a incrementos de 0.001, evaluando la función en cada paso y escribiendo por salida estándar los puntos que son raíces.
//Los extremos del intervalo serán de tipo real y su valor estará dado por constantes del programa. 
#include <stdio.h>
#include <math.h>

#define INCREMENTO 0.001
#define EPS 0.0001

double function(double x);

int main(void) {

    double izq = -4;
    double der = 4;
    int prevSign;
    int actualSign;
    double y;

    prevSign = function(izq) > 0 ? 1 : -1;

    for(; izq <= der; izq += INCREMENTO){
        y = function(izq);

        actualSign =  function(izq) > 0 ? 1 : -1;

        if (fabs(y)<=EPS || actualSign != prevSign){
            printf("Hay raiz en %g\n", izq);
        }

        prevSign = actualSign;
    }

    return 0;
}

double function(double x){
    return pow(2, x) *  pow(x,3);
}
