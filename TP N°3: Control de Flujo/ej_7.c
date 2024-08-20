//Decir qué envía el siguiente programa a la salida estándar.

#include <stdio.h>
#include "../getnum.h"


int
main(void)
{
	int i, j, n = 0, suma = 0;


	while( n <= 0 )
		n = getint("Ingrese cantidad de elementos:"); //Esto esta bien, no deja seguir al usuario hasta que n sea positivo


	for(i=1; i<=n; i++) //Corre este ciclo n veces
	{
		j = getint("Ingrese valor %d:",i); //Va a pedirle un numero n veces y los va a sumar
		suma += j;
	}


	printf("El resultado es : %.2f\n", suma / (float) j); //Toma la suma de los n numeros y lo divide por el ultimo ingresado
	return 0;	
}
