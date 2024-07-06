#include <stdio.h>
#include "BST.h"

int main(void) {
    printf("Hello, World!\n");

    NodePtr BST;
    initializeBinarySearchTree(&BST);

    Product A = {"Chocolate", 1.80, 110, {8, 8, 2024}};
    Product B = {"Milk", 3.00, 50, {20, 7, 2024}};
    Product C = {"Apple", 1.20, 100, {10, 7, 2024}};
    Product D = {"Shampoo", 0.50, 150, {12, 7, 2024}};
    Product E = {"Coffee", 2.50, 80, {25, 7, 2024}};

    insertProducts_to_BST(&BST, A);
    insertProducts_to_BST(&BST, B);
    insertProducts_to_BST(&BST, C);
    insertProducts_to_BST(&BST, E);
    insertProducts_to_BST(&BST, D);

    // BFS
    // DFS
    // PreOrder, InOrder, PostOrder

    printf("PreOrder Traversals: ");
    displayPreOrder(BST);

    printf("\nInOrder Traversals: ");
    displayInOrder(BST);

    printf("\nPostOrder Traversals: ");
    displayPostOrder(BST);

    deleteProducts_from_BST(&BST, "Milk");

    printf("\nBreadth First Search Traversals: ");
    BFS_traversal(BST);

    return 0;
}
