
#include "jokesADT.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define BLOCK 20


typedef struct Joke {
    char * joke;
    size_t longitud; //No contamos el cero
} Joke;

//Dado que no implementamos deleteJokes (Donde tal vez sirviria el orden)
//Los jokes estaran desordenados, por ende se añaden de forma mas eficiente (al final)
//Y cuando devolvemos uno lo hacemos con un index random :)
typedef struct category {
    char * name;
    Joke * jokes; // Vector dinamico para almacenar los chistes
    size_t jokesSize; //Para poder añadir al final
    size_t reservedJokesSpace; //Esto para ir agrandando el vector de structs de a bloques
    struct category * next;
    size_t nameLen;
} CategoryNode;

//Las categorias estaran ordenadas en una lista dinamica por alfabeto
struct jokesCDT {
    CategoryNode * categoriesList;
    size_t categoriesAmount; //Para categoriesCount mas eficiente
};

static CategoryNode * addCategoryRec(CategoryNode * list, const char * category, int * flag);
static char* copyWithBlocks(char* s, size_t* dim);
static void addJokeRec(CategoryNode* list, const char * category, const char * joke);
static int randInt(int izq, int der);
static char* jokeRec(CategoryNode* list, const char * category);

jokesADT newJokes(void) {
    return calloc(1, sizeof(struct jokesCDT));
}

void addCategory(jokesADT jokes, const char * category) {
    if(category == NULL)
        return;

    int flag = 0;

    jokes->categoriesList = addCategoryRec(jokes->categoriesList, category, &flag);

    jokes->categoriesAmount += flag;
}

static CategoryNode * addCategoryRec(CategoryNode * list, const char * category, int * flag) {
    int res;
    
    if(list == NULL || (res=strcmp(list->name, category)) > 0) {
        CategoryNode * newCategory = calloc(1, sizeof(CategoryNode));
        newCategory->nameLen = strlen(category);
        newCategory->name = malloc(sizeof(char) * (newCategory->nameLen + 1));
        strcpy(newCategory->name, category);
        newCategory->next = list;
        *flag =1;
        return newCategory;
    }

    //Si la categoria estaba no agregamos
    if(res == 0)
        return list;

    list->next = addCategoryRec(list->next, category, flag);
    return list;
}

void addJoke(jokesADT jokes, const char * category, const char * joke) {
    addJokeRec(jokes->categoriesList, category, joke);
}

static void addJokeRec(CategoryNode* list, const char * category, const char * joke) {
    
    int res;
    if(list == NULL) 
        return;

    if((res = strcmp(list->name, category)) == 0) {
        if(list->reservedJokesSpace == list->jokesSize) {
            list->reservedJokesSpace += BLOCK;
            list->jokes = realloc(list->jokes, sizeof(Joke) * list->reservedJokesSpace);
            for (size_t i = list->jokesSize; i <= list->reservedJokesSpace; i++)
            {
                list->jokes[i].longitud = 0;
                list->jokes[i].joke = NULL;
            }
        }

        //Ahora que nos aseguramos de que existe el espacio
        //Copiamos en bloques porque puede tener miles de caracteres
        list->jokes[list->jokesSize].joke = copyWithBlocks(joke, &(list->jokes[list->jokesSize].longitud));
        list->jokesSize++;
    }

    if ( res < 0 ) {
        addJokeRec(list->next, category, joke);
    } 

}

static char* copyWithBlocks(char* s, size_t* dim) {
    char* res = NULL;
    int i;
    for ( i = 0; s[i] != '\0'; i++ ) {
        if ( i % BLOCK == 0 ) {
            res = realloc(res, i + BLOCK);
        }
        res[i] = s[i];
    }
    res = realloc(res, i + 1);
    res[i] = '\0';
    *dim = i; // No cuento el cero final
    return res;
}
char * joke(jokesADT jokes, const char * category) {
    return jokeRec(jokes->categoriesList, category);
}

static int randInt(int izq, int der) {
    if(izq > der) {
        int aux = izq;
        izq = der;
        der = aux;
    }

    return rand() % (der-izq+1) - izq;
}

static char* jokeRec(CategoryNode* list, const char * category) {
    int res;
    if ( list == NULL || (res = strcmp(list->name, category)) > 0 ) {
        return NULL;
    }
    else if ( res == 0 ) {
        int index = randInt(0, list->jokesSize - 1);
        char* joke_res = malloc(list->jokes[index].longitud + 1);
        strcpy(joke_res, list->jokes[index].joke);
        return joke_res;
    }
    return jokeRec(list->next, category);
}

size_t categoriesCount(const jokesADT jokes) {
    return jokes->categoriesAmount;
}

char ** categories(const jokesADT jokes) {
    size_t categoriesCant = categoriesCount(jokes);
    if(categoriesCant == 0)
        return NULL;

    CategoryNode * aux = jokes->categoriesList;
    char** res = malloc(categoriesCant * sizeof(char *));
    for ( int i = 0; i < categoriesCant; i++ ) {
        res[i] = malloc(aux->nameLen + 1);
        strcpy(res[i], aux->name);
        aux = aux->next;
    }
    return res;
}

void freeJokes(jokesADT jokes) {
    CategoryNode* aux = jokes->categoriesList;
    while ( aux != NULL ) {
        free(aux->name);
        for ( int i = 0; i < aux->jokesSize; i++ ) {
            free(aux->jokes[i].joke);
        }
        free(aux->jokes);
        CategoryNode* aux_free = aux;
        aux = aux->next;
        free(aux_free);
    }
    free(jokes);
}