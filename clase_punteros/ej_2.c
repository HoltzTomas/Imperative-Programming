
#include <stdio.h>

longString(const char *string);

int main(void)
{
    int cant;
    char texto[] = "asi";

    cant = longString(texto);

    printf("La cantidad de caracteres es %d", cant);

    return 0;
}

int longString(const char *string)
{
    int cantidad = 0;

    while (*string++)
        cantidad++;

    return cantidad;
}
