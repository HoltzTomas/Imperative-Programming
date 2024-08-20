#include <stdio.h>

int main(void){
	int fahr, celsius;
    int lower = 0, upper = 150, step = 15;
    
    printf("Celsius\tFahr\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * 9 / 5 + 32;
        printf("%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}