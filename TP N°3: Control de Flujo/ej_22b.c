#include <stdio.h>
#include "../getnum.h"

int main(void){
     int c;

    while ( (c = getchar()) != '\n' && c != EOF ) {
        if ( c == '\b' ) {
            printf("\\b");
        }
        else if ( c == '\t' ) {
            printf("\\t");
        }
        else if ( c == '\\' ) {
            printf("\\\\");
        }
        else {
            putchar(c);
        }
    }
}