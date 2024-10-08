

int isNull(int v[], unsigned dim){

    if(dim == 0)
        return 1;

    // Caso base: Si algún elemento es distinto de 0, no es "nulo"
    if (v[dim - 1] != 0) {
        return 0;
    }

    return isNull(v, dim - 1);

}