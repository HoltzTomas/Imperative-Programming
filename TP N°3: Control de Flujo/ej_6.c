// Identificar y corregir los errores en los siguientes fragmentos de programas.
// Resolverlos primero en papel, y luego verificarlos con un debugger.
#include <stdio.h>

enum dias
{
    LUN,
    MAR,
    MIE,
    JUE,
    VIE,
    SAB,
    DOM
};

int main(void)
{
    int resultado = 0;

    // a)
    int a;
    // while ( a <= 4)
    //     resultado += a;
    // 	a++;

    // Al ser un conjunto de proposiciones, deberian ir con llaves. a++ quedo fuera del bucle
    // Ademas, es mas simple ver esto con un for

    for (a = 1; a <= 4; a++)
    {
        resultado += a;
        printf("Resultado %d\n", resultado);
    }

    // b
    //  if ( sueldo >= 1000),//Esta coma no va
    //  printf ( "El sueldo es mayor o igual a 1.000\n"), //Aca va un punto y coma
    //  else
    //  printf ("El sueldo es menor a 1.000\n");

    // Forma correcta
    int sueldo = 2000;
    if (sueldo >= 1000)
        printf("El sueldo es mayor o igual a 1.000\n");
    else
        printf("El sueldo es menor a 1.000\n");

    // c
    // Dado que var2 no esta inicializado, puede valer cualquier cosa (valor basura)
    // Ejemplo de lo que dio var2 en cada iteracion al probar el programa
    //  Valor var2: 1762525216
    //  Valor var2: 1762525218
    //  Valor var2: 1762525221
    //  Valor var2: 1762525225
    //  Valor var2: 1762525230
    //  Valor var2: 1762525236
    //  Valor var2: 1762525243
    //  Valor var2: 1762525251
    // Solucion: inicializar var2=0;, el resto esta todo bien.
    int var1 = 1, var2;
    while (var1 <= 8)
    {
        var2 += var1;
        ++var1;
        printf("Valor var2: %d\n", var2);
    }

    // d
    // El signo de exclamacion debe estar pegado al de igual
    // No existe la variable c
    // Otro problema, no queremos que imprima el mensaje al recibir un enter
    int c;
    while ('Y' != (c = getchar()))
    {
        if (c != '\n')
            printf("Pulse Y para abandonar este ciclo \n");
    }

    // e
    // El ciclo no esta mal escrito, pero deberia utilizarse int
    // en lugar de char, dado que si no perdemos valores
    //(EOF suele ser un numero negativo, ademas no sabemos si char es signed o no)
    // char character;
    // while ((character = getchar()) != EOF)
    //     putchar(c);

    // f
    //Se me ocurren mejores formas de hacerlo, como armar un array con los seis nombres y utilizar el enum como indice
    //Pero al ser una guia de control de flujo, calculo que la idea es usar un switch
    enum dias dia = LUN;
    switch(dia) {
        case LUN: printf("Hoy es lunes");
        break;
        case MAR: printf("Hoy es martes");
        break;
        case MIE: printf("Hoy es miercoles");
        break;
        case JUE: printf("Hoy es jueves");
        break;
        case VIE: printf("Hoy es viernes");
        break;
        case SAB: printf("Hoy es sabado");
        break;
        case DOM: printf("Hoy es domingo");
        break;
    }

    return 0;
}
