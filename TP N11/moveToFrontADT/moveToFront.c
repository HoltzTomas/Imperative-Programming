#include "moveToFront.h"
#include <stdlib.h>

typedef struct TNode{
    elemType elem;
    struct TNode * tail;
}TNode;

typedef TNode * TList;

typedef struct moveToFrontCDT{
    TList first;    // puntero al primer elemento de la lista
    size_t cante;   // almacena la cantidad de elementos
    TList iter;     // para iterar, apunta al nodo que contiene el valor a retornar por la función next
    compare cmp;  // Guardamos la función de comparación
}moveToFrontCDT;


/* Agrega un elemento a la lista. Utiliza un parámetro de entrada/salida en el que se devuelve
** 0 si no se pudo agregar el elemento porque ya estaba o 1 si fue agregado
*/
static TList addRec(TList list, elemType elem, int * flag, compare cmp);

/* Busca un elemento en una lista. Si no lo encuentra devuelve en el parámetro de entrada/salida found NULL.
** Si lo encuentra, elimina de la lista el nodo que lo contiene (lo "saltea") y devuelve un puntero a ese 
** nodo en foundco
*/
static TList searchAndDisconnect(TList list ,elemType elem, TList * found, compare cmp);

/* Utilizamos calloc para cear un nuevo conjunto de elementos genérico ya que
** al inicio está vacío
*/
moveToFrontADT newMoveToFront(compare cmp){
    moveToFrontADT ans = calloc(1,sizeof(moveToFrontCDT));
    ans->cmp = cmp;
    return ans;
}

unsigned int size(moveToFrontADT moveToFront) {
	return moveToFront->cante;
}

static TList addRec(TList list, elemType elem, int * flag, compare cmp){
    // Si list es NULL, estaba vacía o no encontramos el elemento,
    // entonces creamos un nuevo nodo para agregarlo y modificamos el flag.
    if(list == NULL){
        TList new = malloc(sizeof(TNode));
        new->elem = elem;
        new->tail = NULL;
        *flag = 1;
        return new;
    }
    // Si la comparación es 0, significa que el elemento ya estaba. 
    // No agregamos nada y dejamos el flag en 0.
    if(cmp(list->elem,elem)==0)
        return list;
    
    // Si no ocurre ninguno de los dos casos anteriores, seguimos avanzando en la lista.
    list->tail = addRec(list->tail,elem,flag,cmp);
    return list;
}

unsigned int add(moveToFrontADT moveToFront, elemType elem){
    int flag = 0;               //Si agregamos un elemento cambiamos el flag a 1, sino lo dejamos en 0.
    moveToFront->first = addRec(moveToFront->first, elem, &flag, moveToFront->cmp);
    moveToFront->cante+=flag;
    return flag;
}

void toBegin(moveToFrontADT moveToFront){
    moveToFront->iter = moveToFront->first;
}

int hasNext(moveToFrontADT moveToFront){
    return moveToFront->iter != NULL;
}

elemType next(moveToFrontADT moveToFront){
    if(!hasNext(moveToFront))
        exit(1);
    elemType elem = moveToFront->iter->elem;
    moveToFront->iter = moveToFront->iter->tail;
    return elem;
}

static TList searchAndDisconnect(TList list ,elemType elem, TList * found, compare cmp){
    // Si la lista es NULL, significa que el elemento no estaba
    // Dejamos NULL en el parámetro de entrada/salida found
    if(list == NULL){
        *found = NULL;
        return NULL;
    }

    // Si encontramos el elemento, lo desconectamos de la lista, haciendo que la cola del
    // elemento anterior apunte al siguiente. 
    // Dejamos en found el puntero al nodo que contiene al elemento que buscábamos.
    if(cmp(list->elem,elem) == 0){
        *found = list;
        return list->tail;
    }

    list->tail = searchAndDisconnect(list->tail,elem,found, cmp);
    return list;
}

elemType * get(moveToFrontADT moveToFront, elemType elem){
    TList found;
    //Buscamos el elemento en la lista.
    moveToFront->first = searchAndDisconnect(moveToFront->first,elem, &found, moveToFront->cmp);

    // Si no estaba, devolvemos NULL
    if(found == NULL)
        return NULL;
    
    // Si lo encontramos, como ya lo "desenganchamos" de la lista, lo insertamos al principio: hacemos que 
    // su cola apunte al elemento que antes era el primero y lo fijamos como primero
    found->tail = moveToFront->first;
    moveToFront->first = found;

    // Hacemos una copia del elemento encontrado para devolverlo
    elemType * e = malloc(sizeof(elemType));
    *e = found->elem;
    return e;
}
static void freeRec(TList list){
    if(list != NULL){
        freeRec(list->tail);
        free(list);
    }
}

void freeMoveToFront(moveToFrontADT moveToFront){
    freeRec(moveToFront->first);
    free(moveToFront);
}
