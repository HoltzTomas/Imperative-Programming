// LISTA DE elemType

#ifndef UNTITLED5_LISTADT_H
#define UNTITLED5_LISTADT_H

typedef struct listCDT* listADT;

typedef int elemType;

// Retorna 0 si son iguales, > 0 si e1 es "mayor" que e2, <0 si e1 es "menor" que e2
typedef int (*compare) (elemType e1, elemType e2);

listADT newList (compare);

void freeList (listADT);

int isEmptyList (const listADT);

int belongs(listADT, elemType);

// devuelve 1 si lo pudo insertar, 0 si no (repetido, sin memoria)
int insert(listADT, elemType);

// devuelve 1 si lo borra, 0 si no lo enuentra
int delete(listADT, elemType);

int elem_i(listADT, int);

void map(listADT, elemType (*) (elemType));

int size(const listADT);

elemType elementAtIndex(const listADT, size_t);

// Implementamos un iterador para recorres la lista de forma eficiente

// Aviso que voy a recorrer
void toBegin(listADT list);

// Devuelve el proximo elemento, si se hace despues del toBegin devuelve el primero
elemType next(listADT list);

// Chequea si existe un proximo elemento, devuelve 1 si lo hay, 0 si no
int hasNext(listADT list);

#endif //UNTITLED5_LISTADT_H