//
// Created by Kurt Mike Pino on 6/18/24.
//

#include "QueueArray.h"

void initCircularArrayQueue(CircularQ *CQ){
    CQ->rear = MAX-1;
    CQ->front = 0;
}

void enqueueCircularArray(CircularQ *CQ, info newData){
    if (!isFullCircularArray(*CQ)){
        CQ->rear = (CQ->rear + 1) % MAX;
        CQ->data[CQ->rear] = newData;
    }
}

void dequeueCircularArray(CircularQ *CQ){
    if (!isEmptyCircularArray(*CQ)){
        CQ->front = (CQ->front + 1) % MAX;
    }
}

bool isEmptyCircularArray(CircularQ CQ){
    return (CQ.rear + 1) % MAX == CQ.front ? true : false;
}

bool isFullCircularArray(CircularQ CQ){
    return (CQ.rear + 2) % MAX == CQ.front ? true : false;
}

void displayCircularArrayQueue(CircularQ CQ){
    int newFront = (CQ.rear + 1) % MAX;

    printf("\n Circular Array Queue \n");
    printf(" %10s | %10s | %10s \n", "INDEX", "ID", "NAME");
    if(!isEmptyCircularArray(CQ)){
        while(CQ.front != newFront){
            printf(" %10d | %10d | %10s \n", 1 , CQ.data[CQ.front].idNum, CQ.data[CQ.front].name);
            CQ.rear = (CQ.rear+1)%MAX;
            CQ.data[CQ.rear] = CQ.data[CQ.front];
            CQ.front = (CQ.front+1)%MAX;
        }
    }
    printf("\n");
}