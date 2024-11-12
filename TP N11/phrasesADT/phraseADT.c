#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "phrasesADT.h"
#define BLOCK 20

typedef struct node {
    size_t head;
    struct node* tail;
} TNode;

typedef TNode* TList;

typedef struct {
    char* phrase;
    size_t longitud; // Sin contar el 0
    size_t reservado;
} elemVec;

typedef struct phrasesCDT {
    size_t keyFrom;
    size_t keyTo;
    elemVec* phrases; // Vector donde guardo las frases asociadas a las claves
    size_t cantidad; // Cantidad de frases reservadas
} phrasesCDT;

phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo) {
    if ( keyFrom > keyTo ) {
        return NULL;
    }
    phrasesADT new = malloc(sizeof(phrasesCDT));
    new->cantidad = 0;
    new->keyFrom = keyFrom;
    new->keyTo = keyTo;
    new->phrases = calloc(1, (keyTo - keyFrom + 1) * sizeof(elemVec));
    return new;
}

static int isValidKey (phrasesADT ph, size_t key) {
    return key >= ph->keyFrom && key <= ph->keyTo;
}

int put(phrasesADT ph, size_t key, const char * phrase) {
    if ( !isValidKey(ph, key) ) {
        return 0;
    }
    size_t index = key - ph->keyFrom;
    if ( ph->phrases[index].phrase == NULL ) { // Si no estaba ocupado, agrego la key a mi lista de keys
        ph->cantidad++;
    }
    ph->phrases[index].longitud = 0; // Esté o no ocupado, la piso
    ph->phrases[index].reservado = 0;
    // Como dice que la frase puede tener miles de caracteres, es ineficiente hacer strlen yluego strcpy porque la recorro dos veces. Realoco de a bloques
    int i;
    for ( i = 0; phrase[i] != '\0'; i++ ) {
        if ( ph->phrases[index].longitud == ph->phrases[index].reservado ) {
            ph->phrases[index].reservado += BLOCK;
            ph->phrases[index].phrase = realloc(ph->phrases[index].phrase, ph->phrases[index].reservado * sizeof(char));
        }
        ph->phrases[index].phrase[i] = phrase[i];
        ph->phrases[index].longitud++;
    }
    ph->phrases[index].phrase = realloc(ph->phrases[index].phrase, (ph->phrases[index].longitud + 1) * sizeof(char));
    ph->phrases[index].phrase[i] = '\0';
    return 1;
}

char* get(const phrasesADT ph, size_t key) {
    size_t index = key - ph->keyFrom;
    if ( !isValidKey(ph, key) || ph->phrases[index].phrase == NULL ) {
        return NULL;
    }
    char* res = malloc((ph->phrases[index].longitud + 1) * sizeof(char));
    res = strcpy(res, ph->phrases[index].phrase);
    return res;
}

size_t size(const phrasesADT ph) {
    return ph->cantidad;
}

char* concatAll(const phrasesADT ph) {
    char* res = NULL;
    int dim_resp = 0;
    int reservado = 0;
    size_t aux = ph->cantidad; // Si llego a la cantidad de claves, corto antes
    for ( int i = 0; i < ph->keyTo - ph->keyFrom + 1 && aux > 0; i++ ) {
        if ( ph->phrases[i].phrase != NULL ) {
            reservado += ph->phrases[i].longitud;
            res = realloc(res, reservado * sizeof(char));
            for ( int j = 0; j < ph->phrases[i].longitud; j++ ) {
                res[dim_resp++] = ph->phrases[i].phrase[j];
            }
            aux--;
        }
    }
    res = realloc(res, (dim_resp + 1) * sizeof(char));
    res[dim_resp] = '\0';
    return res;
}

char* concat(const phrasesADT ph, size_t from, size_t to) {
    if ( !isValidKey(ph, from) || !isValidKey(ph, to) ) {
        return NULL;
    }
    char* res = NULL;
    int reservado = 0;
    int dim_resp = 0;
    size_t aux = ph->cantidad;
    for ( int i = from - ph->keyFrom; i <= to - ph->keyFrom && aux > 0; i++ ) {
        if ( ph->phrases[i].phrase != NULL ) {
            reservado += ph->phrases[i].longitud;
            res = realloc(res, reservado * sizeof(char));
            for ( int j = 0; j < ph->phrases[i].longitud; j++ ) {
                res[dim_resp++] = ph->phrases[i].phrase[j];
            }
            aux--;
        }
    }
    res = realloc(res, (dim_resp + 1) * sizeof(char));
    res[dim_resp] = '\0';
    return res;
}

void freePhrases(phrasesADT ph) {
    for ( int i = 0; i < (ph->keyTo - ph->keyFrom + 1); i++ ) {
        free(ph->phrases[i].phrase);
    }
    free(ph->phrases);
    free(ph);
}