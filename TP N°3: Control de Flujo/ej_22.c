#include <stdio.h>
#include "../getnum.h"

int main(void){
    int c;
    int counter = 0; /* contador de espacios */

    while ( (c = getchar()) != EOF ) {
        if ( c == ' ' || c == '\t' ) {
            if ( counter == 0 ) {
                putchar(c);
                counter++;
            }
        }
        else {
            putchar(c);
            if ( counter == 1 ) {
                counter--;
            }
        }
    }

    printf("\n");
}