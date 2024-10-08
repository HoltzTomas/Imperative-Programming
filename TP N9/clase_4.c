#include <stdio.h>
#include <assert.h>
// #include <string.h>

int esCapicua(char *str, unsigned len);

int main(void)
{

    char *str = "auto";
    char *str2 = "velev";

    assert(!esCapicua(str, 4));
    assert(esCapicua(str2, 5));

    puts("OK!");
}

int esCapicua(char *str, unsigned len)
{

    if (len == 0 || len == 1)
        return 1;

    if (str[0] == str[len-1])
        return esCapicua(str + 1, len - 2);

    return 0;
}