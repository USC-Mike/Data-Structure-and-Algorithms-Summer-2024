//
// Created by Kurt Mike Pino on 6/19/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "FCFS_Process.h"

void insertProcess(Process** head, int id, int arrivalTime, int burstTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->arrivalTime = arrivalTime;
    newProcess->burstTime = burstTime;
    newProcess->completionTime = 0;
    newProcess->turnAroundTime = 0;
    newProcess->waitingTime = 0;
    newProcess->next = NULL;

    if (*head == NULL) {
        *head = newProcess;
    } else {
        Process* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProcess;
    }
}

void swapProcesses(Process* a, Process* b) {
    int temp;

    temp = a->id;
    a->id = b->id;
    b->id = temp;

    temp = a->arrivalTime;
    a->arrivalTime = b->arrivalTime;
    b->arrivalTime = temp;

    temp = a->burstTime;
    a->burstTime = b->burstTime;
    b->burstTime = temp;
}

void sortProcessesByArrivalTime(Process* head) {
    Process* i = head;
    while (i != NULL) {
        Process* min = i;
        Process* j = i->next;
        while (j != NULL) {
            if (j->arrivalTime < min->arrivalTime ||
                (j->arrivalTime == min->arrivalTime && j->id < min->id)) {
                min = j;
            }
            j = j->next;
        }
        if (min != i) {
            swapProcesses(i, min);
        }
        i = i->next;
    }
}

void calculateTimes(Process* head, int n) {
    Process* current = head;
    int currentTime = 0;
    float totalTurnAroundTime = 0, totalWaitingTime = 0;

    while (current != NULL) {
        if (currentTime < current->arrivalTime) {
            currentTime = current->arrivalTime;
        }
        current->completionTime = currentTime + current->burstTime;
        current->turnAroundTime = current->completionTime - current->arrivalTime;
        current->waitingTime = current->turnAroundTime - current->burstTime;

        totalTurnAroundTime += current->turnAroundTime;
        totalWaitingTime += current->waitingTime;

        currentTime = current->completionTime;
        current = current->next;
    }

    printf("\nAverage Turn Around Time = %.2f\n", totalTurnAroundTime / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWaitingTime / n);
}

void printProcesses(Process* head) {
    printf("===============================================\n");
    printf("Process ID\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    Process* temp = head;
    while (temp != NULL) {
        printf("\t%d\t\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", temp->id, temp->arrivalTime, temp->burstTime, temp->completionTime, temp->turnAroundTime, temp->waitingTime);
        temp = temp->next;
    }
}