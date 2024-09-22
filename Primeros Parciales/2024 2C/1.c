#include <stdio.h>
#include <assert.h>

void diffTime(unsigned times[], unsigned dim, unsigned *hours, unsigned *minutes, unsigned *seconds);

int main(void)
{

    unsigned hours, minutes, seconds;

    // Prueba 1: Diferencia entre tiempos normales
    unsigned times1[] = {3600, 7200, 1800}; // 1 hora, 2 horas, 30 minutos
    diffTime(times1, 3, &hours, &minutes, &seconds);
    assert(hours == 1);
    assert(minutes == 30);
    assert(seconds == 0);

    // Prueba 2: Diferencia entre un solo tiempo (dim < 2)
    unsigned times2[] = {3600}; // 1 hora
    diffTime(times2, 1, &hours, &minutes, &seconds);
    assert(hours == 0);
    assert(minutes == 0);
    assert(seconds == 0);

    // Prueba 3: Diferencia entre tiempos iguales
    unsigned times3[] = {5400, 5400, 5400}; // 1 hora y 30 minutos
    diffTime(times3, 3, &hours, &minutes, &seconds);
    assert(hours == 0);
    assert(minutes == 0);
    assert(seconds == 0);

    // Prueba 4: Diferencia con tiempo en desorden
    unsigned times4[] = {4000, 1000, 2000};
    diffTime(times4, 3, &hours, &minutes, &seconds);
    assert(hours == 0);
    assert(minutes == 50);
    assert(seconds == 0);

    // Prueba 5: Diferencia con valores límite
    unsigned times5[] = {0, 86400}; // 0 segundos y 1 día completo (24 horas)
    diffTime(times5, 2, &hours, &minutes, &seconds);
    assert(hours == 24);
    assert(minutes == 0);
    assert(seconds == 0);

    printf("All tests passed successfully.\n");

    return 0;
}

void diffTime(unsigned times[], unsigned dim, unsigned *hours, unsigned *minutes, unsigned *seconds)
{

    // Si la dimension es 1 o 0, no hay diferencia
    if (dim < 2)
    {
        *hours = 0;
        *minutes = 0;
        *seconds = 0;
        return;
    }

    int min_in_seconds = times[0];
    int max_in_seconds = times[0];
    int diff_in_seconds;

    for (int i = 1; i < dim; i++)
    {
        if (times[i] > max_in_seconds)
        {
            max_in_seconds = times[i];
        }
        else if (times[i] < min_in_seconds)
        {
            min_in_seconds = times[i];
        }
    }

    diff_in_seconds = max_in_seconds - min_in_seconds;

    *hours = (diff_in_seconds / 3600);
    diff_in_seconds = diff_in_seconds % 3600;
    *minutes = (diff_in_seconds / 60);
    diff_in_seconds = diff_in_seconds % 60;
    *seconds = diff_in_seconds;

    return;
}
