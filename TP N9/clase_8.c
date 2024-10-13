
#include <stdio.h>
void sumatoria(int vec[], unsigned dim, int *suma);

int main(void) {
    int vec[] = {9, 3, 2, 3, 10};
    int suma = 0;

    sumatoria(vec, 5, &suma);
    
    printf("Sumatoria: %d\n", suma);

    return 0;
}

void sumatoria(int vec[], unsigned dim, int *suma) {

    if(dim == 0)
      return;

    sumatoria(vec, dim -1, suma);
    *suma += vec[dim - 1];
}