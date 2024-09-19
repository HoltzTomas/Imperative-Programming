// Escribir la función eliminaRepetidas, que recibe un string y que, por cada secuencia de caracteres repetidos, deja uno solo.

#include <stdio.h>
#include <assert.h>
#include <string.h>

void eliminaRepetidas(char *str);

int main(void)
{
    char str1[] = "gooooooooooooooooool     de    Argentinaaaaaaaaaaaaaaaaaaaaaaaaa gol de Messssssssiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
    eliminaRepetidas(str1);
    assert(strcmp(str1, "gol de Argentina gol de Mesi") == 0);
    eliminaRepetidas(str1);
    assert(strcmp(str1, "gol de Argentina gol de Mesi") == 0);

    char str2[] = "aaaaaaaa";
    eliminaRepetidas(str2);
    assert(strcmp(str2, "a") == 0);

    char str3[] = "abcabcabcabczzzzzza";
    eliminaRepetidas(str3);
    assert(strcmp(str3, "abcabcabcabcza") == 0);

    eliminaRepetidas(NULL);

    char str4[] = "a";
    eliminaRepetidas(str4);
    assert(strcmp(str4, "a") == 0);

    char str5[] = "";
    eliminaRepetidas(str5);
    assert(strcmp(str5, "") == 0);

    puts("OK");
    return 0;
}

void eliminaRepetidas(char *str)
{

    if (str == NULL)
        return;

    if (*str == '\0' || *(str + 1) == '\0')
        return;

    int write_idx = 1;
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (str[i] != str[i - 1])
        {
            str[write_idx++] = str[i];
        }
    }

    str[write_idx] = '\0';
}
