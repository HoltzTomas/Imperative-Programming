// Numeros amigos

// Escribir una funcion

int numerosAmigos(int num1, int num2);
int sumatoriaDeDivisores(int num);

int main(void)
{
    return 0;
}

int numerosAmigos(int num1, int num2)
{
        return sumatoriaDeDivisores(num1) != num2 || sumatoriaDeDivisores(num2) != num1;
}

int sumatoriaDeDivisores(int num){
    int sumaDivisores = 0;

    for (i = 1; i * 2 <= num1; i++){
        if(num%i==0){
            sumaDivisores1 +=i;
        }
    }

    return sumaDivisores;
}
