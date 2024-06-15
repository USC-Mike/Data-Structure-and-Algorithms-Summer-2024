//
// Created by Kurt Mike Pino on 6/13/24.
//

#include <stdio.h>
#include <stdbool.h>
#include "StackArray.h"

void initStackArray(StackArrayList *S){
    S->top = -1;
}

bool stack_push(StackArrayList *S, int elem){
    if (S->top != MAX-1){
        S->data[++(S->top)] = elem;
    }
}

bool stack_pop(StackArrayList *S){
    if (S->top != -1){
        S->top--;
    }
}

int stack_peek(StackArrayList S){
    return S.top != -1 ? S.data[S.top] : -1;
}

bool isEmpty(StackArrayList S){
    return (S.top == -1) ? true : false;
}

bool isFull(StackArrayList S){
    return (S.top == MAX) ? true : false;
}

void display(StackArrayList S){
    StackArrayList Replica;
    initStackArray(&Replica);

    printf("%10s", "Array Stack =>");
    while(!isEmpty(S)){
        stack_push(&Replica, stack_peek(S));
        stack_pop(&S);
    }
    while(!isEmpty(Replica)){
        printf("%3d ", Replica.data[Replica.top]);
        stack_push(&S, stack_peek(Replica));
        stack_pop(&Replica);
    }
    printf("\n\n");
}
void visualizeStack(StackArrayList S){
    int i;

    printf("%10s | %5s | %5s\n", "Index", "Value", "");
    printf("%10d | %5d | %5s\n", S.top,  S.data[S.top], "<--TOP");
    for(i = S.top-1; i >= 0; --i) {
        printf("%10d | %5d | \n", i, S.data[i]);
    }
    printf("\n");
}

// GetAllEvenNumbers
StackArrayList getAllEven(StackArrayList *S){
    StackArrayList Replica;
    initStackArray(&Replica);

    StackArrayList newStack;
    initStackArray(&newStack);

    while (!isEmpty(*S)){
        stack_push(&Replica, stack_peek(*S));
        stack_pop(S);
    }

    while (!isEmpty(Replica)){
        if (Replica.data[Replica.top] % 2 == 0){
            stack_push(&newStack, stack_peek(Replica));
            stack_pop(&Replica);
        } else {
            stack_push(S, stack_peek(Replica));
            stack_pop(&Replica);
        }
    }

    return newStack;
}