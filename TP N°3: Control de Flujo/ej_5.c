
#include <stdio.h>

#define isUppperCase (a >= 'A' && a<= 'Z')
#define isLowerCase (a >= 'a' && a<= 'z')

int isVocal(int a);

int main(void){
    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();


    int aIsVocal = isVocal(a);

    if (!aIsVocal && isUppperCase){
        printf("El caracter %c es una consonante mayúscula \n", a);
    } else if (!aIsVocal && isLowerCase){
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
    
    if ( b >= '0' && b<= '9' ){
        b -= '0';
        if ( b % 2 == 0 ){
            printf("El caracter %c representa un dígito par \n", b);
        } 
    }
    
    if ( isVocal(c) || (c >= 'A' && c <= 'Z')  ){
        printf("El caracter %c es una vocal o es mayúscula \n", c);
    }
    
    if ( !isVocal(c) && (isUppperCase || isLowerCase) ){
        printf("El caracter %c no es una vocal pero es letra \n", c);
    }

    return 0;
}

int isVocal(int a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||
            a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
}
