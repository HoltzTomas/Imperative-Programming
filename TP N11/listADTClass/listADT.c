#include "listADT.h"
#include <stdlib.h>

struct listCDT {
    compare cmp;
    int size;
    struct node * first;
};

struct node {
    elemType head;
    struct node * tail;
};

struct node * recursiveAdd(struct node * list, elemType elem, compare cmp, int *flag);

int add(listADT list, elemType elem) {
    int flag = 0;
    list->first = recursiveAdd(list->first, elem, list->cmp, &flag);
    list->size += flag;
    return flag;
}

struct node * recursiveAdd(struct node * list, elemType elem, compare cmp, int *flag) {
    int res;

    if (list == NULL || (res = cmp(list->head, elem)) > 0) {
        struct node* aux = malloc(sizeof(struct node));
        aux->head = elem;
        aux->tail = list;
        *flag = 1;
        return aux;
    }

    if (res < 0) {
        list->tail = recursiveAdd(list->tail, elem, cmp, flag);
    }
    return list;
}

int isEmpty(const listADT list) {
    return list->first == NULL;
}

int sizeList(const listADT list) {
    return list->size;
}

listADT newList(compare cmpFn) {
    listADT l = calloc(1, sizeof(struct listCDT));
    l->cmp = cmpFn;
    return l;
}

int belongs(const listADT list, elemType elem) {
    return recursiveBelongs(list->first, elem, list->cmp);
}

int recursiveBelongs(struct node * l, elemType elem, compare cmp) {
    if (l == NULL)
        return 0;

    if (cmp(l->head, elem) == 0)
        return 1;

    return recursiveBelongs(l->tail, elem, cmp);
}

void map(listADT l, elemType (*mod)(elemType)) {
    mapRecursive(l->first, mod);
}

void mapRecursive(struct node * elem, elemType (*mod)(elemType)) {
    if (elem == NULL)
        return;

    elem->head = mod(elem->head);
    mapRecursive(elem->tail, mod);  // Continúa con el siguiente nodo
}
