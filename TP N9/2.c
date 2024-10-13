//Escribir la función recursiva suma que reciba un único parámetro de entrada de tipo integer 
//y devuelva en su nombre la suma de sus dígitos.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  // Para usar abs()

int suma(int numero);
int sumaRecursiva(int numero);

int main(void) {

  assert(suma(0)==0);
  assert(suma(1)==1);
  assert(suma(12)==3);
  assert(suma(100000)==1);
  assert(suma(123456)==21);
  assert(suma(-123456)==21);
  assert(suma(999999)==54);

  puts("OK!");
  return 0;
}

int suma(int numero) {

    int num = abs(numero);

    return sumaRecursiva(num);
}

int sumaRecursiva(int numero) {

    if(numero / 10 == 0)
        return numero;

    return numero % 10 + suma(numero / 10);
}
