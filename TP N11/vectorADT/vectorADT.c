

#include "vectorADT.h"
#include "stdlib.h"

struct vectorCDT {
    compare cmp;
    size_t dim;
    size_t usedSpaces;
    elemType * elems;
    char * isEmpty;    // isEmpty[i] == 1 si elems[i] esta libre, 0 si no está libre
};

vectorADT newVector( compare cmp ) {
    vectorADT aux = calloc(1, sizeof(struct vectorCDT));
    aux->cmp = cmp;
    return aux;
}

void freeVector(vectorADT v) {

    if(v != NULL){
        free(v->elems);
        free(v->isEmpty);
    }

    free(v);
    return;

}

int put(vectorADT v, elemType * elems, size_t dim, size_t index) {

    if(elems == NULL)
        return 0;

    if(dim+index > v->dim) {
    
        v->elems = realloc(v->elems, sizeof(elemType) * (dim+index));
        v->isEmpty = realloc(v->isEmpty, sizeof(char) * (dim+index));

        for(size_t i=v->dim; i< dim + index; i++)
            v->isEmpty[i] = 1;
        v->dim = dim + index;
    }

     size_t count=0;
     for(size_t i=index, j=0; i < index+dim; i++, j++){
        if(v->isEmpty[i]){
            v->elems[i]=elems[j];
            v->isEmpty[i]=0;
            count++;
            v->usedSpaces++;
        }
    }
    return count;
}

int getIdx(vectorADT v, elemType elem) {
    for(size_t i=0; i < v->dim; i++){
        if(! v->isEmpty[i] && v->cmp(v->elems[i], elem)==0) {
                return i;
            }
        }
    return -1;
}
void deleteElement(vectorADT v, size_t index){
    if(index>=v->dim)
        return;
    if(! v->isEmpty[index]){
        v->isEmpty[index] = 1;
        v->usedSpaces--;
    }
    return;
}

int elementCount(vectorADT v){
    return v->usedSpaces;
}
