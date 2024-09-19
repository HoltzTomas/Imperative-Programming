//a) Escribir una función que reciba un string y elimine del mismo todos los caracteres que representan un dígito

//b) Escribir un programa completo (función main) que invoque a la función del punto a y provoque sí o sí un error de ejecución

#include <stdio.h>
#include <ctype.h>

void deleteDigit(char str[]){

    int write_idx = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if(!isdigit(str[i])){
            str[write_idx++] = str[i];
        }
    }

    str[write_idx++] = '\0';
}

int main(void) {

    char str1[] = "Este string funciona9999";
    char *str2 = "Este es solo lecture, se rompe";

    deleteDigit(str1);

    for (int i = 0; str1[i] != '\0'; i++)
    {
        printf("%c", str1[i]);
    }
    
    //Esto rompe
    deleteDigit(str2);

}
