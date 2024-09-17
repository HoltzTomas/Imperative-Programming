// Escribir una función secuenciaAsc que reciba un vector de enteros (sin orden) y su dimensión y almacene en dos parámetros de salida:

// comienzo: Dónde comienza la secuencia de números ordenados en forma ascendente (cada elemento debe ser mayor al anterior) de mayor longitud

// longitud: Longitud de esa secuencia

// En caso de haber más de una secuencia con la mayor longitud debe almacenar en
// comienzo donde comienza la primera de ellas.

#include <stdio.h>
#include <assert.h>

void secuenciaAsc(int v[], unsigned dim, int *comienzo, int *longitud);

int main(void)
{

    int comienzo;
    int longitud;
    int v1[] = {1, 1, 3, 4, 4, 7, 10, 9, 11};
    secuenciaAsc(v1, 9, &comienzo, &longitud);

    assert(comienzo == 1);
    assert(longitud == 3);

    int v2[] = {};
    secuenciaAsc(v2, 0, &comienzo, &longitud);

    assert(comienzo == 0);
    assert(longitud == 0);

    int v3[] = {3};
    secuenciaAsc(v3, 1, &comienzo, &longitud);

    assert(comienzo == 0);
    assert(longitud == 1);

    int v4[] = {2, 2, 2};
    secuenciaAsc(v4, 3, &comienzo, &longitud);

    assert(comienzo == 0);
    assert(longitud == 1);

    int v5[] = {3, 2, 1, 0, -1};
    secuenciaAsc(v5, 5, &comienzo, &longitud);

    assert(comienzo == 0);
    assert(longitud == 1);

    int v6[] = {1, 2, 3, 4, 5, 7, 10, 90, 111};
    secuenciaAsc(v6, 9, &comienzo, &longitud);

    assert(comienzo == 0);
    assert(longitud == 9);

    puts("OK!");
}

void secuenciaAsc(int v[], unsigned dim, int *comienzo, int *longitud)
{

    if (dim == 0)
    {
        *comienzo = 0;
        *longitud = 0;
        return;
    }

    int actual_sec = 1;
    int actual_sec_idx = 0;
    int max_sec = 1;
    int max_sec_idx = 0;

    for (int i = 0; i < dim - 1; i++)
    {
        // Si el elemento es mayor o igual al siguiente termina la secuencia
        if (v[i] >= v[i + 1])
        {
            // Si la secuencia que acaba de terminar es mayor a la maxima
            if (actual_sec > max_sec)
            {
                max_sec = actual_sec;
                max_sec_idx = actual_sec_idx;
            }
            // De lo contrario la secuencia maxima sigue siendo la misma

            actual_sec_idx = i + 1;
            actual_sec = 1;
        }
        else
        {
            // En este caso la secuencia continua
            actual_sec++;
        }
    } 
    // Por si la secuencia al terminar era mas larga pero no habia terminado
    if (actual_sec > max_sec)
    {
        max_sec = actual_sec;
        max_sec_idx = actual_sec_idx;
    }

    *comienzo = max_sec_idx;
    *longitud = max_sec;
}