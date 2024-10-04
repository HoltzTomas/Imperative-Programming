/**
 *
 * * Escribir un programa interactivo para jugar al juego del ahorcado.
 *
 * @cond Las palabras que almacena la máquina deben estar guardadas en un arreglo de strings constantes
 *       y cada vez que se elija jugar, utilizar aleatoriamente alguna de dichas palabras.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define WORDS 6
// The number of errors users make
#define MAX_ERRORS 10

int randInt(int from, int to);
int ahorcado(char *word);

int main(void)
{

    // Program depends on pseudorandom integer generation, so we need
    // a new seed
    srand(time(NULL));
    rand(); // Thats because Clang bugs

    char *words[WORDS] = {"Tomas", "Holtz", "Learning", "How", "To", "Code"};

    // We have to select a word
    int random_i = randInt(0, WORDS - 1);
    char *word = words[random_i];

    if(ahorcado(word))
        printf("You win! Congrats\n");
    else
        printf("You lose!\n");

    return 0;
}

int ahorcado(char *word)
{

    int errors_counter = 0;

    int word_length = strlen(word);
    char user_answer[word_length + 1];

    for (int i = 0; i < word_length; i++)
        user_answer[i] = '_';

    user_answer[word_length] = '\0';

    // Each time user introduces a letter, if it is in the vector, its ok
    // if not, a counter of errors increments
    int user_wins = 0;
    while (errors_counter < MAX_ERRORS)
    {

        // Mostramos el progreso
        printf("Word: %s\n", user_answer);
        printf("Remaining attemps: %d\n", MAX_ERRORS - errors_counter);

        printf("Enter a letter: ");
        char next_char = getchar();
        while (getchar() != '\n')
            ;
        printf("\n");
        int belongs = 0;
        for (int i = 0; i < word_length; i++)
        {
            if (tolower(word[i]) == tolower(next_char))
            {
                belongs++;
                user_answer[i] = word[i];
            }
        }

        if (belongs)
        {
            printf("¡La letra %c está en la palabra!\n", next_char);
            if (strcmp(word, user_answer) == 0)
                return 1;
        }
        else
        {
            printf("¡La letra %c no está en la palabra!\n", next_char);
            errors_counter++; // Incrementamos el contador de errores
        }
    }

    return 0;
}

int randInt(int from, int to)
{

    if (from > to)
    {
        int aux = from;
        from = to;
        to = aux;
    }

    double randomNormalized = rand() / ((double)RAND_MAX + 1);

    return randomNormalized * (to - from + 1) + from;
}