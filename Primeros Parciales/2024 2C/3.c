#include <stdio.h>
#include <assert.h>

void diferencia(int v1[], int v2[]);

// Función para comparar dos vectores
int compararVectores(int v1[], int v2[])
{
    int i = 0;
    while (v1[i] != -1 && v2[i] != -1)
    {
        if (v1[i] != v2[i])
        {
            return 0; // Los vectores no son iguales
        }
        i++;
    }
    return (v1[i] == v2[i]); // Ambos deben haber terminado en -1
}

// Función para imprimir el contenido de un vector
void printVector(int v[])
{
    int i = 0;
    while (v[i] != -1)
    {
        printf("%d ", v[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    // Prueba 1: Vectores con elementos comunes
    int v1_1[] = {1, 2, 3, 4, -1};
    int v2_1[] = {2, 4, 5, -1};
    int expected_v1_1[] = {1, 3, -1}; // Después de eliminar comunes, quedan 1 y 3
    int expected_v2_1[] = {5, -1};    // Después de eliminar comunes, queda 5

    diferencia(v1_1, v2_1);
    assert(compararVectores(v1_1, expected_v1_1));
    assert(compararVectores(v2_1, expected_v2_1));
    printf("Test 1 passed.\n");

    // Prueba 2: Un vector es subconjunto del otro
    int v1_2[] = {1, 2, 3, -1};
    int v2_2[] = {1, 2, 3, 4, 5, -1};
    int expected_v1_2[] = {-1};       // Todos los elementos están en v2, se elimina todo
    int expected_v2_2[] = {4, 5, -1}; // 1, 2 y 3 se eliminan de v2

    diferencia(v1_2, v2_2);
    assert(compararVectores(v1_2, expected_v1_2));
    assert(compararVectores(v2_2, expected_v2_2));
    printf("Test 2 passed.\n");

    // Prueba 3: Vectores sin elementos comunes
    int v1_3[] = {1, 3, 5, -1};
    int v2_3[] = {2, 4, 6, -1};
    int expected_v1_3[] = {1, 3, 5, -1}; // No cambia, no hay comunes
    int expected_v2_3[] = {2, 4, 6, -1}; // No cambia, no hay comunes

    diferencia(v1_3, v2_3);
    assert(compararVectores(v1_3, expected_v1_3));
    assert(compararVectores(v2_3, expected_v2_3));
    printf("Test 3 passed.\n");

    // Prueba 4: Vectores con un único elemento común
    int v1_4[] = {1, -1};
    int v2_4[] = {1, -1};
    int expected_v1_4[] = {-1}; // Se elimina 1
    int expected_v2_4[] = {-1}; // Se elimina 1

    diferencia(v1_4, v2_4);
    assert(compararVectores(v1_4, expected_v1_4));
    assert(compararVectores(v2_4, expected_v2_4));
    printf("Test 4 passed.\n");

    // Prueba 5: Vectores vacíos
    int v1_5[] = {-1};
    int v2_5[] = {-1};
    int expected_v1_5[] = {-1}; // Sigue vacío
    int expected_v2_5[] = {-1}; // Sigue vacío

    diferencia(v1_5, v2_5);
    assert(compararVectores(v1_5, expected_v1_5));
    assert(compararVectores(v2_5, expected_v2_5));
    printf("Test 5 passed.\n");
    return 0;
}

void diferencia(int v1[], int v2[])
{
    int i = 0, j = 0;
    int write_1_idx = 0, write_2_idx = 0;

    while (v1[i] != -1 || v2[j] != -1)
    {
        if (v1[i] == v2[j])
        {
            // Si ambos son iguales, los salteo
            i++;
            j++;
        }
        else if (v2[j] == -1 || (v1[i] < v2[j]))
        {
            // Este numero esta unicamente en v1
            v1[write_1_idx++] = v1[i++];
        }
        else if (v1[i] == -1 || (v2[j] < v1[i]))
        {
            // Este numero esta unicamente en v2
            v2[write_2_idx++] = v2[j++];
        }
    }

    v1[write_1_idx] = -1;
    v2[write_2_idx] = -1;

    return;
}