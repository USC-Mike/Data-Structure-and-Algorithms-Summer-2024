//
// Created by Kurt Mike Pino on 7/5/24.
//

#include <string.h>
#include "BST.h"

void initializeBinarySearchTree(NodePtr *BST){
    (*BST)->item.prodQty = 0;
    (*BST)->Right = NULL;
    (*BST)->Left = NULL;
}

void insertProducts_to_BST(NodePtr *BST, Product Prod){
//    NodePtr *trav;
//    for(trav = BST; *trav != NULL && strcmp((*trav)->item.prodName,Prod.prodName) != 0;){
//        trav = (strcmp(Prod.prodName, (*trav)->item.prodName) < 0) ? &(*trav)->Left : &(*trav)->Right;
//    }
//    if (*trav==NULL){ //element does not exist
//        *trav = (NodePtr)calloc(1,sizeof(NodePtr));
//        (*trav)->item = Prod;
//    }

    if(*BST != NULL && strcmp((*BST)->item.prodName, Prod.prodName) != 0){
        BST = (strcmp((*BST)->item.prodName, Prod.prodName) < 0) ? &(*BST)->Right : &(*BST)->Left;
        insertProducts_to_BST(BST, Prod);
    } else{
        *BST = calloc(1, sizeof(NodeType));
        if((*BST)->item.prodQty != 0){
            (*BST)->item = Prod;
        }
    }
}

void inorderBST(NodePtr BST){ //sorted order
    if(BST->item.prodQty != 0){
        inorderBST(BST->Left);
        printf("\n%-9s ",BST->item.prodName);
        printf("%-10d ",BST->item.prodQty);
        printf("%-1f ",BST->item.prodPrice);
        printf("%-10d ",BST->item.expDate);
        inorderBST(BST->Right);
    }
}

void displayBST(NodePtr BST){
    if(BST->item.prodQty == 0){
        printf("\nBST is empty");
    } else {
        printf("\n");
        inorderBST(BST);
    }
}