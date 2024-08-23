//Write a program to count blanks, tabs and newlines

#include <stdio.h>

int main(void) {
    int counter = 0, c;

    while((c=getchar()) != EOF){
        if(c == '\n' || c == ' ' || c == '\t') {
            counter++;
        }
    }

    printf("%i\n", counter);

    return 0;
}