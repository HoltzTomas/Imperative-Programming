// Se desea eliminar de un texto todas las vocales, siempre y cuando no sean vocales "sueltas",
// esto es, para eliminarlas deben tener al menos una letra antes o una letra después (y que no sea vocal).
// Escribir una función eliminaVoc que reciba únicamente un string y elimine todas las vocales siguiendo
// las reglas mencionadas anteriormente.
#include <ctype.h> // Para usar tolower
#include <stdio.h> // Para usar tolower
void eliminaVocales(char *str);
int esVocal(char c)
{
    c = tolower(c); // Convertir el carácter a minúscula para simplificar
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void)
{
    char texto[] = "Este es un ejemplo de texto";
    eliminaVocales(texto);
    printf("Texto sin vocales eliminadas: %s\n", texto);

    return 0;
}

void eliminaVocales(char *str)
{
    int writeIndex = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        char actual = str[i];
        char anterior = (i > 0) ? str[i - 1] : '\0';               // Si es el primer carácter, no hay anterior
        char siguiente = (str[i + 1] != '\0') ? str[i + 1] : '\0'; // Si es el último, no hay siguiente

        if (esVocal(actual))
        {
            if ((!esVocal(anterior) && isalpha(anterior)) ||
                (!esVocal(siguiente) && isalpha(siguiente)))
            {
                // Tiene una letra antes o después que no es vocal, por lo tanto la eliminamos
                i++;
            }
            else
            {
                str[writeIndex++] = actual;
                i++;
            }
        }
        else
        {
            str[writeIndex++] = actual;
            i++;
        }
    }

    str[writeIndex]='\0';
    
}
