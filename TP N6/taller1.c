#include <stdio.h>
#include <assert.h>

#define OK 1
#define ERROR !OK

/*
** Función que recibe un año y determina si es bisiesto (1) o no (0).
** [Implementada abajo de todo]
*/
static int bisiesto(int);
/*
** Funciones auxiliares para verificar si un año, mes o día son inválidos.
** [Las funciones no están implementadas]
*/
static int invalidoAnio(int);
static int invalidoMes(int);
/*
** Función que recibe un día, mes y año y devuelve 1 si la fecha es válida y 0 si no lo es.
*/
static int invalidoDia(int, int, int);
int unDiaMas(int *, int *, int *);

int daytab[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void)
{
    int dia, mes, anio;

    dia = 9, mes = 4, anio = 2021;
    printf("Fecha actual: %d/%d/%d\n", dia, mes, anio);
    if (unDiaMas(&dia, &mes, &anio))
        printf("Fecha con un dia mas: %d/%d/%d\n", dia, mes, anio);
    else
        printf("Error en los datos\n");

    dia = 1, mes = 1, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 2 && mes == 1 && anio == 2021);

    dia = 31, mes = 3, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 4 && anio == 2021);

    dia = 31, mes = 12, anio = 2020;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 1 && anio == 2021);

    printf("OK!\n");
    return 0;
}

int unDiaMas(int *dia, int *mes, int *anio)
{
    if (invalidoAnio(*anio) || invalidoDia(*anio, *mes, *dia) || invalidoMes(*mes))
        return 0;

    int a = bisiesto(*anio) ? 1 : 0;
    if (*dia == daytab[a][(*mes) - 1])
    {
        if (*mes == 12)
        {
            (*mes) = 1;
            (*anio) += 1;
        }
        else
        {
            (*mes) += 1;
        }

        (*dia) = 1;
    }
    else
    {
        *dia += 1;
    }
    return 1;
}

static int invalidoMes(int mes)
{
    return (mes < 1 || mes > 12);
}

static int invalidoAnio(int anio)
{
    return anio < 0;
}

static int invalidoDia(int anio, int mes, int dia)
{
    int a = bisiesto(anio) ? 1 : 0;
    return dia < 1 || dia > daytab[a][mes - 1];
}

static int
bisiesto(int anio)
{
    int esb = 0;
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        esb = 1;
    return esb;
}
