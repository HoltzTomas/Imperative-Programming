#include <stdio.h>

int main(void){
    int c = 2;

    c = neg(c);
    printf("%d", c);
    return 0;

}

int neg(int n)
{
    return -n;
}