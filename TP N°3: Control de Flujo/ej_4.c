//Problema del else colgante.

//Determine la salida estándar  para cada uno de los siguientes casos, cuando x = 9 e y = 11.
//Advierta que el compilador ignora las indentaciones.
//El compilador siempre asocia un else con el if anterior, a menos que se le indique lo contrario con llaves {}.
//A primera vista el programador tal vez no esté seguro de cuál if coincide con cuál else, ésto se conoce como el problema del "else colgante".  
//Se eliminaron las sangrías para hacer el problema un poco más 'interesante'. 

//Determinar la salida primero haciendo el seguimiento y luego comprobándola con la PC.
//a)

#include <stdio.h>

int main(void){
    int x = 9, y=11;

    //a)
    printf("a)\n");
    if (x < 10) //Primero entra en este if dado q x<10
    if (y > 10) //En este tmb entra, por ende la sigueinte linea corre
    printf("#######\n"); //Esto se muestra
    else //Lo que este dentro del else no se muestra
    printf("%%%%%\n"); //Osea esto no se muestra, es es la unica proposicion del else
    printf("********\n"); //Esto si

    //b)
    printf("\nb)\n");
    if (x < 10) { //Entra en esto dado q x>10
	if (y > 10) //En este tmb entra
	printf("########\n"); //Esto se muestra
	}
	else {
	printf("%%%%%\n"); //No
	printf("********\n"); //no
	}

    return 0;
}
