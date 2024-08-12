//Probar las siguientes instrucciones e investigar cuales son equivalentes entre sí. 
//Sacar conclusiones.
#include <stdio.h>

int main(void) {
    //Esta linea imprime el caracter de alerta o realiza un sonido en caso de ser permitido
    printf("\a\n");
    //Esta linea imprime el ASCII 7 (Alerta)
	printf("Caracter: %c\n", 7);
    //Esta imprime el valor decimal de 7 (7)
	printf("Decimal: %d\n", 7);
    //Esta imprime el valor float de 7.0 (7.000000)
	printf("Float: %f\n", 7.0);
    // Esta línea imprime 7.0 usando el especificador %g para una representación compacta.
	printf("G: %g\n", 7.0);
}

