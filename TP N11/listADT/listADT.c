#include <stdlib.h>
#include "./listADT.h"

typedef struct node {
    elemType head;
    struct node* tail;
} node;

struct listCDT {
    node* first;
    int size;
    compare cmp;
    node* next;
};

listADT newList (compare compare) {
    listADT aux = calloc(1, sizeof(struct listCDT));
    aux->cmp = compare;
    return aux;
}

int isEmptyList (const listADT list) {
    return list->size == 0;
}

int size(const listADT list) {
    return list->size;
}

// La lista está ordenada, corto antes si me paso
int belongs(const listADT list, elemType elem) {
    node* aux = list->first;
    int res;
    while ( aux != NULL && (res = list->cmp(aux->head, elem)) <= 0 ) {
        if ( res == 0 ) {
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

node* deleteRec(node* list, elemType elem, compare cmp, int* flag) {
    int res;
    if ( list == NULL || ( res = cmp(list->head, elem) ) > 0 ) {
        return list;
    }
    if ( res == 0 ) {
        node* aux = list->tail;
        free(list);
        *flag = 1;
        return aux;
    }
    list->tail = deleteRec(list->tail, elem, cmp, flag);
    return list;
}

int delete(listADT list, elemType elem) {
    int flag = 0;
    deleteRec(list->first, elem, list->cmp, &flag);
    return flag;
}

int elem_i(listADT list, int pos) {
    if ( pos >= list->size ) {
        exit(1);
    }
    node* aux = list->first;
    int i;
    for ( i = 0; i < pos; i++ ) {
        aux = aux->tail;
    }
    return aux->head;
}

void map(listADT list, elemType (*funcion) (elemType)) {
    node* aux = list->first;
    while ( aux != NULL ) {
        aux->head = funcion(aux->head);
        aux = aux->tail;
    }
}

static node* insertRec(node* list, elemType elem, compare cmp, int* flag) {
    int res;
    if ( list == NULL || (res = cmp(list->head, elem)) > 0 ) {
        node* aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        *flag = 1;
        return aux;
    }
    if ( res == 0 ) {
        return list;
    }
    list->tail = insertRec(list->tail, elem, cmp, flag);
    return list;
}

int insert(listADT list, elemType elem) {
    int flag = 0;
    list->first = insertRec(list->first, elem, list->cmp, &flag);
    list->size += flag;
    return flag;
}

static void freeRec(node* list) {
    if ( list == NULL ) {
        return;
    }
    node* aux = list->tail;
    free(list);
    freeRec(aux);
}

void freeList(listADT list) {
    freeRec(list->first);
    free(list);
}
elemType elementAtIndexRec(const node* list, size_t index) {
    if ( index == 0 ) {
        return list->head;
    }
    return elementAtIndexRec(list->tail, index - 1);
}

elemType elementAtIndex(const listADT list, size_t index) {
    if ( list->first == NULL || index >= list->size ) {
        exit(1);
    }
    return elementAtIndexRec(list->first, index);
}

void toBegin(listADT list) {
    list->next = list->first;
}

elemType next(listADT list) {
    if (!hasNext(list)) {
        exit(1);
    }
    elemType aux = list->next->head;
    list->next = list->next->tail;
    return aux;
}

int hasNext(listADT list) {
    return list->next != NULL;
}