//
// Created by Kurt Mike Pino on 6/14/24.
//

#ifndef MYSTACK_STACKLINKEDLIST_H
#define MYSTACK_STACKLINKEDLIST_H

#include <stdbool.h>
#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} NodeType, *NodePtr, *StackLinkedList;

void initStackLinkedList(StackLinkedList *S);
bool stack_push_linked_list(StackLinkedList *S, int elem);
bool stack_pop_linked_list(StackLinkedList *S);
int stack_peek_linked_list(StackLinkedList S);
bool isEmptyLinkedList(StackLinkedList S);
void displayLL(StackLinkedList S);

//Others
//Create a function that would get all even numbers
//and return as a new stack removing from the old stack
StackLinkedList getAllEvenLinkedList(StackLinkedList *S);

#endif //MYSTACK_STACKLINKEDLIST_H
