//Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, escribir una función para obtener 
//la mayor diferencia entre dos elementos consecutivos. 
//(En no más de 5 líneas). 
//Tener en cuenta que los números pueden ser negativos. 
//En caso de que el vector tenga un solo elemento deberá retornar como diferencia el valor cero.
#define EPSILON 0.000001
#include <math.h>
#include <assert.h>
#include <stdio.h>

double biggestDifference(double vector[]);

int main(void) {

  double v[] = {1.0, 0.0};
  assert(fabs(biggestDifference(v))==0.0);

  double v2[] = {1.0, 1.0, 1.0, 0.0};
  assert(fabs(biggestDifference(v2))==0.0);

  double v3[] = {1.5, 3.0, -1.0, 0.0};
  assert(fabs(biggestDifference(v3) - 4.0) < EPSILON);

  double v4[] = {1.5, 3.0, 4.5, 3.0, 0.0};
  assert(fabs(biggestDifference(v4) -1.5) < EPSILON);

  double v5[] = {2.5, 1.0, 1.5, 2.0, 0.0};
  assert(fabs(biggestDifference(v5)- 1.5) < EPSILON );

  double v6[] = {1.5,  -1.0, 3.0, 0.0};
  assert(fabs(biggestDifference(v6) - 4.0) < EPSILON);

  puts("OK!");
  return 0;
}
double biggestDifference(double vector[]){

    double biggestDiference = 0;

    if(vector[0] == 0){
        return 0;
    }

    for(int i = 0; vector[i + 1] != 0; i++){
        double difference = fabs(vector[i] - vector[i + 1]);
        
        if(difference > biggestDiference){
            biggestDiference = difference;
        }
    }

    return biggestDiference;
}
