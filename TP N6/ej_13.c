// Escribir una función que realice el producto de dos matrices cuadradas y lo devuelva en una tercera.
// El algoritmo de la función que realiza el producto no debe tener más de dos ciclos for anidados explícitamente,
// pero sí puede utilizar funciones auxiliares que contengan ciclos
//(Ninguna de las funciones debe superar las 5 líneas).
#include <stdio.h>
#include <assert.h>

#define MAXCOL 4

void multMatrix(unsigned int dim, const int m1[][dim], const int m2[][dim], int m3[][dim]);
int multRowCol(unsigned int dim, const int fila[], const int mat2[][dim], int col);

int main(void) {

  int m1[MAXCOL][MAXCOL] = {
      { 1, 2, 3, 4},
      {11,12,13,14},
      {21,22,23,24},
      {31,32,33,34},
      };

  int m2[MAXCOL][MAXCOL] = {
      { 2, 1, 3, 4},
      { 3, 4, 5, 2},
      { 2, 5,10,11},
      {21,12,13,14},
      };

  int ceros[MAXCOL][MAXCOL] ={{0}};

  int m3[MAXCOL][MAXCOL];

  multMatrix(MAXCOL, m1, ceros, m3);

  for(int i=0; i < MAXCOL; i++) {
    for(int j=0; j < MAXCOL; j++)
      assert(m3[i][j]==0);
  }

  // Ahora ceros para a ser I
  for(int i=0; i < MAXCOL; i++) {
    ceros[i][i] = 1;
  }
  multMatrix(MAXCOL, m1, ceros, m3);
  for(int i=0; i < MAXCOL; i++) {
    for(int j=0; j < MAXCOL; j++)
      assert(m3[i][j]==m1[i][j]);
  }

  int res[][MAXCOL] = {
    {98,72,95,97},
    {378,292,405,407},
    {658,512,715,717},
    {938,732,1025,1027}
  };

  multMatrix(MAXCOL, m1, m2, m3);
  for(int i=0; i < MAXCOL; i++) {
    for(int j=0; j < MAXCOL; j++)
      assert(m3[i][j]==res[i][j]);
  }

  int res3[][3] = {
    {14,24,43},
    {84,124,223},
    {154,224,403}
  };
  
  int m4[3][3] = {
      { 1, 2, 3},
      {11,12,13},
      {21,22,23}
      };

  int m5[3][3] = {
      { 2, 1, 3},
      { 3, 4, 5},
      { 2, 5,10}
      };

 int m6[3][3];
  
  multMatrix(3, m4, m5, m6);
  for(int i=0; i < 3; i++) {
    for(int j=0; j < 3; j++) {
      assert(m6[i][j]==res3[i][j]);
	}
  }

  puts("OK!");
}

void multMatrix(unsigned int dim, const int m1[][dim], const int m2[][dim], int m3[][dim])
{
    // Si la cantidad de elementos por row es dim, seran dim * dim multiplicaciones de fila por columna

    // Por cada columna de la matriz resultado
    for (int i= 0; i < dim; i++)
    {
        // Recorremos cada fila y llenamos
        for (int j = 0; j < dim; j++)
            m3[i][j] = multRowCol(dim, m1[i], m2, j);
    }
}

int multRowCol(unsigned int dim, const int fila[], const int mat2[][dim], int col)
{
    int i;
    int total = 0;

    for (i = 0; i < dim; i++)
        total += fila[i] * mat2[i][col];
    return total;
}
