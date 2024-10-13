#include <stdio.h>
#include <assert.h>

int balance(const char *texto);


int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}

int balance(const char *exp) {
    // Caso base: Si la expresión es vacía, los paréntesis están balanceados
    if (*exp == '\0') {
        return 0;
    }

    // Si encuentro un paréntesis de apertura, incremento la cuenta
    if (*exp == '(') {
        return 1 + balance(exp + 1);
    }

    // Si encuentro un paréntesis de cierre, decremento la cuenta
    if (*exp == ')') {
        return -1 + balance(exp + 1);
    }

    // Si es cualquier otro carácter, continúo la búsqueda sin modificar la cuenta
    return balance(exp + 1);
}
