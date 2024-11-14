

#include "squirrelADT.h"
#include <stdlib.h>

// La implementación será una matriz. Pero no necesitamos que tener las filas completas, por lo
// que tendremos que la estructura principal será un vector donde cada elemento represente una fila.
// Y por cada fila tendremos un vector que representará las columnas. En cada fila indicaremos
// cuántas columnas hay en la misma

// Representa una fila. No necesitamos una marca de "ocupadda" o "libre" para cada posición, ya
// que decir que hay cero ardillas es equivalente a decir "no sabemos cuántas hay" o "no han registrado
// ardillas en esta celda"
struct squirrelRow {
    size_t * squirrels;
    size_t cols;
};

struct squirrelCensusCDT {
    size_t blockSizeMeters;
    struct squirrelRow * rows;
    size_t rowCount;
};

#define distanceToBlockIndex(squirrelADT, distance) ((distance) / (squirrelADT->blockSizeMeters))

squirrelCensusADT newSquirrelCensus(size_t blockSizeMeters) {
    if(blockSizeMeters == 0) {
        return NULL;
    }

    squirrelCensusADT newSquirrelCensus = calloc(1, sizeof(struct squirrelCensusCDT));
    newSquirrelCensus->blockSizeMeters = blockSizeMeters;
    return newSquirrelCensus;
}

size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance) {

    size_t blockRow = distanceToBlockIndex(squirrelAdt, yDistance);
    if(blockRow >= squirrelAdt->rowCount) {
        squirrelAdt->rows = realloc(squirrelAdt->rows, (blockRow + 1) * sizeof(struct squirrelRow));
        for(size_t i = squirrelAdt->rowCount; i <= blockRow; i++) {
            squirrelAdt->rows[i].cols = 0;
            squirrelAdt->rows[i].squirrels = NULL;
        }
        squirrelAdt->rowCount = blockRow + 1;
    }

    //Ahora la fila existe si o si, chequeamos que existe la columna
    size_t blockColumn = distanceToBlockIndex(squirrelAdt, xDistance);
    if(blockColumn >= squirrelAdt->rows[blockRow].cols) {
        squirrelAdt->rows[blockRow].squirrels = realloc(squirrelAdt->rows[blockRow].squirrels, (blockColumn + 1) * (sizeof(size_t)));
        for(size_t i = squirrelAdt->rows[blockRow].cols; i <= blockColumn; i++) {
            squirrelAdt->rows[blockRow].squirrels[i] = 0;
        }
        squirrelAdt->rows[blockRow].cols = blockColumn + 1;
    }

    //Ahora que ya tenemos ambasl
    squirrelAdt->rows[blockRow].squirrels[blockColumn]++;
    return squirrelAdt->rows[blockRow].squirrels[blockColumn];
}

size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDist, size_t xDist) {
    size_t blockRow = distanceToBlockIndex(squirrelAdt, yDist);
    if(blockRow >= squirrelAdt->rowCount)
        return 0;

    size_t blockCol = distanceToBlockIndex(squirrelAdt, xDist);
    if(blockCol >= squirrelAdt->rows[blockRow].cols)
        return 0;

    return squirrelAdt->rows[blockRow].squirrels[blockCol];
}

void freeSquirrelCensus(squirrelCensusADT squirrelAdt) {
    for (size_t i = 0; i < squirrelAdt->rowCount; i++)
    {
        free(squirrelAdt->rows[i].squirrels);
    }

    free(squirrelAdt->rows);
    free(squirrelAdt);
}
