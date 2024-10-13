

int isNull(int v[], unsigned dim){

    if(dim == 0)
        return 1;

    return (v[0] == 0) &&  isNull(v + 1, dim - 1);
}