
#include <stdio.h>
#include <stdlib.h>
#include "rankingADT.h"

typedef struct rankingCDT{
	elemType * elems;
	size_t size;
	compare cmp;
}rankingCDT;

static void swap( rankingADT ranking, size_t n, size_t m ){
	elemType aux = ranking->elems[n];
	ranking->elems[n] = ranking->elems[m];
	ranking->elems[m] = aux;
}

static int where( rankingADT ranking, elemType elem, compare cmp ){
	for( int i = 0; i < size(ranking); i++ )
		if( cmp(ranking->elems[i], elem) == 0 )
			return i;
	return -1;
}

rankingADT newRanking(elemType elems[], size_t dim, compare cmp) {

    rankingADT new = malloc( sizeof(rankingCDT) );
	new->size = dim;
    if ( dim > 0 ) {
	    new->elems = malloc( dim * sizeof(elemType) );
	    for( int i = 0; i < dim; i++ )
		    new->elems[i] = elems[i];
	} else {
	    new->elems = NULL;
	}
	new->cmp = cmp;
	return new;
}

void addRanking(rankingADT ranking, elemType elem){
	int n = where( ranking, elem, ranking->cmp );
	if( n == 0 )
		return;
	else if( n > 0 ){
		swap( ranking, n, n-1 );
		return;
	}
	else{
		ranking->size++;
		ranking->elems = realloc( ranking->elems, ranking->size * sizeof(elemType) );
		ranking->elems[size(ranking) - 1] = elem;
		return;
	}
}

int getByRanking(rankingADT ranking, size_t n, elemType * elem) {
    if( n <= 0 || n > size(ranking) )
		return 0;
	* elem = ranking->elems[n-1];
    if( n > 1 )
		swap( ranking, n-1, n-2 );
	return 1;
}

elemType * getTopRanking(const rankingADT ranking, size_t * top) {
    size_t qty = size(ranking);
	if( qty == 0 ){
		*top = 0;
		return NULL;
	}
    // Si la cantidad pedida supera a la cantidad de elementos, usamos la cantidad total
	// como tope
	if( qty < *top )
		*top = qty;  

    elemType * ans = malloc( (*top) * sizeof(elemType) );
	for( int i = 0; i < *top; i++ )
		ans[i] = ranking->elems[i];
	return ans;
}

int contains(rankingADT ranking, elemType elem) {
    int n = where(ranking, elem, ranking->cmp);
	if( n < 0 )
		return 0;
	if( n > 0 )
		swap( ranking, n, n-1 );
	return 1;
}

int position(const rankingADT ranking, elemType elem) {
	int n = where(ranking, elem, ranking->cmp);
	return ( n < 0 ) ? 0 : n+1;
}

void downByRanking(rankingADT ranking, size_t n){
    if(n < size(ranking))
	    swap( ranking, n-1, n );
}

size_t size(const rankingADT ranking){
	return ranking->size;
}

void freeRanking(rankingADT r){
	free(r->elems);
	free(r);
	return;
}
