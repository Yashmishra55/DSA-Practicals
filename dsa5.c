#include <stdio.h>
#define MAX_SIZE 100

// Structure to represent deque
struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize deque
void initDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = 0;
}

// Function to check if deque is empty
int isEmpty(struct Deque *dq) {
    return dq->front == -1 || dq->front > dq->rear;
}

// Function to check if deque is full
int isFull(struct Deque *dq) {
    return dq->rear == MAX_SIZE - 1;
}

// Function to add element at front of deque
void addFront(struct Deque *dq, int data) {
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
        dq->arr[dq->front] = data;
    } else if (dq->front > 0) {
        dq->arr[--dq->front] = data;
    } else {
        printf("Deque is full at the front. Cannot add element.\n");
    }
}

// Function to add element at rear of deque
void addRear(struct Deque *dq, int data) {
    if (!isFull(dq)) {
        dq->arr[++dq->rear] = data;
        if (dq->front == -1) {
            dq->front = 0;
        }
    } else {
        printf("Deque is full at the rear. Cannot add element.\n");
    }
}

// Function to delete element from front of deque
void deleteFront(struct Deque *dq) {
    if (!isEmpty(dq)) {
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1;
        } else {
            dq->front++;
        }
    } else {
        printf("Deque is empty. Cannot delete from front.\n");
    }
}

// Function to delete element from rear of deque
void deleteRear(struct Deque *dq) {
    if (!isEmpty(dq)) {
        dq->rear--;
    } else {
        printf("Deque is empty. Cannot delete from rear.\n");
    }
}

// Function to display elements of deque
void displayDeque(struct Deque *dq) {
    if (!isEmpty(dq)) {
        printf("Deque elements: ");
        for (int i = dq->front; i <= dq->rear; i++) {
            printf("%d ", dq->arr[i]);
        }
        printf("\n");
    } else {
        printf("Deque is empty.\n");
    }
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    addFront(&dq, 5);
    addFront(&dq, 10);
    addRear(&dq, 15);
    addRear(&dq, 20);

    displayDeque(&dq);

    deleteFront(&dq);
    deleteRear(&dq);

    displayDeque(&dq);

    return 0;
}
