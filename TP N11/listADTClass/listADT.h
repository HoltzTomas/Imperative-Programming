
#ifndef _listADTH_
#define _listADTH_

typedef struct {
    int key;
    char* remarks;
} elemType;

typedef struct listCDT *listADT;

typedef int (*compare) (elemType e1, elemType e2);

listADT newList(compare comp);

void freeList(listADT list);

int add(listADT list, elemType elem);

int delete(listADT list, elemType elem);

int isEmpty(const listADT);

int sizeList(const listADT);

int belongs(const listADT, elemType);

void map(listADT, elemType (*mod)(elemType));

#endif