/**
 * 
 * * Crear una funcion recursiva que reciba dos numeros enteros y devuelva el maximo comun divisor
 * 
 * @cond utilizar algoritmo de euclides
 * 
 */


//Doy por hecho que a > b? Dijieron de no validar parametros
int mcd(int a, int b) {
    if(b == 0)
        return a;
    return mcd(b, a%b);
}