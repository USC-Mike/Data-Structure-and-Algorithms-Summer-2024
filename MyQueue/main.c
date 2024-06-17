#include <stdio.h>
#include "QueueLinkedList.h"

int main(void) {
    //printf("Hello, World!\n");

    QueueLinkedList QL;
    initQueueLinkedList(&QL);

    enqueueQueueLinkedList(&QL, 9);
    enqueueQueueLinkedList(&QL, 8);
    enqueueQueueLinkedList(&QL, 7);
    enqueueQueueLinkedList(&QL, 6);
    enqueueQueueLinkedList(&QL, 5);

    dequeueQueueLinkedList(&QL);
    printf("\nFront => %d\n", front(QL));
    displayQueueLL(&QL);

    printf("\nFront => %d\n", front(QL));

    return 0;
}
