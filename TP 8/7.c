#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 7
#define FILS 6
#define BLOQUE 5

typedef enum
{
    DER = 0,
    IZQ,
    ABA,
    ARR,
    I_AR,
    I_AB,
    D_AR,
    D_AB
} Tdireccion;

// Desplazamientos para cada dirección
int desplazamientos[8][2] = {
    {0, 1},   // DER
    {0, -1},  // IZQ
    {1, 0},   // ABA
    {-1, 0},  // ARR
    {-1, -1}, // I_AR
    {1, -1},  // I_AB
    {-1, 1},  // D_AR
    {1, 1}    // D_AB
};

typedef struct posicion
{
    char *palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
} posicion;

posicion *resolverSopa(char *diccionario[], char sopa[][COLS]);
int buscarPalabra(int i, int j, char *palabra, char sopa[FILS][COLS], Tdireccion dir);
int agregarPalabra(posicion **resultados, int tamanioResultados, char *palabra, int fila, int columna, Tdireccion dir);

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de
//       letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que coincida con el orden en que se encuentran.

int main(void)
{
    char *diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};

    char sopa[FILS][COLS] =
        {{'X', 'X', 'X', 'O', 'X', 'X', 'X'},
         {'A', 'P', 'A', 'C', 'Y', 'Y', 'O'},
         {'Z', 'E', 'Z', 'R', 'Z', 'C', 'X'},
         {'E', 'R', 'R', 'O', 'R', 'X', 'X'},
         {'X', 'R', 'I', 'O', 'I', 'E', 'X'},
         {'X', 'O', 'X', 'X', 'O', 'X', 'X'}};

    struct posicion *res = resolverSopa(diccionario, sopa);
    // La cantidad de palabras encontradas debe ser 9
    int expected = 9;
    int count = 0;
    while (res[count].palabra != NULL)
        printf("%s\n", res[count++].palabra);
    assert(count == expected);

    assert(strcmp(res[0].palabra, "ARRE") == 0);
    assert(res[0].fila == 1);
    assert(res[0].columna == 2);
    assert(res[0].direccion == D_AB);

    assert(strcmp(res[3].palabra, "ORCO") == 0);
    assert(res[3].fila == 3);
    assert(res[3].columna == 3);
    printf("%d\n", res[3].direccion);
    assert(res[3].direccion == ARR);

    assert(strcmp(res[4].palabra, "ORCO") == 0);
    assert(res[4].fila == 4);
    assert(res[4].columna == 3);
    assert(res[4].direccion == D_AR);

    assert(strcmp(res[6].palabra, "REA") == 0);
    assert(res[6].fila == 3);
    assert(res[6].columna == 2);
    assert(res[6].direccion == I_AR);
    free(res);
    puts("OK primera parte");

    char *diccionario2[] = {""};
    res = resolverSopa(diccionario2, sopa);
    // La cantidad de palabras encontradas debe ser 0
    expected = 0;
    count = 0;
    while (res[count].palabra != NULL)
        printf("%s\n", res[count++].palabra);
    assert(count == expected);
    free(res);
    puts("OK sin palabras encontradas");
    return 0;
}

posicion *resolverSopa(char *diccionario[], char sopa[][COLS])
{

    posicion *resultados = NULL;
    int tamanioResultados = 0;

    // Para cada palabra del diccionario
    for (int d = 0; diccionario[d][0] != '\0'; d++)
    {
        // Buscamos su equivalente en la sopa
        // Para eso primero recorremos la matriz buscando la primer letra
        char first_char = diccionario[d][0];
        // Recorremos toda la matriz porque si la palabra esta dos veces tiene que aparecer ambas
        for (int i = 0; i < FILS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                // Solo buscamos en todas las direcciones si encontramos la primer letra de la palabra
                if (first_char == sopa[i][j])
                {
                    for (Tdireccion dir = DER; dir <= D_AB; dir++)
                    {
                        // Si encontramos la palabra en una direccion la agregamos
                        if (buscarPalabra(i, j, diccionario[d], sopa, dir))
                        {
                            //Si devuelve falso hubo error de memoria
                            if(!agregarPalabra(&resultados, tamanioResultados, diccionario[d], i, j, dir))
                                return NULL;

                            tamanioResultados++;
                        }
                    }
                }
            }
        }
    }

    posicion *resultadosAux = realloc(resultados, (tamanioResultados + 1) * sizeof(posicion));
    if (resultadosAux == NULL)
    {
        free(resultados);
        return NULL;
    }
    resultados = resultadosAux;
    resultados[tamanioResultados].palabra = NULL; // Indicar final de resultados

    return resultados;
}

int agregarPalabra(posicion **resultados, int tamanioResultados, char *palabra, int fila, int columna, Tdireccion dir)
{
    posicion *resultadosAux;

    if (tamanioResultados % BLOQUE == 0)
    {
        resultadosAux = realloc(*resultados, (tamanioResultados + BLOQUE) * sizeof(posicion));
        if (resultadosAux == NULL && tamanioResultados != 0)
        {
            free(*resultados);
            return 0;
        }
        *resultados = resultadosAux;
    }

    (*resultados)[tamanioResultados].palabra = palabra;
    (*resultados)[tamanioResultados].fila = fila;
    (*resultados)[tamanioResultados].columna = columna;
    (*resultados)[tamanioResultados].direccion = dir;

    return 1;
}

int buscarPalabra(int fila, int columna, char *palabra, char sopa[FILS][COLS], Tdireccion dir)
{
    int len = strlen(palabra);

    for (int i = 0; i < len; i++)
    {
        int nuevaFila = fila + i * desplazamientos[dir][0];
        int nuevaColumna = columna + i * desplazamientos[dir][1];

        // Verificar límites de la sopa
        if (nuevaFila < 0 || nuevaFila >= FILS || nuevaColumna < 0 || nuevaColumna >= COLS)
        {
            return 0;
        }

        if (sopa[nuevaFila][nuevaColumna] != palabra[i])
        {
            return 0;
        }
    }

    return 1;
}
