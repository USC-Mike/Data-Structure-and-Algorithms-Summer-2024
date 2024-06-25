//
// Created by Kurt Mike Pino on 6/25/24.
//

#include <ctype.h>
#include <string.h>
#include "Open_Hash.h"

void initializeDict(Dict D){
    int x;

    for (x = 0; x < SIZE; ++x) {
        D[x] = NULL;
    }
}

void insert_to_Dict(Dict D, info value){
    NodePtr *replica;
    int hash = hashValue(value.barangay);

    for (replica = &D[hash]; *replica != NULL && (*replica)->person.Fname != value.Fname; replica = &(*replica)->link) {}

    if (*replica == NULL){
        *replica = malloc(sizeof (Node));

        if (*replica != NULL){
            (*replica)->person = value;
            (*replica)->link = NULL;
        }
    }
}

void insert_sorted_to_Dict(Dict D, info value){
    NodePtr *replica, temp;
    int x, hash = hashValue(value.barangay);

    if(*replica == NULL || (*replica)->person.Fname != value.Fname){
        temp = malloc(sizeof(Node));

        if(temp != NULL){
            temp->person = value;
            temp->link = *replica;
            *replica = temp;
        }
    }
}

int hashValue(char value[]){
    int x, hash = 0;

    for (int a = 0; value[a] != '\0'; ++a) {
        hash += value[a];
    }

    printf("The integer value is: %d\n", hash);
    printf("The integer value is: %d\n", hash % SIZE);

    return hash % SIZE;
}

void displayDict(Dict D){
    NodePtr trav;
    int x;

    for (x = 0; x < SIZE; ++x) {
        printf("%3s[%d] => ", "D", x);

        for(trav = D[x]; trav != NULL; trav = trav->link){
            printf(" %4s", trav->person.Fname);
            printf("%3s", "->");
        }

        if(trav == NULL) printf("%4c", 254);
        printf("\n");
    }
    printf("\n");
}