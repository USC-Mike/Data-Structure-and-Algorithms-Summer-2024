//
// Created by Kurt Mike Pino on 6/25/24.
//

#ifndef DICTIONARY_CLOSED_HASHING_CLOSED_HASH_H
#define DICTIONARY_CLOSED_HASHING_CLOSED_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INITIAL_TABLE_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.65

typedef struct {
    char FN[24], MI, LN[16];
}Nametype;

typedef struct {
    char ID[10];
    Nametype name;
    char barangay[10];
    int houseNo;
}Studtype;

//Open Hashing Definition #define OD_SIZE
//#define OD_SIZE 0X1A
//typedef struct node {
//    Studtype stud; struct node *link;
//}nodetype, *LList;
//
//typedef LList OpenDic[OD_SIZE];

//Closed Hashing Definition #define CD_SIZE
#define CD_SIZE 0X1A
typedef enum {
    EMPTY, DELETED, OCCUPIED
}Status; // Hash Table component status

typedef struct {
    Studtype stud;
    Status stat;
}element;

typedef struct {
    element HTable[CD_SIZE];
    int elemCtr; // actual # of dictionary elements
}ClosedDic;

// Linear Probing

void initializeDictClosed(ClosedDic *D);
void insert_Dict(ClosedDic *D, Studtype *P);
int hashValue(char *value);
bool isMember(ClosedDic D, Studtype *value);
void display_Dict(ClosedDic D);

#endif //DICTIONARY_CLOSED_HASHING_CLOSED_HASH_H
