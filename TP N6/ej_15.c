#include <stdio.h>
#include <assert.h>

#define ALTO 6
#define ANCHO 5

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

void suavizar(unsigned char m[ALTO][ANCHO], int w);
// Promedio debe recibir W ya dividido por la mitad
static int promedio(unsigned char m[ALTO][ANCHO], int x, int y, int w);

int equals(unsigned int cols, unsigned char m1[][cols], unsigned char m2[][cols], unsigned int rows) {
  for (int i=0; i < rows; i++) {
     for(int j=0; j < cols; j++) {
         if ( m1[i][j] != m2[i][j]) {
            return 0;
         }
     }
  }
  return 1;  
}

int main(void) {
  unsigned char bmp[ALTO][ANCHO] =    {
      {10,10,20,23,24},
      {10,12,18,25,23},
      {12,14,18,26,22},
      {12,14,19,20,22},
      {13,16,19,20,22},
      {14,14,19,21,23}};
 
  
  suavizar(bmp, 3);
  unsigned char suave[ALTO][ANCHO] =    {
      {10,13,18,22,23},
      {11,13,18,22,23},
      {12,14,18,21,23},
      {13,15,18,20,22},
      {13,15,18,20,21},
      {14,15,18,20,21}};

  assert(equals(ANCHO, bmp, suave, ALTO));

  // Ahora una con w=5
  unsigned char suave5[ALTO][ANCHO] =    {
	{14,16,17,19,20},
	{14,16,17,18,20},
	{14,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,19}};

   suavizar(bmp, 5);
   assert(equals(ANCHO, bmp, suave5, ALTO));

  puts("OK!");
  return 0;
}

static int promedio(unsigned char m[ALTO][ANCHO], int x, int y, int w)
{

    int sum = 0, counter = 0;

    for (int i = MAX(y - w, 0); i <= MIN(ALTO - 1, y + w); i++)
    {
        for ( int j = MAX(0,x-w); j <= MIN(ANCHO-1,x+w); j++ )
        {
            sum += m[i][j];
            counter++;
        }
    }

    return (sum / counter);
}

void suavizar(unsigned char m[ALTO][ANCHO], int w)
{

    if (w < 3 || w % 2 == 0)
        return;

    // Primero inicializamos una matriz auxiliar
    unsigned char aux[ALTO][ANCHO];

    // Para cada elemento de m, calculamos su promedio y lo guardamos en aux
    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            aux[i][j] = promedio(m, j, i, w / 2);
        }
    }

    // Luego copiamos aux en la original

    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            m[i][j] = aux[i][j];
        }
    }
}
