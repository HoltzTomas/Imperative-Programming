#include <stdio.h>
#include <assert.h>

//Esta funcion toma los dos vectores y chequea que
//todos los elementos del primero esten en el segundo
int corresponde(int v1[], unsigned dim1, int v2[], unsigned dim2);
//Esta funcion deja en vOut[i] la suma de los elementos de la fila i de mat
void sumasMatriz(unsigned rows, unsigned cols, unsigned mat[][cols], int vOut[rows]);
int verificaSuma(unsigned rows1, unsigned cols1, unsigned mat1[][cols1], unsigned rows2, unsigned cols2, unsigned mat2[][cols2]);

int main(void){

    // Prueba 1: Ambas matrices tienen la misma suma de filas
    unsigned mat1_1[][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    unsigned mat1_2[][3] = {
        {6, 5, 4},
        {3, 2, 1}
    };
    assert(verificaSuma(2, 3, mat1_1, 2, 3, mat1_2) == 1);

    // Prueba 2: Una matriz tiene una fila que no está en la otra
    unsigned mat2_1[][2] = {
        {1, 1},
        {2, 2}
    };
    unsigned mat2_2[][2] = {
        {2, 2},
        {3, 3}
    };
    assert(verificaSuma(2, 2, mat2_1, 2, 2, mat2_2) == 0);

    // Prueba 3: Todas las filas de la primera matriz están en la segunda, pero no viceversa
    unsigned mat3_1[][2] = {
        {3, 3},
        {2, 2}
    };
    unsigned mat3_2[][2] = {
        {2, 2},
        {3, 3},
        {4, 4}
    };
    assert(verificaSuma(2, 2, mat3_1, 3, 2, mat3_2) == 1);

    // Prueba 4: Ninguna suma coincide entre las matrices
    unsigned mat4_1[][2] = {
        {1, 1},
        {1, 1}
    };
    unsigned mat4_2[][2] = {
        {3, 3},
        {3, 3}
    };
    assert(verificaSuma(2, 2, mat4_1, 2, 2, mat4_2) == 0);

    // Prueba 5: Matrices con sumas repetidas
    unsigned mat5_1[][3] = {
        {1, 1, 1},
        {1, 1, 1}
    };
    unsigned mat5_2[][3] = {
        {2, 2, 0},
        {0, 0, 3}
    };
    assert(verificaSuma(2, 3, mat5_1, 2, 3, mat5_2) == 1);

    printf("All tests passed successfully.\n");

}
 
int verificaSuma(unsigned rows1, unsigned cols1, unsigned mat1[][cols1], unsigned rows2, unsigned cols2, unsigned mat2[][cols2]){
 
  int sumas_mat_1[rows1];
  int sumas_mat_2[rows2];
 
  //Inicializo estos vectores donde voy a guardar el valor de la suma
  //de cada fila
  for(int i = 0; i < rows1; i++)
      sumas_mat_1[i] = 0;
 
  for(int i = 0; i < rows2; i++)
      sumas_mat_2[i] = 0;
 
  //Sumas matriz 1
  sumasMatriz(rows1, cols1, mat1, sumas_mat_1);
 
  //Sumas matriz 2
  sumasMatriz(rows2, cols2, mat2, sumas_mat_2);
 
  //Ahora que ya tengo todos los resultados de las sumas
  //la funcion corresponde se encarga de ver si todas las sumas de mat1
  //estan en mat2 y visceversa
 
  int corresponde_1_2 = corresponde(sumas_mat_1, rows1, sumas_mat_2, rows2);
  if(corresponde_1_2)
    return 1;
 
  int corresponde_2_1 = corresponde(sumas_mat_2, rows2, sumas_mat_1, rows1);
  if(corresponde_2_1)
    return 2;
 
  return 0;
}
 
void sumasMatriz(unsigned rows, unsigned cols, unsigned mat[][cols], int vOut[rows]){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++)
      vOut[i] += mat[i][j];
  }
  return;
}
 
int corresponde(int v1[], unsigned dim1, int v2[], unsigned dim2){
  for(int i = 0; i < dim1; i++){
    int esta_en_el_otro = 0; 
    for(int j = 0; j < dim2; j++){
      if(v1[i] == v2[j])
        esta_en_el_otro = 1;
    }
    //Con que una sola vez esta_en_el_otro sea falso, ya se que no todos los
    //elementos de v1 estan en v2 y puedo retornar falso
    if(!esta_en_el_otro){
        return 0;
    }
  }
  //Si sali del ciclo, todos los elementos de v1 estan en v2
  return 1;
}
