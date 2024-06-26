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
    int hash = hashValue(value.Fname);

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
    int hash = hashValue(value.Fname);

    for(replica = &D[hash]; *replica != NULL && (*replica)->person.Fname[0] < value.Fname[0]; replica = &(*replica)->link){}
    if(*replica == NULL || (*replica)->person.Lname[0] != value.Lname[0]){
        temp = malloc(sizeof(Node));

        if(temp != NULL){
            temp->person = value;
            temp->link = *replica;
            *replica = temp;
        }
    }
}

void delete_from_Dict(Dict D, info value){
    NodePtr *replica, temp;
    int hash = hashValue(value.Fname);

    for(replica = &D[hash]; *replica != NULL && (*replica)->person.Fname != value.Fname; replica = &(*replica)->link){}
    if(*replica != NULL){
        temp = *replica;
        *replica = temp->link;
        free(temp);
    }
}

int hashValue(char *value){
    int a, hash = 0;

    for (a = 0; value[a] != '\0'; ++a) {
        hash += value[a];
    }

    printf("The integer value is: %d\n", hash);
    printf("The integer value is: %d\n", hash % SIZE);

    return hash % SIZE;
}

int isMember(Dict D, info value){
    NodePtr *replica, temp;
    int x, hash = hashValue(value.Fname);

    for(replica = &D[hash]; *replica != NULL && (*replica)->person.Fname != value.Fname; replica = &(*replica)->link){}
    if(*replica != NULL){
        printf("Person First Name: %c\n", (*replica)->person.Fname );
        printf("Person Last Name: %c\n", (*replica)->person.Lname );
    }
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

