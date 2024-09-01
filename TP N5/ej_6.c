// Escribir un programa que ofrezca las siguientes opciones para accionar sobre un caracter leído desde la entrada estándar.
// Utilizar distintas funciones (con no más de 4 líneas) para cada una de las opciones y una función para el menú de opciones:

// 1. Convertir de mayúscula a minúscula.
// 2. Convertir de minúscula a mayúscula.
// 3. Imprimir el carácter siguiente.
// 4. Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')
#include <stdio.h>
#include "../getnum.h"
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#define CHAR_EPS ('a' - 'A')
#define IS_UPPER (c >= 'A' && c <= 'Z')
#define IS_LOWER (c >= 'a' && c <= 'z')

int menu(void);
int toUpper(int c);
int toLower(int c);
void printNextChar(void);
void printCircleNextChar(void);

int main(void)
{
    int user_input = menu();

    if (user_input == 1)
    {
        int c = getchar();
        c = toLower(c);
    }
    else if (user_input == 2)
    {
        int c = getchar();
        c = toUpper(c);
    }
    else if (user_input == 3)
    {
       printNextChar();
    }
    else
    {
        printCircleNextChar();
    }
}
int menu(void)
{
    int input;
    do
    {
        input = getint("Para pasar de mayuscula a minuscula, pulse 1.\nPara pasar de minuscula a mayuscula, pulse 2.\nPara imprimir el siguiente caracter, pulse 3.\nPara impimir la proxima letra en forma circular, pulse 4\n");
    } while (input < 1 || input > 4);

    return input;
}

int toUpper(int c)
{
    if (IS_LOWER)
    {
        return c - CHAR_EPS;
    }
    return c;
}

int toLower(int c)
{
    if (IS_UPPER)
    {
        return c - CHAR_EPS;
    }
    return c;
}

void printNextChar(void)
{
    int c = getchar(); // Leer un carácter de entrada estándar
    if (c != EOF)
    {

        putchar(c);
    }
    else
    {

        // Chequear si el error fue debido al final del archivo
        if (feof(stdin))
        {
            printf("Error: Se alcanzó el final del archivo.\n");
        }
        else
        {
            printf("Error: Hubo un problema al leer el carácter.\n");
        }
    }
}

void printCircleNextChar(void)
{
    int c = getchar(); // Leer un carácter de entrada estándar
    if (c != EOF)
    {

        if (!(isalpha(c)))
        {
             printf("Error: No es una letra\n");
        }

        if (c == 'Z' || c == 'z')
        {
            putchar(islower(c) ? 'a' : 'A');
            return;
        }

        putchar(c+1);
    }
    else
    {

        // Chequear si el error fue debido al final del archivo
        if (feof(stdin))
        {
            printf("Error: Se alcanzó el final del archivo.\n");
        }
        else
        {
            printf("Error: Hubo un problema al leer el carácter.\n");
        }
    }
}
