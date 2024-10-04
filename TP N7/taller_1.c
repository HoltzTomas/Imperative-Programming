/**
 *  * Implementar una funcion que reciba un arreglo de nombres de alumnos,
 *  * el arreglo de notas y retorne la lista de aprobados
 * 
 *  El prototipo es el de abajo
 * 
 *  - Que retorna la funcion? 
 *  - Se puede modificar los nombres en el arreglo destino? No sabes 
 *  - Como se lee la variable aprobasdos? Tiene suficiente espacio?
 *  - Como copiarian los nombres?
 */

#define NOTA_APROBADO 6

int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[tam], int notas[]);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
 
#define OK 1
#define NOOK !OK
#define NOTA_APROBADO 6
 
int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], int notas[]);
static void mostrarNombres(char * arrNombres[], size_t n);
 
int
main(void) {
    char * arrNombres[] = {"anita","pepe","fabi","carlos","tere"};
    char * aprobados[5];
    int notas[] = {3,4,8,10,1};
    int tam, tamApro;
    tam = sizeof(arrNombres) / sizeof(char*);
    mostrarNombres(arrNombres, tam);
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
    printf("Aprobados:\n");
    mostrarNombres(aprobados, tamApro);
 
    // Test del ejemplo
    char * 2[5];
    assert(obtenerAprobados(arrNombres, 0, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 1, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 2, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 3, aprobados1, notas) == 1);
    assert(strcmp(aprobados1[0], "fabi") == 0);
    for (int i = 0; i < aprobados; i++)
    {
        free(aprobados1[i]);
    }
    
    char * aprobados2[5];
    assert(obtenerAprobados(arrNombres, 4, aprobados2, notas) == 2);
    assert(strcmp(aprobados2[0], "fabi") == 0);
    assert(strcmp(aprobados2[1], "carlos") == 0);
    char * aprobados3[5];
    assert(obtenerAprobados(arrNombres, 5, aprobados3, notas) == 2);
    assert(strcmp(aprobados3[0], "fabi") == 0);
    assert(strcmp(aprobados3[1], "carlos") == 0);

 
    printf("\nOK!\n");
    return 0;
}

static void mostrarNombres(char *arrNombres[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%s\n", arrNombres[i]);
    }
}

int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], int notas[]) {
    int cantidadAprobados = 0;

    // Recorremos el arreglo de notas y nombres
    for (int i = 0; i < tam; i++) {
        if (notas[i] >= NOTA_APROBADO) {
             aprobados[cantidadAprobados] = (char *)malloc((strlen(arrNombres[i]) + 1) * sizeof(char));
            
            // Copiamos el nombre del alumno aprobado
            strcpy(aprobados[cantidadAprobados++], arrNombres[i]);
        }
    }

    return cantidadAprobados;  // Retorna la cantidad de aprobados
}

