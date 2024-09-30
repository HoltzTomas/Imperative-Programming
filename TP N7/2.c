#include <stdio.h>
#include <string.h>
#include <math.h>

// Función para convertir un número en base 'from_base' a decimal
int to_decimal(const char *num_str, int from_base) {
    int decimal = 0, power = 0;
    int len = strlen(num_str);

    // Convertir cada dígito de la cadena en su valor decimal
    for (int i = len - 1; i >= 0; i--) {
        int digit = num_str[i] - '0'; // Convertir el carácter a su valor numérico
        decimal += digit * pow(from_base, power);
        power++;
    }
    return decimal;
}

// Función para convertir un número en decimal a cualquier base 'to_base'
void from_decimal(int decimal, int to_base, char *result) {
    char temp[32]; // Usamos un buffer temporal
    int index = 0;

    // Convertir a la nueva base
    do {
        temp[index++] = (decimal % to_base) + '0'; // Guardar el residuo como dígito
        decimal /= to_base;
    } while (decimal > 0);

    // Invertir el resultado
    for (int i = 0; i < index; i++) {
        result[i] = temp[index - i - 1];
    }
    result[index] = '\0'; // Terminar la cadena
}

int main() {
    char input[100], num_str[50], result[50];
    int from_base, to_base;

    // Leer la cadena de entrada
    printf("Introduce la cadena (ej. <5>2 41): ");
    scanf("%s %s", input, num_str); // Capturamos la base y el número por separado

    // Extraer las bases de la cadena de entrada
    sscanf(input, "<%d>%d", &from_base, &to_base);

    // Convertir el número en base 'from_base' a decimal
    int decimal = to_decimal(num_str, from_base);

    // Convertir el número en decimal a la base 'to_base'
    from_decimal(decimal, to_base, result);

    // Imprimir el resultado
    printf("El número %s en base %d es %s en base %d\n", num_str, from_base, result, to_base);

    return 0;
}
