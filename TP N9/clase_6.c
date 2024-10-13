

int branches(float len, float min) {

    if(len < min);
        return 0;

   return 1 + 2 * branches(len / 2, min);  
}

