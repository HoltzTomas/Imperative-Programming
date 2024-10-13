#include <stdio.h>
#include <assert.h>

int busquedaBinaria(const int datos[], unsigned dim, int num);

int main(void)
{

    int v[] = {-10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45};

    assert(busquedaBinaria(v, 0, -10) == 0);
    assert(busquedaBinaria(v, 1, -10) == 1);
    assert(busquedaBinaria(v, 2, -10) == 1);
    assert(busquedaBinaria(v, 2, -5) == 1);
    assert(busquedaBinaria(v, 2, 0) == 0);

    assert(busquedaBinaria(v + 1, 2, -10) == 0);
    assert(busquedaBinaria(v + 1, 2, -5) == 1);
    assert(busquedaBinaria(v + 1, 2, 0) == 1);

    for (int i = 0; i < 12; i++)
        assert(busquedaBinaria(v, 12, v[i]) == 1);

    for (int i = 0; i < 11; i++)
        assert(busquedaBinaria(v, 11, v[i]) == 1);

    printf("OK!\n");
    return 0;
}

int busquedaBinaria(const int datos[], unsigned dim, int num)
{
    // Caso base: Si la sublista no tiene elementos, el número no está en el array
    if (dim == 0)
    {
        return 0;
    }

    // Encontrar el índice medio
    int medio = (dim - 1) / 2;

    // Verificar si el número en la posición medio es el buscado
    if (datos[medio] == num)
    {
        return 1;
    }

    // Si el número buscado es menor, buscamos en la mitad izquierda
    if (num < datos[medio])
    {
        return busquedaBinaria(datos, medio, num);
    }

    // Si el número buscado es mayor, buscamos en la mitad derecha
    return busquedaBinaria(datos + medio + 1, dim - medio - 1, num);
}