#include <stdio.h>
#include <assert.h>

/**
 *
 * @param vIn vector de enteros con la cadena de pixeles original
 *
 * @param dim entero sin signo con la cantidad de elementos de vIn
 *
 * @param salto entero sin signo que indica el salto
 *
 * @param vOut vector de enteros donde almacenar los pixeles reordenados
 *
 * @return void
 */
void hide(int vIn[], unsigned dim, unsigned jump, int vOut[dim]);

int main(void)
{

    int v1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v1_out[9];
    int v1_expected[] = {1, 3, 5, 7, 9, 2, 4, 6, 8};

    hide(v1, 9, 2, v1_out);

    for (int i = 0; i < 9; i++)
    {
        assert(v1_out[i] == v1_expected[i]);
    }

    int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2_out[9];
    int v2_expected[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};

    hide(v2, 9, 3, v2_out);

    for (int i = 0; i < 9; i++)
    {
        assert(v2_out[i] == v2_expected[i]);
    }

    int v3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int v3_out[8];
    int v3_expected[] = {1, 4, 7, 2, 5, 8, 3, 6};

    hide(v3, 9, 3, v3_out);

    for (int i = 0; i < 9; i++)
    {
        assert(v3_out[i] == v3_expected[i]);
    }

    puts("OK!");
}

void hide(int vIn[], unsigned dim, unsigned jump, int vOut[dim])
{

    // La cantidad de recorridos seran igual al numero de jump
    // Ej: jump = 2 se veran la mitad primero y la otra mitad desp
    int write_idx = 0;
    for (int i = 0; i < jump; i++)
    {
        for (int j = i; j < dim; j += jump)
        {
            vOut[write_idx++] = vIn[j];
        }
    }
}