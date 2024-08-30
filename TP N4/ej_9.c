// La siguiente función recibe como parámetros de entrada las horas y los minutos que
// representan el momento de ingreso al trabajo de un empleado, y devuelve 1 ( verdadero ) si el empleado llegó a horario y 0 ( falso ) si llegó tarde.
// Las constantes ENT_HORA y ENT_MINUTOS están definidas fuera de la función e indican el horario esperado de entrada al trabajo.
// Testearla, y de no funcionar correctamente, corregirla.
#include <stdio.h>
#define TRUE 1
#define FALSE !TRUE
#define ENT_HORA 9
#define ENT_MINUTOS 0

int llegaTemprano(const int hora, const int minutos);

int main(void) {
    int hora = 9;
    int minutos = 30;

    if (llegaTemprano(hora, minutos)) {
        printf("Llegó a tiempo.\n");
    } else {
        printf("Llegó tarde.\n");
    }

    return 0;
}

int llegaTemprano(const int hora, const int minutos)
{
    if (hora < ENT_HORA)
    {
        return TRUE; // Llegó temprano
    }
    else if (hora == ENT_HORA && minutos <= ENT_MINUTOS)
    {
        return TRUE; // Llegó exactamente a tiempo
    }
    else
    {
        return FALSE; // Llegó tarde
    }
}
