//
// Created by Kurt Mike Pino on 6/14/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"

void initStackLinkedList(StackLinkedList *S){
    *S = NULL;
}

bool stack_push_linked_list(StackLinkedList *S, int elem){
// insert front 0(1)
    StackLinkedList Replica = malloc(sizeof (NodeType));

    if (Replica != NULL){
        Replica->data = elem;
        Replica->next = *S;
        *S = Replica;
    }
    return (*S != NULL) ? true : false;
}

bool stack_pop_linked_list(StackLinkedList *S){
// deletefront 0(1)
    StackLinkedList Replica;
    if (*S != NULL){
        Replica = *S;
        *S = Replica->next;
        free(Replica);
    }
    return (*S != NULL) ? true : false;
}

int stack_peek_linked_list(StackLinkedList S){
    return S != NULL ? S->data : -1;
}

bool isEmptyLinkedList(StackLinkedList S){
    return (S == NULL) ? true : false;
}

void displayLL(StackLinkedList S){
    StackLinkedList Replica;
    initStackLinkedList(&Replica);

    StackLinkedList Temp;
    initStackLinkedList(&Temp);

    //Stack cannot be traverse

    while (!isEmptyLinkedList(S)){
        Replica = S;
        S = Replica->next;
        Replica->next = Temp;
        Temp = Replica;
    }

    printf("Linked List Stack Head ==> ");
    while (!isEmptyLinkedList(Temp)){
        printf("%d ", stack_peek_linked_list(Temp));
        Replica = Temp;
        Temp = Replica->next;
        Replica->next = S;
        S = Replica;
    }
    printf("\n");
}

StackLinkedList getAllEvenLinkedList(StackLinkedList *S){
    StackLinkedList Replica;
    initStackLinkedList(&Replica);

    StackLinkedList Temp;
    initStackLinkedList(&Temp);

    StackLinkedList newStackLL;
    initStackLinkedList(&newStackLL);

    while (!isEmptyLinkedList(*S)){
        Replica = *S;
        *S = Replica->next;
        Replica->next = Temp;
        Temp = Replica;
    }

    while (!isEmptyLinkedList(Temp)){
        if (Temp->data % 2 == 0 ){
            stack_push_linked_list(&newStackLL, Temp->data);
            stack_pop_linked_list(&Temp);
        } else {
            Replica = Temp;
            Temp = Replica->next;
            Replica->next = *S;
            *S = Replica;
        }

    }
    return newStackLL;
}