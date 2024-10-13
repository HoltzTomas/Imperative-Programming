#include <stdio.h>

int cociente(int n1, int n2, int *resto);
void factorial(unsigned n, int *res);

int main(void)
{

    int fact;
    factorial(8, &fact);

    int div, resto;
    div = cociente(13, 4, &resto);

    printf("DIV: %d\n", div);
    printf("REST: %d\n", resto);
}

int cociente(int n1, int n2, int *resto)
{

    if (n1 < n2)
    {
        *resto = n1;
        return 0;
    }

    return 1 + cociente(n1 - n2, n2, resto);
}

void factorial(unsigned n, int *res)
{

    if (n == 0)
    {
        *res = 1;
        return;
    }

    factorial(n - 1, res);
    *res *= n;
}