#include "list.h"
#include <stdlib.h>
#include <stdio.h>

#define BLOCK 50

int isEmpty(const List l)
{
    return l == NULL;
}

int belongs(const List l, int elem)
{
    if (l == NULL || l->head > elem)
    {
        return 0;
    }
    if (l->head == elem)
    {
        return 1;
    }

    return belongs(l->tail, elem);
}

int belongsIter(const List l, int elem)
{
    List aux = l;
    while (aux != NULL && elem <= aux->head)
    {
        if (aux->head == elem)
        {
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

int indexOf(const List l, int elem)
{
    if (isEmpty(l) || l->head > elem)
    {
        return -1;
    }
    if (l->head == elem)
    {
        return 0;
    }
    int aux = indexOf(l->tail, elem);
    if (aux == -1)
    {
        return -1;
    }
    return 1 + aux;
}

int size(const List l)
{
    if (l == NULL)
    {
        return 0;
    }
    return 1 + size(l->tail);
}

void freeList(List l)
{
    if (l == NULL)
    {
        return;
    }
    freeList(l->tail);
    free(l);
}

List add(List l, int elem)
{
    if (l == NULL || l->head > elem)
    {
        List aux = malloc(sizeof(struct node));
        aux->head = elem;
        aux->tail = l;
        return aux;
    }
    if (l->head == elem)
    {
        return l;
    }
    // El elemento a insertar es mayor que el primero
    l->tail = add(l->tail, elem);
    return l;
}

List delete(List l, int elem)
{
    if (l == NULL || l->head > elem)
    {
        return l;
    }
    if (l->head == elem)
    {
        List aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = delete (l->tail, elem);
    return l;
}

int get(const List l, unsigned idx)
{
    if (l == NULL)
    {
        fprintf(stderr, "get invalido\n");
        exit(1);
    }
    if (idx == 0)
    {
        return l->head;
    }
    return get(l->tail, idx - 1);
}

int getIter(const List l, int idx)
{
    List aux = l;
    while (aux != NULL && idx > 0)
    {
        aux = aux->tail;
        idx--;
    }
    if (aux == NULL)
    {
        fprintf(stderr, "get invalido\n");
        exit(1);
    }
    return aux->head;
}

int *toArray(const List l, int *dim)
{
    int *ans = NULL;
    int i;
    List aux = l;
    for (i = 0; aux != NULL; i++, aux = aux->tail)
    {
        if (i % BLOCK == 0)
        {
            ans = realloc(ans, (i + BLOCK) * sizeof(*ans));
        }
        ans[i] = aux->head;
    }
    ans = realloc(ans, i * sizeof(*ans));
    *dim = i;
    return ans;
}

// Primera version: muy simple, usando size
int *arrayTo2(const List l, int *dim)
{
    *dim = size(l);
    int *ans = malloc(*dim * sizeof(*dim));
    List aux = l;
    for (int i = *dim - 1; aux != NULL; i--, aux = aux->tail)
    {
        ans[i] = aux->head;
    }
    return ans;
}

// Segunda version: usando toArray, luego invirtiendo
int *arrayTo3(const List l, int *dim)
{
    int *ans = toArray(l, dim);
    for (int i = 0; i < *dim / 2; i++)
    {
        int aux = ans[i];
        ans[i] = ans[*dim - i - 1];
        ans[*dim - i - 1] = aux;
    }
    return ans;
}

// Hacemos algo parecido al ejercicio 10 del TP 9 que tenia que invertir un string, el código era
/*
  int invierte(const char *origen, char *destino)
{
    int n;
    if (*origen == 0) {
         return 0;
    }
    n = invierte(origen +1, destino);
    destino[n] = *origen;
    return n +1;
}
 */

static int _arrayTo(List l, int **vec)
{
    int n;
    if (isEmpty(l))
    {
        return 0;
    }
    n = _arrayTo(l->tail, vec);
    if (n % BLOCK == 0)
    {
        *vec = realloc(*vec, (n + BLOCK) * sizeof(*vec));
    }
    (*vec)[n] = l->head;
    return n + 1;
}

// Tercera version: mas compleja usando una funcion auxiliar.
// La complejidad es para evitar recorrer dos veces la lista o el vector (no se justifica)
int *arrayTo(const List l, int *dim)
{
    int *ans = NULL;
    *dim = _arrayTo(l, &ans);
    return ans;
}

int head(const List l)
{
    if (l == NULL)
    {
        fprintf(stderr, "Error al invocar head");
        exit(1);
    }
    return l->head;
}

List tail(const List l)
{
    if (l == NULL)
    {
        fprintf(stderr, "Error al invocar tail");
        exit(1);
    }
    return l->tail;
}

/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus elementos, en el mismo orden
*/
List fromArray(const int v[], unsigned int dim)
{
    List ans = NULL;
    while (dim)
    {
        List aux = malloc(sizeof(TNode));
        aux->head = v[--dim];
        aux->tail = ans;
        ans = aux;
    }
    return ans;
}
