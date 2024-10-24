#include <stdlib.h>
#include <stdio.h>

#define BLOCK 2

int * subSet(int * set, size_t dim, int (*criteria)(int), size_t * newDim);

int even(int n) {
    return (n % 2 == 0);
}

int odd(int n) {
    return (n % 2 == 1);
}

int *
subSet(int * set, size_t dim, int(*criteria)(int), size_t * newDim) {
    int * res = NULL;
    int k = 0;
    for(int i = 0; i < dim; i++) {
        if(criteria(set[i])) {
            if(k % BLOCK == 0) {
                res = realloc(res, (k + BLOCK) * sizeof(*res));
            }
            res[k++] = set[i];
        }
    }
    res = realloc(res, k * sizeof(*res));
    *newDim = k;
    return res;
}

int main(void) {
    int v[] = {1, 2, 3, 4, 5, 6};

    int * evens, i;
    size_t n;
    evens = subSet(v, sizeof(v) / sizeof(v[0]), even, &n);
    for (i = 0; i < n; i++)
        printf("pares[%d]=%d\n", i, evens[i]);
    free(evens);

    int * odds;
    size_t k;
    odds = subSet(v, sizeof(v) / sizeof(v[0]), odd, &k);
    for (i = 0; i < n; i++)
        printf("impares[%d]=%d\n", i, odds[i]);
    free(odds);

    return 0;
}
