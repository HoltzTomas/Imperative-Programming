#define N 10
#define M 20


int
main (void)
{
	int dim = 7; // Declara e inicializa int dim a 7
	int vectorA[ M * N]; // Declara vectorA sin valor con 200 elementos int de espacio
	int vectorB[ -10 ]; // Error de compilacion un vector no puede tener cantidad de elementos negativo
	int vectorC[ 10.0 ]; // Tiene que ser un int 
	int vectorD[dim]; //Longitud variable, no va
	vectorC[2.5] = 'a'; //No hay posicion 2.5
	vectorB[-1] = 5; // No hay posicion -1
	vectorA['0'] = 10; // Esto tecnicamente funciona
	vectorC[vectorA[48]] = 5.5; // vectorA[48] podrias ser mayor a la dimension
	vectorA[1000] = 0; //No existe la posicion 1000
	vectorA[M * N] = 10; //No existe dicha posicion dado que arranca en cero y llega a (M*N) -1
	return 0;
}
