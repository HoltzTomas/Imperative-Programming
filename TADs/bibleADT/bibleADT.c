
#include "bibleADT.h"
#include <stdlib.h>
#include <string.h>

#define BOOKS 76
#define BLOCK 10

typedef char *tVerse;

typedef struct {
    tVerse *verses;
    size_t dim;
} tBook;

struct bibleCDT {
    tBook books[BOOKS];
};


void freeBible(bibleADT bible) {
    for ( int i = 0; i < BOOKS; i++ ) {
        for ( int j = 0; j < bible->books[i].dim; j++ ) {
            free(bible->books[i].verses[j]);
        }
        free(bible->books[i].verses);
    }
    free(bible);
}


int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse) {
    if ( verse == NULL || bookNbr > BOOKS || (bible->books[bookNbr - 1].dim >= verseNbr && bible->books[bookNbr - 1].verses[verseNbr - 1] != NULL) ) { // Ya está escrito
        return 0;
    }

    if ( bible->books[bookNbr - 1].dim < verseNbr ) {
        bible->books[bookNbr - 1].verses = realloc(bible->books[bookNbr - 1].verses, verseNbr * sizeof(tVerse));
        for ( int i = bible->books[bookNbr - 1].dim; i < verseNbr; i++ ) {
            bible->books[bookNbr - 1].verses[i] = NULL; // Relleno de NULL
        }
        bible->books[bookNbr - 1].dim = verseNbr;
    }

    char* res = NULL;
    int i;

    for ( i = 0; verse[i] != '\0'; i++ ) { // Copio el versiculo
        if ( i % BLOCK == 0 ) {
            res = realloc(res, (i + BLOCK) * sizeof(char));
        }
        res[i] = verse[i];
    }

    res = realloc(res, (i + 1) * sizeof(char));
    res[i] = '\0';
    bible->books[bookNbr - 1].verses[verseNbr - 1] = res;

    return 1;
}

char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr) {

    if ( bookNbr > BOOKS || bible->books[bookNbr - 1].dim < verseNbr || bible->books[bookNbr - 1].verses[verseNbr - 1] == NULL ) {
        return NULL;
    }

    char* res = malloc(strlen((bible->books[bookNbr - 1].verses[verseNbr - 1]) + 1) * sizeof(char));
    res = strcpy(res, bible->books[bookNbr - 1].verses[verseNbr - 1]);
    return res;
}

bibleADT newBible(void) {
    return calloc(1, sizeof(struct bibleCDT));
}
