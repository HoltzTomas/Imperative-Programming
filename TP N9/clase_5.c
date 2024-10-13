
#include <stdio.h>

void imprimirRegla(unsigned altura)
{

    if (altura > 0)
    {
        imprimirRegla(altura / 2);

        printf("%u", altura);

        imprimirRegla(altura / 2);
    }
}

int main(void)
{
    unsigned altura = 5;
    printf("Secuencia de la regla con altura %u:\n", altura);
    imprimirRegla(altura);
    printf("\n");

    return 0;
}