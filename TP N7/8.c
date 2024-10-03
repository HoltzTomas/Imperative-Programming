/**
 * * Escribir un programa que realice la simulación de un bingo para dos jugadores
 *
 * @cond este imprimirá paso a paso la bolilla extraída y los números faltantes (que aún no salieron)de cada cartón.
 *
 * @cond Las bolillas están representadas por los números del 1 al 90
 *       y cada jugador tiene un cartón con 15 números distintos.
 *
 * @cond Los cartones son generados por el programa en forma aleatoria.
 *       No es necesario conservar los números que se van marcando en cada cartón
 *       (cuando hay coincidencia con la bolilla extraída)
 *
 * @typedef int TipoLinea[5];
 *
 * @typedef TipoLinea Carton[3];
 *
 */

#include "stdio.h"
#include "../random.h"

#define NUMEROS 90
#define LINEAS 3
#define COLS 5

typedef int Linea[5];
typedef Linea Carton[3];

void generarCarton(Carton c);
void swap(int *a, int *b);
void generarCarton(Carton carton);
int sacarBolilla(int bolillero[], int indice);
int controlarCarton(Carton carton, int bolilla);
int buscarBolilla(Carton carton, int bolilla);
int controlarLinea(int linea[]);
void imprimirCarton(Carton carton);
int jugar(int bolillero[], Carton carton1, Carton carton2);

int main(void)
{

    //* Planto semilla
    randomize();

    //* Generar carton
    Carton carton1, carton2;
    generarCarton(carton1);
    generarCarton(carton2);

    //* Jugar
    int bolillero[NUMEROS];
    jugar(bolillero, carton1, carton2);
}

int jugar(int bolillero[NUMEROS], Carton carton1, Carton carton2)
{
    // Primero lleno el bolillero
    for (int i = 0; i < NUMEROS; i++)
        bolillero[i] = i + 1;

    // Y ahora lo mezclo
    for (int i = 0; i < NUMEROS; i++)
        swap(&bolillero[i], &bolillero[randInt(0, NUMEROS - 1)]);

    // Saco bolillas hasta que un carton este lleno
    int bingo = 0, bolilla, j1, j2;
    for (int i = 0; i < NUMEROS && !bingo; i++)
    {
        // Sacar bolilla
        bolilla = sacarBolilla(bolillero, i);
        j1 = controlarCarton(carton1, bolilla);
        j2 = controlarCarton(carton2, bolilla);
        printf("Bolilla sacada: %i\n\n", bolilla);
        puts("TABLERO 1:");
        imprimirCarton(carton1);
        puts("TABLERO 2:");
        imprimirCarton(carton2);
        if (j1 == LINEAS || j2 == LINEAS)
        {
            bingo++;
        }
    }
    return (j1 == LINEAS ? (j2 == LINEAS ? 3 : 1) : (j2 == LINEAS ? 1 : 0));
}

int sacarBolilla(int bolillero[], int indice)
{
    return (bolillero[indice]);
}

int controlarCarton(Carton carton, int bolilla)
{
    buscarBolilla(carton, bolilla);
    int counter_linea = 0;
    for (int i = 0; i < LINEAS; i++)
    {
        counter_linea += controlarLinea(carton[i]);
    }
    return counter_linea;
}

int buscarBolilla(Carton carton, int bolilla)
{
    for (int i = 0; i < LINEAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (carton[i][j] == bolilla)
            {
                carton[i][j] = '\0'; // Marco que fue encontrado
                return 1;
            }
        }
    }
    return 0;
}

int controlarLinea(int linea[])
{
    for (int i = 0; i < COLS; i++)
    {
        if (linea[i] != '\0')
        {
            return 0;
        }
    }
    return 1;
}

void imprimirCarton(Carton carton)
{
    for (int i = 0; i < LINEAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%i\t", carton[i][j]);
        }
        puts("");
    }
    puts("");
}

void generarCarton(Carton carton)
{

    // Creo un vector con numeros del 1 a 90 ordenados ascendentemente
    unsigned v[NUMEROS];

    for (int i = 0; i < 90; i++)
        v[i] = i + 1;

    // Los mezclo
    for (int i = 0; i < NUMEROS; i++)
    {
        swap(&v[i], &v[randInt(0, NUMEROS - 1)]);
    }

    // Lleno carton
    int indice_v = 0;
    for (int i = 0; i < LINEAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            carton[i][j] = v[indice_v++];
        }
    }
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}