#include <stdio.h>
#include <assert.h>
#include <string.h>

void invierte(char *str, char *str2);

int main(void) {

  char s[20] = {0};

  invierte("1234567890", s);
  assert(strcmp(s, "0987654321")==0);

  memset(s, 0, 20);
  invierte("", s);
  assert(strcmp(s, "")==0);

  memset(s, 0, 20);
  invierte("a", s);
  assert(strcmp(s, "a")==0);

  memset(s, 0, 20);
  invierte("ab", s);
  assert(strcmp(s, "ba")==0);
  
  memset(s, 0, 20);
  invierte("abc", s);
  assert(strcmp(s, "cba")==0);

  printf ("OK!\n");
  return 0;
}

void invierte(char *str, char *str2) {

    if(*str == '\0')
        return;

    // Calculamos la longitud restante y asignamos el carácter invertido en la posición adecuada
    int len = strlen(str);  // Longitud de la cadena restante
    str2[len - 1] = *str;

    // Llamada recursiva para el siguiente carácter
    invierte(str + 1, str2);
}