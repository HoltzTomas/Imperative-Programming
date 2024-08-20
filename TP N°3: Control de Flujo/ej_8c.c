#include <stdio.h>
#include "../getnum.h"

int main(void){
    int lim = getint("Ingrese límite:"), c;
    int i = 0;

   while ( i < lim-1 ) {
    if ( (c=getchar()) == '\n' ) {
        puts("");
        return 1;
    }
    else if (  c == EOF ) {
        puts("");
        return 1;
    }

    putchar(c);
    i++;
   }

   puts("");
   
   return 0;

}