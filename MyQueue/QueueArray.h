//
// Created by Kurt Mike Pino on 6/18/24.
//

#ifndef MYQUEUE_QUEUEARRAY_H
#define MYQUEUE_QUEUEARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char name[20];
    int idNum;
    int age;
}info;

typedef struct {
    info data[MAX];
    int front, rear;
}CircularQ;

void initCircularArrayQueue(CircularQ *CQ);
void enqueueCircularArray(CircularQ *CQ, info newData);
void dequeueCircularArray(CircularQ *CQ);
bool isEmptyCircularArray(CircularQ CQ);
bool isFullCircularArray(CircularQ CQ);
void displayCircularArrayQueue(CircularQ CQ);

#endif //MYQUEUE_QUEUEARRAY_H
