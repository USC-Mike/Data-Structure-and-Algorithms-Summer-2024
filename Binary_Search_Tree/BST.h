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

void initializeBinarySearchTree(NodePtr *BST);
void populateProducts_to_BST(NodePtr *BST, Product Prod);
void insertProducts_to_BST(NodePtr *BST, Product Prod);
void displayBST(NodePtr BST);


#endif //BINARY_SEARCH_TREE_BST_H
