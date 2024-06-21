#include <stdio.h>
#include "Union_Intersection.h"

int main(void) {
    printf("Hello, World!\n");

    SET A = {0, 1, 0, 1, 1, 1, 0, 0};
    SET B = {1, 0, 0, 1, 0, 1, 1, 1};

    printf(" SET A ==> "); displaySET(A);
    printf(" SET B ==> "); displaySET(B);

    SET *U;
    U = Union(A, B);
    printf("\n Union of TWO SETS ==> "); displaySET(*U);

    SET *I;
    I = Intersection(A, B);
    printf("\n Intersection of TWO SETS ==> "); displaySET(*I);

    SET *D;
    D = Difference(A, B);
    printf("\n Difference of TWO SETS ==> "); displaySET(*D);


    printf("\n SET A ==> "); displaySET(A);

    printf(" SET B ==> "); displaySET(B);
    return 0;
}
