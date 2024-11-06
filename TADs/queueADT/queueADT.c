#include <stdlib.h>
#include "queueADT.h"

//Esto maneja una cola de enteros no ordenados
//Por eso nos sirve el last, para agregar directamente al final
//total no hay que llevar orden

typedef struct node {
    elementType value;
    struct node *next;
} tnode;

struct queueCDT {
    tnode *first;
    tnode *last;
    tnode *iterator;
};

static void freeRec(tnode *l);

void toBegin(queueADT q) {
    q->iterator = q->first;
    return;
}

int hasNext(queueADT q) {
    return q->iterator != NULL;
}

elementType next(queueADT q) {
    if(!hasNext(q)) exit(1);

    elementType elem = q->iterator->value;
    q->iterator = q->iterator->next;
    return elem;
}

void queue(queueADT q, elementType n) {
    tnode *node = calloc(1, sizeof(tnode));
    node->value = n;

    if(isEmpty(q)) {
        q->first = node;
        q->last = node;
    } else {
        q->last->next = node;
        q->last = node;
    }

    return;
}

void dequeue(queueADT q, elementType * out) {
    if(!isEmpty(q)) {
        *out = q->first->value;
        tnode *currentFirst = q->first;
        if(currentFirst == q->last){
            q->first = q->last = NULL;
        } else {
            q->first = q->first->next;
        }
        free(currentFirst);
        return;
    }
}

int isEmpty(queueADT q) {
    return q->last == NULL;
}

void freeQueue(queueADT q) {
    freeRec(q->first);
    free(q);
}

static void freeRec(tnode *l) {
    if(l == NULL)
        return;

    freeRec(l->next);
    free(l);
}

queueADT newQueue(void) {
    return calloc(1, sizeof(struct queueCDT));
}
