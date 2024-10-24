
#ifndef UNTITLED5_STACKADT_H
#define UNTITLED5_STACKADT_H

typedef struct complexCDT* complexADT;

complexADT createComplex(double, double);

double realPart(complexADT c);

double complexPart(complexADT c);

complexADT sum(complexADT c1, complexADT c2);

void freeComplex(complexADT c);

#endif //UNTITLED5_STACKADT_H
