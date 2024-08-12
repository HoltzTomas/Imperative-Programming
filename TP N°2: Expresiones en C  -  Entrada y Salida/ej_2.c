// a)  Escribir un programa que imprima el mensaje "Este es un programa en C" en la salida estándar, 
// colocando cada palabra en una línea. (Usar un único printf)
// b)  Redireccionar la salida del programa hacia el archivo output.txt. 
// Una vez terminada la ejecución del programa, editar dicho archivo y verificar que contenga la salida correcta.
#include <stdio.h>

//Nota, es probable que que el ejercicio pida redireccionar la salida no en el codigo sino en la ejecucion
//del comando

//Ej: ./ej_2 >> output.txt

//De todas formas, esta es la forma correcta de hacerlo a nivel codigo

int main(void){
    freopen("output.txt", "w", stdout);
    printf("Este\nes\nun\nprograma\nen\nC");
    fclose(stdout);
}
