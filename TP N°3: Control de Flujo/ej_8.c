#include <stdio.h>

int main(void){
	int fahr, celsius;
    int lower = 0, upper = 300, step = 20;
    
    printf("Fahr\tCelsius\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}