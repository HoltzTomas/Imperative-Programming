#include <stdio.h>
#include <assert.h>
#include "utillist.h"
#include <stdlib.h>

TList listUnion  (const TList list1, const TList list2);

int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  TList l1 = fromArray(v, 6);
  TList l2 = fromArray(w, 9);
  TList l3 = listUnion(l1, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l1);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, NULL);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(NULL, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);
  freeList(l1);
  freeList(l2);
  
  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listUnion(l1, l2);
  freeList(l1);
  freeList(l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);


  printf ("OK!\n");
  return 0;
}

TList listUnion (const TList list1, const TList list2) {
  if (list1 == NULL && list2 == NULL)
     return NULL;
  // Para simplificar casos, si lista1 es NULL, invertimos los parametros
  if ( list1 == NULL)
     return listUnion(list2, list1);
  // Sí o sí se va a crear uno nuevo
  TList aux = malloc(sizeof(TNode));

  // Copiamos el de lista 1 ?
  if (list2==NULL || list1->elem < list2->elem) {
    aux->elem = list1->elem;
    aux->tail = listUnion(list1->tail, list2);
  }
  // Copiamos de lista 2 ?
  // Ya sabemos que ni list1 ni list2 son NULL
  else if (list1->elem > list2->elem) {
    aux->elem = list2->elem;
    aux->tail = listUnion(list1, list2->tail);
  } else {   // Son iguales
    aux->elem = list1->elem;
    aux->tail = listUnion(list1->tail, list2->tail);
  }
  return aux;
}
