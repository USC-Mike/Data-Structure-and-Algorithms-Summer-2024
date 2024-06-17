//
// Created by Kurt Mike Pino on 6/17/24.
//

#include <stdlib.h>
#include <stdio.h>
#include "QueueLinkedList.h"

void initQueueLinkedList(QueueLinkedList *Q){
    Q->rear = NULL;
    Q->front = NULL;
}

void enqueueQueueLinkedList(QueueLinkedList *Q, int newData){
    NodePtr Replica = malloc(sizeof (Node));

    if (Replica != NULL){
        Replica->data = newData;
        Replica->link = NULL;

        if (Q->rear == NULL){
            Q->front =  Replica;
        } else {
            Q->rear->link = Replica;
        }
        Q->rear = Replica;
    }
}
void dequeueQueueLinkedList(QueueLinkedList *Q){
    NodePtr Replica;

    if (Q->front != NULL){
        Replica = Q->front;
        Q->front = Q->front->link;

        if (Q->front == NULL){
            Q->rear = NULL;
        }
        free(Replica);
    }
}

int rear(QueueLinkedList Q){
    return Q.rear != NULL ? Q.rear->data : -1;
}

int front(QueueLinkedList Q){
    return Q.rear != NULL ? Q.front->data : -1;
}
bool isEmpty(QueueLinkedList Q){
    return Q.rear == NULL ? true : false;
}

void displayQueueLL(QueueLinkedList *Q){
    QueueLinkedList Replica;
    initQueueLinkedList(&Replica);

    while(Q->front != NULL){
        printf("%d ", front(*Q));
        enqueueQueueLinkedList(&Replica, front(*Q));
        dequeueQueueLinkedList(Q);
    }
    while(Replica.front != NULL){
        enqueueQueueLinkedList(Q, front(Replica));
        dequeueQueueLinkedList(&Replica);
    }
    printf("\n");
}
