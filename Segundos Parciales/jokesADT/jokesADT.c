
#include "jokesADT.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define BLOCK 20

typedef struct
{
    char *joke;
    size_t longitud; // No cuento el 0 final
} Joke;

typedef struct node
{
    char *name;
    size_t longitud_name; // No cuento el 0 final
    Joke *v;
    size_t dim;
    size_t reservado;
    struct node *tail;
} CategoryNode;

typedef struct jokesCDT
{
    CategoryNode *first;
    size_t cant_categories;
} jokesCDT;

static char *jokeRec(CategoryNode *list, const char *category);
static CategoryNode *addCategoryRec(CategoryNode *categories, const char *name, int *flag);
static void addJokeRec(CategoryNode *list, const char *category, const char *joke);

static char *copyWithBlocks(char *s, size_t *dim)
{
    char *res = NULL;
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (i % BLOCK == 0)
        {
            res = realloc(res, i + BLOCK);
        }
        res[i] = s[i];
    }
    res = realloc(res, i + 1);
    res[i] = '\0';
    *dim = i; // No cuento el cero final
    return res;
}

static int randInt(int izq, int der)
{
    if (izq > der)
    {
        int aux = der;
        der = izq;
        izq = aux;
    }

    return rand() % (der - izq + 1) + izq;
}

jokesADT newJokes(void)
{
    return calloc(1, sizeof(jokesCDT));
}

static CategoryNode *addCategoryRec(CategoryNode *categories, const char *name, int *flag)
{
    int res;
    if (categories == NULL || (res = strcmp(categories->name, name)) > 0)
    {
        *flag = 1;
        CategoryNode *new = calloc(1, sizeof(CategoryNode));
        new->longitud_name = strlen(name);
        new->name = malloc(new->longitud_name + 1); // Los nombres son cortos
        strcpy(new->name, name);
        new->tail = categories;
        return new;
    }
    if (res < 0)
    {
        categories->tail = addCategoryRec(categories->tail, name, flag);
    }
    return categories;
}

void addCategory(jokesADT jokes, const char *category)
{
    int flag = 0;
    jokes->first = addCategoryRec(jokes->first, category, &flag);
    jokes->cant_categories += flag;
}

size_t categoriesCount(const jokesADT jokes)
{
    return jokes->cant_categories;
}

void addJoke(jokesADT jokes, const char *category, const char *joke)
{
    addJokeRec(jokes->first, category, joke);
}

static void addJokeRec(CategoryNode *list, const char *category, const char *joke)
{

    int res;
    if (list == NULL)
    {
        return;
    }
    if ((res = strcmp(list->name, category)) == 0)
    {
        if (list->dim == list->reservado)
        {
            list->reservado += BLOCK;
            list->v = realloc(list->v, list->reservado * sizeof(Joke));
        }
        list->v[list->dim].joke = copyWithBlocks(joke, &(list->v[list->dim].longitud));
        list->dim++;
    }
    if (res < 0)
    {
        addJokeRec(list->tail, category, joke);
    }
}

char *joke(jokesADT jokes, const char *category)
{
    return jokeRec(jokes->first, category);
}

static char *jokeRec(CategoryNode *list, const char *category)
{

    int res;
    if (list == NULL || (res = strcmp(list->name, category)) > 0)
    {
        return NULL;
    }
    else if (res == 0)
    {
        int index = randInt(0, list->dim - 1);
        char *joke_res = malloc(list->v[index].longitud + 1);
        strcpy(joke_res, list->v[index].joke);
        return joke_res;
    }

    return jokeRec(list->tail, category);
}

char **categories(const jokesADT jokes)
{

    CategoryNode *aux = jokes->first;
    int cantCategories = jokes->cant_categories;
    size_t dim = 0;
    char **res = calloc(cantCategories, sizeof(char *));

    if(cantCategories == 0)
        return NULL;

    while (aux != NULL)
    {
        res[dim] = malloc(sizeof(char) * aux->longitud_name);
        strcpy(res[dim++], aux->name);
        aux = aux->tail;
    }

    return res;
}

void freeJokes(jokesADT jokes)
{
    CategoryNode *aux = jokes->first;
    while (aux != NULL)
    {
        free(aux->name);
        for (int i = 0; i < aux->dim; i++)
        {
            free(aux->v[i].joke);
        }
        free(aux->v);
        CategoryNode *aux_free = aux;
        aux = aux->tail;
        free(aux_free);
    }
    free(jokes);
}
