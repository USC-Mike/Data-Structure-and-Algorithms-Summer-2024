//
// Created by Kurt Mike Pino on 6/17/24.
//

#ifndef MYQUEUE_QUEUELINKEDLIST_H
#define MYQUEUE_QUEUELINKEDLIST_H
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *link;
}Node, *NodePtr;

typedef struct{
    NodePtr front;
    NodePtr rear;
}QueueLinkedList;

void initQueueLinkedList(QueueLinkedList *Q);
void enqueueQueueLinkedList(QueueLinkedList *Q, int newData);
void dequeueQueueLinkedList(QueueLinkedList *Q);
int rear(QueueLinkedList Q);
int front(QueueLinkedList Q);
bool isEmpty(QueueLinkedList Q);
void displayQueueLL(QueueLinkedList *Q);

#endif //MYQUEUE_QUEUELINKEDLIST_H
