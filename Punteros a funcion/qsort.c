#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmpInts(int * n1, int * n2) {
    return *n1 - *n2;
}

int cmpStrings(const char ** s1, const char ** s2) {
    return strcmp(*s1, *s2);
}

int main(void) {
    int v[] = {1, 3, 2, 5, 7, 4}, i, n;
    n = sizeof(v) / sizeof(v[0]);
    qsort(v, n, sizeof(v[0]),
          ((int (*)(const void *, const void *)) cmpInts));
    for (i = 0; i < n; i++)
        printf("v[%d]=%d\n", i, v[i]);

    char * v2[] = {"hola", "mundo", "abc", "foo", "bar"};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    qsort(v2, n2, sizeof(v2[0]),
          (int (*)(const void *, const void *)) cmpStrings);
    for (i = 0; i < n2; i++)
        printf("v2[%d]=%s\n", i, v2[i]);

    return 0;
}
