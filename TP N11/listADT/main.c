#include <stdio.h>
#include <stdlib.h>
#include "./listADT.h"
#include <string.h>

typedef struct node {
    elemType head;
    struct node* tail;
} node;

int doble(int n) {
    return 2*n;
}

int comparo(int n1, int n2) {
    return n1 - n2;
}

int main(void) {
    listADT myList = newList((compare)comparo);
    insert(myList, 3);
    insert(myList, 4);
    insert(myList, 2);
    map(myList, doble);
    int size_list = size(myList);
    for ( int i = 0; i < size_list; i++ ) {
        printf("%d\t", elem_i(myList, i));
    }
    freeList(myList);
    puts("");
    return 0;
}