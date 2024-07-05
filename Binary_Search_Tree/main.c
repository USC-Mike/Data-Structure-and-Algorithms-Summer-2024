#include <stdio.h>
#include "BST.h"

int main(void) {
    printf("Hello, World!\n");

    NodePtr BST;

    initializeBinarySearchTree(&BST);

    Product A = {"Chocolate", 21.3, 3, {2,3,2021}};
    insertProducts_to_BST(&BST, A);
    displayBST(BST);

    return 0;
}
