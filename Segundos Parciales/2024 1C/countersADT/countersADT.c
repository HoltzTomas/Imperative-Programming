#include "countersADT.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct person {
    char * name;
    struct person * next;
};

typedef struct person * List;

typedef struct counter {
    List firstPerson;
    List lastPerson; // Lo necesito para insertar de forma eficiente
    size_t waitingPassengers;
    List iterCounter; // Para iterar
} Counter;

struct countersCDT {
    size_t maxCounters;
    Counter *counterVec;
};

static void freeList(List initialNode);

countersADT newCounters(size_t maxCounters) {
    if (maxCounters == 0)
        return NULL;

    countersADT newCounter = calloc(1, sizeof(struct countersCDT));
    newCounter->maxCounters = maxCounters;
    newCounter->counterVec = calloc(maxCounters, sizeof(Counter));

    return newCounter;
}

void enterCounter(countersADT counters, size_t counterNumber, const char * passenger) {
    assert(counterNumber < counters->maxCounters);
    assert(passenger != NULL);

    List newPerson = calloc(1, sizeof(struct person));
    newPerson->name = strcpy(malloc(strlen(passenger)+1), passenger);;  // Usamos strdup para asignar y copiar
    if (counters->counterVec[counterNumber].lastPerson == NULL) {
        counters->counterVec[counterNumber].firstPerson = newPerson;
        counters->counterVec[counterNumber].lastPerson = newPerson;
    } else {
        counters->counterVec[counterNumber].lastPerson->next = newPerson;
        counters->counterVec[counterNumber].lastPerson = newPerson;
    }
    counters->counterVec[counterNumber].waitingPassengers++;
}

void toBeginByCounter(countersADT counters, size_t counterNumber) {
    counters->counterVec[counterNumber].iterCounter = counters->counterVec[counterNumber].firstPerson;
}

size_t hasNextByCounter(const countersADT counters, size_t counterNumber) {
    return counters->counterVec[counterNumber].iterCounter != NULL;
} 

const char * nextByCounter(countersADT counters, size_t counterNumber) {
    if (!hasNextByCounter(counters, counterNumber)) {
        exit(1);  // No hay siguiente elemento
    }

    const char * elem = counters->counterVec[counterNumber].iterCounter->name;
    counters->counterVec[counterNumber].iterCounter = counters->counterVec[counterNumber].iterCounter->next;
    return elem;
}

struct checkInResult * checkInCounters(countersADT counters, size_t * checkInResultDim) {
    int dim = 0;
    struct checkInResult * checkInList = NULL;

    for (size_t i = 0; i < counters->maxCounters; i++) {
        if (counters->counterVec[i].firstPerson != NULL) {
            checkInList = realloc(checkInList, (dim + 1) * sizeof(struct checkInResult));

            struct person *toRemove = counters->counterVec[i].firstPerson;
            
            // Creamos una copia de `name` antes de liberar `toRemove`
            char *passengerNameCopy = strcpy(malloc(strlen(toRemove->name)+1), toRemove->name);;

            struct checkInResult aux = {
                .counterNumber = i,
                .checkedInPassenger = passengerNameCopy,  // Usamos la copia
                .waitingPassengers = counters->counterVec[i].waitingPassengers - 1,
            };

            counters->counterVec[i].firstPerson = toRemove->next;

            if (counters->counterVec[i].firstPerson == NULL) {
                counters->counterVec[i].lastPerson = NULL;
            }

            free(toRemove->name);
            free(toRemove);
            counters->counterVec[i].waitingPassengers--;

            checkInList[dim++] = aux;
        }
    }

    *checkInResultDim = dim;
    return checkInList;
}

static void freeList(List initialNode) {
    if (initialNode == NULL)
        return;

    freeList(initialNode->next);
    free(initialNode->name);
    free(initialNode);
}

void freeCounters(countersADT counters) {
    for (size_t i = 0; i < counters->maxCounters; i++) {
        freeList(counters->counterVec[i].firstPerson);
    }
    free(counters->counterVec);
    free(counters);
}
