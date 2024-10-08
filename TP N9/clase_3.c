
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esVocal(char c);
int cantidadVocales(char * str);

int main(void){

    char * str = "Hola Mundo!";

    int amount = cantidadVocales(str);

    printf("La cantidad de vocales es %u", amount);
    
}

int cantidadVocales(char * str) {

    if(*str == '\0')
        return 0;
    
    //Si es vocal, sumo uno a amount
    return esVocal(*str) + cantidadVocales(str + 1);
}

int esVocal(char c) {

    char letter = tolower(c);

    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';    

}