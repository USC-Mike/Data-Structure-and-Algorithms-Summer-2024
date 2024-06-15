//
// Created by Kurt Mike Pino on 6/13/24.
//

#ifndef MYSTACK_STACKARRAY_H
#define MYSTACK_STACKARRAY_H

#include <stdbool.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int top;
} StackArrayList;

void initStackArray(StackArrayList *S);
bool stack_push(StackArrayList *S, int elem);
bool stack_pop(StackArrayList *S);
int stack_peek(StackArrayList S);
bool isEmpty(StackArrayList S);
bool isFull(StackArrayList S);
void display(StackArrayList S);
void visualizeStack(StackArrayList S);

//Others
//Create a function that would get all even numbers
//and return as a new stack removing from the old stack

StackArrayList getAllEven(StackArrayList *S);

#endif //MYSTACK_STACKARRAY_H
