// Sean Nombre y Curso dos arreglos que contienen el nombre y el curso( ‘G’ o ‘H’) de cada uno de los alumnos de una materia.
// Escribir una función que reciba dichos arreglos como parámetros de entrada y retorne en
// parámetros de salida otros dos arreglos CursoG y CursoH con el nombre de los alumnos separados por curso.
// El string vacío en el nombre indica fin del arreglo.

#include <stdio.h>
#include <string.h>

// Definimos la función que separa los nombres en dos arreglos, uno para el curso G y otro para el curso H.
void separarPorCurso(const char nombres[][50], const char cursos[], char cursoG[][50], char cursoH[][50])
{
    int i = 0, gIndex = 0, hIndex = 0;

    // Recorremos el arreglo de nombres hasta que encontremos el string vacío (indicador del fin del arreglo)
    while (strcmp(nombres[i], "") != 0)
    {
        // Si el alumno está en el curso 'G', lo añadimos a CursoG
        if (cursos[i] == 'G')
        {
            strcpy(cursoG[gIndex], nombres[i]);
            gIndex++;
        }
        // Si el alumno está en el curso 'H', lo añadimos a CursoH
        else if (cursos[i] == 'H')
        {
            strcpy(cursoH[hIndex], nombres[i]);
            hIndex++;
        }
        i++;
    }

    // Añadimos el string vacío al final de cada arreglo como indicador de fin
    strcpy(cursoG[gIndex], "");
    strcpy(cursoH[hIndex], "");
}

int main()
{
    // Ejemplo de nombres y cursos
    char nombres[6][50] = {"Juan", "Ana", "Pedro", "Lucia", "Carlos", ""}; // El último elemento es el string vacío que marca el fin
    char cursos[6] = {'G', 'H', 'G', 'H', 'G', '\0'};                      // Los cursos correspondientes a cada alumno

    // Arreglos para almacenar los nombres de los alumnos en curso G y curso H
    char cursoG[6][50], cursoH[6][50];

    // Llamamos a la función para separar los nombres
    separarPorCurso(nombres, cursos, cursoG, cursoH);

    // Imprimimos los alumnos del curso G
    printf("Alumnos en el curso G:\n");
    for (int i = 0; strcmp(cursoG[i], "") != 0; i++)
    {
        printf("%s\n", cursoG[i]);
    }

    // Imprimimos los alumnos del curso H
    printf("Alumnos en el curso H:\n");
    for (int i = 0; strcmp(cursoH[i], "") != 0; i++)
    {
        printf("%s\n", cursoH[i]);
    }

    return 0;
}