#include <stdio.h>

// Preguntar esto en el taller
//test.c:6:24: error: character too large for enclosing character literal type
//     a = (unsigned int) 'ñ';
//                        ^
// test.c:7:23: error: character too large for enclosing character literal type
//     b = (signed char) 'ñ';
//                       ^
// test.c:8:25: error: character too large for enclosing character literal type
//     c = (unsigned char) 'ñ';
//                         ^
// test.c:10:38: error: character too large for enclosing character literal type
//     printf("%d %d %d %d\n", a, b, c, 'ñ');
//                                      ^
// test.c:11:38: error: character too large for enclosing character literal type
//     printf("%c %c %c %c\n", a, b, c, 'ñ');

// main(void) {
//     int a,b,c;

//     a = (unsigned int) 'ñ';
//     b = (signed char) 'ñ';
//     c = (unsigned char) 'ñ';
    
//     printf("%d %d %d %d\n", a, b, c, 'ñ');
//     printf("%c %c %c %c\n", a, b, c, 'ñ');

//     return 0;
// }


int main(void) {
    int x,y;
    x=(char)300;
    y=x++;

    printf("%d", x);

    return 0;
}
