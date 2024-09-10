// Se desea calcular la desviación estándar de un arreglo de números enteros.
// Los números del arreglo toman valores entre 0 y 15 inclusive, por lo que para almacenar cada número se utilizarán solo 4 bits,
// pudiendo almacenar dos números en un solo byte.

// Para representar dicho arreglo se utilizará un vector de caracteres,
// donde cada elemento del vector contendrá dos números (uno en los cuatro bits superiores y el otro en los cuatro bits inferiores).

// Escribir una función que reciba un arreglo como el mencionado anteriormente y
// la cantidad de números que contiene y retorne en su nombre la desviación estándar de los números recibidos.
#include <math.h>
#include <stdio.h>
#include <assert.h>

// Calcula la desviación estandar de un vector de numeros de 4 bits almacenados en chars
double desv(const unsigned char vector[], int dim);

// Calcula el promedio de un vector de numeros de 4 bits almacenados en chars
double average(const unsigned char vector[], int dim);

// Calcula la sumatoria de (valor - promedio)^2
double summation(const unsigned char vector[], int dim, double average);

// Toma los 4 primeros bits de izquierda a derecha
char nibbleh(unsigned char num);

// Toma los 4 ultimos bits de izquierda a derecha
char nibblel(unsigned char num);

int main(void)
{
    double d;
    unsigned char arreglo2[] = {0x33, 0x33, 0x33, 0x33, 0x33};
    for (int i = 0; i <= 10; i++)
        assert(desv(arreglo2, i) == 0);

    unsigned char arreglo[] = {0x37, 0xF2, 0x03, 0x4A, 0xFF};
    assert(desv(arreglo, 1) == 0);
    assert(desv(arreglo, 2) == 2.0);

    assert(desv(arreglo, 3) > 4.98 && desv(arreglo, 3) < 4.99);

    assert(desv(arreglo, 10) > 5.6071 && desv(arreglo, 3) < 5.6072);

    puts("OK!");
}

double desv(const unsigned char vector[], int dim)
{

    if (dim == 0)
        return 0.0;
    // Primero calculamos el promedio de los valores del vector
    double vectorAverage = average(vector, dim);
    printf("El promedio dio %g\n", vectorAverage);

    // Luego realizamos la sumatoria de (valor - promedio)^2
    double vectorSummation = summation(vector, dim, vectorAverage);
    printf("La sumatoria dio %g\n", vectorSummation);

    // Luego la raiz cuadrada de la sumatoria dividia por el total de elementos
    return sqrt(vectorSummation / dim);
}

double average(const unsigned char vector[], int dim)
{
    int i = 0, rest = dim; // En rest tenemos la cantidad de valores que restan recorrer
    double sum = 0;

    while (rest-- > 0)
    {
        // Tomamos el mas alto
        sum += nibbleh(vector[i]);

        // De corresponder, el mas bajo
        if (rest-- > 0)
            sum += nibblel(vector[i]);

        i++;
    }

    return sum / dim;
}

double summation(const unsigned char vector[], int dim, double average)
{
    int i = 0; // En rest tenemos la cantidad de valores que restan recorrer
    double sum = 0;

    while (dim-- > 0)
    {
        // Tomamos el mas alto
        sum += pow(nibbleh(vector[i]) - average, 2);

        // De corresponder, el mas bajo
        if (dim-- > 0)
            sum += pow(nibblel(vector[i]) - average, 2);
        i++;
    }

    return sum;
}

char nibbleh(unsigned char num)
{
    return num >> 4;
}

char nibblel(unsigned char num)
{
    return num & 0x0F;
}
