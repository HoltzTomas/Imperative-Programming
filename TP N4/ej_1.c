// Decidir, en caso de ser posible, con qué valor termina cada una de las variables en los
// siguientes programas. En caso de haber errores de compilación, corregirlos.
#include <stdio.h>

#define DIVISION(x, y, z)                           \
    {                                               \
        int i;                                      \
        for (z = 0, i = x - y; i >= 0; z++, i -= y) \
            ;                                       \
    }

int main(void)
{
    int a, b, c, m, n, p, x, y, z;

    a = 20;
    b = 5;
    c = 3;
    DIVISION(a, b, c);

    m = 5;
    n = 4;
    p = 2;
    DIVISION(m++, n--, p);

    x = 15;
    y = 3;
    z = 0;
    DIVISION(x, y, 0);

    return 0;
}
