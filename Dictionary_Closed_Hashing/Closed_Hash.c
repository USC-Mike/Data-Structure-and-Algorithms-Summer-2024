//
// Created by Kurt Mike Pino on 6/25/24.
//

#include <string.h>
#include <stdbool.h>
#include "Closed_Hash.h"

void initializeDictClosed(ClosedDic *D){

    int ctr;
    for (ctr = 0; ctr < CD_SIZE; ctr++) {
        D->HTable[ctr].stat = EMPTY;
    }
    D->elemCtr = 0;
}

void insert_Dict(ClosedDic *D, Studtype *P) {

    int index = hashValue(P->ID);
    if (D->HTable[index].stat == EMPTY) {
        D->HTable[index].stud = *P;
        D->HTable[index].stat = OCCUPIED;
        D->elemCtr++;
    } else {
        printf("Error: Duplicate ID\n");
    }
}

void delete_Dict(ClosedDic *D, Studtype P) {

    int index = hashValue(P.ID);
    if (D->HTable[index].stat != EMPTY && strcmp(D->HTable[index].stud.ID, P.ID) == 0) {
        D->HTable[index].stat = DELETED;
        D->elemCtr--;
    } else {
        printf("Error: Entry not found\n");
    }
}

int hashValue(char *value){
    unsigned long hash = 5381;
    int c;

    while ((c = *value++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % CD_SIZE;
}

bool isMember(ClosedDic D, Studtype *value) {

    int index = hashValue(value->ID);
    if (D.HTable[index].stat == OCCUPIED && strcmp(D.HTable[index].stud.ID, value->ID) == 0) {
        return true;
    } else {
        return false;
    }
}

void display_Dict(ClosedDic D) {

    int i;
    printf("\n");
    for(i = 0 ; i < CD_SIZE ; i++){
        printf("Index [%d]: ", i);

        if(D.HTable[i].stat == DELETED){
            printf("Deleted node!");

        } if(D.HTable[i].stat == EMPTY){
            printf("Empty node!");
        }
        else{
            printf("ID: %s Last Name: %s", D.HTable[i].stud.ID, D.HTable[i].stud.name.LN);
        }
        printf("\n");
    }
}
