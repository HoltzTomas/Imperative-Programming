//El siguiente programa funciona correctamente en algunas computadoras, pero no en otras. Indicar cuál puede ser el problema 
//(si bien aún no se vió en detalle, con la instrucción while se puede ejecutar un ciclo mientras la condición sea verdadera, en este
// caso queremos leer todos los caracteres de la entrada estándar hasta que no haya más caracteres por leer)
#include <stdio.h>

int 
main(void) 
{
     char c;
     while ((c = getchar()) != EOF) 
          putchar(c);
     
    return 0;
}

//El valor del EOF suele ser -1
//char no tiene default, podria ser unsigned en algunas maquinas
//en ese caso nunca toma valor -1
//por ende torna en un loop infinito