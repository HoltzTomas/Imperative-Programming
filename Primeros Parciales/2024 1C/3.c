// Una escalera de palabras (Word Ladder) consiste en un conjunto de palabras donde cada una difiere de la anterior únicamente en una letra
//(sin distinguir mayúsculas de minúsculas) en una posición.

// No se forma una escalera de palabras si:

// ● Cambian dos o más letras de una palabra a otra. Por ejemplo TEST -> EAST cambia T->E y E->A

// ● La posición de la letra que cambió se repite entre dos palabras seguidas.
// Por ejemplo TEST -> BEST -> REST cambia dos veces seguidas la primera letra T->B y B->R.


#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#define TRUE 1
#define FALSE !TRUE

/**
 * @param n Cantidad de palabras del conjunto
 *
 * @param len Longitud de cada palabra (Se asume que son de la misma longitud)
 *
 * @param m Matriz de chars donde cada fila corresponde a una palabra
 */
int isWordLadder(unsigned n, unsigned len, char m[][len])
{

    // Aca guardo en que letra fue la ultima letra que cambio
    // inicia en -1 para que el primer ciclo la ignore
    int lastChangeIndex = -1;

    // De ser 4 palabras, son 3 ciclos de tomar la palabra i e i+1
    for (int i = 0; i < n - 1; i++)
    {

        int amountOfChanges = 0;

        for (int j = 0; j < len; j++)
        {
            char actualStr1Char = m[i][j];
            char actualStr2Char = m[i + 1][j];
            if (tolower(actualStr1Char) != tolower(actualStr2Char))
            {
                // Si ya habiamos encontrado un letra distinta, esta es la segunda
                // No Hay escalera de palabras
                // Si cambio una letra en la misma posicion q antes, tambien
                if (amountOfChanges == 1 || lastChangeIndex == j)
                    return FALSE;
                // Si hay una letra distinta entre palabras, se guardara en lastChangeIndex
                // Para utilizar en el siguiente ciclo
                lastChangeIndex = j;
                amountOfChanges++;
            }
        }
    }

    return TRUE;
}

int main(void)
{
    char wordMatrix[][4] = {
        {'T', 'e', 'S', 't'},
        {'b', 'e', 'S', 'T'},
        {'B', 'E', 's', 'o'},
        {'B', 'E', 'S', 'A'}};
    // Considerando todas las filas no es escalera
    // pues los últimos dos cambios son en la última letra
    assert(!isWordLadder(4, 4, wordMatrix));
    // Considerando una sola fila es escalera
    assert(isWordLadder(1, 4, wordMatrix) == 1);
    // Considerando las tres primeras filas es escalera
    assert(isWordLadder(3, 4, wordMatrix) == 1);
    char wordMatrix2[][3] = {
        {'T', 'e', 'S'},
        {'t', 'b', 'e'},
        {'S', 'b', 'E'},
        {'B', 'b', 'e'}};
    // TeS -> Tbe cambian dos letras
    assert(!isWordLadder(4, 3, wordMatrix2));
    char wordMatrix3[][3] = {
        {'a', 'm', 'o'},
        {'a', 'r', 'o'},
        {'o', 's', 'a'}};
    // aro -> osa cambian tres letras
    assert(!isWordLadder(3, 3, wordMatrix3));
    puts("OK!");
    return 0;
}
