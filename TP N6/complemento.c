// Escribir la función complemento que, dado un string, arme otro string que contenga únicamente
// las letras del alfabeto inglés (en mayúsculas y orden alfabético) que NO figuren en el primer string.

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

void complemento(char str[], char out[]);

int main(void)
{
    char out[27];
    complemento("1 abc2DEGFCAXYZ", out);
    assert(strcmp(out, "HIJKLMNOPQRSTUVW") == 0);
    complemento("GfedCBA HIJKLMNO utsrqp/+= vwxyz ", out);
    assert(strcmp(out, "") == 0);
    puts("OK!");
    return 0;
}

// void complemento(char str[], char out[26])
// {

//     if (str == NULL)
//         return;

//     unsigned char appearences[26] = {0};
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         if (isalpha(str[i]))
//         {
//             unsigned char actual = toupper(str[i]) - 'A';
//             appearences[actual]++;
//         }
//     }

//     int write_idx = 0;

//     for (int j = 0; j < 26; j++)
//     {
//         if (appearences[j] == 0)
//         {
//             out[write_idx++] = j + 'A';
//         }
//     }

//     out[write_idx] = '\0';

//     return;
// }

// Opcion mas eficiente (Calaje de bits)
void complemento(char str[], char out[26])
{

    if (str == NULL)
        return;

    unsigned int letters_present = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)str[i];
        if (isalpha(ch))
        {
            unsigned char actual = toupper(ch) - 'A';
            if (actual < 26) //Esto porque el sistema podria estar en español
                letters_present |= (1U << actual);
        }
    }

    int write_idx = 0;

    // Construir el string de salida con las letras ausentes
    for (int j = 0; j < 26; j++)
    {
        if ((letters_present & (1U << j)) == 0)
        {
            // Si el bit está en 0, la letra no está presente
            out[write_idx++] = j + 'A';
        }
    }

    out[write_idx] = '\0';

    return;
}