//
// Created by Kurt Mike Pino on 6/19/24.
//

#ifndef FIRST_COME_FIRST_SERVE_FCFS_PROCESS_H
#define FIRST_COME_FIRST_SERVE_FCFS_PROCESS_H
#include <stdbool.h>
typedef struct {
    char Process_Value;
    int Arrival_Time;
    int Burst_Time;
    int Waiting_Time;
    int Turn_Around_Time;
    int Total_Turn_Around_Time;
    int Total_Waiting_Time;
    int Average_Turn_Around_Time;
    int Average_Waiting_Time;
    int Total_Process_Number;
}Details;

typedef struct node{
    Details P;
    struct node * link;
}Node, *NodePTR;

typedef struct {
    NodePTR front;
    NodePTR rear;
}Process;

void initializeProcess(Process *Q);
Details takeInput();
void enqueueProcess(Process *Q, Details Value);
void enqueueSortedProcess(Process *Q, Details Value);
Details dequeueProcess(Process Q);
int peekProcess(Process Q);
int removeAtProcess(Process Q);
bool isEmptyProcess(Process Q);
bool isFullProcess(Process Q);
void displayProcess(Process Q);


#endif //FIRST_COME_FIRST_SERVE_FCFS_PROCESS_H
