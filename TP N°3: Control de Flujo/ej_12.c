//Escriba enunciados for que impriman las siguientes secuencias de valores:
#include <stdio.h>

int main(void){
    int i;
    //a
    for(i=3; i<=23; i+=5)
        printf("%d\n", i);

    //b
    for(i=20; i>=-10; i-=6)
        printf("%d\n", i);

    //c
    for(i=19; i<=51; i+=8)
        printf("%d\n", i);

    return 0;
}