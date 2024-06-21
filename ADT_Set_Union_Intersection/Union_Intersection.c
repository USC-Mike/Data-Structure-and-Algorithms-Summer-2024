//
// Created by Kurt Mike Pino on 6/21/24.
//
#include <stdlib.h>
#include <printf.h>
#include "Union_Intersection.h"

void insert_To_SET(SET S, int x){
    if ( x >= 0 && x < SET_MAX){
        S[x] |= 1;
    }
}
void delete_From_SET(SET S, int x){
    if ( x >= 0 && x < SET_MAX){
        S[x] &= 0;
    }
}

SET *Union(SET A, SET B){
    int U;
    SET *Replica = NULL;

    Replica = malloc(sizeof(SET)*SET_MAX);
    if (Replica != NULL){
        for (U = 0; U < SET_MAX; U++) {
            (*Replica)[U] = A[U] | B[U];
        }
    }
    return Replica;
}

SET *Intersection(SET A, SET B){
    int I;
    SET *Replica = NULL;

    Replica = malloc(sizeof(SET)*SET_MAX);
    if (Replica != NULL){
        for (I = 0; I < SET_MAX; I++) {
            (*Replica)[I] = A[I] & B[I];
        }
    }
    return Replica;
}

SET *Difference(SET A, SET B){
    int D;
    SET *Replica = NULL;

    Replica = malloc(sizeof(SET)*SET_MAX);
    if (Replica != NULL){
        for (D = 0; D < SET_MAX; D++) {
            (*Replica)[D] = A[D] & ~B[D];
        }
    }
    return Replica;
}

void displaySET(SET A){
    int i;
    for(i = 0; i < SET_MAX; i++){
        printf("%-5d", A[i]);
    }
    printf("\n");
}
