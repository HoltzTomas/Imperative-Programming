
#include "dataADT.h"
#define BLOCK 10

typedef struct node {
    elemType elem;
    struct node * tail;
} tNode;

typedef tNode * List;

typedef struct dataCDT {
    compare cmp;
    List list;
    size_t elemsAmount;
} dataCDT;

static List addElementRec(List firstElem, elemType elem, int *output, compare cmp);

dataADT newData(compare cmp) {
    dataADT newData = calloc(1, sizeof(dataCDT));
    newData->cmp = cmp;
    return newData;
}

int addElement(dataADT data, elemType elem) {
    int added = 0;

    data->list = addElementRec(data->list, elem, flag, data->cmp);

    return added;
}

static List addElementRec(List firstElem, elemType elem, int *output, compare cmp) {
    int c;
    if(firstElem == NULL || (c=cmp(elem, firstElem->tail)) < 0) {
        List aux = malloc(sizeof(tNode));
        aux->elem = elem;
        aux->tail = firstElem;
        *output = 1;
        return aux;
    }

    if(c == 0)
        return firstElem;

    addElementRec(firstElem->tail, elem, output, cmp);
    return firstElem;
}

int deleteElement(dataADT data, elemType elem) {
    int deleted = 0;
    data->list = deleteElemRec(data->list, elem, &deleted, data->cmp);
    return deleted;
}

static List deleteElemRec(List firstElem, elemType elem, int *output, compare cmp) {
    if(firstElem == NULL || (c=cmp(elem, firstElem->tail)) < 0) 
        return firstElem;

    if(c == 0){
        //Eliminamos este elemento
        List aux = firstElem->tail;
        free(firstElem);
        return aux;
    }

     firstElem->tail = addElementRec(firstElem->tail, elem, flag, cmp);
     return firstElem;
}

elemType * elems(const dataADT data, int (*filter) (elemType), size_t * dim) {

    List aux = data->list;
    int dimAux = 0;
    elemType * res = NULL;

    while (aux != NULL)
    {
        if(filter(aux->elem)){
            if(dimAux % BLOCK == 0) {
                res = realloc(res, sizeof(elemType) * (BLOCK + dimAux));
            }

            res[dimAux++] = aux->elem;
        }
        aux = aux->tail;
    }
    
    *dim = dimAux;
    return res;
}

    





