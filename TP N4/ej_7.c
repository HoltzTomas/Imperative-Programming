//Escribir la macro isdigit que dado un caracter indique si dicho caracter representa un dígito decimal o no.

#define ISDIGIT(c) ((c) >= '0' && (c) <= '9')

int main(void){
    int letra;
	letra = getchar();
	if ( ISDIGIT(letra) )
		printf("Es un dígito\n");

    return 0;
}
