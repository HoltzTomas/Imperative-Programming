#include <stdio.h>
#include <assert.h>

int orden(const int v[]);

int main(void)
{

    int v[] = {-1};
    assert(orden(v) == 0);

    int v2[] = {1, -1};
    assert(orden(v2) == 0);

    int v3[] = {1, 2, -1};
    assert(orden(v3) == 1);

    int v4[] = {1, 2, 3, 10, 100, 999, 2345, -1};
    assert(orden(v4) == 1);

    int v5[] = {100, 29, 23, 19, 18, 5, 4, 0, -1};
    assert(orden(v5) == -1);

    int v6[] = {1, 2, 3, 10, 100, 999, 998, -1};
    assert(orden(v6) == 0);

    int v7[] = {1, 2, 3, 10, 1000, 999, 1998, -1};
    assert(orden(v7) == 0);

    int v8[] = {1, 1, 1, 10, 1000, 1999, 2998, -1};
    assert(orden(v8) == 0);

    int v9[] = {1, 1, -1};
    assert(orden(v9) == 0);

    printf("OK!\n");
    return 0;
}

int orden(const int v[])
{

    if (v[1] == -1) { // Caso base: si solo hay un elemento o termina en -1
        return 0; // Un solo elemento, no está ordenado
    }

    // Si el tercer elemento marca el fin (-1), terminamos
    if (v[2] == -1) {
        return (v[1] > v[0]) ? 1 : (v[1] < v[0]) ? -1 : 0;
    }

    //Si es ascendente
    if (*(v + 1) > *v){
        int resultado = orden(v + 1);
        return resultado == 1 ? 1 : 0;
    }
    //Si es descendente
    if (*(v + 1) < *v ){
        int resultado = orden(v + 1);
        return resultado == -1 ? -1 : 0;
    }

    return 0;
}