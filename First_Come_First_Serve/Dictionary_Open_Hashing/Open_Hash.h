//
// Created by Kurt Mike Pino on 6/25/24.
//

#ifndef DICTIONARY_OPEN_HASHING_OPEN_HASH_H
#define DICTIONARY_OPEN_HASHING_OPEN_HASH_H

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

/**
 *
 * The program accepts the name of a person and its address.
 *
 * */

typedef struct {
    char Fname[10];
    char Mname[5];
    char Lname[10];
    char province[10];
    char city[10];
}info;

typedef struct node{
    info person;
    struct node *link;
}*NodePtr, Node;

typedef NodePtr Dict[SIZE];

void initializeDict(Dict D);
void insert_to_Dict(Dict D, info value);
void insert_sorted_to_Dict(Dict D, info value);
void delete_from_Dict(Dict D, info value);

int hashValue(char *value);

int isMember(Dict D, info value);

void displayDict(Dict D);
#endif //DICTIONARY_OPEN_HASHING_OPEN_HASH_H
