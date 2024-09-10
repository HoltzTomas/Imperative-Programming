//Los laboratorios de Propulsión por Reacción tienen la representación del cielo y sus estrellas, 
//digitalizada en una matriz bidimensional de hasta 80 columnas por 20 filas. 

// Cada elemento de la misma representa la cantidad de luz que hay en una zona del cielo con un rango de intensidad entre 0 y 20.

//(Osea, es una matriz de chars sin signo)

//En el lugar de coordenadas (i,j) del cielo se considera que hay una estrella si el elemento Aij correspondiente
//cumple con la siguiente relación:

//( A[i,j] + suma de las ocho intensidades circundantes ) / 9 > 10    (hacer las cuentas como int)

//Escribir una función (en no más de 15 líneas) que reciba tres parámetros de entrada representando a una matriz de dichas características y sus dimensiones. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../random.h"
#define COLUMNAS 80
#define FILAS 20
/* Generar una matriz con valores al azar */
void generaMatriz(int cielo[][COLUMNAS], int filas, int columnas);

/* Dada una matriz que representa una zona estelar, 
** grafica las estrellas en salida estandar */
void graficar (const int cielo[][COLUMNAS], int filas, int columnas);

int
main (void) {
	int cielo[FILAS][COLUMNAS];

	/* Setear la semilla de números aleatorios */
	randomize();

	generaMatriz(cielo, FILAS, COLUMNAS);
	graficar(cielo, FILAS, COLUMNAS);
	return 0;
}


void 
generaMatriz(int cielo[][COLUMNAS], int filas, int columnas) {
	int i, j;

	/* Generar una matriz en forma aleatoria */
	for (i = 0; i< filas; i++)
		for (j = 0; j < columnas; j++)
			cielo[i][j] = randInt(0, 20);
}


void
graficar (const int cielo[][COLUMNAS], int filas, int columnas) {
        int  suma;

        for (int i = 1; i < filas-1; i++) {
                printf("\n ");
                for (int j = 1; j < columnas-1; j++)
                {
                        suma = 0;
                        for (int k = -1; k <= 1; k++)
                                for (int m = -1; m <= 1; m++)
                                        suma += cielo[i+k][j+m];
                        if (suma / 9 > 10 )
                                putchar('*');
                        else
                                putchar(' ');
                }
        }
        putchar('\n');
}
