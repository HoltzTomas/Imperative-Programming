
#include <stdlib.h>
#include "complexADT.h"
#include <math.h>

struct complexCDT {
    double realPart;
    double complexPart;
};

double realPart(complexADT c) {
    return c->realPart;
}

double complexPart(complexADT c) {
    return c->complexPart;
}

complexADT sum(complexADT c1, complexADT c2) {
    complexADT sum = malloc(sizeof(struct complexCDT));
    sum->realPart = c1->realPart + c2->realPart;
    sum->complexPart = c1->complexPart + c2->complexPart;
    return sum;
}

complexADT createComplex(double real, double complex) {
    complexADT num = malloc(sizeof(struct complexCDT));
    num->realPart = real;
    num->complexPart = complex;
    return num;
}

void freeComplex(complexADT c) {
    free(c);
}
