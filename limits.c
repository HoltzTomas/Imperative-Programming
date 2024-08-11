#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    // Usando límites del header <limits.h>
    printf("Usando limits.h:\n\a");
    printf("char: [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: [0, %u]\n", UCHAR_MAX);
    printf("short: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: [0, %u]\n", USHRT_MAX);
    printf("int: [%d, %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int: [0, %u]\n", UINT_MAX);
    printf("long: [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: [0, %lu]\n", ULONG_MAX);
    printf("\n");


    printf("==============================\n");

    printf("\n");
    printf("Valores de punto flotante:\n");
    printf("Diferencia minima: Distancia de 1.0 al proximo numero representable\n");
    printf("\n");

    // Constantes para float
    printf("float:\n");
    printf("Mínimo positivo: %e\n", FLT_MIN);
    printf("Máximo positivo: %e\n", FLT_MAX);
    printf("Precisión: %d dígitos\n", FLT_DIG);
    printf("Diferencia mínima: %e\n", FLT_EPSILON);

    // Constantes para double
    printf("\ndouble:\n");
    printf("Mínimo positivo: %e\n", DBL_MIN);
    printf("Máximo positivo: %e\n", DBL_MAX);
    printf("Precisión: %d dígitos\n", DBL_DIG);
    printf("Diferencia mínima: %e\n", DBL_EPSILON);

    // Constantes para long double
    printf("\nlong double:\n");
    printf("Mínimo positivo: %Le\n", LDBL_MIN);
    printf("Máximo positivo: %Le\n", LDBL_MAX);
    printf("Precisión: %d dígitos\n", LDBL_DIG);
    printf("Diferencia mínima: %Le\n", LDBL_EPSILON);



    return 0;
}
