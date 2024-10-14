
//Escribir una función recursiva que reciba como parámetros de entrada un vector de enteros y 
//su dimensión, y que devuelva en su nombre la suma de todos sus elementos.


#include <stdio.h>
#include <assert.h>

int sumaVec(const int *vector, unsigned int dim);

int main(void) {
  int v[] = {1, 2, 3, 4, 5, -5};

  assert(sumaVec(v,0)==0);
  assert(sumaVec(v,1)==1);
  assert(sumaVec(v,2)==3);
  assert(sumaVec(v,3)==6);
  assert(sumaVec(v,4)==10);
  assert(sumaVec(v,5)==15);
  assert(sumaVec(v,6)==10);

  puts("Test simple:OK!");
  
  int dim = 100;
  int w[dim];
  for(int i=0; i < dim; i++) {
	  w[i]=i+1;
  }
  assert(sumaVec(w,dim) == dim * (dim+1) / 2);
  puts("OK!"); 
  return 0;
}


int sumaVec(const int *vector, unsigned int dim){

    if(dim == 0){
        return 0;
    }

    return vector[dim - 1] + sumaVec(vector, dim-1);

}