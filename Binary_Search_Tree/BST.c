//
// Created by Kurt Mike Pino on 7/5/24.
//

#include <string.h>
#include "BST.h"

void initializeBinarySearchTree(NodePtr *BST) {
    *BST = NULL;
}

void insertProducts_to_BST(NodePtr *BST, Product Prod) { // Non-Recursive
    NodePtr *trav;

    for (trav = BST; *trav != NULL;) {
        trav = (strcmp((*trav)->item.prodName, Prod.prodName) > 0) ? &(*trav)->Left : &(*trav)->Right;
    }

    if (*trav == NULL) {
        *trav = (NodePtr)malloc(sizeof(NodeType));

        if (*trav != NULL) {
            (*trav)->item = Prod;
            (*trav)->Left = NULL;
            (*trav)->Right = NULL;
        }
    }
}

void deleteProducts_from_BST(NodePtr *BST, char *name) {

    NodePtr temp, *trav;

    for(trav = BST; *trav != NULL && strcmp((*trav)->item.prodName, name) != 0 ;){
        trav = strcmp((*trav)->item.prodName, name) < 0 ? &(*trav)->Right : &(*trav)->Left;
    }

    if(*trav != NULL){
        temp = *trav;
        if((*trav)->Left == NULL){
            *trav = (*trav)->Right;
        } else if((*trav)->Right == NULL){
            *trav = (*trav)->Left;
        } else{
            for(trav = &(*trav)->Left; (*trav)->Right != NULL; trav = &(*trav)->Right){}
            temp->item = (*trav)->item;

            temp = *trav;
            *trav = temp->Left;
        }
        free(temp);
    }
}

void initializeQueue(QueueLList *Q) {
    Q->front = Q->rear = NULL;
}

void enqueue(QueueLList *Q, NodePtr treeNode) {
    QueueNodePtr newQueueNode = (QueueNodePtr)malloc(sizeof(QueueNode));
    if (newQueueNode != NULL) {
        newQueueNode->treeNode = treeNode;
        newQueueNode->next = NULL;

        if (Q->rear == NULL) {
            Q->front = Q->rear = newQueueNode;
        } else {
            Q->rear->next = newQueueNode;
            Q->rear = newQueueNode;
        }
    }
}

NodePtr dequeue(QueueLList *Q) {
    if (Q->front == NULL) {
        printf("Queue is empty\n");
        return NULL; // Return NULL if the queue is empty
    }

    QueueNodePtr Replica = Q->front;
    Q->front = Replica->next;

    if (Q->front == NULL) {
        Q->rear = NULL;
    }

    NodePtr currentNode = Replica->treeNode; // Store the node to return
    free(Replica); // Free the memory allocated for the queue node
    return currentNode; // Return the node that was dequeued
}

void BFS_traversal(NodePtr BST) {
    if (!BST) return; // Base case: the tree is empty

    QueueLList Q;
    initializeQueue(&Q);
    enqueue(&Q, BST); // Enqueue the root node

    while (Q.front != NULL) {
        NodePtr current = dequeue(&Q); // Dequeue a node
        if (current != NULL) {
            printf("%s -> ", current->item.prodName); // Process the node

            // Enqueue the children of the current node
            if (current->Left) enqueue(&Q, current->Left);
            if (current->Right) enqueue(&Q, current->Right);
        }
    }
}

void displayPreOrder(NodePtr BST) {
    if (BST != NULL) {
        printf("%s -> ", BST->item.prodName);
        displayPreOrder(BST->Left);
        displayPreOrder(BST->Right);
    }
}

void displayInOrder(NodePtr BST) {
    if (BST != NULL) {
        displayInOrder(BST->Left);
        printf("%s -> ", BST->item.prodName);
        displayInOrder(BST->Right);
    }
}

void displayPostOrder(NodePtr BST) {
    if (BST != NULL) {
        displayPostOrder(BST->Left);
        displayPostOrder(BST->Right);
        printf("%s -> ", BST->item.prodName);
    }
}