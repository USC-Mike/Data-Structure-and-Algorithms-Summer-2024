//
// Created by Kurt Mike Pino on 6/19/24.
//

#ifndef FIRST_COME_FIRST_SERVE_FCFS_PROCESS_H
#define FIRST_COME_FIRST_SERVE_FCFS_PROCESS_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    struct Process* next;
} Process;

void insertProcess(Process** head, int id, int arrivalTime, int burstTime);
void swapProcesses(Process* a, Process* b);
void sortProcessesByArrivalTime(Process* head);
void calculateTimes(Process* head, int n);
void printProcesses(Process* head);



#endif //FIRST_COME_FIRST_SERVE_FCFS_PROCESS_H
