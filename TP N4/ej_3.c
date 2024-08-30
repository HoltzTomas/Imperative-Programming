//Escribir, en no más de 5 líneas, un programa que defina y 
//utilice una macro con un parámetro para calcular el volumen de una esfera.
//El programa deberá calcular el volumen para esferas de radios de 1 a 10 cm., e imprimir los resultados en forma tabulada.	
#define PI 3.14
#define SPHERE_VOLUME(r) ( 4.0/3 ) * PI * (r) * (r) * (r)

#include <stdio.h>
#include "../getnum.h"

int main(void){
    int radio = getint("Ingresar radio: ");
    printf("El volumen de la esfera de radio %d es %.2fm^3", radio, SPHERE_VOLUME(radio));

    return 0;
}
