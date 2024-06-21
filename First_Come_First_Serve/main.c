#include <stdio.h>
#include "FCFS_Process.h"

int main(void) {
    //printf("Hello, World!\n");

    Process FCFS;
    initializeProcess(&FCFS);

    printf("\t\t -----------------------------------------------------------------------------------------\n");
    printf("\t\t ");

    //takeInput(&FCFS);

    displayProcess(FCFS);
    return 0;
}
