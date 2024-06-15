#include "StackArray.h"
#include "StackLinkedList.h"

int main(void) {
//  printf("Hello, World!\n");

    // STACK ARRAY
    StackArrayList SA;
    initStackArray(&SA);

    StackArrayList newStack;
    initStackArray(&newStack);

    stack_push(&SA, 9);
    stack_push(&SA, 8);
    stack_push(&SA, 7);
    stack_push(&SA, 6);
    stack_push(&SA, 5);
    stack_push(&SA, 4);

    display(SA);
    visualizeStack(SA);

    newStack = getAllEven(&SA);

    display(newStack);
    visualizeStack(newStack);

    display(SA);
    visualizeStack(SA);

    //STACK LINKED LIST
    StackLinkedList SLL;
    initStackLinkedList(&SLL);

    StackLinkedList newStackLL;
    initStackLinkedList(&newStackLL);

    stack_push_linked_list(&SLL, 10);
    stack_push_linked_list(&SLL, 11);
    stack_push_linked_list(&SLL, 12);
    stack_push_linked_list(&SLL, 13);
    stack_push_linked_list(&SLL, 14);
    stack_push_linked_list(&SLL, 15);
    stack_push_linked_list(&SLL, 16);

    displayLL(SLL);

    //stack_pop_linked_list(&SLL);
    //displayLL(SLL);

    newStackLL = getAllEvenLinkedList(&SLL);
    displayLL(newStackLL);

    return 0;
}