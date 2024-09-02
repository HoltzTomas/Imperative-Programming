
#include <stdio.h>
#include <ctype.h>

int isVocal(int a);

int main(void){
    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();


    int aIsVocal = isVocal(a);

    if (!aIsVocal && isupper(a)){
        printf("El caracter %c es una consonante mayúscula \n", a);
    } else if (!aIsVocal && islower(a)){
        printf("El caracter %c es una consonante minúscula \n", a);
    } else {
     		if (aIsVocal)
    			printf("El caracter %c es una vocal \n", a);
    		else
    			printf("El caracter %c no es una letra \n", a);
    }


    if ( b % 2 == 0 ){
        printf("El valor ASCII de %c es par \n", b);
    } 
    
    if ( isdigit(b) ){
        b -= '0';
        if ( b % 2 == 0 ){
            printf("El caracter %c representa un dígito par \n", b);
        } 
    }
    
    if ( isVocal(c) || isupper(c)  ){
        printf("El caracter %c es una vocal o es mayúscula \n", c);
    }
    
    if ( !isVocal(c) && isalpha(c) ){
        printf("El caracter %c no es una vocal pero es letra \n", c);
    }

    return 0;
}

int isVocal(int a) {
    a = tolower(a);
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}
