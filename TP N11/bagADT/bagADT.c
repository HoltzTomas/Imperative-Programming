
#include "bagADT.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *tail;
    unsigned count;
    elemType head;
};

typedef struct node * nodeP;

typedef struct bagCDT {
    nodeP first;
    unsigned size;
    compare cmp;
} bagCDT;

static nodeP addRec(nodeP first, elemType elem, compare cmp, unsigned *count);
static unsigned countRec(nodeP first, elemType elem, compare cmp);
static nodeP removeRec(nodeP first, elemType elem, int * countElem, compare cmp);

bagADT newBag(compare cmp) {
    bagADT bag = calloc(1, sizeof(bagCDT));
    bag->cmp = cmp;
    return bag;
}

unsigned int add(bagADT bag, elemType elem) {
    unsigned countOutput;
    bag->first = addRec(bag->first, elem, bag->cmp, &countOutput);

    if (countOutput == 1)	// es el primero
		bag->size++;

    return countOutput;
}

static nodeP addRec(nodeP first, elemType elem, compare cmp, unsigned *count) {
    int res;

    if(first == NULL || (res = cmp(elem, first->head)) < 0) {
        nodeP newNode = malloc( sizeof(struct node));
        newNode->tail = first;
        newNode->head =elem;
        newNode->count =1;
        *count = 1;
        return newNode;
    }

    if(res > 0){
        first->tail = addRec(first->tail, elem, cmp, count);
    }

    if(res == 0) {
        first->count++;
        *count = first->count;
    }

    return first;
}

unsigned int count(const bagADT bag, elemType elem) {

    return countRec(bag->first, elem, bag->cmp);
}

static unsigned countRec(nodeP first, elemType elem, compare cmp) {

    int res;

    if(first == NULL || (res=cmp(elem, first->head)) < 0)
        return 0;

    if(res == 0)
        return first->count;

    return countRec(first->tail, elem, cmp);
}

unsigned int size(const bagADT bag) {
    return bag->size;
}

unsigned int delete(bagADT bag, elemType elem) {
    int countElem;

    bag->first = removeRec(bag->first, elem, &countElem, bag->cmp);

    if (countElem == 0)	// habia uno solo
        bag->size--;
    else if ( countElem < 0) {
        countElem = 0;
    }
    return countElem;

}

static nodeP removeRec(nodeP first, elemType elem, int * countElem, compare cmp) {
    int c;
    if( first == NULL || (c=cmp(first->head, elem)) > 0 ) {
        // El elemento no estaba, no alterar la lista e indicar que no está
        *countElem = -1;
        return first;
    }
    if( c < 0 )
        first->tail = removeRec( first->tail, elem, countElem, cmp);
    else {
        *countElem = --(first->count);
        if ( *countElem == 0) {
            nodeP aux = first->tail;
            free(first);
            first = aux;
        }
    }
    return first;
}

void freeBag( bagADT bag) {
	nodeP curr = bag->first, aux;

	while (curr != NULL) {
		aux = curr->tail;
		free(curr);
		curr = aux;
	}
	free(bag);
}

elemType mostPopular(bagADT bag) {
    elemType ans;
	if ( bag->size == 0) {
		fprintf(stderr, "El bag no debe estar vacío\n");
        exit(1);
	} else {
		nodeP aux = bag->first;
		int cant = aux->count;
		ans = aux->head;
		aux = aux->tail;
		while ( aux != NULL ) {
			if ( aux->count > cant ) {
				ans = aux->head;
				cant = aux->count;
			}
			aux = aux->tail;
		}
	}
	return ans;
}
