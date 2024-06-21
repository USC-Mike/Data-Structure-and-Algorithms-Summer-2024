//
// Created by Kurt Mike Pino on 6/19/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "FCFS_Process.h"

void initializeProcess(Process *FCFS){
    FCFS->front = NULL;
    FCFS->rear = NULL;
}

Details takeInput(){
    Details data;

    printf("\t\t Total Process Number: ");
    scanf("%d", &data.Total_Process_Number);

    printf("\t\t Process Value: ");
    scanf("%s", &data.Process_Value);

    printf("\t\t Burst Time: ");
    scanf("%d", &data.Burst_Time);

    printf("\t\t Arrival Time: ");
    scanf("%d", &data.Arrival_Time);

    printf("Total Process Number: %d\n", data.Total_Process_Number);
    printf("Burst Time: %d\n", data.Burst_Time);
    printf("Arrival Time: %d\n", data.Arrival_Time);

    return data;
}

void enqueueProcess(Process *FCFS, Details Value){
    NodePTR Replica = malloc(sizeof (Node));

    if (Replica != NULL){
        Replica->P = Value;
        Replica->link = FCFS;
        FCFS = Replica;
    }
}

void enqueueSortedProcess(Process *List, Details Value){
    NodePTR Replica = malloc(sizeof (Node));
    //Process *Temp = malloc(sizeof (Process));

    while ()

    if (Replica != NULL){

    }
}

bool isEmptyProcess(Process List){
    return (List.rear == NULL) ? true : false;
}

bool isFullProcess(Process List){
    return (List.front == NULL) ? true : false;
}

void displayProcess(Process FCFS){


    printf("\n\t\t\ --------------------------------------------------------------------------------------------\n");
    printf("\t\t |     %5s     |  %5s  |  %5s  |  %5s  |  %5s  |\n", "PROCESS ID", "BURST TIME", "ARRIVAL TIME", "WAITING TIME", "TURN AROUND TIME");
    //printf("\t\t |     %5s     |  %5s  |  %5s  |  %5s  |  %5s  |");
}