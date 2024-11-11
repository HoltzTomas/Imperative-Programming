
#include <stdlib.h>
#include "socialADT.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define MAX 21

struct related {
    char name[MAX];             // Usamos un vector estático porque hay un límite y es pequeño.
                                // También se podría usar char*, y no tener un límite.
    struct related * nextR;
};

struct person {
    char name[MAX];
    struct related * firstR;
    struct person * next;
    size_t size;
};

struct socialCDT {
    struct person * people;
    size_t sizeP;
};

static char * copyStr(const char * s) {
    return strcpy(malloc(strlen(s)+1), s);
}


static struct person * addPersonRec(struct person * first, const char * name, int *ok);
static void freeRelated(struct related * first);
static void freeSocialP(struct person * first);
static struct person * findPerson(struct person * first, const char * name);

static struct person * findPerson(struct person * first, const char * name) {
    struct person * aux = first;
    while ( aux != NULL) {
        int c = strcmp(aux->name, name);
        if ( c == 0) {
            return aux;
        }
        if ( c > 0)
            return NULL;
        aux = aux->next;
    }
    return NULL;
}

socialADT newSocial(void) {
    return calloc(1, sizeof(struct socialCDT));
}

static void freeRelated(struct related * first) {
    if ( first == NULL)
        return;
    freeRelated(first->nextR);
    free(first);
}

static void freeSocialP(struct person * first) {
    if ( first == NULL)
        return;
    freeSocialP(first->next);
    freeRelated(first->firstR);
    free(first);
}

/* Libera todos los recursos reservados por el TAD */
void freeSocial(socialADT soc) {
    freeSocialP(soc->people);
    free(soc);
}

void addPerson(socialADT soc, const char * name) {
    int ok=0;
    soc->people = addPersonRec(soc->people, name, &ok);
    if(ok)
        soc->sizeP++;
    return;
}
static struct person * addPersonRec(struct person * first, const char * name, int *ok){
    int c;
    if ( first == NULL || ( c = strcmp(first->name, name)) > 0) {
        struct person * aux = malloc(sizeof(struct person));
        aux->firstR = NULL;
        aux->size = 0;
        // si usaban char *, debían hacer aux->name = malloc(strlen(name)+1);
        strncpy(aux->name, name, MAX-1);        // Programación defensiva: usamos strncpy para no pisar memoria
        aux->name[MAX-1] = 0;                   // si strncpy copia la cantidad justa, no agrega ceros
        aux->next = first;
        *ok=1;
        return aux;
    }
    if ( c < 0)
        first->next = addPersonRec(first->next, name, ok);
    return first;
}

static struct related * addRelatedRec(struct related * first, const char * name){
    int c;
    if ( first == NULL || ( c = strcmp(first->name, name)) >= 0) {
        struct related * aux = malloc(sizeof(struct related));
        strncpy(aux->name, name, MAX-1);
        aux->name[MAX-1] = 0;                   // si strncpy copia la cantidad justa, no agrega ceros
        aux->nextR = first;
        return aux;
    }
    if ( c < 0)
        first->nextR = addRelatedRec(first->nextR, name);
    return first;
}

void addRelated(socialADT soc, const char * name, const char * related) {
    struct person * aux = findPerson(soc->people, name);
    if(aux != NULL){
        aux->firstR = addRelatedRec(aux->firstR, related);
        aux->size++;
    }
}

char ** related(const socialADT soc, const char * person) {
    char ** ans;
    struct person * p = findPerson(soc->people, person);
    int k=0;

    if ( p != NULL) {
        ans = malloc((p->size+1) * sizeof(char *));
        struct related * auxR = p->firstR;
        while ( auxR != NULL) {
            ans[k++] = copyStr(auxR->name);
            auxR = auxR->nextR;
        }
    } else
        ans = malloc(sizeof(char *));
    
    ans[k] = NULL;
    return ans;
}

char ** persons(const socialADT soc) {
    char ** ans = malloc((soc->sizeP+1) * sizeof(char *));
    struct person * aux = soc->people;
    int k=0;
    while ( aux != NULL) {
        ans[k++] = copyStr(aux->name);
        aux = aux->next;
    }

    ans[k] = NULL;
    return ans;
}
