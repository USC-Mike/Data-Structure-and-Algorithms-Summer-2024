#include <stdio.h>
#include "FCFS_Process.h"

int main() {
    int n, id, arrivalTime, burstTime;
    Process* head = NULL;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process id, arrival time, and burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &id, &arrivalTime, &burstTime);
        insertProcess(&head, id, arrivalTime, burstTime);
    }

    sortProcessesByArrivalTime(head);
    calculateTimes(head, n);
    printProcesses(head);

    return 0;
}