#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100

struct Job {
    int id;
};

struct JobQueue {
    struct Job jobs[MAX_JOBS];
    int front, rear;
};

void initializeQueue(struct JobQueue *queue) {
    queue->front = queue->rear = -1;
}

int isQueueEmpty(struct JobQueue *queue) {
    return (queue->front == -1);
}
int isQueueFull(struct JobQueue *queue) {
    return (queue->rear == MAX_JOBS - 1);
}

void addJob(struct JobQueue *queue, struct Job job) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot add more jobs.\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->jobs[queue->rear] = job;
    printf("Job with ID %d added to the queue.\n", job.id);
}

void deleteJob(struct JobQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. No jobs to delete.\n");
        return;
    }

    struct Job deletedJob = queue->jobs[queue->front];
    if (queue->front == queue->rear) {
        initializeQueue(queue);
    } else {
        queue->front++;
    }

    printf("Job with ID %d deleted from the queue.\n", deletedJob.id);
}

int main() {
    struct JobQueue jobQueue;
    initializeQueue(&jobQueue);

    while (1) {
        printf("1. Add a job\n2. Delete a job\n3. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (!isQueueFull(&jobQueue)) {
                    struct Job newJob;
                    printf("Enter job ID: ");
                    scanf("%d", &newJob.id);
                    addJob(&jobQueue, newJob);
                } else {
                    printf("Queue is full. Cannot add more jobs.\n");
                }
                break;
            }
            case 2: {
                if (!isQueueEmpty(&jobQueue)) {
                    deleteJob(&jobQueue);
                } else {
                    printf("Queue is empty. No jobs to delete.\n");
                }
                break;
            }
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
