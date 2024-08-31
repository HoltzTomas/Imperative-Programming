// Hacer un programa que genere una letra mayuscula aleatoria y un numero aleatorio N entre 1 y 256

// Luego debera invocar una funcion que lea un texto hasta N caracteres como maximo (si aparece antes EOF, termina la lectura)
// y retorne la cantidad de veces que dicha letra aparece en matuscula o en minuscula.

// Ejemplos para cuando el texto es:
//"Habia una vez una avestruz muy vivo, vivisimo que se llamaba victor"

// Si se genera la letra 'V' y N=101 la funcion retornaria 7
// Si se  genera la letra 'A' y N=5 la funcion retornaria 2

#include <stdio.h>
#include <ctype.h>
#include "../random.h"

#define EPS ('a' - 'A')

int countLetterAppeareces(int num, int character);

int main(void)
{
    randomize();
    int randomCharacter = randInt('A', 'Z');
    int num = randInt(0, 256);

    int appeareces = countLetterAppeareces(num, randomCharacter);

    printf("El numero fue %d, la letra fue %c y la cantidad de apariciones fue %d\n", num, randomCharacter, appeareces);
}

int countLetterAppeareces(int num, int character)
{
    int c = getchar();
    int counter = 0;
    int lower = tolower(character);

    for (int i = 1; i < num && c != EOF; i++, c = getchar()){
        if (c == character || c == lower){
            counter++;
        }
    }

    return counter;
}
