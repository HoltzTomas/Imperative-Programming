#include <stdio.h>
#include <string.h>
#include <assert.h>

char *mi_strrchr(const char *str, char ch) {
    // Caso base: si llegamos al final de la cadena
    if (*str == '\0') {
        return NULL;
    }

    // Recursión: buscar en el resto de la cadena
    char *last_occurrence = mi_strrchr(str + 1, ch);

    // Si encontramos una ocurrencia en la llamada recursiva, la devolvemos
    if (last_occurrence != NULL) {
        return last_occurrence;
    }

    // Si el carácter actual coincide, devolvemos un puntero a él
    if (*str == ch) {
        return (char *)str;
    }

    // Si no encontramos nada, devolvemos NULL
    return NULL;
}


int
main(void) {
	char * s = "vamos a buscar";

	for ( int i=0; s[i]; i++) {
		assert(strrchr(s, s[i]) == mi_strrchr(s, s[i]));
	} 
	
	assert(NULL == mi_strrchr(s, 'x'));
	
	// También tiene que dar NULL para el valor 0
	assert(NULL == mi_strrchr(s, '\0'));

	puts("OK!");
}