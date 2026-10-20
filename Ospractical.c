#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int arrivaltime;
    int priority;
    int remaining;
    int done;
} Process;

typedef enum
{
    SCHEDULE_FCFS,
    SCHEDULE_SJF,
    SCHEDULE_PRIORITY
} ScheduleType;

static void resetProcesses(Process p[], int n);
static void printProcessTable(const Process p[], int n, const char *label);
static void scheduleNonPreemptive(Process p[], int n, ScheduleType type,
                                  const char *label);
static int isProcessQueued(const int queue[], int head, int queued, int n,
                           int processIndex);
static void enqueueArrivedProcesses(const Process p[], int n, int currentTime,
                                    int excludedIndex, int queue[], int head,
                                    int *tail, int *queued);
static void fcfs(Process p[], int n);
static void sjf(Process p[], int n);
static int roundRobin(Process p[], int n, int quantum);
static void priorityScheduling(Process p[], int n);

int main(void)
{
    const int quantum = 4;
    Process processes[] = {
        {1, 6, 0, 0, 2, 3, 6, 0},
        {2, 8, 0, 0, 0, 1, 8, 0},
        {3, 7, 0, 0, 0, 3, 7, 0},
        {4, 3, 0, 0, 0, 4, 3, 0}};
    const int processCount =
        (int)(sizeof(processes) / sizeof(processes[0]));

    fcfs(processes, processCount);
    sjf(processes, processCount);

    if (quantum <= 0)
    {
        fprintf(stderr, "Round Robin quantum must be greater than zero.\n");
        return EXIT_FAILURE;
    }
    if (!roundRobin(processes, processCount, quantum))
    {
        return EXIT_FAILURE;
    }

    priorityScheduling(processes, processCount);
    return EXIT_SUCCESS;
}

static void resetProcesses(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].waitingTime = 0;
        p[i].turnaroundTime = 0;
        p[i].remaining = p[i].burstTime;
        p[i].done = 0;
    }
}

static void printProcessTable(const Process p[], int n, const char *label)
{
    double totalWaitingTime = 0.0;
    double totalTurnaroundTime = 0.0;

    printf("%s\n", label);
    printf("PID\tBurst\tArrival\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].burstTime,
               p[i].arrivaltime,
               p[i].priority,
               p[i].waitingTime,
               p[i].turnaroundTime);
        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }

    if (n > 0)
    {
        printf("Average waiting time: %.2f\n",
               totalWaitingTime / n);
        printf("Average turnaround time: %.2f\n\n",
               totalTurnaroundTime / n);
    }
}

static void scheduleNonPreemptive(Process p[], int n, ScheduleType type,
                                  const char *label)
{
    int currentTime = 0;
    int completed = 0;

    resetProcesses(p, n);

    while (completed < n)
    {
        int selected = -1;

        for (int i = 0; i < n; i++)
        {
            if (p[i].done || p[i].arrivaltime > currentTime)
            {
                continue;
            }

            if (selected == -1)
            {
                selected = i;
                continue;
            }

            if ((type == SCHEDULE_FCFS &&
                 p[i].arrivaltime < p[selected].arrivaltime) ||
                (type == SCHEDULE_SJF &&
                 p[i].burstTime < p[selected].burstTime) ||
                (type == SCHEDULE_PRIORITY &&
                 p[i].priority < p[selected].priority))
            {
                selected = i;
            }
        }

        if (selected == -1)
        {
            currentTime++;
            continue;
        }

        p[selected].waitingTime = currentTime - p[selected].arrivaltime;
        currentTime += p[selected].burstTime;
        p[selected].turnaroundTime =
            currentTime - p[selected].arrivaltime;
        p[selected].done = 1;
        completed++;
    }

    printProcessTable(p, n, label);
}

static int isProcessQueued(const int queue[], int head, int queued, int n,
                           int processIndex)
{
    for (int position = 0; position < queued; position++)
    {
        int queueIndex = (head + position) % n;
        if (queue[queueIndex] == processIndex)
        {
            return 1;
        }
    }
    return 0;
}

static void enqueueArrivedProcesses(const Process p[], int n, int currentTime,
                                    int excludedIndex, int queue[], int head,
                                    int *tail, int *queued)
{
    for (;;)
    {
        int selected = -1;
        for (int i = 0; i < n; i++)
        {
            if (i == excludedIndex || p[i].done || p[i].remaining <= 0 ||
                p[i].arrivaltime > currentTime ||
                isProcessQueued(queue, head, *queued, n, i))
            {
                continue;
            }

            if (selected == -1 ||
                p[i].arrivaltime < p[selected].arrivaltime)
            {
                selected = i;
            }
        }

        if (selected == -1)
        {
            return;
        }

        queue[*tail] = selected;
        *tail = (*tail + 1) % n;
        (*queued)++;
    }
}

static void fcfs(Process p[], int n)
{
    scheduleNonPreemptive(p, n, SCHEDULE_FCFS,
                          "First-Come, First-Served (FCFS)");
}

static void sjf(Process p[], int n)
{
    scheduleNonPreemptive(p, n, SCHEDULE_SJF,
                          "Shortest Job First (non-preemptive)");
}

static int roundRobin(Process p[], int n, int quantum)
{
    int *queue = malloc((size_t)n * sizeof(*queue));
    int head = 0;
    int tail = 0;
    int queued = 0;
    int currentTime = 0;
    int completed = 0;

    if (queue == NULL)
    {
        fprintf(stderr, "Could not allocate the Round Robin queue.\n");
        return 0;
    }

    resetProcesses(p, n);

    while (completed < n)
    {
        enqueueArrivedProcesses(p, n, currentTime, -1, queue, head, &tail,
                                &queued);

        if (queued == 0)
        {
            currentTime++;
            continue;
        }

        int index = queue[head];
        head = (head + 1) % n;
        queued--;

        int runTime = p[index].remaining < quantum
                          ? p[index].remaining
                          : quantum;
        p[index].remaining -= runTime;
        currentTime += runTime;

        if (p[index].remaining == 0)
        {
            p[index].done = 1;
            p[index].turnaroundTime =
                currentTime - p[index].arrivaltime;
            p[index].waitingTime =
                p[index].turnaroundTime - p[index].burstTime;
            completed++;
        }

        enqueueArrivedProcesses(p, n, currentTime, index, queue, head, &tail,
                                &queued);

        if (p[index].remaining > 0)
        {
            queue[tail] = index;
            tail = (tail + 1) % n;
            queued++;
        }
    }

    free(queue);
    printProcessTable(p, n, "Round Robin");
    return 1;
}

static void priorityScheduling(Process p[], int n)
{
    scheduleNonPreemptive(p, n, SCHEDULE_PRIORITY,
                          "Priority Scheduling (non-preemptive)");
}