// Escribir la función contiene que reciba dos vectores de enteros y la dimensión de cada uno y retorne:

// 1 si todos los elementos del primer vector están en el segundo
// 2 si todos los elementos del segundo vector están en el primero
// 0 en caso contrario

#include <stdio.h>
#include <assert.h>

// Primero una funcion que me chequee q un elemento pertenece a un vector
int pertenece(int element, int const v[], unsigned int dim);
int contieneAux(int const v1[], unsigned int dim1, int const v2[], unsigned int dim2);
int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2);


int main(void) {

  int v1[] = {1,6,5,3,2};
  int v2[] = {1,2};
  assert(contiene(v1, 5, v2, 2)==2);
  assert(contiene(v2, 2, v1, 5)==1);
  assert(contiene(v1, 1, v2, 2)==1);
  assert(contiene(v1, 0, v2, 2)==1);
  assert(contiene(v1, 5, v2, 0)==2);
  
  int v3[] = {1,2,3,4,5,6};
  assert(contiene(v1, 5, v3, 6)==1);

  int cnt = contiene(v1, 0, v3, 0);
  assert(cnt ==1 || cnt==2);

  int v4[] = { 10, 20, 30, 1, 2};
  assert(contiene(v2, 2, v4, 4)==0);
  assert(contiene(v2, 2, v4, 5)==1);
  assert(contiene(v4, 5, v2, 2)==2);

  int v5[] = {1,1,1,1,1,2,1,2};
  int v6[] = {1,2,3};
  assert(contiene(v5, 8, v6, 3)==1);
  assert(contiene(v6, 3, v5, 8 )==2);

  printf("OK!\n");
  return 0;
}

int pertenece(int element, int const v[], unsigned int dim)
{
    for (int i = 0; i < dim; i++)
        if (v[i] == element)
            return 1;

    return 0;
}

int contieneAux(int const v1[], unsigned int dim1, int const v2[], unsigned int dim2)
{
    int i, encontrado;
    for (i = 0, encontrado = 1; i < dim1 && encontrado; i++)
    {
        encontrado = pertenece(v1[i], v2, dim2);
    }

    return encontrado;
}

int contiene(int const v1[], unsigned int dim1, int const v2[], unsigned int dim2)
{
    // Todos los de v1 existen en v2
    if (contieneAux(v1, dim1, v2, dim2))
        return 1;
    if (contieneAux(v2, dim2, v1, dim1))
        return 2;
    return 0;
}