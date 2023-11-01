#include <stdio.h>
#include <string.h>

// Process structure
struct ProcessDetails
{
    int processId;
    int arrivalTime;
    int burstTime;
    int originalBurst;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

// Round Robin Scheduling
void scheduleRoundRobin(struct ProcessDetails process[], int totalProcesses, int *currentTime, int *completed, char *ganttChart)
{
    int processFound = 0;
    // Use Round Robin with time quantum of 6 units
    for (int i = 0; i < totalProcesses; i++)
    {
        if (process[i].arrivalTime <= *currentTime && process[i].burstTime > 0)
        {
            processFound = 1;
            // If burst time less than time quantum, complete the process
            if (process[i].burstTime <= 6)
            {
                *currentTime += process[i].burstTime;
                // Calculate waiting time
                process[i].waitingTime = *currentTime - process[i].arrivalTime - process[i].originalBurst;
                process[i].burstTime = 0;
                process[i].completionTime = *currentTime;
            }
            else
            {
                // Otherwise schedule for 6 units
                *currentTime += 6;
                process[i].burstTime -= 6;
            }

            // Update Gantt Chart
            sprintf(ganttChart + strlen(ganttChart), "P%d ", process[i].processId);

            if (process[i].burstTime == 0)
            {
                // If completed, update turnaround time
                process[i].turnaroundTime = process[i].completionTime - process[i].arrivalTime;
                (*completed)++;
            }
        }
    }

    if (!processFound)
    {
        // Increment time if no process found
        (*currentTime)++;
        sprintf(ganttChart + strlen(ganttChart), "IDLE ");
    }
}

// Longest Job First Scheduling
void scheduleLongestJob(struct ProcessDetails process[], int totalProcesses, int *currentTime, int *completed, char *ganttChart)
{

    if (*currentTime % 10 == 0)
    {

        int longestJobIndex = -1;
        int longestRemainingTime = -1;

        // Find longest remaining job
        for (int i = 0; i < totalProcesses; i++)
        {
            if (process[i].arrivalTime <= *currentTime &&
                process[i].burstTime > longestRemainingTime)
            {
                longestJobIndex = i;
                longestRemainingTime = process[i].burstTime;
            }
        }

        if (longestJobIndex != -1)
        {
            // Schedule the longest job
            *currentTime += process[longestJobIndex].burstTime;
            process[longestJobIndex].waitingTime = *currentTime - process[longestJobIndex].arrivalTime - process[longestJobIndex].originalBurst;
            process[longestJobIndex].burstTime = 0;
            process[longestJobIndex].completionTime = *currentTime;

            // Update Gantt Chart
            sprintf(ganttChart + strlen(ganttChart), "P%d ", process[longestJobIndex].processId);

            // Update metrics if completed
            process[longestJobIndex].turnaroundTime = process[longestJobIndex].completionTime - process[longestJobIndex].arrivalTime;
            (*completed)++;
        }
    }
}

// Calculate performance metrics
void calculateMetrics(struct ProcessDetails process[], int totalProcesses)
{
    int currentTime = 0;
    int completedProcesses = 0;
    char ganttChart[1000] = "";
    // Loop till all processes are complete
    while (completedProcesses < totalProcesses)
    {
        scheduleRoundRobin(process, totalProcesses, &currentTime, &completedProcesses, ganttChart);
        scheduleLongestJob(process, totalProcesses, &currentTime, &completedProcesses, ganttChart);
    }

    // Print metrics
    printf("\nGantt Chart: %s \n", ganttChart);
    printf("\nProcess  ArrivalTime  OriginalBurst  CompletionTime  TurnaroundTime  WaitingTime\n");
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < totalProcesses; i++)
    {
        printf("P%d        %d            %d            %d              %d               %d\n",
               process[i].processId, process[i].arrivalTime, process[i].originalBurst,
               process[i].completionTime, process[i].turnaroundTime, process[i].waitingTime);
        totalWaitingTime += process[i].waitingTime;
        totalTurnaroundTime += process[i].turnaroundTime;
    }

    // Calculate and print averages
    float avgWaitingTime = (float)totalWaitingTime / totalProcesses;
    float avgTurnaroundTime = (float)totalTurnaroundTime / totalProcesses;

    printf("\nAverage Waiting Time: %.2f ", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
}

int main()
{
    printf("\n================= CPU Scheduling =================\n ");

    int totalProcesses;
    printf("\nEnter total number of processes: ");
    scanf("%d", &totalProcesses);

    struct ProcessDetails process[totalProcesses];

    // Take input
    for (int i = 0; i < totalProcesses; i++)
    {
        printf("\nEnter arrival time P%d: ", i + 1);
        scanf("%d", &process[i].arrivalTime);

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &process[i].burstTime);

        process[i].processId = i + 1;
        process[i].originalBurst = process[i].burstTime;

        process[i].waitingTime = 0;
        process[i].turnaroundTime = 0;
        process[i].completionTime = 0;
    }

    // Calculate and print metrics
    calculateMetrics(process, totalProcesses);

    return 0;
}
