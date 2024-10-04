#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *aMayusculas(char *s)
{

    char *t;

    for (t = s; *t = toupper(*t); t++)
        ;

    return s;
}

void resize(char **p, unsigned bytes)
{

    *p = realloc(*p, bytes); // Asignar el nuevo puntero realocado a la variable en main

    if (*p == NULL) // Verificar si la realocación falló
    {
        printf("Error de memoria!\n");
    }
}

int main(void)
{

    char *p = NULL;

    resize(&p, 12);
    strcpy(p, "hello world");
    aMayusculas(p);
    printf("%s\n", p);

    char *p2[2][3] = { {"abc", "defg", "hi"},
                      {"jklmn", "pqrstuvw", "xyz"} };

    //Cuantos bytes de memoria ocupa la declaracion: 6 * 4 (u 8) + 31

    printf("%c\n", **p2[1]); //j
    printf("%c\n", **(p2[1]+2)); //f
    printf("%c", *(*(p2+1)+1)[1]); //
    // printf("%c", (*(*(p2+1)+1))[7]);
    // printf("%c", *(p2[1][2]+2));

    return 0;
}