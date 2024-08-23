#include <stdio.h>

#define LETTER_OR_SPACE(a) ((a=getchar()) >= 'A' && (a) <= 'Z') || ((a) >= 'a' && (a) <= 'z') || (a == ' ')
#define DELTA ('a' - 'A')
#define TRUE 1
#define FALSE !TRUE

int main(void) {
    int counterUpper = 0, counterLower = 0;
    int isCurrentUpper, isLowerUpper;
    unsigned char lowerCharacter = 'z';
    unsigned char c;

    // Leer caracteres mientras sean letras o espacios
    while (LETTER_OR_SPACE((c))) {
        
        // Contar letras mayúsculas y minúsculas
        if (c >= 'A' && c <= 'Z') {
            counterUpper++;
            c += DELTA; //Paso c a minuscula
            isCurrentUpper = TRUE;
        } else if (c >= 'a' && c <= 'z') {
            counterLower++;
            isCurrentUpper = FALSE;
        }

        if(c < lowerCharacter && c != ' '){
            lowerCharacter = c;
            isLowerUpper = isCurrentUpper;
        }
    }

    printf("La menor alfabeticamente es: %c\n", isLowerUpper ? lowerCharacter - DELTA : lowerCharacter);
    printf("Total de letras mayúsculas: %d\n", counterUpper);
    printf("Total de letras minúsculas: %d\n", counterLower);

    return 0;
}
