// Decidir si en los siguientes pares de códigos cada una de las variables termina 
// con el mismo valor numérico independientemente de la plataforma.
// Indicar en las evaluaciones el tipo de aritmética utilizada. 
// Justificar todas las respuestas.

//a
int main(void) {
    //Opcion 1
    int letra, flag;
    flag = 0;
    if(letra==(int)'x')
        flag = 1;

    // Opcion 2
    int letra, flag;
    flag = 0;
    if(letra=='x')
        flag = 1;

    //La variable letra en ambos casos es declarada como int
    //'x' es tomado como el entero que representa a x en ASCII
    //Por ende `letra=='x'` es una operacion aritmetica de igualdad entre dos enteros
    //No hace falta forzar la conversion a int
    // Ambos programas funcionan igual

    //Nota: letra no esta inicializada, el valor va a ser basura por ende el comportamiento es indefinido
    //La explicacion anterior supone igual comportamiento ante igual valor de letra
}

//b
int main(void) {
    //Opción 1
    float x;
    int y;
    y=5;
    x=y/3.0;

    //Opción 2
    float x;
    int y;
    y=5;
    x = (float) (y / 3);

    // Dado que la expresión es y/3.0, la operacion es aritmetica de punto flotante
    // El resultado sera en punto flotante, 1.6666667
    // x es Float, por ende almacenara el resultado

    //En la segunda opcion, la operacion es de enteros, la cual da 1
    //Al x ser Float, almacena 1.0
}

//c
int main(void) {
    //Opción 1
    float x;
    int y;
    y=5;
    x=y/3.0;

    //Opción 2
    float x;
    int y;
    y=5;
    x = (float) y / 3;

    // Dado que la expresión es y/3.0, la operacion es aritmetica de punto flotante
    // El resultado sera en punto flotante, 1.6666667
    // x es Float, por ende almacenara el resultado

    //En la segunda opcion, dado que y es flotante, sera aritmetica de punto flotante
    //Al x ser Float, almacena 1.6666667
}

//d
int main(void) {
    //Opción 1
    int x;
    float y;
    y=5.5;
    x=y/3;

    //Opción 2
    int x;
    float y;
    y=5.5;
    x=(int) y/3;

    // y/3 es aritmetica punto flotante
    // El resultado sera en punto flotante 1.8333333
    // x es int, almacena 1

    //En la segunda opcion, es aritmetica de enteros, da 1
    //x es int, almacena 1
}

//e
int main(void) {
    //Opción 1
    double x;
    int y;
    x=25;
    y=x/5;

    //Opción 2
    double x;
    float y;
    x=25.0;
    y=x/5;

    // En la primr opcion, por el tipo de dato de x se dara 25.0/5
    // Aritmetica de punto flotante transforma 5 a 5.0, el resultado da 5.0
    // y es un int, almacena 5

    //Mismo procedimiento con aritmetica de flotantes
    //solo que al ser float, y almacena 5.0
}

//f
int main(void) {
    //Opción 1
    int x,y;
    x=(char)5;
    y=x++;

    //Opción 2
    int x,y;
    x=5.0;
    y=x++;

    //En el primero el (char) no hace nada, dado que 5 ya ocupa un solo byte por ende no cambia el valor
    //y desp este se termina almacenando en un int de todas formas.
    //y=5 dado que el incremento se da desp de la asignacion

    //En el segundo caso x=5 dado que se almacena el int de 5.0 (5)
    //y=5 dado que el incremento se da desp de la asignacion


    //En ambos casos x=6 post asignacion a y
}

//g
int main(void){
    //Opción 1
    int i,j;
    int k;
    i=j=20000;
    k=i+j;

    //Opción 2
    int i,j;
    unsigned k;
    i=j=20000;
    k=i+j;

    //No hay modificaciones en este caso entre usar unsigned o int (signed por default)
    //Dado que 40000 esta dentro del rango en ambos casos
    //k=40000 en ambos casos

    //Nota: de no recordar los rangos de int en tu maquina, ejecutar ./limits en el root de este repo.
}

//h
int main(void){
    //Opción 1
    char a,b;
    char c;
    a=b=60;
    c=a+b;

    //Opción 2
    char a,b;
    unsigned char c;
    a=b=60;
    c=a+b;

    //El problema en el primer caso es que char no tiene default, puede ser signed o unsigned
    //dependiendo de la maquina

    //De todos modos, en ambos casos contiene a 60 y a 120, por ende c=120
    //como esperariamos en ambos casos
}

//i
int main(void){
    //Opción 1
    char a,b;
    char c;
    a=b=100;
    c=a+b;

    //Opción 2
    char a,b;
    unsigned char c;
    a=b=100;
    c=a+b;

    //Parecido al caso anterior, ambas opciones asignaran a 'b' y 'a' correctamente el valor 100

    //Pero la suma da 200, que no es soportada por el signed char
    //En ese caso, dado que 200 en binario es 1100 1000 y se asigna ese binario a c
    //c=-56 (El primer bit es negativo)

    //Todo esto en el caso de que char por default sea signed, depende de la maquina esto

    //En el segundo caso, 200 se asigna correctamente a c
}

//j
int main(void){
    //Opción 1
    int x,y;
    x= (char)300;
    y=x++;

    //Opción 2
    int x,y;
    x= 300.0;
    y=x++;

    //En el primer caso, veamos que la representacion binaria de 300 es 1 0010 1100
    //Como lo convertimos a char, tendremos 0010 1100 (44 en base 2) 44 es representable en signed o unsigned char asi que me despreocupo
    //x=44
    //y=44
    //x pasa a valer 55

    //En el segundo caso x vale 300
    //y vale 300
    //x pasa a valer 301
}

//k
int main(void){
    //Opción 1
    int x,y,z;
    z= (x=2) + (y=x);

    //Opción 2
    int x,y,z;
    x=y=2;
    z=x+y;

    //En el primer caso, dado el orden en que opera el compilador, primero asigna valor a x y luego a y.
    //Luego suma, tiene mas presedencia la asignacion que la suma
    //Por ende, z=4

    //En el segundo caso no quedan dudas que z=4
}