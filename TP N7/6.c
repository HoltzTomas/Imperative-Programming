/**
 * *Escribir un programa para desarrollar el juego Mastermind descrito por las siguientes reglas:
 *
 * @cond La computadora construye un conjunto aleatorio de X dígitos distintos
 *       (para X usar una constante simbólica). Sólo se usan los dígitos del 1 al 9
 *
 * @cond Se le  pide ingresar al usuario el nivel en que quiere jugar.
 *       Según esto se trabajará con una tolerancia de hasta N pasos,
 *       dentro de los cuales si no logra ganar el juego se termina automáticamente.
 *
 * @cond El jugador ingresa un conjunto de X dígitos distintos por teclado.
 *
 * @cond Si el número propuesto por el jugador coincide con el que generó la máquina o la cantidad de chances excedió el número tope N,
 *       el juego finaliza;
 *
 * @cond sino el programa debe informarle cuántos dígitos están BIEN (son correctos y están en su lugar)
 *       y cuántos son REGULARES (son correctos pero están fuera de lugar) y se vuelve a ejecutar el paso anterior
 *
 * * Así se va guiando al jugador hasta que adivine el número.
 *
 **/

#include "math.h"
#include "stdio.h"
#include "../random.h"
#include "../getnum.h"

#define X 3
#define SWAP_BOUND 20

/**
 * @def Fills [array] with [dim] different numbers from 1 to 9
 */
void generateRandom(unsigned array[]);

/**
 * @def generates a random int between from and to
 */
unsigned randomInt(unsigned from, unsigned to);

/**
 * @def Swaps two values using their pointers
 */
void swap(unsigned *a, unsigned *b);

/**
 * @def lets user select the level of the game and returns it
 */
unsigned chooseLevel(void);

/**
 * @def reads a number of [dim] digits from std input and save each digit
 *      in a position of [array]
 */
void readNumber(unsigned array[]);

int numberMatches(unsigned unknownRandom[], unsigned userNumber[]);
unsigned amountGood(unsigned unknownRandom[], unsigned userNumber[]);
unsigned amountRegular(unsigned unknownRandom[], unsigned userNumber[]);


int main(void)
{

    // * Generate random array of [X] digits
    unsigned unknownRandom[X];
    generateRandom(unknownRandom);

    // * User choose the elevel of the game
    unsigned level = chooseLevel();

    // * Lets user try to guess
    unsigned userNumber[9];
    for (int i = 0; i < level; i++)
    {
        readNumber(userNumber);
        if ( numberMatches(unknownRandom, userNumber) ) {
            return 1;
        }
    }

    printf("You lose");

    return 0;
}

void generateRandom(unsigned array[])
{

    for (int i = 0; i < X; i++)
    {
        array[i] = i + 1;
    }

    // Generate randoms between 0 and 8 and then swap that positions of the array
    for (int i = 0; i < SWAP_BOUND; i++)
    {
        swap(&array[randomInt(0, X)], &array[randomInt(0, X)]);
    }
}

unsigned randomInt(unsigned from, unsigned to)
{
    if (from > to)
    {
        swap(&from, &to);
    }

    double rand_normalized = rand() / (double)RAND_MAX;
    return ((rand_normalized * (to - from)) + from);
}

void swap(unsigned *a, unsigned *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

unsigned chooseLevel(void)
{
    unsigned level = 0;

    do
    {
        printf("Levels go from 1 to 10\n");
        printf("Choose level: ");
        scanf("%d", &level);

        // After scanf we need to clean the buffer
        while ((getchar()) != '\n')
            ;
    } while (level < 1 || level > 10);

    return level;
}

void readNumber(unsigned array[])
{

    // Here we check if each digit is different
    int appearences[9];
    int is_valid;
    do
    {
        is_valid = 1;
        for (int i = 0; i < 9; i++)
        {
            appearences[i] = 0;
        }

        for (int i = 0; i < X && is_valid;)
        {
            int actual_digit = 0;
            printf("Insert the digit number %d: ", i + 1);
            scanf("%u", &actual_digit);
            printf("\n");

            // After scanf we need to clean the buffer
            while ((getchar()) != '\n')
                ;

            if(actual_digit > 0 && actual_digit < 9){
                if(appearences[actual_digit]++ == 1){
                    is_valid = 0;
                    printf("Digits must be different\n");
                }
                array[i++] = actual_digit;
            }
        }
    } while (!is_valid);
}

int numberMatches(unsigned unknownRandom[], unsigned userNumber[]){
    int good = amountGood(unknownRandom, userNumber);
    int regular = amountRegular(unknownRandom, userNumber);

    printf("%i good, %i regular\n", good, regular);

    return ( good == X );
}

unsigned amountGood(unsigned unknownRandom[], unsigned userNumber[]) {
    unsigned good = 0;
    for ( int i = 0; i < X; i++ ) {
        if ( unknownRandom[i] == userNumber[i] ) {
            good++;
        }
    }
    return good;
}

unsigned amountRegular(unsigned unknownRandom[], unsigned userNumber[]) {
    unsigned regular = 0;
    for ( int i = 0; i < X; i++ ) {
        for ( int j = 0; j < X; j++ ) {
            if ( j != i && unknownRandom[j] == userNumber[i] ) {
                regular++;
            }
        }
    }
    return regular;
}