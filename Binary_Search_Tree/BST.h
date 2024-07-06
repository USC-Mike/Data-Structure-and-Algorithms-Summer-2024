//
// Created by Kurt Mike Pino on 7/5/24.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day, month, year;
}Date;

typedef struct {
    char prodName[20]; // Alphabetical Order Insert
    float prodPrice;
    int prodQty;
    Date expDate;
}Product;

typedef struct node{
    Product item;
    struct node *Left, *Right;
}NodeType, *NodePtr;

typedef struct queueNode {
    NodePtr treeNode;
    struct queueNode *next;
}QueueNode, *QueueNodePtr;

typedef struct {
    QueueNodePtr front;
    QueueNodePtr rear;
}QueueLList;

void initializeQueue(QueueLList *Q);
void enqueue(QueueLList *Q, NodePtr treeNode);
NodePtr dequeue(QueueLList *Q);
void BFS_traversal(NodePtr BST);

void initializeBinarySearchTree(NodePtr *BST);
void insertProducts_to_BST(NodePtr *BST, Product Prod);
void deleteProducts_from_BST(NodePtr *BST, char *name);

void displayPreOrder(NodePtr BST);
void displayInOrder(NodePtr BST);
void displayPostOrder(NodePtr BST);

#endif //BINARY_SEARCH_TREE_BST_H
