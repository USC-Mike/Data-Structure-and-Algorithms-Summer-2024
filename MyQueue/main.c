#include <stdio.h>
#include "QueueLinkedList.h"
#include "QueueArray.h"

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

    CircularQ QA;
    initCircularArrayQueue(&QA);

    info data[] = {{"Yevgeny", 1, 1 } ,
                   {"Daryl", 2, 2},
                   {"Mike", 3, 3}};

    enqueueCircularArray(&QA, data[0]);
    enqueueCircularArray(&QA, data[1]);

    displayCircularArrayQueue(QA);

    dequeueCircularArray(&QA);
    enqueueCircularArray(&QA, data[2]);

    displayCircularArrayQueue(QA);
    return 0;
}
