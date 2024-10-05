#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../random.h"

#define CARTAS 52
#define PALOS 4
#define SWAP_STEPS 52

char *figuras[] = {
    "A", // As
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "J", // Jota
    "Q", // Reina
    "K"  // Rey
};
char *palos[] = {"Corazones", "Diamantes", "Tréboles", "Picas"};

typedef struct
{
    char *figura;
    char *palo;
} Carta;

typedef Carta Mazo[CARTAS];

int swap(int a, int b);
int randInt(int izq, int der);
void generarMazo(Mazo mazo);
void generarPalo(Mazo mazo, char *palo, unsigned indice_inicio);
void mezclarMazo(Mazo mazo);
void swapCartas(Carta *carta1, Carta *carta2);
void printCartas(Mazo mazo, unsigned cant);
void buscarConfigs(Mazo mazo, int configs[3]);

int main(void)
{

    srand(time(NULL));

    // Primero crear el mazo y mezclarlo
    Mazo mazo;
    mezclarMazo(mazo);

    // Primer posicion pares, segundo piernas, tercero poker
    int configuraciones[3] = {0};
    buscarConfigs(mazo, configuraciones);

    printf("PAR\tPIERNA\tPOKER\n");
    for ( int i = 0; i < 3; i++ ) {
        printf("%d\t", configuraciones[i]);
    }
    puts("");
}

void buscarConfigs(Mazo mazo, int configs[3]){
    int conteo[13] = {0}; // Arreglo para contar cuántas veces aparece cada figura

    for (int i = 0; i < 5; i++)
    {
        int cartaEncontrada = 0;
        for (int j = 0; j < 13 && !cartaEncontrada; j++)
        {
            if (strcmp(mazo[i].figura, figuras[j]) == 0)
            {
                conteo[j]++;
                cartaEncontrada++;
            }
        }
    }

    for (int i = 0; i < 13; i++)
    {
        switch (conteo[i])
        {
        case 2:
            configs[0]++;
            break;
        case 3:
            configs[1]++;
            break;
        case 4:
            configs[2]++;
            break;
        default:
            break;
        }
    }
}

void mezclarMazo(Mazo mazo)
{

    generarMazo(mazo);

    for (int i = 0; i < SWAP_STEPS; i++)
        swapCartas(&mazo[i], &mazo[randInt(0, CARTAS - 1)]);

    printCartas(mazo, 5);
}

void printCartas(Mazo mazo, unsigned cant)
{
    for (int i = 0; i < cant; i++)
        printf("%s\t%s\n", mazo[i].palo, mazo[i].figura);
    puts("");
}

void swapCartas(Carta *carta1, Carta *carta2)
{
    Carta aux = *carta1;
    *carta1 = *carta2;
    *carta2 = aux;
}

void generarMazo(Mazo mazo)
{
    generarPalo(mazo, palos[0], 0);
    generarPalo(mazo, palos[1], CARTAS / PALOS);
    generarPalo(mazo, palos[2], 2 * (CARTAS / PALOS));
    generarPalo(mazo, palos[3], 3 * (CARTAS / PALOS));
}

void generarPalo(Mazo mazo, char *palo, unsigned indice_inicio)
{
    for (int i = indice_inicio; i < indice_inicio + CARTAS / PALOS; i++)
        mazo[i] = (Carta) {figuras[i % 13], palo};
}