// Se desea eliminar de un texto todas las vocales, siempre y cuando no sean vocales "sueltas", esto es,
// para eliminarlas deben tener al menos una letra antes o una letra después (y que no sea vocal).
#include <ctype.h> // Para usar tolower
#include <stdio.h> // Para usar tolower
// Escribir una función eliminaVoc que reciba únicamente un string y elimine todas las vocales siguiendo las reglas mencionadas anteriormente.
int isVowel(char c);
void eliminaVoc(char str[]);

int main(void)
{
    char texto[] = "a,e,i,o,u";
    eliminaVoc(texto);
    printf("Texto sin vocales eliminadas: %s\n", texto);

    return 0;
}

void eliminaVoc(char str[])
{
    unsigned write_idx = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char before = i == 0 ? '\0' : str[i - 1];
        char after = str[i + 1];
        char isBeforeCons = isalpha(before) && !isVowel(before);
        char isAfterCons = isalpha(after) && !isVowel(after);


        //Si no es una vocal o no tiene constantes a los costados
        if(!isVowel(str[i]) || (!isBeforeCons && !isAfterCons)) {
            str[write_idx++] = str[i];
        }
    }

     str[write_idx] = '\0';
}

int isVowel(char c)
{
    c = tolower(c); // Convertir el carácter a minúscula para simplificar
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}