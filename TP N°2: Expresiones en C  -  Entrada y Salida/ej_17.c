//Indicar, para aquellas expresiones que compilen correctamente, el valor que devuelve.

 int
 main(void)
 {
 	"3" + "4"; //Estas sumando dos punteros char* no es valido ni tiene sentido
 	'3' + '4'; // Devuelve la suma de los dos valores ascii
   	3 + 4; //7
 	'3' + 4; // Valor ASCII de 3 mas el numero 4
 	3 + '4'; // Valor ASCII de 4 mas el numero 3
 	"3" + '4'; //Desplaza al puntero ASCII 4 posiciones en la memoria 
 	"3" + 4; // Desplaza al puntero 4 posiciones en la memorioa
 	return 0;
 }