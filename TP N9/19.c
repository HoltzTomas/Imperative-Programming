#include <stdio.h>
#include <assert.h>
#include <string.h>

// La primera aparicion de alguno de los caracteres de la cadena chars
char * strpbrkRec(const char * target, const char * chars);
char *buscarEnChars(const char *targetChar, const char *chars);

int main(void) {
  char * s = "abcde";
  char * t = "abcdeab";

  assert( strpbrk(s, "") == strpbrkRec(s, ""));
  assert( strpbrk(s, "a") == strpbrkRec(s, "a"));
  assert( strpbrk(s, "xa") == strpbrkRec(s, "xa"));
  assert( strpbrk(s, "xye") == strpbrkRec(s, "xye"));
  assert( strpbrk(s, "r") == strpbrkRec(s, "r"));
  assert( strpbrk(t, "ba") == t);
  assert( strpbrkRec(t, "ba") == t);
  return 0;
}

char *buscarEnChars(const char *targetChar, const char *chars) {
    // Caso base: devolvemos NULL
    if (*chars == '\0') {
        return NULL;
    }

    if (*targetChar == *chars) {
        return (char *)targetChar;
    }

    return buscarEnChars(targetChar, chars + 1);
}

char *strpbrkRec(const char *target, const char *chars) {
    // Caso base
    if (*target == '\0') {
        return NULL;
    }

    if (buscarEnChars(target, chars) != NULL) {
        return (char *)target;  // Si esta, devolvemos un puntero a ese carácter en target
    }

    return strpbrkRec(target + 1, chars);
}