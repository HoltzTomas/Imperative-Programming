#include <stdlib.h>
#include "landmarksADT.h"

#define indexByMeters(meters) (meters) / 100 //Ej 50 metros -> Indice cero

typedef struct landmark{
    landmarkType elem;
    int estado; //Vacio o ocupado
} Landmark;

typedef Landmark * LandmarkList;

typedef struct landmarkCDT {
    size_t landmarkCount;
    size_t landmarksReservedSpace; //Cantidad de intervalos, si hay hasta 399 metros, sera 4
    compare cmp;
    LandmarkList landmarks;
} landmarkCDT;

landmarkADT newLandmark(compare cmp) {
    landmarkADT newLandmark = calloc(1, sizeof(landmarkCDT));
    newLandmark->cmp = cmp;
    newLandmark->landmarkCount = 0;
    newLandmark->landmarks = NULL;
    return newLandmark;
}

void addLandmark(landmarkADT landmark, size_t meters, landmarkType site) {

    int index = indexByMeters(meters);
    //Ejemplo, index es cero y tengo cero landmarks, no hay lugar reservado aun
    if(index >= landmark->landmarksReservedSpace) {
        size_t newReservedSpace = index + 1;
        landmark->landmarks = realloc(landmark->landmarks, sizeof(Landmark) * (newReservedSpace));
        for (size_t i = landmark->landmarksReservedSpace; i < newReservedSpace; i++)
        {
            landmark->landmarks[i].estado = 0;
        }
        landmark->landmarksReservedSpace = newReservedSpace;
    }

    //Ahora que se que landmark existe en memoria
    //Solo aumento el count si no habia nada
    if (landmark->landmarks[index].estado == 0) {
        landmark->landmarkCount++;
    }
    landmark->landmarks[index].estado = 1;
    landmark->landmarks[index].elem = site;

}

int hasLandmark(const landmarkADT landmark, size_t meters) {
    int index = indexByMeters(meters);
    if(index >= landmark->landmarksReservedSpace)
        return 0;

    return landmark->landmarks[index].estado;
}

int distance(const landmarkADT landmark, landmarkType site) {
    int i;
    for (i = 0; i < landmark->landmarksReservedSpace; i++)
    {
        //Si existe y ademas es la misma, retornamosdistancia estimada
        if(landmark->landmarks[i].estado && landmark->cmp(landmark->landmarks[i].elem, site) == 0) 
            return i * 100; //Distancia aprox en metros
    }
    //
    return -1;
}

size_t landmarkCount(const landmarkADT landmark) {
    return landmark->landmarkCount;
}

landmarkType * landmarks(const landmarkADT landmark) {
    landmarkType * res = NULL;

    if(landmark->landmarkCount == 0)
        return NULL;

    //Ahora asignamos espacio suficiente para las landmarks
    res = realloc(res, sizeof(landmarkType) * landmark->landmarkCount);
    int dim = 0;

    for(size_t i = 0; i < landmark->landmarksReservedSpace; i++) {
        if(landmark->landmarks[i].estado) {
            res[dim++] = landmark->landmarks[i].elem;
        }
    }

    return res;
}

landmarkType * landmarksBetween(const landmarkADT landmark, size_t from, size_t to, size_t *dim) {
    // Validar entrada
    if (landmark->landmarkCount == 0 || from > to) {
        *dim = 0;
        return NULL;
    }

    size_t startIndex = indexByMeters(from);
    size_t endIndex = indexByMeters(to);

    if (endIndex >= landmark->landmarksReservedSpace) {
        *dim = 0;
        return NULL;
    }

    landmarkType *res = NULL;
    size_t dim_aux = 0;

    // Recorrer las landmarks en el rango especificado
    for (size_t i = startIndex; i <= endIndex; i++) {
        if (landmark->landmarks[i].estado) {
            // Redimensionar el bloque de memoria
            landmarkType *temp = realloc(res, sizeof(landmarkType) * (dim_aux + 1));
            if (temp == NULL) {
                // Si realloc falla, liberamos memoria asignada previamente
                free(res);
                *dim = 0;
                return NULL;
            }
            res = temp;
            res[dim_aux++] = landmark->landmarks[i].elem;
        }
    }

    *dim = dim_aux;
    return res;
}


void freeLandmark(landmarkADT landmark) {
    free(landmark->landmarks);
    free(landmark);
}
