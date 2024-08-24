#include <stdio.h>
#include "../getnum.h"

// En el caso de los reales, lo mejor es manejarse con strings para tener una representacion exacta
// Recibiremos por entrada estandar un numero real, e iremos sumando los 5 "enteros" hasta encontrar una coma/punto
// a partir de ahí empezamos a sumar los 5 "decimales" hasta en

#define TRUE 1
#define FALSE !TRUE

//Elegí utilizar un enum en lugar de flags enteros por tema de seguridad y simplicidad
//La cantidad de estados posibles son 2 elevado a la cantidad de flags
//Si tenes 2 flags isIntegerPart y isDecimalPart por ejemplo para saber que estas contando tenes 4 estados posibles
//Deberias manejar los cuatro estados, y el codigo queda menos claro
//Con un enum es mas claro, y tenes un estado menos.

typedef enum {
    DECIMAL_PART,
    INTEGER_PART,
    FINISH
} CounterState;

int main(void)
{
    CounterState counterState = INTEGER_PART;  // Estado inicial
    int c, integerCounter = 0, decimalCounter = 0;

    // Corremos el ciclo hasta el salto de linea, mientras c sea un digito o una coma
    while ((c = getchar()) != '\n' && counterState != FINISH && ((c >= '0' && c <= '9') || c == ','))
    {
        if (c == '5') {
            if (counterState == INTEGER_PART ) {
                integerCounter++;
            } else if (counterState == DECIMAL_PART) {
                decimalCounter++;
            }
        } 

        if (c == ',') {
            if (counterState == INTEGER_PART ) {
                counterState = DECIMAL_PART;
            } else if (counterState == DECIMAL_PART) {
                counterState = FINISH;
            }
        }
    }

    // Imprimir los resultados
    printf("Cantidad de '5' en la parte entera: %d\n", integerCounter);
    printf("Cantidad de '5' en la parte decimal: %d\n", decimalCounter);

    return 0;
}
